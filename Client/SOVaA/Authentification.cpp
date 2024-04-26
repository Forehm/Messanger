#include "pch.h"
#include "Authentification.h"

IMPLEMENT_DYNAMIC(AuthentificationDlg, CDialogEx)

BEGIN_MESSAGE_MAP(AuthentificationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()

void AuthentificationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

AuthentificationDlg::AuthentificationDlg(CWnd* pParent) : CDialogEx(IDD_AUTHENTIFICATION_DIALOG, pParent)
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
	AfxMessageBox(L"Регистрация");
}

void AuthentificationDlg::LogIn()
{
	AfxMessageBox(L"Вход");
}

void AuthentificationDlg::OnPaint()
{
	CDialogEx::OnPaint();
}


