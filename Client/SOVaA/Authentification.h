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
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	void OnNcPaint()
	{
		CDialog::OnNcPaint();

		CDC* pDC = GetWindowDC();

		// ��������� ����, ������� ����� ������������ ��� ����� ����
		COLORREF headerColor = RGB(255, 0, 0); // ������� ���� � ������ ������

		// ������ ����� ����
		CRect rect;
		GetWindowRect(rect);
		rect.bottom = GetSystemMetrics(SM_CYCAPTION);

		pDC->FillSolidRect(rect, headerColor);

		ReleaseDC(pDC);
	}
	DECLARE_MESSAGE_MAP()
};