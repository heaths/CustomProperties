// dllmain.h : Declaration of module class.

class CCustomPropertiesModule : public ATL::CAtlDllModuleT< CCustomPropertiesModule >
{
public:
    DECLARE_LIBID(LIBID_CustomPropertiesLib)
    DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CUSTOMPROPERTIES, "{ce26a877-d9df-46eb-bfb3-105e7415279f}")
};

extern class CCustomPropertiesModule _AtlModule;
