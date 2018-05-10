// Login.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "Login.h"
#include "testDlg.h"
#include "AdoMySQLHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogin dialog


CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogin)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogin)
	DDX_Control(pDX, IDC_USERNAME_EDIT, m_username_edit);
	DDX_Control(pDX, IDC_PASSWORD_EDIT, m_password_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	//{{AFX_MSG_MAP(CLogin)
	ON_BN_CLICKED(IDC_LOGIN_BUTTON, OnLoginButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogin message handlers

void CLogin::OnLoginButton() 
{
	// TODO: Add your control notification handler code here
	CString username,password;
	m_username_edit.GetWindowText(username);
	m_password_edit.GetWindowText(password);
	if(username.IsEmpty()) MessageBox("ÇëÊäÈëÓÃ»§Ãû");
	else if(password.IsEmpty()) MessageBox("ÇëÊäÈëÃÜÂë");
	else {
		CAdoMySQLHelper sql;
		sql.ConnectDB();
		BOOL res=sql.ExecuteQuery("select password from user where username='"+username+"';");
		if(res==TRUE){
			MYSQL_ROW pSQLRow=NULL;
			CString select_res;
			while(pSQLRow=mysql_fetch_row(sql.Get_m_pSQLResultSet())){
				select_res+=pSQLRow[0];
			}
			if(select_res==password){
				MessageBox("µÇÂ¼³É¹¦");
				CTestDlg* parent=(CTestDlg*)GetParent();
				parent->m_MainMenu.ShowWindow(SW_SHOWNORMAL);
				CDialog::OnCancel();
			}
			else MessageBox("µÇÂ¼Ê§°Ü");
		}
	}
	
	/*
	CAdoMySQLHelper sql;
	sql.ConnectDB();
	CString table="test";
	BOOL res=sql.ExecuteQuery("select * from "+table+";");
	if(res==TRUE) {
		MYSQL_ROW pSQLRow=NULL;
		CString select_res;
		while(pSQLRow=mysql_fetch_row(sql.Get_m_pSQLResultSet())){
			for(int i=0;i<2;i++){
				select_res+=pSQLRow[i];
				select_res+=" ";
			}
			select_res+="\n";
		}
		AfxMessageBox(select_res);
	}
	*/
}
