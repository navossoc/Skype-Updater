// Updater.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Updater.h"

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
