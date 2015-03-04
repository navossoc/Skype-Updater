// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "Updater.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		return ProcessAttach();
	case DLL_PROCESS_DETACH:
		return ProcessDetach();
	}
	return TRUE;
}

