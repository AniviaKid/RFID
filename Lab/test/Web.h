//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES
#if !defined(AFX_WEB_H__AF9BE69F_1B33_4423_A3A2_3511F375535F__INCLUDED_)
#define AFX_WEB_H__AF9BE69F_1B33_4423_A3A2_3511F375535F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Web.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWeb dialog

class CWeb : public CDialog
{
// Construction
public:
	CWeb(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWeb)
	enum { IDD = IDD_WEB };
	CEdit	m_time_edit;
	CWebBrowser2	m_web_browser;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWeb)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWeb)
	afx_msg void OnOk();
	afx_msg void OnNewWindow2Explorer(LPDISPATCH FAR* ppDisp, BOOL FAR* Cancel);
	afx_msg void OnStatusTextChangeExplorer(LPCTSTR Text);
	afx_msg void OnTimer(UINT nIDEvent);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
public:
	CString m_strURL;
	UINT_PTR m_ActiveTimer;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEB_H__AF9BE69F_1B33_4423_A3A2_3511F375535F__INCLUDED_)
