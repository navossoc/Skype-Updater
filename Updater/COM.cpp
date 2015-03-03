#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////
// Exported functions
//////////////////////////////////////////////////////////////////////////

HRESULT __stdcall DllCanUnloadNow(void)
{
	return S_OK;
}

HRESULT __stdcall DllGetClassObject(
	_In_   REFCLSID rclsid,
	_In_   REFIID riid,
	_Out_  LPVOID *ppv
)
{
	*ppv = NULL;
	return CLASS_E_CLASSNOTAVAILABLE;
}

HRESULT __stdcall DllRegisterServer(void)
{
	return S_OK;
}

HRESULT __stdcall DllUnregisterServer(void)
{
	return S_OK;
}
