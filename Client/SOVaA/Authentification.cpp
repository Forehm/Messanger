#include "pch.h"
#include "Authentification.h"
#include <string>

IMPLEMENT_DYNAMIC(AuthentificationDlg, CDialogEx)

BEGIN_MESSAGE_MAP(AuthentificationDlg, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_MAIN_LOG_IN_BUTTON, OnButtonLogIn)
	ON_BN_CLICKED(IDC_MAIN_REGISTRATION_BUTTON, OnButtonSignUp)
	ON_BN_CLICKED(IDC_AUTH_BACK_BUTTON, OnBackButton)
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

	GetDlgItem(IDC_LOGIN_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PASSWORD_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_LOG_IN_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_NICKNAME_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SIGN_UP_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AUTH_BACK_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PASSWORD_REPEAT_EDIT)->ShowWindow(SW_HIDE);

	return TRUE;
}

void AuthentificationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

void AuthentificationDlg::OnButtonSignUp()
{
	GetDlgItem(IDC_MAIN_LOG_IN_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MAIN_REGISTRATION_BUTTON)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_AUTH_BACK_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_LOGIN_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PASSWORD_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PASSWORD_REPEAT_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_SIGN_UP_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_NICKNAME_EDIT)->ShowWindow(SW_SHOW);
}

void AuthentificationDlg::OnButtonLogIn()
{
	GetDlgItem(IDC_MAIN_LOG_IN_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MAIN_REGISTRATION_BUTTON)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_AUTH_BACK_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_LOGIN_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_PASSWORD_EDIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_LOG_IN_BUTTON)->ShowWindow(SW_SHOW);
}

void AuthentificationDlg::OnBackButton()
{
	GetDlgItem(IDC_LOGIN_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PASSWORD_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_LOG_IN_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_NICKNAME_EDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_SIGN_UP_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AUTH_BACK_BUTTON)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PASSWORD_REPEAT_EDIT)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_MAIN_LOG_IN_BUTTON)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MAIN_REGISTRATION_BUTTON)->ShowWindow(SW_SHOW);
}

void AuthentificationDlg::OnPaint()
{
	CDialogEx::OnPaint();
}

BOOL AuthentificationDlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(61, 61, 61));
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);
	return bRes;
}


