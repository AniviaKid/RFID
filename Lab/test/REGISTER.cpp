// REGISTER.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "REGISTER.h"
#include "testDlg.h"
#include "AdoMySQLHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CREGISTER dialog


CREGISTER::CREGISTER(CWnd* pParent /*=NULL*/)
	: CDialog(CREGISTER::IDD, pParent)
{
	//{{AFX_DATA_INIT(CREGISTER)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CREGISTER::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CREGISTER)
	DDX_Control(pDX, IDC_USERNAME_EDIT, m_username_edit);
	DDX_Control(pDX, IDC_PASSWORD_EDIT, m_password_edit);
	DDX_Control(pDX, IDC_CONFIRM_EDIT, m_comfirm_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CREGISTER, CDialog)
	//{{AFX_MSG_MAP(CREGISTER)
	ON_BN_CLICKED(IDC_REGISTER, OnRegister)
	ON_BN_CLICKED(IDC_BACK, OnBack)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CREGISTER message handlers

void CREGISTER::OnRegister() 
{
	// TODO: Add your control notification handler code here
	CString username,password,confirm;
	m_username_edit.GetWindowText(username);
	m_password_edit.GetWindowText(password);
	m_comfirm_edit.GetWindowText(confirm);
	if(username.IsEmpty()) MessageBox("请输入用户名");
	else if(password.IsEmpty()) MessageBox("请输入密码");
	else if(confirm.IsEmpty()) MessageBox("请再次输入密码以确认");
	else {
		if(password!=confirm){
			MessageBox("两次输入密码不匹配");
			return;
		}
		CAdoMySQLHelper sql;
		sql.ConnectDB();
		BOOL res=sql.ExecuteQuery("insert into user(username,password) values('"+username+"','"+password+"');");
		if(res==TRUE){
			MessageBox("注册成功");
			CDialog::OnCancel();
		}
		else MessageBox(mysql_error(sql.Get_m_pSQL()));
	}
}

void CREGISTER::OnBack() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

HBRUSH CREGISTER::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	pDC->SetBkMode(TRANSPARENT);
	hbr = (HBRUSH)::GetStockObject(NULL_BRUSH);
	return hbr;
}

void CREGISTER::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
	CRect   rect;     
    GetClientRect(&rect);                                 //获取对话框长宽         
    CDC   dcBmp;                                           //定义并创建一个内存设备环境  
    dcBmp.CreateCompatibleDC(&dc);                         //创建兼容性DC  
    CBitmap   bmpBackground;     
    bmpBackground.LoadBitmap(IDB_BITMAP4);                 //载入资源中的IDB_BITMAP1图片  
    BITMAP   m_bitmap;                                     //图片变量                  
    bmpBackground.GetBitmap(&m_bitmap);                    //将图片载入位图中  
    CBitmap   *pbmpOld=dcBmp.SelectObject(&bmpBackground); //将位图选入临时内存设备环境    
    //调用函数显示图片 StretchBlt显示形状可变  
	//dc.SetStretchBltMode(COLORONCOLOR);
    dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBmp,0,0,  
        m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY); 
}
