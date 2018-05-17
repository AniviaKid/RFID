// testDlg.h : header file
//

#if !defined(AFX_TESTDLG_H__3B401866_3FA5_4E67_ADB0_5D42B29EE166__INCLUDED_)
#define AFX_TESTDLG_H__3B401866_3FA5_4E67_ADB0_5D42B29EE166__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AppDev.h"
#include "Debugger.h"
#include "Web.h"
#include "ZM124U.h"

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog


class CTestDlg : public CDialog
{
// Construction
public:
	CTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestDlg)
	enum { IDD = IDD_TEST_DIALOG };
	CTabCtrl	m_MainMenu;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CDebugger m_MainDebugger;
	CAppDev m_MainAppDev;
	CWeb m_MainWeb;
	
public:
	CString username_tmp;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__3B401866_3FA5_4E67_ADB0_5D42B29EE166__INCLUDED_)
