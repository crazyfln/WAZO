

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Aug 28 16:42:53 2017
 */
/* Compiler settings for PlayVideoActiveX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __PlayVideoActiveXidl_h__
#define __PlayVideoActiveXidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DPlayVideoActiveX_FWD_DEFINED__
#define ___DPlayVideoActiveX_FWD_DEFINED__
typedef interface _DPlayVideoActiveX _DPlayVideoActiveX;

#endif 	/* ___DPlayVideoActiveX_FWD_DEFINED__ */


#ifndef ___DPlayVideoActiveXEvents_FWD_DEFINED__
#define ___DPlayVideoActiveXEvents_FWD_DEFINED__
typedef interface _DPlayVideoActiveXEvents _DPlayVideoActiveXEvents;

#endif 	/* ___DPlayVideoActiveXEvents_FWD_DEFINED__ */


#ifndef __PlayVideoActiveX_FWD_DEFINED__
#define __PlayVideoActiveX_FWD_DEFINED__

#ifdef __cplusplus
typedef class PlayVideoActiveX PlayVideoActiveX;
#else
typedef struct PlayVideoActiveX PlayVideoActiveX;
#endif /* __cplusplus */

#endif 	/* __PlayVideoActiveX_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_PlayVideoActiveX_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_PlayVideoActiveX_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_PlayVideoActiveX_0000_0000_v0_0_s_ifspec;


#ifndef __PlayVideoActiveXLib_LIBRARY_DEFINED__
#define __PlayVideoActiveXLib_LIBRARY_DEFINED__

/* library PlayVideoActiveXLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_PlayVideoActiveXLib;

#ifndef ___DPlayVideoActiveX_DISPINTERFACE_DEFINED__
#define ___DPlayVideoActiveX_DISPINTERFACE_DEFINED__

/* dispinterface _DPlayVideoActiveX */
/* [uuid] */ 


EXTERN_C const IID DIID__DPlayVideoActiveX;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1CE85FEF-73FE-45F5-ACC2-0AF39795D5ED")
    _DPlayVideoActiveX : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DPlayVideoActiveXVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DPlayVideoActiveX * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DPlayVideoActiveX * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DPlayVideoActiveX * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DPlayVideoActiveX * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DPlayVideoActiveX * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DPlayVideoActiveX * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DPlayVideoActiveX * This,
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
        
        END_INTERFACE
    } _DPlayVideoActiveXVtbl;

    interface _DPlayVideoActiveX
    {
        CONST_VTBL struct _DPlayVideoActiveXVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DPlayVideoActiveX_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DPlayVideoActiveX_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DPlayVideoActiveX_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DPlayVideoActiveX_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DPlayVideoActiveX_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DPlayVideoActiveX_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DPlayVideoActiveX_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DPlayVideoActiveX_DISPINTERFACE_DEFINED__ */


#ifndef ___DPlayVideoActiveXEvents_DISPINTERFACE_DEFINED__
#define ___DPlayVideoActiveXEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DPlayVideoActiveXEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DPlayVideoActiveXEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("311BE723-2B9B-432D-B249-E61D93B84DD6")
    _DPlayVideoActiveXEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DPlayVideoActiveXEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DPlayVideoActiveXEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DPlayVideoActiveXEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DPlayVideoActiveXEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DPlayVideoActiveXEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DPlayVideoActiveXEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DPlayVideoActiveXEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DPlayVideoActiveXEvents * This,
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
        
        END_INTERFACE
    } _DPlayVideoActiveXEventsVtbl;

    interface _DPlayVideoActiveXEvents
    {
        CONST_VTBL struct _DPlayVideoActiveXEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DPlayVideoActiveXEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DPlayVideoActiveXEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DPlayVideoActiveXEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DPlayVideoActiveXEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DPlayVideoActiveXEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DPlayVideoActiveXEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DPlayVideoActiveXEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DPlayVideoActiveXEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PlayVideoActiveX;

#ifdef __cplusplus

class DECLSPEC_UUID("336811DA-2169-42D4-829B-A6B18735BCA0")
PlayVideoActiveX;
#endif
#endif /* __PlayVideoActiveXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


