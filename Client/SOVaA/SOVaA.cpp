#include "pch.h"
#include "framework.h"
#include "SOVaA.h"
#include "SOVaADlg.h"
#include "Authentification.h"
#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <windows.h>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


BEGIN_MESSAGE_MAP(CMessangerClientApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

io_service io;

CMessangerClientApp::CMessangerClientApp()
{
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
}


CMessangerClientApp theApp;

void receiveMessages(tcp::socket& socket) {
	try {
		while (true) {
			char data[1024];
			size_t length = socket.read_some(buffer(data, 1024));

			if (length > 0) {
				Beep(500, 300);
			}
		}
	}
	catch (std::exception& e) {
		std::cerr << "Exception in thread: " << e.what() << std::endl;
	}
}


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

	AuthentificationDlg authentification_dlg(NULL);
	authentification_dlg.DoModal();


	tcp::socket socket(io);
	socket.connect(tcp::endpoint(address::from_string("192.168.50.126"), 9999));

	// Создание потока для приема сообщений
	std::thread receiverThread(receiveMessages, std::ref(socket));
	


	CMessangerClientDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();


	receiverThread.join();
	if (!pShellManager)
		delete pShellManager;


	ControlBarCleanUp();

	return FALSE;
}

