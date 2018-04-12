#if !defined(AFX_DEBUGGER_H__0FDE988B_426C_4259_9396_D7476FCADC00__INCLUDED_)
#define AFX_DEBUGGER_H__0FDE988B_426C_4259_9396_D7476FCADC00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Debugger.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDebugger dialog

class CDebugger : public CDialog
{
// Construction
public:
	CDebugger(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDebugger)
	enum { IDD = IDD_DEBUGGER };
	CEdit	m_serial_number;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDebugger)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDebugger)
	virtual void OnOK();
	afx_msg void OnFindCard();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEBUGGER_H__0FDE988B_426C_4259_9396_D7476FCADC00__INCLUDED_)
