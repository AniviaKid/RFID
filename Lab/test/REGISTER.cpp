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
	if(username.IsEmpty()) MessageBox("�������û���");
	else if(password.IsEmpty()) MessageBox("����������");
	else if(confirm.IsEmpty()) MessageBox("���ٴ�����������ȷ��");
	else {
		if(password!=confirm){
			MessageBox("�����������벻ƥ��");
			return;
		}
		CAdoMySQLHelper sql;
		sql.ConnectDB();
		BOOL res=sql.ExecuteQuery("insert into user(username,password) values('"+username+"','"+password+"');");
		if(res==TRUE){
			MessageBox("ע��ɹ�");
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
    GetClientRect(&rect);                                 //��ȡ�Ի��򳤿�         
    CDC   dcBmp;                                           //���岢����һ���ڴ��豸����  
    dcBmp.CreateCompatibleDC(&dc);                         //����������DC  
    CBitmap   bmpBackground;     
    bmpBackground.LoadBitmap(IDB_BITMAP4);                 //������Դ�е�IDB_BITMAP1ͼƬ  
    BITMAP   m_bitmap;                                     //ͼƬ����                  
    bmpBackground.GetBitmap(&m_bitmap);                    //��ͼƬ����λͼ��  
    CBitmap   *pbmpOld=dcBmp.SelectObject(&bmpBackground); //��λͼѡ����ʱ�ڴ��豸����    
    //���ú�����ʾͼƬ StretchBlt��ʾ��״�ɱ�  
	//dc.SetStretchBltMode(COLORONCOLOR);
    dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBmp,0,0,  
        m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY); 
}
