#if !defined(AFX_REGISTER_H__0418D0D7_9F89_436A_A108_1CF78AE6758F__INCLUDED_)
#define AFX_REGISTER_H__0418D0D7_9F89_436A_A108_1CF78AE6758F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// REGISTER.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CREGISTER dialog

class CREGISTER : public CDialog
{
// Construction
public:
	CREGISTER(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CREGISTER)
	enum { IDD = IDD_REGISTER };
	CEdit	m_username_edit;
	CEdit	m_password_edit;
	CEdit	m_comfirm_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CREGISTER)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CREGISTER)
	afx_msg void OnRegister();
	afx_msg void OnBack();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTER_H__0418D0D7_9F89_436A_A108_1CF78AE6758F__INCLUDED_)
