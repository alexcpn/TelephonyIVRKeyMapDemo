// KeyMapping2.cpp : implementation file
//

#include "stdafx.h"
#include "MyIVR1.h"
#include "KeyMapping2.h"
#include "ModuleButton.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern list<CButton *>::iterator i;
extern 	list<CModuleButton::KeyPadMapping >::iterator j;

/////////////////////////////////////////////////////////////////////////////
// CKeyMapping2 property page

IMPLEMENT_DYNCREATE(CKeyMapping2, CPropertyPage)

CKeyMapping2::CKeyMapping2() : CPropertyPage(CKeyMapping2::IDD)
{
	//{{AFX_DATA_INIT(CKeyMapping2)
	//}}AFX_DATA_INIT
	m_bKeyInNumber=0;
}

CKeyMapping2::~CKeyMapping2()
{
}

void CKeyMapping2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKeyMapping2)
	DDX_Control(pDX, IDC_LI_NEXT_ACTION, m_liNextActionList);
	DDX_Control(pDX, IDC_LIST3, m_MapList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKeyMapping2, CPropertyPage)
	//{{AFX_MSG_MAP(CKeyMapping2)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyMapping2 message handlers
/**
	This method uses the values in the keypad settings property page to 
	populate the particular module buttons KeyPadMapping list

*/
bool CKeyMapping2::UpdateKeyList()
{
	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	CLeftView *leftView =mApp->m_oLeftView;
	CModuleButton * tempBut;
	CModuleButton * tempButNew;
	int             iItem,  iActualItem;
	LV_ITEM         lvitem;
	CString csTemp1,csTemp;
	CModuleButton::KeyPadMapping thismap;
	m_MapList.DeleteAllItems(); 


	//get the correct button class for the selected object

	for(i=leftView->mylist.begin();i!=leftView->mylist.end();++i)
	{	
		tempBut=(CModuleButton * )*i;
		if(tempBut->csLabel.CompareNoCase(leftView->csSelButtonText)==0) 
			break;
    }
	iItem=0;
	for(j=tempBut->lKeyMapping.begin();j!=tempBut->lKeyMapping.end();++j)
	{		
		thismap =(*j);
		csTemp1.Format("%d",thismap.KeyPressed);
		if(thismap.KeyPressed==STAR)
				csTemp1="*";
		else if(thismap.KeyPressed==POUND)
			csTemp1 ="#";
		else if(thismap.KeyPressed==NILL)
			csTemp1 ="NIL";
		tempButNew =thismap.NextButton;
		csTemp.Format("%s",tempButNew->csLabel); 
		
		for(int iSubItem=0;iSubItem<2;iSubItem++)
		{
			lvitem.mask = LVIF_TEXT ; 
			lvitem.iItem = (iSubItem == 0)? iItem : iActualItem;
			lvitem.iSubItem = iSubItem;
			
			lvitem.pszText = iSubItem == 0? (char *)(LPCTSTR)csTemp1 : (char *)(LPCTSTR)csTemp;
			if (iSubItem == 0)
				iActualItem = m_MapList.InsertItem(&lvitem); // insert new item
			else
				m_MapList.SetItem(&lvitem); // modify existing item (the sub-item text)

		}
		iItem++;
	
	}
	return true;
}

/**
	This function is used to populate the key pad settings dialog box
	property page from the module buttons keypad mapping list
*/
BOOL CKeyMapping2::PopulateKeyList()
{
	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	CLeftView *leftView =mApp->m_oLeftView;
	CModuleButton * tempBut;
	
	m_liNextActionList.InsertColumn(0,"Action List",LVCFMT_LEFT,100);

	m_liNextActionList.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	m_liNextActionList.DeleteAllItems();

	for(i=leftView->mylist.begin();i!=leftView->mylist.end();++i)
	{	
		tempBut=(CModuleButton * )*i;
		//m_ActionCombo .AddString(tempBut->csNodeName);
		m_liNextActionList.InsertItem(0,tempBut->csLabel);//changed for leabel
    
	}
	CRect rect;
	m_MapList.GetWindowRect(&rect);
	m_MapList.SetExtendedStyle(LVS_EX_GRIDLINES |LVS_EX_FULLROWSELECT); 
	m_MapList.InsertColumn(0, "KeyPressed", LVCFMT_LEFT,
		rect.Width() * 1/3, 0);
	m_MapList.InsertColumn(1, "Go To Module", LVCFMT_LEFT,
		rect.Width() * 2/3, 1);
		UpdateKeyList();
	UpdateData(1);

	
	return TRUE;

}


BOOL CKeyMapping2::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	PopulateKeyList();
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/**
	This function is used to clear a key pad setting from the key pad 
	setting property page's list control

*/ 
void CKeyMapping2::OnClear() 
{
	POSITION pos = m_MapList.GetFirstSelectedItemPosition();
	if (pos == NULL)
	   return;
	CString csDigit;
	CString csAction;
	int nDigit;
	int nItem = m_MapList.GetNextSelectedItem(pos);
	csDigit=  m_MapList.GetItemText(nItem,0);
	csAction = m_MapList.GetItemText(nItem,1);
	nDigit =atoi((char *)(LPCTSTR)csDigit);
	if(csDigit=="*")
		nDigit=STAR;
	else if(csDigit=="#")
		nDigit =POUND;
	else if(csDigit=="NIL")
		nDigit =NILL;



	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	CLeftView *leftView =mApp->m_oLeftView;
	CModuleButton * tempBut;


	//get the correct button class for the selected object

	for(i=leftView->mylist.begin();i!=leftView->mylist.end();++i)
	{	
		tempBut=(CModuleButton * )*i;
		if(tempBut->csLabel.CompareNoCase (leftView->csSelButtonText)==0) 
			break;
    }

	//get the list of that button class to insert key maps
	
	CModuleButton::KeyPadMapping thismap;

	for(j=tempBut->lKeyMapping.begin();j!=tempBut->lKeyMapping.end();++j)
	{
		thismap =*j;
		if(thismap.KeyPressed==nDigit && thismap.NextButton->csLabel==csAction)
		{
		 tempBut->lKeyMapping.erase(j); 
			break;
		}
	}
	UpdateKeyList();
	
	
}
/**
	This method is used to assign a prompt and inserts that key pad map
	into the module buttons key pad mapping list
*/
bool CKeyMapping2::AssignPrompt(CString csKeyAssigned)
{

	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	CLeftView *leftView =mApp->m_oLeftView;
	CModuleButton * tempBut;
	CModuleButton * tempButTo;

	
	POSITION pos = m_liNextActionList.GetFirstSelectedItemPosition();

	int nIndex = m_liNextActionList.GetNextSelectedItem(pos);
	if(nIndex == -1)
	{
		MessageBox("Please select an Action", "MyIVR - KeyPad",MB_OK|MB_ICONINFORMATION);
		return 0;
	}

	if(m_bKeyInNumber==1)
	{
		if(csKeyAssigned.Compare("#")!=0)
		{
			m_csKeyInNumber+=csKeyAssigned;
			return 1;
		}
		else
		{
			m_bKeyInNumber=0;
			csKeyAssigned=m_csKeyInNumber;
			m_csKeyInNumber="";
		}

	}
	if(csKeyAssigned.Compare("STORE_TILL_#")==0)
	{
		m_bKeyInNumber=1;
		return 1;
	}

	// List View Checking

	for(i=leftView->mylist.begin();i!=leftView->mylist.end();++i)
	{	
		tempBut=(CModuleButton * )*i;
	
		if(tempBut->csLabel.CompareNoCase(leftView->csSelButtonText)==0) 
			break;
    }

	CString csAction= m_liNextActionList.GetItemText(nIndex,0);
	
	CModuleButton::KeyPadMapping thismap;
	
	if(csKeyAssigned=="")
		return 0;
	
	int nKey =atoi(csKeyAssigned);
	
	if(csKeyAssigned=="*")
		nKey=STAR;
	else if(csKeyAssigned=="#")
		nKey =POUND;
	else if(csKeyAssigned=="Nil")
		nKey =NILL;

	thismap.KeyPressed=nKey;

	if(csAction==""||csAction==leftView->csSelButtonText)

		return 0;

	for(i=leftView->mylist.begin();i!=leftView->mylist.end();++i)
	{	
		tempButTo=(CModuleButton * )*i;
		if(tempButTo->csLabel.CompareNoCase(csAction)==0) 
			break;
    }
	thismap.NextButton =tempButTo;

	//Check Key and Action if already Assigned 
	if(IsAssigned(csAction,csKeyAssigned))
	{
		tempBut->lKeyMapping.insert(tempBut->lKeyMapping.end(),thismap);
	
		UpdateKeyList();
	}
	
	return 0;		
}
/**
	This function is used to check if a particular key is already
	assigned
*/
bool CKeyMapping2::IsAssigned(CString csActionName,CString csKey)
{
	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	CLeftView *leftView =mApp->m_oLeftView;
	CModuleButton * tempBut;
	CModuleButton  * tempButNew;
	CString csTempKey;

	// Moving pointer to the Current Selected Block

	for(i=leftView->mylist.begin();i!=leftView->mylist.end();++i)
	{	
		tempBut=(CModuleButton * )*i;
	
		if(tempBut->csLabel.CompareNoCase (leftView->csSelButtonText)==0) 
			break;
    }

	CModuleButton::KeyPadMapping thismap;

	

	for(j=tempBut->lKeyMapping.begin();j!=tempBut->lKeyMapping.end();++j)
	{

		thismap = *j;

		// Checking Keys if assigned
		csTempKey.Format("%d",thismap.KeyPressed);
		
		if(thismap.KeyPressed==STAR)
			csTempKey="*";
		else if(thismap.KeyPressed==POUND)
			csTempKey ="#";
		else if(thismap.KeyPressed==NILL)
			csTempKey ="NIL";

		if(strcmpi(csKey ,csTempKey)==0)
		{
			MessageBox("Key already assigned ! \nPlease choose another Key","MyIVR - KeyPad",MB_ICONINFORMATION);
			return FALSE;
		}

		// Checking Action if assigned
		tempButNew =thismap.NextButton;
		
		if(strcmpi(csActionName ,tempButNew->csLabel)==0)
		{
			MessageBox("Action already assigned ! \nPlease choose another action","MyIVR - KeyPad",MB_ICONINFORMATION);
			return FALSE;
		}

	}

return TRUE;
}

BOOL CKeyMapping2::OnCommand(WPARAM wParam, LPARAM lParam) 
{

	switch(wParam)
	{
		case IDC_BU_1:
			AssignPrompt("1");
			break;
		case IDC_BU_2:
			AssignPrompt("2");
			break;
		case IDC_BU_3:
			AssignPrompt("3");
			break;
		case IDC_BU_4:
			AssignPrompt("4");
			break;
		case IDC_BU_5:
			AssignPrompt("5");
			break;
		case IDC_BU_6:
			AssignPrompt("6");
			break;
		case IDC_BU_7:
			AssignPrompt("7");
			break;
		case IDC_BU_8:
			AssignPrompt("8");
			break;
		case IDC_BU_9:
			AssignPrompt("9");
			break;
		case IDC_BU_STAR:
			AssignPrompt("*");
			break;
		case IDC_BU_0:
			AssignPrompt("0");
			break;
		case IDC_BU_POUND:
			AssignPrompt("#");
			break;
		case IDC_BU_NILL:
			AssignPrompt("Nil");
			break;
		case IDC_BU_NUMBER:
			AssignPrompt("STORE_TILL_#");
			break;

	}	
	return CPropertyPage::OnCommand(wParam, lParam);
}
