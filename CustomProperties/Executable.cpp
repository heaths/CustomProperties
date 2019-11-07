// Executable.cpp : Implementation of CExecutable

#include "pch.h"
#include "Executable.h"

#define MAKEPTR(cast, ptr, addValue) (cast)((DWORD_PTR)(ptr) + (DWORD_PTR)(addValue))

// CExecutable

STDMETHODIMP CExecutable::Load(
    /* [in] */ __RPC__in LPCOLESTR pszFileName,
    /* [in] */ DWORD dwMode)
{
    Reset();

    const DWORD FILE_SHARE_ALL = FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE;
    auto hr = m_file.Create(pszFileName, GENERIC_READ, FILE_SHARE_ALL, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY | FILE_FLAG_RANDOM_ACCESS);
    if (FAILED(hr))
    {
        return AtlHresultFromLastError();
    }

    hr = m_fileMapping.MapFile(m_file, 0, 0, PAGE_READONLY | SEC_IMAGE_NO_EXECUTE);
    if (FAILED(hr))
    {
        return AtlHresultFromLastError();
    }
}

void CExecutable::Reset() throw()
{
    m_pCorDirectory = nullptr;
    m_pFileHeaders = nullptr;

    m_fileMapping.Unmap();
    m_file.Close();
}

PIMAGE_NT_HEADERS CExecutable::GetFileHeaders() throw()
{
    if (!m_pFileHeaders)
    {
        auto pDosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(m_fileMapping.GetData());
        if (IMAGE_DOS_SIGNATURE == pDosHeader->e_magic)
        {
            m_pFileHeaders = MAKEPTR(PIMAGE_NT_HEADERS, pDosHeader, pDosHeader->e_lfanew);
        }
    }

    return m_pFileHeaders;
}

PIMAGE_DATA_DIRECTORY CExecutable::GetCorDirectory() throw()
{
    auto pFileHeaders = GetFileHeaders();
    if (!pFileHeaders)
    {
        return nullptr;
    }

    if (!m_pCorDirectory)
    {
        if (IMAGE_NT_SIGNATURE == pFileHeaders->Signature)
        {
            switch (pFileHeaders->OptionalHeader.Magic)
            {
            case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
                m_pCorDirectory = &reinterpret_cast<PIMAGE_NT_HEADERS32>(pFileHeaders)->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR];
                break;

            case IMAGE_NT_OPTIONAL_HDR64_MAGIC:
                m_pCorDirectory = &reinterpret_cast<PIMAGE_NT_HEADERS64>(pFileHeaders)->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR];
                break;
            }
        }
    }

    return m_pCorDirectory;
}

STDMETHODIMP CExecutable::get_Architecture(Architecture* pArchitecture)
{
    if (!pArchitecture)
    {
        return E_POINTER;
    }

    auto headers = GetFileHeaders();
    if (!headers)
    {
        return CO_E_NOT_SUPPORTED;
    }

    *pArchitecture = static_cast<Architecture>(headers->FileHeader.Machine);
    return S_OK;
}


STDMETHODIMP CExecutable::get_IsManagedAssembly(VARIANT_BOOL* pIsManagedAssembly)
{
    if (!pIsManagedAssembly)
    {
        return E_POINTER;
    }

    auto cor = GetCorDirectory();
    if (!cor)
    {
        return CO_E_NOT_SUPPORTED;
    }

    *pIsManagedAssembly = cor->VirtualAddress && cor->Size ? VARIANT_TRUE : VARIANT_FALSE;
    return S_OK;
}
