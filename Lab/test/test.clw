; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWeb
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "test.h"

ClassCount=8
Class1=CTestApp
Class2=CTestDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_DEBUGGER
Resource2=IDR_MAINFRAME
Resource3=IDD_APPDEV
Class4=CAppDev
Resource4=IDD_ABOUTBOX
Class5=CDebugger
Resource5=IDD_REGISTER
Class6=CLogin
Resource6=IDD_TEST_DIALOG
Class7=CREGISTER
Resource7=IDD_LOGIN
Class8=CWeb
Resource8=IDD_WEB

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
LastObject=CTestDlg

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
ControlCount=22
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
Control15=IDC_STATE_EDIT,edit,1350631552
Control16=IDC_RECHARGE_BUTTON,button,1342242816
Control17=IDC_PAY_BUTTON,button,1342242816
Control18=IDC_STATIC,button,1342177287
Control19=IDC_HISTORY_EDIT,edit,1476464772
Control20=IDC_REMOVE_HISTORY,button,1342242816
Control21=IDC_INQUIRE_HISTORY,button,1342242816
Control22=IDC_INQUIRE_ALL_HISTORY,button,1342242816

[CLS:CAppDev]
Type=0
HeaderFile=AppDev.h
ImplementationFile=AppDev.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_INQUIRE_ALL_HISTORY
VirtualFilter=dWC

[DLG:IDD_DEBUGGER]
Type=1
Class=CDebugger
ControlCount=33
Control1=ID_START_INS,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_STATE,edit,1350566016
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
Control32=IDC_STATIC,static,1342308352
Control33=IDC_USERNAME_EDIT,edit,1484849280

[CLS:CDebugger]
Type=0
HeaderFile=Debugger.h
ImplementationFile=Debugger.cpp
BaseClass=CDialog
Filter=D
LastObject=CDebugger
VirtualFilter=dWC

[DLG:IDD_LOGIN]
Type=1
Class=CLogin
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_USERNAME_EDIT,edit,1350631552
Control4=IDC_PASSWORD_EDIT,edit,1350631584
Control5=IDC_LOGIN_BUTTON,button,1342242816
Control6=IDC_REGISTERED_BUTTON,button,1342242816

[CLS:CLogin]
Type=0
HeaderFile=Login.h
ImplementationFile=Login.cpp
BaseClass=CDialog
Filter=D
LastObject=CLogin
VirtualFilter=dWC

[DLG:IDD_REGISTER]
Type=1
Class=CREGISTER
ControlCount=8
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_USERNAME_EDIT,edit,1350631552
Control5=IDC_PASSWORD_EDIT,edit,1350631584
Control6=IDC_CONFIRM_EDIT,edit,1350631584
Control7=IDC_REGISTER,button,1342242816
Control8=IDC_BACK,button,1342242816

[CLS:CREGISTER]
Type=0
HeaderFile=REGISTER.h
ImplementationFile=REGISTER.cpp
BaseClass=CDialog
Filter=D
LastObject=CREGISTER
VirtualFilter=dWC

[DLG:IDD_WEB]
Type=1
Class=CWeb
ControlCount=4
Control1=IDC_EXPLORER,{8856F961-340A-11D0-A96B-00C04FD705A2},1342242816
Control2=IDC_OK,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TIME_EDIT,edit,1484849280

[CLS:CWeb]
Type=0
HeaderFile=Web.h
ImplementationFile=Web.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EXPLORER
VirtualFilter=dWC

