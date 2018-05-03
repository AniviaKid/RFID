; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDebugger
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "test.h"

ClassCount=5
Class1=CTestApp
Class2=CTestDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_APPDEV
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CAppDev
Resource4=IDD_TEST_DIALOG
Class5=CDebugger
Resource5=IDD_DEBUGGER

[CLS:CTestApp]
Type=0
HeaderFile=test.h
ImplementationFile=test.cpp
Filter=N

[CLS:CTestDlg]
Type=0
HeaderFile=testDlg.h
ImplementationFile=testDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_TAB1

[CLS:CAboutDlg]
Type=0
HeaderFile=testDlg.h
ImplementationFile=testDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TEST_DIALOG]
Type=1
Class=CTestDlg
ControlCount=1
Control1=IDC_TAB1,SysTabControl32,1342177280

[DLG:IDD_APPDEV]
Type=1
Class=CAppDev
ControlCount=18
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_WALLET_SECTOR_COMBO,combobox,1344340226
Control4=IDC_STATIC,static,1342308352
Control5=IDC_WALLET_BLOCK_COMBO,combobox,1344340226
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BALANCE_EDIT,edit,1350631552
Control8=IDC_INIT_WALLET_BUTTON,button,1342242816
Control9=IDC_INQUIRE_BALANCE_BUTTON,button,1342242816
Control10=IDC_STATIC,static,1342308352
Control11=IDC_RECHARGE_EDIT,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_PAY_EDIT,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATE_EDIT,edit,1484849280
Control16=IDC_RECHARGE_BUTTON,button,1342242816
Control17=IDC_PAY_BUTTON,button,1342242816
Control18=IDC_STATIC,button,1342177287

[CLS:CAppDev]
Type=0
HeaderFile=AppDev.h
ImplementationFile=AppDev.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_PAY_BUTTON
VirtualFilter=dWC

[DLG:IDD_DEBUGGER]
Type=1
Class=CDebugger
ControlCount=31
Control1=ID_START_INS,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_STATE,edit,1484849280
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_NUMBER,edit,1484849280
Control7=IDC_FIND_CARD,button,1342242816
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_CARD_WR_SECTOR_COMBO,combobox,1344339971
Control11=IDC_STATIC,static,1342308352
Control12=IDC_CARD_WR_BLOCK0_EDIT,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_CARD_WR_BLOCK_COMBO,combobox,1344339970
Control15=IDC_STATIC,static,1342308352
Control16=IDC_CARD_WR_BLOCK1_EDIT,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_CARD_WR_BLOCK2_EDIT,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_READ_SECTOR,button,1342242816
Control21=IDC_READ_BLOCK,button,1342242816
Control22=IDC_WRITE_BLOCK,button,1342242816
Control23=IDC_STATIC,button,1342177287
Control24=IDC_RADIO_A_PASSWORD,button,1342177289
Control25=IDC_RADIO_B_PASSWORD,button,1342177289
Control26=IDC_STATIC,static,1342308352
Control27=IDC_PASSWORD_EDIT,edit,1350631552
Control28=IDC_DEFAULT_PASSWORD,button,1342242816
Control29=IDC_CARD_WR_BLOCK3_EDIT1,edit,1350631552
Control30=IDC_CARD_WR_BLOCK3_EDIT2,edit,1350631552
Control31=IDC_CARD_WR_BLOCK3_EDIT3,edit,1350631552

[CLS:CDebugger]
Type=0
HeaderFile=Debugger.h
ImplementationFile=Debugger.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RADIO_B_PASSWORD
VirtualFilter=dWC

