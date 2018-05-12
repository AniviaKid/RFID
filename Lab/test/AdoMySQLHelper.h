// AdoMySQLHelper.h: interface for the CAdoMySQLHelper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOMYSQLHELPER_H__F7480013_5926_4FCB_ABE4_9257AAAF3588__INCLUDED_)
#define AFX_ADOMYSQLHELPER_H__F7480013_5926_4FCB_ABE4_9257AAAF3588__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include ".\include\mysql.h"



class CAdoMySQLHelper  
{
public:
	CAdoMySQLHelper();
	virtual ~CAdoMySQLHelper();

private:
	MYSQL* m_pSQL;  
	MYSQL_RES* m_pSQLResultSet;
	
protected:
	BOOL m_bIsConnect;    
public:
	BOOL ConnectDB();
	BOOL ExecuteQuery(const char* strSQL);
	MYSQL_RES* Get_m_pSQLResultSet();
	MYSQL* Get_m_pSQL();
	//my_ulonglong mysql_affected_rows(MYSQL *mysql); //return affected rows
};

#endif // !defined(AFX_ADOMYSQLHELPER_H__F7480013_5926_4FCB_ABE4_9257AAAF3588__INCLUDED_)
