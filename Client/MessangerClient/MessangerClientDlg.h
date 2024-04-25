#pragma once


class CMessangerClientDlg : public CDialogEx
{
private:
	DECLARE_DYNAMIC(CMessangerClientDlg)

	virtual void DoDataExchange(CDataExchange* pDX);

	enum { IDD = IDD_MESSANGERCLIENT_DIALOG };


public:
	CMessangerClientDlg(CWnd* pParent = nullptr);	


protected:
	


	

protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()
};
