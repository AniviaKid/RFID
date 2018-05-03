// AppDev.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "AppDev.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAppDev dialog


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
	
}

void CAppDev::OnRechargeButton() 
{
	// TODO: Add your control notification handler code here
	
}

void CAppDev::OnPayButton() 
{
	// TODO: Add your control notification handler code here
	
}
