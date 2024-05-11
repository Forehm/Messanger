#pragma once
#include "Resource.h"
#include "Client.h"

class AuthentificationDlg : public CDialogEx
{
private:
	DECLARE_DYNAMIC(AuthentificationDlg)

	virtual void DoDataExchange(CDataExchange* pDX);

	enum { IDD = IDD_AUTHENTIFICATION_DIALOG };


public:
	AuthentificationDlg(CWnd* pParent, Client& client);

protected:

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnButtonSignUp();
	afx_msg void OnButtonLogIn();
	afx_msg void OnBackButton();
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	void OnNcPaint()
	{
		CDialog::OnNcPaint();

		CDC* pDC = GetWindowDC();

		// Определим цвет, который хотим использовать для шапки окна
		COLORREF headerColor = RGB(255, 0, 0); // Красный цвет в данном случае

		// Рисуем шапку окна
		CRect rect;
		GetWindowRect(rect);
		rect.bottom = GetSystemMetrics(SM_CYCAPTION);

		pDC->FillSolidRect(rect, headerColor);

		ReleaseDC(pDC);
	}
	DECLARE_MESSAGE_MAP()
private:
	Client&							m_client;
};