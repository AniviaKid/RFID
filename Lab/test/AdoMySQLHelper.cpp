// AdoMySQLHelper.cpp: implementation of the CAdoMySQLHelper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "test.h"
#include "AdoMySQLHelper.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#pragma comment(lib,"./libmysql.lib")

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAdoMySQLHelper::CAdoMySQLHelper()
{
	m_pSQL = NULL;
	m_pSQLResultSet = NULL;
	m_bIsConnect = FALSE;
}

CAdoMySQLHelper::~CAdoMySQLHelper()
{
	mysql_close(m_pSQL);
}

BOOL CAdoMySQLHelper::ConnectDB(){
	if(m_bIsConnect){
		AfxMessageBox("Connected Successful.");
		return TRUE;
	}
	mysql_library_init(0,NULL,NULL);
	if((m_pSQL=mysql_init(NULL))==NULL){
		AfxMessageBox("Init Connect Failed.");
		return FALSE;
	}
	mysql_options(m_pSQL,MYSQL_SET_CHARSET_NAME,"gb2312");
	if(mysql_real_connect(m_pSQL,"a.aniviakid.cn","user1","user1","RFID",3306,NULL,0)==NULL){
		AfxMessageBox(mysql_error(m_pSQL));
		return FALSE;
	}
	m_bIsConnect=TRUE;
	return m_bIsConnect;
}

BOOL CAdoMySQLHelper::ExecuteQuery(const char* strSQL){
	if(mysql_query(m_pSQL,strSQL)){
		AfxMessageBox(mysql_error(m_pSQL));
		return FALSE;
	}
	m_pSQLResultSet=mysql_store_result(m_pSQL);
	return TRUE;
}

MYSQL_RES* CAdoMySQLHelper::Get_m_pSQLResultSet() {return m_pSQLResultSet;}

MYSQL* CAdoMySQLHelper::Get_m_pSQL() {return m_pSQL;}

