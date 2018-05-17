// Login.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "Login.h"
#include "testDlg.h"
#include "AdoMySQLHelper.h"
#include "REGISTER.h"

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
	ON_BN_CLICKED(IDC_REGISTERED_BUTTON, OnRegisteredButton)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
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
	if(username.IsEmpty()) MessageBox("请输入用户名");
	else if(password.IsEmpty()) MessageBox("请输入密码");
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
				MessageBox("登录成功");
				CTestDlg* parent=(CTestDlg*)GetParent();
				parent->m_MainMenu.ShowWindow(SW_SHOWNORMAL);
				parent->username_tmp=username;
				CDialog::OnCancel();
			}
			else{
				MessageBox("登录失败");
				m_password_edit.SetWindowText("");
			}
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

void CLogin::OnRegisteredButton() 
{
	// TODO: Add your control notification handler code here
	CREGISTER registerd;
	registerd.DoModal();
}

HBRUSH CLogin::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	pDC->SetBkMode(TRANSPARENT);
	hbr = (HBRUSH)::GetStockObject(NULL_BRUSH);
	return hbr;
}

void CLogin::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
	CRect   rect;     
    GetClientRect(&rect);                                 //获取对话框长宽         
    CDC   dcBmp;                                           //定义并创建一个内存设备环境  
    dcBmp.CreateCompatibleDC(&dc);                         //创建兼容性DC  
    CBitmap   bmpBackground;     
    bmpBackground.LoadBitmap(IDB_BITMAP3);                 //载入资源中的IDB_BITMAP1图片  
    BITMAP   m_bitmap;                                     //图片变量                  
    bmpBackground.GetBitmap(&m_bitmap);                    //将图片载入位图中  
    CBitmap   *pbmpOld=dcBmp.SelectObject(&bmpBackground); //将位图选入临时内存设备环境    
    //调用函数显示图片 StretchBlt显示形状可变  
	//dc.SetStretchBltMode(COLORONCOLOR);
    dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBmp,0,0,  
        m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY); 
}
