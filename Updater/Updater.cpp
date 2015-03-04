// Updater.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Updater.h"

//////////////////////////////////////////////////////////////////////////
// Function pointers
//////////////////////////////////////////////////////////////////////////

prtShowWindow fnShowWindow = NULL;

//////////////////////////////////////////////////////////////////////////
// DLL events
//////////////////////////////////////////////////////////////////////////

BOOL ProcessAttach()
{
	// Initialize
	if (MH_Initialize() != MH_OK)
	{
		return FALSE;
	}

	// Create a hook for ShowWindow
	if (MH_CreateHook(&ShowWindow, &DetourShowWindow,
		reinterpret_cast<void**>(&fnShowWindow)) != MH_OK)
	{
		return FALSE;
	}

	// Enable all hooks
	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL ProcessDetach()
{
	// Uninitialize
	if (MH_Uninitialize() != MH_OK)
	{
		return FALSE;
	}

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////
// Detour functions
//////////////////////////////////////////////////////////////////////////

_Use_decl_annotations_
BOOL WINAPI DetourShowWindow(HWND hWnd, int nCmdShow)
{
	WCHAR szClassName[128] = { 0 };

	if (GetClassName(hWnd, szClassName, 127))
	{
		if (wcscmp(szClassName, SKYPE_UPDATE_CLASS) == 0)
		{
			DestroyWindow(hWnd);
		}
	}

	return fnShowWindow(hWnd, nCmdShow);
}
