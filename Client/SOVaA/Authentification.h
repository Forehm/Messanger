#pragma once
#include "Resource.h"

class AuthentificationDlg : public CDialogEx
{
private:
	DECLARE_DYNAMIC(AuthentificationDlg)

	virtual void DoDataExchange(CDataExchange* pDX);

	enum { IDD = IDD_AUTHENTIFICATION_DIALOG };


public:
	AuthentificationDlg(CWnd* pParent);



protected:


	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void SignUp();
	afx_msg void LogIn();
	afx_msg void OnPaint();


	DECLARE_MESSAGE_MAP()
};