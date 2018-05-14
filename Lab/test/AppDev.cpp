// AppDev.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "AppDev.h"
#include "ZM124U.h"
#include "AdoMySQLHelper.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAppDev dialog
extern CString now_password;
extern unsigned char now_psw_type;
extern CString now_username;


BOOL isExcuted;


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
	DDX_Control(pDX, IDC_HISTORY_EDIT, m_history_edit);
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
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_REMOVE_HISTORY, OnRemoveHistory)
	ON_BN_CLICKED(IDC_INQUIRE_HISTORY, OnInquireHistory)
	ON_BN_CLICKED(IDC_INQUIRE_ALL_HISTORY, OnInquireAllHistory)
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
			//Write_To_History(INIT_WALLET_MODE,(int)init_account);
			
			int return_state=write_account(cur_page,cur_block,now_psw_type,psw,init_account);
			if(return_state!=0){
				CString tmp;
				tmp.Format("%d",return_state);
				isExcuted=FALSE;
				m_state_edit.SetWindowText("初始化失败,状态码为"+tmp);
				return;
			}
			
			Write_To_History(1,(int)init_account);
			isExcuted=TRUE;
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
				isExcuted=FALSE;
				m_state_edit.SetWindowText("查询失败,状态码为"+tmp);
				return;
			}
			
			CString tmp;
			tmp.Format("%d",account);
			m_balance_edit.SetWindowText(tmp);
			isExcuted=TRUE;
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
			//Write_To_History(RECHARGE_MODE,(int)addAccount);
			
			int return_state=add_account(cur_page,cur_block,now_psw_type,psw,addAccount);
			if(return_state!=0){
				CString tmp;
				tmp.Format("%d",return_state);
				isExcuted=FALSE;
				m_state_edit.SetWindowText("充值失败,状态码为"+tmp);
				return;
			}
			Write_To_History(RECHARGE_MODE,(int)addAccount);
			isExcuted=TRUE;
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
			//Write_To_History(PAY_MODE,(int)subAccount);
			
			int return_state_read=read_account(cur_page,cur_block,now_psw_type,psw,&account);
			if(return_state_read!=0){
				CString tmp;
				tmp.Format("%d",return_state_read);
				isExcuted=FALSE;
				m_state_edit.SetWindowText("读取余额失败,状态码为"+tmp);
				return;
			}
			if(subAccount>account) MessageBox("卡内余额不足,扣费失败");
			else {
				int return_state_sub=sub_account(cur_page,cur_block,now_psw_type,psw,subAccount);
				if(return_state_sub!=0){
					CString tmp;
					tmp.Format("%d",return_state_sub);
					isExcuted=FALSE;
					m_state_edit.SetWindowText("扣费失败,状态码为"+tmp);
					return;
				}
				Write_To_History(PAY_MODE,(int)subAccount);
				isExcuted=FALSE;
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
	//Write To Local
	CFile file;
	file.Open(FILE_NAME,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
	CString tmp,tmp2;
	if(mode==INIT_WALLET_MODE) tmp="Init Wallet Money:";
	else if(mode==RECHARGE_MODE) tmp="Recharge:";
	else if(mode==PAY_MODE) tmp="Pay:";
	tmp2.Format("%d\r\n",number);
	tmp+=tmp2;
	file.SeekToEnd();
	file.Write(tmp,strlen(tmp));
	
	//Write To Database
	CString operation_mode,operation_description,amount;
	operation_mode.Format("%d",mode);
	if(mode==INIT_WALLET_MODE) operation_description="Init Wallet Money";
	else if(mode==RECHARGE_MODE) operation_description="Recharge";
	else if(mode==PAY_MODE) operation_description="Pay";
	amount.Format("%d",number);
	
	CAdoMySQLHelper sql;
	sql.ConnectDB();
	BOOL res=sql.ExecuteQuery(
		"insert into record(username,operation_mode,operation_description,amount) values('"+now_username+"',"+operation_mode+",'"+operation_description+"',"+amount+");"
	);
	if(res==FALSE) MessageBox(mysql_error(sql.Get_m_pSQL()));
}

void CAppDev::Read_History(){
	CFileFind finder;
	if(!finder.FindFile(FILE_NAME)){
		MessageBox("无历史记录");
		return;
	}
	CString str,tmp;
	CStdioFile file;
	CFileException except;
	file.Open(FILE_NAME,CFile::modeRead,&except);
	while(file.ReadString(tmp)) str+=(tmp+"\r\n");
	file.Close();
	m_history_edit.SetWindowText(str);
}

void CAppDev::OnRemoveHistory() 
{
	// TODO: Add your control notification handler code here
	m_history_edit.SetWindowText("");
	CFileFind finder;
	if(!finder.FindFile(FILE_NAME)) return;
	CFile file;
	file.Remove(FILE_NAME);
}

void CAppDev::OnInquireHistory() 
{
	// TODO: Add your control notification handler code here
	Read_History();
}

HBRUSH CAppDev::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	switch(pWnd->GetDlgCtrlID()){
		case IDC_STATE_EDIT:
			if(isExcuted) pDC->SetTextColor(RGB(0,0,255));
			else pDC->SetTextColor(RGB(255,0,0));
			break;
		default:
			pDC->SetTextColor(RGB(0,0,0));
			break;
	}
	return hbr;
}

void CAppDev::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
	CRect   rect;     
    GetClientRect(&rect);                                 //获取对话框长宽         
    CDC   dcBmp;                                           //定义并创建一个内存设备环境  
    dcBmp.CreateCompatibleDC(&dc);                         //创建兼容性DC  
    CBitmap   bmpBackground;     
    bmpBackground.LoadBitmap(IDB_BITMAP_YASUO);                 //载入资源中的IDB_BITMAP1图片  
    BITMAP   m_bitmap;                                     //图片变量                  
    bmpBackground.GetBitmap(&m_bitmap);                    //将图片载入位图中  
    CBitmap   *pbmpOld=dcBmp.SelectObject(&bmpBackground); //将位图选入临时内存设备环境    
    //调用函数显示图片 StretchBlt显示形状可变  
	dc.SetStretchBltMode(COLORONCOLOR);
    dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcBmp,0,0,  
        m_bitmap.bmWidth,m_bitmap.bmHeight,SRCCOPY); 
}

void CAppDev::OnInquireAllHistory() 
{
	// TODO: Add your control notification handler code here
	CString hint="This user's history is:\r\n";
	CAdoMySQLHelper sql;
	sql.ConnectDB();
	BOOL res=sql.ExecuteQuery("select operation_description,amount from record where username='"+now_username+"';");
	if(res==TRUE) {
		MYSQL_ROW pSQLRow=NULL;
		while(pSQLRow=mysql_fetch_row(sql.Get_m_pSQLResultSet())){
			hint+=pSQLRow[0];
			hint+=":";
			hint+=pSQLRow[1];
			hint+="\r\n";
		}
		m_history_edit.SetWindowText(hint);
	}
	else MessageBox(mysql_error(sql.Get_m_pSQL()));
}
