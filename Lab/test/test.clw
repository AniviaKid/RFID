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
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CAppDev]
Type=0
HeaderFile=AppDev.h
ImplementationFile=AppDev.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_DEBUGGER]
Type=1
Class=CDebugger
ControlCount=46
Control1=ID_START_INS,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_STATE,edit,1484849280
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_NUMBER,edit,1484849280
Control7=IDC_FIND_CARD,button,1342242816
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_COMBO2,combobox,1344340226
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT1,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_COMBO3,combobox,1344340226
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT2,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_EDIT3,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_EDIT4,edit,1350631552
Control21=IDC_BUTTON1,button,1342242816
Control22=IDC_BUTTON2,button,1342242816
Control23=IDC_BUTTON3,button,1342242816
Control24=IDC_STATIC,button,1342177287
Control25=IDC_RADIO1,button,1342177289
Control26=IDC_RADIO2,button,1342177289
Control27=IDC_STATIC,static,1342308352
Control28=IDC_EDIT5,edit,1350631552
Control29=IDC_BUTTON4,button,1342242816
Control30=IDC_STATIC,button,1342177287
Control31=IDC_STATIC,static,1342308352
Control32=IDC_COMBO4,combobox,1344340226
Control33=IDC_STATIC,static,1342308352
Control34=IDC_COMBO5,combobox,1344340226
Control35=IDC_STATIC,static,1342308352
Control36=IDC_EDIT6,edit,1350631552
Control37=IDC_BUTTON5,button,1342242816
Control38=IDC_BUTTON6,button,1342242816
Control39=IDC_STATIC,static,1342308352
Control40=IDC_EDIT7,edit,1350631552
Control41=IDC_STATIC,static,1342308352
Control42=IDC_EDIT8,edit,1350631552
Control43=IDC_STATIC,static,1342308352
Control44=IDC_EDIT9,edit,1484849280
Control45=IDC_BUTTON7,button,1342242816
Control46=IDC_BUTTON8,button,1342242816

[CLS:CDebugger]
Type=0
HeaderFile=Debugger.h
ImplementationFile=Debugger.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_STATE
VirtualFilter=dWC

