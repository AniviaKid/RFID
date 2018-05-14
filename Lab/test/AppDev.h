#if !defined(AFX_APPDEV_H__C5FE4948_5F83_4103_AC6A_1103439CA458__INCLUDED_)
#define AFX_APPDEV_H__C5FE4948_5F83_4103_AC6A_1103439CA458__INCLUDED_
#define FILE_NAME "history.txt"
#define INIT_WALLET_MODE 1
#define RECHARGE_MODE 2
#define PAY_MODE 3

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Debugger.h"
// AppDev.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAppDev dialog

class CAppDev : public CDialog
{
// Construction
public:
	CAppDev(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAppDev)
	enum { IDD = IDD_APPDEV };
	CEdit	m_history_edit;
	CEdit	m_state_edit;
	CEdit	m_recharge_edit;
	CEdit	m_pay_edit;
	CComboBox	m_wallet_sector_combo;
	CComboBox	m_wallet_block_combo;
	CEdit	m_balance_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAppDev)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAppDev)
	afx_msg void OnInitWalletButton();
	afx_msg void OnInquireBalanceButton();
	afx_msg void OnRechargeButton();
	afx_msg void OnPayButton();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnInquireAllHistory();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
private:
	afx_msg void Transform_CString_to_UnsignedChar(CString str,unsigned char* ch);
	afx_msg void Write_To_History(int mode,int number);
	afx_msg void Read_History();
	afx_msg void OnRemoveHistory();
	afx_msg void OnInquireHistory();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_APPDEV_H__C5FE4948_5F83_4103_AC6A_1103439CA458__INCLUDED_)
