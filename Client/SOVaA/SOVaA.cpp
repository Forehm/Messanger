#include "pch.h"
#include "framework.h"
#include "SOVaA.h"
#include "SOVaADlg.h"
#include "Authentification.h"
#include <WinSock2.h>
#include <iostream>
#include <thread>
#include <windows.h>
#include "processing_msg.h"

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma warning(disable: 4996)

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


BEGIN_MESSAGE_MAP(CMessangerClientApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


CMessangerClientApp::CMessangerClientApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}


CMessangerClientApp theApp;





BOOL CMessangerClientApp::InitInstance()
{
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();
	AfxEnableControlContainer();

	CShellManager *pShellManager = new CShellManager;
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	//==============================================================================///

	Client client;


	
	/*WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("192.168.50.126");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
		return 1;
	
	client.AddConnection(&connection);

	std::thread receiverThread(ClientHandler, std::ref(client));*/

	AuthentificationDlg authentification_dlg(NULL, client);
	int hr = authentification_dlg.DoModal();
	if (hr == WA_CLICKACTIVE)
	{
		return FALSE;
	}


	CMessangerClientDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	//==============================================================================///

	if (!pShellManager)
		delete pShellManager;


	ControlBarCleanUp();

	return FALSE;
}

