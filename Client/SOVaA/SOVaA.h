#pragma once
#include "resource.h"	
#include "Authentification.h"

class CMessangerClientApp : public CWinApp
{
public:
	CMessangerClientApp();

public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern CMessangerClientApp theApp;
