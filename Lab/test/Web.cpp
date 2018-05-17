// Web.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "Web.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWeb dialog


CWeb::CWeb(CWnd* pParent /*=NULL*/)
	: CDialog(CWeb::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWeb)
	//}}AFX_DATA_INIT
}


void CWeb::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWeb)
	DDX_Control(pDX, IDC_TIME_EDIT, m_time_edit);
	DDX_Control(pDX, IDC_EXPLORER, m_web_browser);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWeb, CDialog)
	//{{AFX_MSG_MAP(CWeb)
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeb message handlers

int now_hour=0,now_minute=0,now_second=0;
void CWeb::OnOk() 
{
	// TODO: Add your control notification handler code here
	/*CString szHeader = "Content-Type: application/x-www-form-urlencoded\r\n";
	VARIANT vaHeader = COleVariant(szHeader, VT_BSTR);*/
	//VARIANT vaurl = COleVariant("http://localhost:8080/treesoft/login", VT_BSTR);
	m_web_browser.Navigate("www.baidu.com",NULL,NULL,NULL,NULL);
	m_time_edit.SetWindowText("00:00:00");
	now_hour=0;now_minute=0;now_second=0;
	m_ActiveTimer = SetTimer(0, 1000, NULL);
}

BEGIN_EVENTSINK_MAP(CWeb, CDialog)
    //{{AFX_EVENTSINK_MAP(CWeb)
	ON_EVENT(CWeb, IDC_EXPLORER, 251 /* NewWindow2 */, OnNewWindow2Explorer, VTS_PDISPATCH VTS_PBOOL)
	ON_EVENT(CWeb, IDC_EXPLORER, 102 /* StatusTextChange */, OnStatusTextChangeExplorer, VTS_BSTR)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CWeb::OnNewWindow2Explorer(LPDISPATCH FAR* ppDisp, BOOL FAR* Cancel) 
{
	// TODO: Add your control notification handler code here
	//VARIANT vars;
	m_web_browser.Navigate(m_strURL,NULL,NULL,NULL,NULL);	
	*Cancel=TRUE; 
}


void CWeb::OnStatusTextChangeExplorer(LPCTSTR Text) 
{
	// TODO: Add your control notification handler code here
	/*DWORD dwServiceType=AFX_INET_SERVICE_HTTP; 
	CString strServer; 
	CString strObject; 
	INTERNET_PORT nPort; 

	if (::AfxParseURL(Text,dwServiceType,strServer,strObject,nPort)) 
	{ 
		m_strURL=Text; 
	} */
	m_strURL=Text;
}

void CWeb::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==0){
		now_second++;
		if(now_second>=60){
			now_minute++;
			now_second=0;
		}
		if(now_minute>=60){
			now_hour++;
			now_minute=0;
		}
		CString res,tmp;
		
		if(now_hour<10) res+="0";
		tmp.Format("%d",now_hour);
		res+=tmp;res+=":";
		
		if(now_minute<10) res+="0";
		tmp.Format("%d",now_minute);
		res+=tmp;res+=":";
		
		if(now_second<10) res+="0";
		tmp.Format("%d",now_second);
		res+=tmp;
		
		m_time_edit.SetWindowText(res);
	}
	
	CDialog::OnTimer(nIDEvent);
}

BOOL CWeb::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	KillTimer(m_ActiveTimer);
	return CDialog::DestroyWindow();
}
