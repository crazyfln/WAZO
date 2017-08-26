// PlayVideoActiveX.cpp : CPlayVideoActiveXApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "PlayVideoActiveX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CPlayVideoActiveXApp theApp;

const GUID CDECL _tlid = { 0x75FF8839, 0xB7C9, 0x425C, { 0x89, 0x61, 0x46, 0x2F, 0xC1, 0x47, 0x88, 0xDC } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CPlayVideoActiveXApp::InitInstance - DLL 初始化

BOOL CPlayVideoActiveXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CPlayVideoActiveXApp::ExitInstance - DLL 终止

int CPlayVideoActiveXApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
