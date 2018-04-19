// Debugger.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "Debugger.h"
#include "ZM124U.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDebugger dialog


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
	DDX_Control(pDX, IDC_EDIT_NUMBER, m_serial_number);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDebugger, CDialog)
	//{{AFX_MSG_MAP(CDebugger)
	ON_BN_CLICKED(IDC_FIND_CARD, OnFindCard)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDebugger message handlers

void CDebugger::OnOK() 
{
	// TODO: Add extra validation here
	
	
	CDialog::OnOK();
}

void CDebugger::OnFindCard() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	IDD_PowerOn();
	unsigned char uid[50]=new unsigned char[50];
	int* uid_len=new int;
	int state=find_14443(uid,uid_len);
	CString uid_res;
	uid_res.Format("%X",uid);
	/*for(int i=0;i<*uid_len;i++){
		tem.Format("%02X",uid[i]);
		uid_res += tem;
	}*/
	CString sta;
	sta.Format("%d",state);
	MessageBox(sta);
	if(state==0) m_serial_number.SetWindowText(uid_res);
	
	/*int tmp=IDD_PowerOn();
	unsigned char uid[50];
	int* uid_len=new int;
	int state=find_14443(uid,uid_len);
	CString uid_res = "", tem;
	
	for(int i=0;i<*uid_len;i++){
		tem.Format("%02X",uid[i]);
		uid_res += tem;
	}
	CString sta;
	sta.Format("%d",state);
	MessageBox(sta);
	m_serial_number.SetWindowText(uid_res);
	/*delete uid;
	delete uid_len;*/
	//IDD_PowerOff();
}
