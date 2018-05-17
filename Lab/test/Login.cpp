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
	if(username.IsEmpty()) MessageBox("�������û���");
	else if(password.IsEmpty()) MessageBox("����������");
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
				MessageBox("��¼�ɹ�");
				CTestDlg* parent=(CTestDlg*)GetParent();
				parent->m_MainMenu.ShowWindow(SW_SHOWNORMAL);
				parent->username_tmp=username;
				CDialog::OnCancel();
			}
			else{
				MessageBox("��¼ʧ��");
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
    GetClientRect(&rect);                                 //��ȡ�Ի��򳤿�         
    CDC   dcBmp;                                           //���岢����һ���ڴ��豸����  
    dcBmp.CreateCompatibleDC(&dc);                         //����������DC  
    CBitmap   bmpBackground;     
    bmpBackground.LoadBitmap(IDB_BITMAP3);                 //������Դ�е�IDB_BITMAP1ͼƬ  
    BITMAP   m_bitmap;                                     //ͼƬ����                  
    bmpBackground.GetBitmap(&m_bitmap);                    //��ͼƬ����λͼ��  
    CBitmap   *pbmpOld=dcBmp.SelectObject(&bmpBackground); //��λͼѡ����ʱ�ڴ��豸����    
    //���ú�����ʾͼƬ StretchBlt��ʾ��״�ɱ�  
	//dc.SetStretchBltMode(COLORONCOLOR);
    dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBmp,0,0,  
        m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY); 
}
