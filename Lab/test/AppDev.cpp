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
	if(now_password.IsEmpty()) MessageBox("请输入密钥");
	else {
		if(now_psw_type!=0x0A&&now_psw_type!=0x0B){
			MessageBox("请选择密钥类型");
			return;
		}
		
		unsigned char psw[6];
		now_password.MakeUpper();
		Transform_CString_to_UnsignedChar(now_password,psw);
		
		int cur_page=m_wallet_sector_combo.GetCurSel();
		int cur_block=m_wallet_block_combo.GetCurSel();
		if(cur_page==-1) MessageBox("请选择扇区");
		else if(cur_block==-1) MessageBox("请选择块");
		else {
			long init_account;
			CString str;
			m_balance_edit.GetWindowText(str);
			if(str.IsEmpty()){
				MessageBox("请输入初始化金额");
				return;
			}
			init_account=_ttoi(str);
			Write_To_History(INIT_WALLET_MODE,(int)init_account);
			
			int return_state=write_account(cur_page,cur_block,now_psw_type,psw,init_account);
			if(return_state!=0){
				CString tmp;
				tmp.Format("%d",return_state);
				m_state_edit.SetWindowText("初始化失败,状态码为"+tmp);
				return;
			}
			
			//Write_To_History(1,(int)init_account);
			m_state_edit.SetWindowText("初始化成功");
		}
	}
}

void CAppDev::OnInquireBalanceButton() 
{
	// TODO: Add your control notification handler code here
	//MessageBox(now_password);
	if(now_password.IsEmpty()) MessageBox("请输入密钥");
	else {
		if(now_psw_type!=0x0A&&now_psw_type!=0x0B){
			MessageBox("请选择密钥类型");
			return;
		}
		
		unsigned char psw[6];
		now_password.MakeUpper();
		Transform_CString_to_UnsignedChar(now_password,psw);
		
		int cur_page=m_wallet_sector_combo.GetCurSel();
		int cur_block=m_wallet_block_combo.GetCurSel();
		if(cur_page==-1) MessageBox("请选择扇区");
		else if(cur_block==-1) MessageBox("请选择块");
		else {
			long account;
			int return_state=read_account(cur_page,cur_block,now_psw_type,psw,&account);
			if(return_state!=0){
				CString tmp;
				tmp.Format("%d",return_state);
				//MessageBox("查询失败,状态码为"+tmp);
				m_state_edit.SetWindowText("查询失败,状态码为"+tmp);
				return;
			}
			
			CString tmp;
			tmp.Format("%d",account);
			m_balance_edit.SetWindowText(tmp);
			m_state_edit.SetWindowText("查询成功");
		}
	}
}

void CAppDev::OnRechargeButton() 
{
	// TODO: Add your control notification handler code here
	if(now_password.IsEmpty()) MessageBox("请输入密钥");
	else {
		if(now_psw_type!=0x0A&&now_psw_type!=0x0B){
			MessageBox("请选择密钥类型");
			return;
		}
		
		unsigned char psw[6];
		now_password.MakeUpper();
		Transform_CString_to_UnsignedChar(now_password,psw);
		
		int cur_page=m_wallet_sector_combo.GetCurSel();
		int cur_block=m_wallet_block_combo.GetCurSel();
		if(cur_page==-1) MessageBox("请选择扇区");
		else if(cur_block==-1) MessageBox("请选择块");
		else {
			long addAccount;
			CString add_str;
			m_recharge_edit.GetWindowText(add_str);
			if(add_str.IsEmpty()){
				MessageBox("请输入充值金额");
				return;
			}
			addAccount=_ttoi(add_str);
			Write_To_History(RECHARGE_MODE,(int)addAccount);
			
			int return_state=add_account(cur_page,cur_block,now_psw_type,psw,addAccount);
			if(return_state!=0){
				CString tmp;
				tmp.Format("%d",return_state);
				m_state_edit.SetWindowText("充值失败,状态码为"+tmp);
				return;
			}
			//Write_To_History(RECHARGE_MODE,(int)addAccount);
			m_state_edit.SetWindowText("充值成功");
		}
	}
}

void CAppDev::OnPayButton() 
{
	// TODO: Add your control notification handler code here
	if(now_password.IsEmpty()) MessageBox("请输入密钥");
	else {
		if(now_psw_type!=0x0A&&now_psw_type!=0x0B){
			MessageBox("请选择密钥类型");
			return;
		}
		
		unsigned char psw[6];
		now_password.MakeUpper();
		Transform_CString_to_UnsignedChar(now_password,psw);
		
		int cur_page=m_wallet_sector_combo.GetCurSel();
		int cur_block=m_wallet_block_combo.GetCurSel();
		if(cur_page==-1) MessageBox("请选择扇区");
		else if(cur_block==-1) MessageBox("请选择块");
		else {
			long subAccount,account;
			CString sub_str;
			m_pay_edit.GetWindowText(sub_str);
			if(sub_str.IsEmpty()){
				MessageBox("请输入扣费金额");
				return;
			}
			subAccount=_ttoi(sub_str);
			Write_To_History(PAY_MODE,(int)subAccount);
			
			int return_state_read=read_account(cur_page,cur_block,now_psw_type,psw,&account);
			if(return_state_read!=0){
				CString tmp;
				tmp.Format("%d",return_state_read);
				m_state_edit.SetWindowText("读取余额失败,状态码为"+tmp);
				return;
			}
			if(subAccount>account) MessageBox("卡内余额不足,扣费失败");
			else {
				int return_state_sub=sub_account(cur_page,cur_block,now_psw_type,psw,subAccount);
				if(return_state_sub!=0){
					CString tmp;
					tmp.Format("%d",return_state_sub);
					m_state_edit.SetWindowText("扣费失败,状态码为"+tmp);
					return;
				}
				//Write_To_History(PAY_MODE,(int)subAccount);
				m_state_edit.SetWindowText("扣费成功");
			}
		}
	}
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
	for(i=0;j<leng/2;){
		res[j]=(unsigned char)(buffer[i++]<<4);
		res[j++] |= buffer[i++];
	}
}

void CAppDev::Write_To_History(int mode,int number){
	CFile file_mode,file_num;
	file_mode.Open(FILE_MODE_NAME,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
	file_num.Open(FILE_NUMBER_NAME,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
	CString tmp;
	tmp.Format("%d\r\n",mode);
	file_mode.SeekToEnd();
	file_mode.Write(tmp,strlen(tmp));
	tmp.Empty();
	tmp.Format("%d\r\n",number);
	file_num.SeekToEnd();
	file_num.Write(tmp,strlen(tmp));
}

void CAppDev::Read_History(){
	
}
