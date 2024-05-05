#include "pch.h"
#include "Authentification.h"
#include <string>

IMPLEMENT_DYNAMIC(AuthentificationDlg, CDialogEx)

BEGIN_MESSAGE_MAP(AuthentificationDlg, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_LOG_IN_BUTTON, LogIn)
	ON_BN_CLICKED(IDC_REGISTRATION_BUTTON, SignUp)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

void AuthentificationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

AuthentificationDlg::AuthentificationDlg(CWnd* pParent, Client& client) : CDialogEx(IDD_AUTHENTIFICATION_DIALOG, pParent),
m_client(client)
{
	
}

BOOL AuthentificationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	HICON hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	SetIcon(hIcon, FALSE);


	return TRUE;
}

void AuthentificationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

void AuthentificationDlg::SignUp()
{
	Packet test_packet = P_Test;
	send(*m_client.GetConnection(), (char*)&test_packet, sizeof(Packet), NULL);
	std::string command = "register";
	int msg_size = command.size();
	Packet packettype = P_Message;
	send(*m_client.GetConnection(), (char*)&packettype, sizeof(Packet), NULL);
	send(*m_client.GetConnection(), (char*)&msg_size, sizeof(int), NULL);
	send(*m_client.GetConnection(), command.c_str(), msg_size, NULL);
}

void AuthentificationDlg::LogIn()
{
	Packet test_packet = P_Test;
	send(*m_client.GetConnection(), (char*)&test_packet, sizeof(Packet), NULL);
	std::string command = "login";
	int msg_size = command.size();
	Packet packettype = P_Message;
	send(*m_client.GetConnection(), (char*)&packettype, sizeof(Packet), NULL);
	send(*m_client.GetConnection(), (char*)&msg_size, sizeof(int), NULL);
	send(*m_client.GetConnection(), command.c_str(), msg_size, NULL);
}

void AuthentificationDlg::OnPaint()
{
	CDialogEx::OnPaint();
}

BOOL AuthentificationDlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(61, 61, 61));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}


