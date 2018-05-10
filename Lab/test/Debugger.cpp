// Debugger.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "Debugger.h"
#include "ZM124U.h"
#include "AdoMySQLHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDebugger dialog
CString now_password;
unsigned char now_psw_type;

BOOL isDeviceOpen;

CDebugger::CDebugger(CWnd* pParent /*=NULL*/)
	: CDialog(CDebugger::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDebugger)
	//}}AFX_DATA_INIT
}


void CDebugger::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDebugger)
	DDX_Control(pDX, IDC_PASSWORD_EDIT, m_password_edit);
	DDX_Control(pDX, IDC_CARD_WR_BLOCK_COMBO, m_card_wr_block_combo);
	DDX_Control(pDX, IDC_CARD_WR_SECTOR_COMBO, m_card_wr_sector_combo);
	DDX_Control(pDX, IDC_CARD_WR_BLOCK3_EDIT3, m_block3_edit3);
	DDX_Control(pDX, IDC_CARD_WR_BLOCK3_EDIT2, m_block3_edit2);
	DDX_Control(pDX, IDC_CARD_WR_BLOCK3_EDIT1, m_block3_edit1);
	DDX_Control(pDX, IDC_CARD_WR_BLOCK2_EDIT, m_block2_edit);
	DDX_Control(pDX, IDC_CARD_WR_BLOCK1_EDIT, m_block1_edit);
	DDX_Control(pDX, IDC_CARD_WR_BLOCK0_EDIT, m_block0_edit);
	DDX_Control(pDX, IDC_EDIT_STATE, m_ins_state);
	DDX_Control(pDX, IDC_EDIT_NUMBER, m_serial_number);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDebugger, CDialog)
	//{{AFX_MSG_MAP(CDebugger)
	ON_BN_CLICKED(IDC_FIND_CARD, OnFindCard)
	ON_BN_CLICKED(ID_START_INS, OnStartIns)
	ON_BN_CLICKED(IDC_READ_BLOCK, OnReadBlock)
	ON_BN_CLICKED(IDC_READ_SECTOR, OnReadSector)
	ON_BN_CLICKED(IDC_WRITE_BLOCK, OnWriteBlock)
	ON_BN_CLICKED(IDC_DEFAULT_PASSWORD, OnDefaultPassword)
	ON_EN_CHANGE(IDC_PASSWORD_EDIT, OnChangePasswordEdit)
	ON_BN_CLICKED(IDC_RADIO_A_PASSWORD, OnRadioAPassword)
	ON_BN_CLICKED(IDC_RADIO_B_PASSWORD, OnRadioBPassword)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDebugger message handlers


void CDebugger::OnFindCard() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	unsigned char uid[50];
	int* uid_len=new int;
	int state=find_14443(uid,uid_len);
	CString uid_res,temp;
	//uid_res.Format("%X",uid);
	for(int i=0;i<*uid_len;i++){
		temp.Format("%02X",uid[i]);
		uid_res += temp;
	}
	CString sta;
	sta.Format("%d",state);
	//MessageBox(sta);
	if(state==0) m_serial_number.SetWindowText(uid_res);
}

void CDebugger::OnStartIns() 
{
	// TODO: Add your control notification handler code here
	int state=IDD_PowerOn();
	if(state==0){
		isDeviceOpen=TRUE;
		m_ins_state.SetWindowText("ø™≥°≥…π¶");
	}
	else{
		isDeviceOpen=FALSE;
		m_ins_state.SetWindowText("ø™≥° ß∞‹");
	}
}

void CDebugger::OnReadBlock() 
{
	// TODO: Add your control notification handler code here
	//MessageBox("∂¡øÈ");
	CString password;//√‹‘ø
	unsigned char pw_type;//√‹‘ø¿‡–Õ
	m_password_edit.GetWindowText(password);
	if(password.IsEmpty()) MessageBox("«Î ‰»Î√‹‘ø");
	else {
		//CString√‹‘ø◊™Œ™unsigned char
		unsigned char psw[6];
		password.MakeUpper();
		Transform_CString_to_UnsignedChar(password,psw);
		
		//≈–∂œ√‹‘ø¿‡–Õ
		if(((CButton *)GetDlgItem(IDC_RADIO_A_PASSWORD))->GetCheck()==1) pw_type=0x0A;
		else if(((CButton *)GetDlgItem(IDC_RADIO_B_PASSWORD))->GetCheck()==1) pw_type=0x0B;
		else {
			MessageBox("«Î—°‘Ò√‹‘ø¿‡–Õ");
			return;
		}
		
		//ªÒµ√—°÷–…»«¯∫≈°¢øÈ∫≈
		int cur_page=m_card_wr_sector_combo.GetCurSel();
		int cur_block=m_card_wr_block_combo.GetCurSel();
		if(cur_page==-1) MessageBox("«Î—°‘Ò…»«¯");
		else if(cur_block==-1) MessageBox("«Î—°‘ÒøÈ");
		else {
			//∂¡ƒ⁄»›
			unsigned char des_data[50];int des_len;
			int return_state=read_block(cur_page,cur_block,pw_type,psw,des_data,&des_len);
			if(return_state!=0){
				CString tmp;
				tmp.Format("%d",return_state);
				MessageBox("∂¡øÈ ß∞‹,◊¥Ã¨¬ÎŒ™"+tmp);
				return;
			}

			//–¥ƒ⁄»›
			CString tmp;
			if(cur_block==0||cur_block==1||cur_block==2){ //øÈ0 øÈ1 øÈ2
				for(int k=0;k<des_len;k++){
					CString s1;
					s1.Format("%02X",des_data[k]);
					tmp+=s1;
				}
				if(cur_block==0) m_block0_edit.SetWindowText(tmp);
				else if(cur_block==1) m_block1_edit.SetWindowText(tmp);
				else if(cur_block==2) m_block2_edit.SetWindowText(tmp);
			}
			else if(cur_block==3){ //øÈ3
				for(int k=0;k<des_len;k++){
					CString s1;
					s1.Format("%02X",des_data[k]);
					tmp+=s1;
					if(k==5){
						m_block3_edit1.SetWindowText(tmp);
						tmp.Empty();
					}
					else if(k==9){
						m_block3_edit2.SetWindowText(tmp);
						tmp.Empty();
					}
				}
				m_block3_edit3.SetWindowText(tmp);
			}
		}
	}
}

void CDebugger::OnReadSector() 
{
	// TODO: Add your control notification handler code here
	//MessageBox("∂¡…»«¯");
	CString password;//√‹‘ø
	unsigned char pw_type;//√‹‘ø¿‡–Õ
	m_password_edit.GetWindowText(password);
	if(password.IsEmpty()) MessageBox("«Î ‰»Î√‹‘ø");
	else {
		//CString√‹‘ø◊™Œ™unsigned char
		unsigned char psw[6];
		password.MakeUpper();
		Transform_CString_to_UnsignedChar(password,psw);
		
		//≈–∂œ√‹‘ø¿‡–Õ
		if(((CButton *)GetDlgItem(IDC_RADIO_A_PASSWORD))->GetCheck()==1) pw_type=0x0A;
		else if(((CButton *)GetDlgItem(IDC_RADIO_B_PASSWORD))->GetCheck()==1) pw_type=0x0B;
		else {
			MessageBox("«Î—°‘Ò√‹‘ø¿‡–Õ");
			return;
		}
		
		//ªÒµ√—°÷–…»«¯∫≈
		int cur_page=m_card_wr_sector_combo.GetCurSel();
		if(cur_page==-1) MessageBox("«Î—°‘Ò…»«¯");
		else {
			Clear_WR_View();
			for(int i=0;i<=3;i++){ //±È¿˙∂¡øÈ
				unsigned char des_data[50];int des_len;
				int return_state=read_block(cur_page,i,pw_type,psw,des_data,&des_len);
				if(return_state!=0){
					CString tmp;
					tmp.Format("%d",return_state);
					MessageBox("∂¡øÈ ß∞‹,◊¥Ã¨¬ÎŒ™"+tmp);
					return;
				}

				//–¥ƒ⁄»›
				CString tmp;
				if(i==0||i==1||i==2){ //øÈ0 øÈ1 øÈ2
					for(int k=0;k<des_len;k++){
						CString s1;
						s1.Format("%02X",des_data[k]);
						tmp+=s1;
					}
					if(i==0) m_block0_edit.SetWindowText(tmp);
					else if(i==1) m_block1_edit.SetWindowText(tmp);
					else if(i==2) m_block2_edit.SetWindowText(tmp);
				}
				else if(i==3){ //øÈ3
					for(int k=0;k<des_len;k++){
						CString s1;
						s1.Format("%02X",des_data[k]);
						tmp+=s1;
						if(k==5){
							m_block3_edit1.SetWindowText(tmp);
							tmp.Empty();
						}
						else if(k==9){
							m_block3_edit2.SetWindowText(tmp);
							tmp.Empty();
						}
					}
					m_block3_edit3.SetWindowText(tmp);
				}
			}
		}
	}
}

void CDebugger::OnWriteBlock() 
{
	// TODO: Add your control notification handler code here
	//MessageBox("–¥øÈ");
	CString password;//√‹‘ø
	unsigned char pw_type;//√‹‘ø¿‡–Õ
	m_password_edit.GetWindowText(password);
	if(password.IsEmpty()) MessageBox("«Î ‰»Î√‹‘ø");
	else {
		unsigned char psw[6];
		password.MakeUpper();
		Transform_CString_to_UnsignedChar(password,psw);
		
		if(((CButton *)GetDlgItem(IDC_RADIO_A_PASSWORD))->GetCheck()==1) pw_type=0x0A;
		else if(((CButton *)GetDlgItem(IDC_RADIO_B_PASSWORD))->GetCheck()==1) pw_type=0x0B;
		else {
			MessageBox("«Î—°‘Ò√‹‘ø¿‡–Õ");
			return;
		}
		
		int cur_page=m_card_wr_sector_combo.GetCurSel();
		int cur_block=m_card_wr_block_combo.GetCurSel();
		if(cur_page==-1) MessageBox("«Î—°‘Ò…»«¯");
		else if(cur_block==-1) MessageBox("«Î—°‘ÒøÈ");
		else{
			if(cur_block==0||cur_block==1||cur_block==2){
				CString content;
				switch(cur_block){
					case 0:
						m_block0_edit.GetWindowText(content);
						break;
					case 1:
						m_block1_edit.GetWindowText(content);
						break;
					case 2:
						m_block2_edit.GetWindowText(content);
						break;
				}
				if(content.IsEmpty()){
					MessageBox("«Î ‰»Î–¥»Î÷µ");
					return;
				}
				unsigned char src_data[16];
				Transform_CString_to_UnsignedChar(content,src_data);
				int return_state=write_block(cur_block,cur_page,pw_type,psw,src_data,content.GetLength());
				if(return_state!=0){
					CString tmp;
					tmp.Format("%d",return_state);
					MessageBox("–¥øÈ ß∞‹,◊¥Ã¨¬ÎŒ™"+tmp);
					return;
				}
				MessageBox("–¥øÈ≥…π¶");
			}
			else if(cur_block==3){
				
			}
		}
	}
}

void CDebugger::OnDefaultPassword() 
{
	// TODO: Add your control notification handler code here
	((CButton *)GetDlgItem(IDC_RADIO_B_PASSWORD))->SetCheck(TRUE);
	m_password_edit.SetWindowText("FFFFFFFFFFFF");
	now_password="FFFFFFFFFFFF";
	now_psw_type=0x0B;
	//((CButton *)GetDlgItem(IDC_RADIO_A_PASSWORD))->GetCheck()
}

void CDebugger::Clear_WR_View()
{
	m_block0_edit.SetWindowText("");
	m_block1_edit.SetWindowText("");
	m_block2_edit.SetWindowText("");
	m_block3_edit1.SetWindowText("");
	m_block3_edit2.SetWindowText("");
	m_block3_edit3.SetWindowText("");
}

void CDebugger::Transform_CString_to_UnsignedChar(CString str,unsigned char* res){
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

void CDebugger::OnChangePasswordEdit()  
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	m_password_edit.GetWindowText(now_password);
}

void CDebugger::OnRadioAPassword() 
{
	// TODO: Add your control notification handler code here
	now_psw_type=0x0A;
}

void CDebugger::OnRadioBPassword() 
{
	// TODO: Add your control notification handler code here
	now_psw_type=0x0B;
}


HBRUSH CDebugger::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	switch(pWnd->GetDlgCtrlID()){
		case IDC_EDIT_STATE:
			if(isDeviceOpen) pDC->SetTextColor(RGB(0,0,255));
			else pDC->SetTextColor(RGB(255,0,0));
			break;
		case IDC_PASSWORD_EDIT:
			pDC->SetTextColor(RGB(0,0,255));
			break;
		default:
			pDC->SetTextColor(RGB(51,51,51));
			break;
	}
	return hbr;
}
