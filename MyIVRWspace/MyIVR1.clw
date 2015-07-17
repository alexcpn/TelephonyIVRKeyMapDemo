; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLabelDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyIVR1.h"
LastPage=0

ClassCount=13
Class1=CMyIVR1App
Class2=CMyIVR1Doc
Class3=CMyIVR1View
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CLeftView
Class7=CModuleButton
Resource2=IDD_KEYDLG
Class8=CKeyMapping
Class9=CLeftButton
Resource3=IDR_MAINFRAME
Class10=CSubItemPage
Class11=CKeyMapping2
Class12=CMyPropertySheet
Resource4=IDD_SUBITEM
Class13=CLabelDlg
Resource5=IDD_DIALOG_LABEL

[CLS:CMyIVR1App]
Type=0
HeaderFile=MyIVR1.h
ImplementationFile=MyIVR1.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=CMyIVR1App

[CLS:CMyIVR1Doc]
Type=0
HeaderFile=MyIVR1Doc.h
ImplementationFile=MyIVR1Doc.cpp
Filter=N
LastObject=ID_EDIT_UNDO

[CLS:CMyIVR1View]
Type=0
HeaderFile=MyIVR1View.h
ImplementationFile=MyIVR1View.cpp
Filter=C
LastObject=CMyIVR1View
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=MyIVR1.cpp
ImplementationFile=MyIVR1.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_APP_ABOUT
CommandCount=5

[DLG:IDR_MAINFRAME]
Type=1
Class=?
ControlCount=3
Control1=IDC_GENSCRIPT,button,1342275584
Control2=IDC_LOADXML,button,1342275584
Control3=IDC_LABEL,button,1342275584

[CLS:CLeftView]
Type=0
HeaderFile=LeftView.h
ImplementationFile=LeftView.cpp
BaseClass=CView
Filter=C
LastObject=CLeftView
VirtualFilter=VWC

[CLS:CModuleButton]
Type=0
HeaderFile=ModuleButton.h
ImplementationFile=ModuleButton.cpp
BaseClass=CButton
Filter=W
LastObject=CModuleButton
VirtualFilter=BWC

[CLS:CKeyMapping]
Type=0
HeaderFile=KeyMapping.h
ImplementationFile=KeyMapping.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CKeyMapping

[CLS:CLeftButton]
Type=0
HeaderFile=LeftButton.h
ImplementationFile=LeftButton.cpp
BaseClass=CButton
Filter=W
LastObject=CLeftButton
VirtualFilter=BWC

[DLG:IDD_SUBITEM]
Type=1
Class=CSubItemPage
ControlCount=19
Control1=IDC_ENABLED,combobox,1075904515
Control2=IDC_PROMPT,edit,1350631552
Control3=IDC_TYPE,combobox,1344339971
Control4=IDC_PLAYTILLEND,combobox,1342242819
Control5=IDC_TIMEOUT,edit,1350639744
Control6=IDC_PLAYNEXT,combobox,1344339970
Control7=IDC_STATIC,static,1073873408
Control8=IDC_STATIC,static,1342308864
Control9=IDC_STATIC,static,1342308864
Control10=IDC_STATIC,static,1342308864
Control11=IDC_STATIC,static,1342308864
Control12=IDC_STATIC,static,1342308864
Control13=IDC_STATIC,button,1342177287
Control14=IDC_STATIC,static,1342308864
Control15=IDC_CHECK1,button,1342275587
Control16=IDC_CHKFIRST,button,1342275587
Control17=IDC_STATIC,static,1342177294
Control18=IDC_VARIABLE,edit,1350631552
Control19=IDC_STATIC,static,1342308864

[CLS:CSubItemPage]
Type=0
HeaderFile=SubItemPage.h
ImplementationFile=SubItemPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CSubItemPage
VirtualFilter=idWC

[DLG:IDD_KEYDLG]
Type=1
Class=CKeyMapping2
ControlCount=25
Control1=IDC_LIST3,SysListView32,1350631433
Control2=IDC_CLEAR,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_BU_1,button,1342275584
Control5=IDC_BU_2,button,1342275584
Control6=IDC_BU_3,button,1342275584
Control7=IDC_BU_4,button,1342275584
Control8=IDC_BU_5,button,1342275584
Control9=IDC_BU_6,button,1342275584
Control10=IDC_BU_7,button,1342275584
Control11=IDC_BU_8,button,1342275584
Control12=IDC_BU_9,button,1342275584
Control13=IDC_BU_STAR,button,1342275584
Control14=IDC_BU_0,button,1342275584
Control15=IDC_BU_POUND,button,1342275584
Control16=IDC_LI_NEXT_ACTION,SysListView32,1350647837
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,button,1342177287
Control21=IDC_BU_NILL,button,1342275584
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342177283
Control24=IDC_STATIC,static,1342308353
Control25=IDC_BU_NUMBER,button,1342275584

[CLS:CKeyMapping2]
Type=0
HeaderFile=KeyMapping2.h
ImplementationFile=KeyMapping2.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CKeyMapping2

[CLS:CMyPropertySheet]
Type=0
HeaderFile=MyPropertySheet.h
ImplementationFile=MyPropertySheet.cpp
BaseClass=CPropertySheet
Filter=W
VirtualFilter=hWC
LastObject=CMyPropertySheet

[DLG:IDD_DIALOG_LABEL]
Type=1
Class=CLabelDlg
ControlCount=2
Control1=IDC_EDIT1,edit,1350631552
Control2=IDOK,button,1342242817

[CLS:CLabelDlg]
Type=0
HeaderFile=LabelDlg.h
ImplementationFile=LabelDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

