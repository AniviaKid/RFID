// AppDev.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "AppDev.h"
#include "ZM124U.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAppDev dialog
extern CString now_password;
extern unsigned char now_psw_type;


CAppDev::CAppDev(CWnd* pParent /*=NULL*/)
	: CDialog(CAppDev::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAppDev)
	//}}AFX_DATA_INIT
}


void CAppDev::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAppDev)
	DDX_Control(pDX, IDC_STATE_EDIT, m_state_edit);
	DDX_Control(pDX, IDC_RECHARGE_EDIT, m_recharge_edit);
	DDX_Control(pDX, IDC_PAY_EDIT, m_pay_edit);
	DDX_Control(pDX, IDC_WALLET_SECTOR_COMBO, m_wallet_sector_combo);
	DDX_Control(pDX, IDC_WALLET_BLOCK_COMBO, m_wallet_block_combo);
	DDX_Control(pDX, IDC_BALANCE_EDIT, m_balance_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAppDev, CDialog)
	//{{AFX_MSG_MAP(CAppDev)
	ON_BN_CLICKED(IDC_INIT_WALLET_BUTTON, OnInitWalletButton)
	ON_BN_CLICKED(IDC_INQUIRE_BALANCE_BUTTON, OnInquireBalanceButton)
	ON_BN_CLICKED(IDC_RECHARGE_BUTTON, OnRechargeButton)
	ON_BN_CLICKED(IDC_PAY_BUTTON, OnPayButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAppDev message handlers

void CAppDev::OnInitWalletButton() 
{
	// TODO: Add your control notification handler code here
	
}

void CAppDev::OnInquireBalanceButton() 
{
	// TODO: Add your control notification handler code here
	//MessageBox(now_password);
	if(now_password.IsEmpty()) MessageBox("«Î ‰»Î√‹‘ø");
	else {
		if(now_psw_type!=0x0A&&now_psw_type!=0x0B){
			MessageBox("«Î—°‘Ò√‹‘ø¿‡–Õ");
			return;
		}
		
		unsigned char psw[6];
		now_password.MakeUpper();
		Transform_CString_to_UnsignedChar(now_password,psw);
		
		int cur_page=m_wallet_sector_combo.GetCurSel();
		int cur_block=m_wallet_block_combo.GetCurSel();
		if(cur_page==-1) MessageBox("«Î—°‘Ò…»«¯");
		else if(cur_block==-1) MessageBox("«Î—°‘ÒøÈ");
		else {
			long account;
			int return_state=read_account(cur_page,cur_block,now_psw_type,psw,&account);
			if(return_state!=0){
				CString tmp;
				tmp.Format("%d",return_state);
				//MessageBox("≤È—Ø ß∞‹,◊¥Ã¨¬ÎŒ™"+tmp);
				m_state_edit.SetWindowText("≤È—Ø ß∞‹,◊¥Ã¨¬ÎŒ™"+tmp);
				return;
			}
			
			CString tmp;
			tmp.Format("%d",account);
			m_balance_edit.SetWindowText(tmp);
			m_state_edit.SetWindowText("≤È—Ø≥…π¶");
		}
	}
}

void CAppDev::OnRechargeButton() 
{
	// TODO: Add your control notification handler code here
	
}

void CAppDev::OnPayButton() 
{
	// TODO: Add your control notification handler code here
	
}

void CAppDev::Transform_CString_to_UnsignedChar(CString str,unsigned char* res){
	unsigned char buffer[50];
	for(int i=0;i<str.GetLength();i++){
		char ch=str[i];
		if(ch>0x40) buffer[i]=(unsigned char)ch-0x37;
		else buffer[i]=(unsigned char)atoi(&ch);
	}
	int j=0;
	int leng=str.GetLength();
	if(leng%2==1) {
		res[j++]='0';
		leng++;
	}
	for(i=0;j<str.GetLength()/2;){
		res[j]=(unsigned char)(buffer[i++]<<4);
		res[j++] |= buffer[i++];
	}
}