// Executable.h : Declaration of the CExecutable

#pragma once
#include "resource.h"       // main symbols

#include "CustomProperties_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;

// CExecutable

class ATL_NO_VTABLE CExecutable :
    public CComObjectRootEx<CComMultiThreadModel>,
    public CComCoClass<CExecutable, &CLSID_Executable>,
    public IDispatchImpl<IExecutable, &IID_IExecutable, &LIBID_CustomPropertiesLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
    public IPersistFile
{
public:
    CExecutable() :
        m_pFileHeaders(nullptr),
        m_pCorDirectory(nullptr)
    {
    }

    DECLARE_REGISTRY_RESOURCEID(106)

    BEGIN_COM_MAP(CExecutable)
        COM_INTERFACE_ENTRY(IExecutable)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IPersistFile)
    END_COM_MAP()

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    HRESULT FinalConstruct()
    {
        return S_OK;
    }

    void FinalRelease()
    {
    }

public:
    // IPersist
    STDMETHODIMP GetClassID(
        /* [out] */ __RPC__out CLSID* pClassID)
    {
        return E_NOTIMPL;
    }

    // IPersistFile
    STDMETHODIMP IsDirty(void)
    {
        return S_FALSE;
    }

    STDMETHOD(Load)(
        /* [in] */ __RPC__in LPCOLESTR pszFileName,
        /* [in] */ DWORD dwMode);

    STDMETHODIMP Save(
        /* [unique][in] */ __RPC__in_opt LPCOLESTR pszFileName,
        /* [in] */ BOOL fRemember)
    {
        return E_NOTIMPL;
    }

    STDMETHODIMP SaveCompleted(
        /* [unique][in] */ __RPC__in_opt LPCOLESTR pszFileName)
    {
        return S_OK;
    }

    STDMETHODIMP GetCurFile(
        /* [out] */ __RPC__deref_out_opt LPOLESTR* ppszFileName)
    {
        return E_NOTIMPL;
    }

private:
    void Reset() throw();

    PIMAGE_NT_HEADERS GetFileHeaders() throw();
    PIMAGE_DATA_DIRECTORY GetCorDirectory() throw();

private:
    CAtlFile m_file;
    CAtlFileMappingBase m_fileMapping;

    PIMAGE_NT_HEADERS m_pFileHeaders;
    PIMAGE_DATA_DIRECTORY m_pCorDirectory;

public:
    STDMETHOD(get_Architecture)(Architecture* pArchitecture);
    STDMETHOD(get_IsManagedAssembly)(VARIANT_BOOL* pIsManagedAssembly);
};

OBJECT_ENTRY_AUTO(__uuidof(Executable), CExecutable)
