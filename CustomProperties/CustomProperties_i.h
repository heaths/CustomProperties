

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for CustomProperties.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __CustomProperties_i_h__
#define __CustomProperties_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IExecutable_FWD_DEFINED__
#define __IExecutable_FWD_DEFINED__
typedef interface IExecutable IExecutable;

#endif 	/* __IExecutable_FWD_DEFINED__ */


#ifndef __Executable_FWD_DEFINED__
#define __Executable_FWD_DEFINED__

#ifdef __cplusplus
typedef class Executable Executable;
#else
typedef struct Executable Executable;
#endif /* __cplusplus */

#endif 	/* __Executable_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_CustomProperties_0000_0000 */
/* [local] */ 

typedef /* [helpstring] */ 
enum Architecture
    {
        None	= 0,
        x86	= 0x14c,
        IA64	= 0x200,
        x64	= 0x8664
    } 	Architecture;



extern RPC_IF_HANDLE __MIDL_itf_CustomProperties_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_CustomProperties_0000_0000_v0_0_s_ifspec;

#ifndef __IExecutable_INTERFACE_DEFINED__
#define __IExecutable_INTERFACE_DEFINED__

/* interface IExecutable */
/* [helpstring][unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IExecutable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e0f7e719-ec14-4431-8ebe-51986400cc9f")
    IExecutable : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Architecture( 
            /* [retval][out] */ Architecture *pArchitecture) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsManagedAssembly( 
            /* [retval][out] */ VARIANT_BOOL *pIsManagedAssembly) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IExecutableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExecutable * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExecutable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExecutable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IExecutable * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IExecutable * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IExecutable * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IExecutable * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Architecture )( 
            IExecutable * This,
            /* [retval][out] */ Architecture *pArchitecture);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsManagedAssembly )( 
            IExecutable * This,
            /* [retval][out] */ VARIANT_BOOL *pIsManagedAssembly);
        
        END_INTERFACE
    } IExecutableVtbl;

    interface IExecutable
    {
        CONST_VTBL struct IExecutableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExecutable_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IExecutable_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IExecutable_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IExecutable_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IExecutable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IExecutable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IExecutable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IExecutable_get_Architecture(This,pArchitecture)	\
    ( (This)->lpVtbl -> get_Architecture(This,pArchitecture) ) 

#define IExecutable_get_IsManagedAssembly(This,pIsManagedAssembly)	\
    ( (This)->lpVtbl -> get_IsManagedAssembly(This,pIsManagedAssembly) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IExecutable_INTERFACE_DEFINED__ */



#ifndef __CustomPropertiesLib_LIBRARY_DEFINED__
#define __CustomPropertiesLib_LIBRARY_DEFINED__

/* library CustomPropertiesLib */
/* [version][helpstring][uuid] */ 


EXTERN_C const IID LIBID_CustomPropertiesLib;

EXTERN_C const CLSID CLSID_Executable;

#ifdef __cplusplus

class DECLSPEC_UUID("a3da9115-050d-42b5-8eac-10aaa8f73a76")
Executable;
#endif
#endif /* __CustomPropertiesLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


