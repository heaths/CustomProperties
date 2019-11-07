#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CustomProperties
{
    TEST_CLASS(ExecutableTests)
    {
    public:

        TEST_CLASS_INITIALIZE(Initialize)
        {
            m_hr = ::CoInitialize(nullptr);
        }

        TEST_CLASS_CLEANUP(Cleanup)
        {
            if (SUCCEEDED(m_hr))
            {
                ::CoUninitialize();
            }
        }

    private:
        static HRESULT m_hr;

    public:
        TEST_METHOD(get_Architecture)
        {
            CComPtr<IExecutable> pExecutable;
            CComPtr<IPersistFile> pPersistFile;

            auto hr = pExecutable.CoCreateInstance(__uuidof(Executable));
            Assert::AreEqual(S_OK, hr);

            hr = pExecutable.QueryInterface(&pPersistFile);
            Assert::AreEqual(S_OK, hr);

            wchar_t szPath[MAX_PATH];
            ::GetModuleFileName(NULL, szPath, MAX_PATH);

            hr = pPersistFile->Load(szPath, STGM_READ);
            Assert::AreEqual(S_OK, hr);

            Architecture arch = Architecture::None;
            hr = pExecutable->get_Architecture(&arch);
            Assert::AreEqual(S_OK, hr);

#ifdef WIN32
            Assert::AreEqual<DWORD>(Architecture::x86, arch);
#else
            Assert::AreEqual<DWORD>(Architecture::x64, arch);
#endif
        }

        TEST_METHOD(get_IsManagedAssembly)
        {
            CComPtr<IExecutable> pExecutable;
            CComPtr<IPersistFile> pPersistFile;

            auto hr = pExecutable.CoCreateInstance(__uuidof(Executable));
            Assert::AreEqual(S_OK, hr);

            hr = pExecutable.QueryInterface(&pPersistFile);
            Assert::AreEqual(S_OK, hr);

            wchar_t szPath[MAX_PATH];
            ::GetModuleFileName(NULL, szPath, MAX_PATH);

            hr = pPersistFile->Load(szPath, STGM_READ);
            Assert::AreEqual(S_OK, hr);

            VARIANT_BOOL vtbool;
            hr = pExecutable->get_IsManagedAssembly(&vtbool);
            Assert::AreEqual(S_OK, hr);
            Assert::AreEqual(VARIANT_TRUE, vtbool);
        }
    };

    HRESULT ExecutableTests::m_hr = S_OK;
}
