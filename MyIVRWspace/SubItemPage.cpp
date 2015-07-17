// SubItemPage.cpp : implementation file
//

#include "stdafx.h"
#include "MyIVR1.h"
#include "SubItemPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "ModuleButton.h"

extern list<CButton *>::iterator i;
extern 	list<CModuleButton::SubItem>::iterator nsub;

CString	CSubItemPage::m_csNext[10];
int	CSubItemPage::nNext=0;
CSubItemPage * CSubItemPage::lastCheckedPage=0;
/////////////////////////////////////////////////////////////////////////////
// CSubItemPage property page

IMPLEMENT_DYNCREATE(CSubItemPage, CPropertyPage)

CSubItemPage::CSubItemPage() : CPropertyPage(CSubItemPage::IDD)
{
	//{{AFX_DATA_INIT(CSubItemPage)
	m_Variable = _T("");
	//}}AFX_DATA_INIT
//	memset((void *)&myItem,0,sizeof(CModuleButton::SubItem));

}

CSubItemPage::~CSubItemPage()
{
}

void CSubItemPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubItemPage)
	DDX_Control(pDX, IDC_CHKFIRST, m_chkFirst);
	DDX_Control(pDX, IDC_CHECK1, m_promptenabled);
	DDX_Control(pDX, IDC_PLAYNEXT, m_Next);
	DDX_Control(pDX, IDC_TYPE, m_type);
	DDX_Control(pDX, IDC_TIMEOUT, m_timeout);
	DDX_Control(pDX, IDC_PROMPT, m_prompt);
	DDX_Control(pDX, IDC_PLAYTILLEND, m_playtillend);
	DDX_Control(pDX, IDC_ENABLED, m_enabled);
	DDX_Text(pDX, IDC_VARIABLE, m_Variable);
	DDV_MaxChars(pDX, m_Variable, 25);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubItemPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSubItemPage)
	ON_BN_CLICKED(IDC_SET, OnSet)
	ON_BN_CLICKED(IDC_CHKFIRST, OnChkfirst)
	ON_WM_SHOWWINDOW()
	ON_WM_CAPTURECHANGED()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubItemPage message handlers

BOOL CSubItemPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	if(myItem.csType=="NUMBER")
		m_type .SetCurSel(0);
	else if(myItem.csType=="DIGIT")
		m_type.SetCurSel(1);
	else 
		m_type.SetCurSel(2);


	m_prompt.SetWindowText(myItem.csPrompt);
	if(myItem.bPromptEnabled=="1")
		m_promptenabled.SetCheck(1);
	else
		m_promptenabled.SetCheck(0);

	m_timeout.SetWindowText(myItem.TimeOut); 

	if(myItem.bEnabled=="1")
		m_enabled.SetCurSel(0);
	else
		m_enabled.SetCurSel(1);
	
	if(myItem.PlayTillEnd=="1")
		m_playtillend.SetCurSel(0);
	else
		m_playtillend.SetCurSel(1);
	

	if(myItem.csBegin=="1")
	{
		m_chkFirst.SetCheck(1);
		lastCheckedPage=this;
	}
	else
		m_chkFirst.SetCheck(0);
	
	m_Variable = myItem.csVariable;

	for(int i=0;i<nNext;i++)
		if(m_Next.FindStringExact(-1,m_csNext[i])==CB_ERR ) 
			m_Next.InsertString(-1,m_csNext[i]);
	
	m_Next.SelectString(-1,myItem.csNext); 

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
bool CSubItemPage::SetItemProperty(CModuleButton::SubItem *thisItem)
{
	try{
	
		m_csNext[nNext] =myItem.csName=thisItem->csName;
		myItem.bEnabled=thisItem->bEnabled;
		myItem.bPromptEnabled=thisItem->bPromptEnabled;
		myItem.csPrompt=thisItem->csPrompt;
		myItem.csType=thisItem->csType;
		myItem.PlayTillEnd=thisItem->PlayTillEnd;
		myItem.TimeOut=thisItem->TimeOut;
		myItem.csNext=thisItem->csNext;
		myItem.csBegin=thisItem->csBegin;
		myItem.csVariable =thisItem->csVariable;
		nNext++;
		if(nNext>9)
			nNext=0;
	}
	catch(CMemoryException *e)
	{
		delete e;
		return FALSE;
	}
		


	return TRUE;

}

void CSubItemPage::OnSet() 
{ 
	// save the changes in the subitem list
	UpdateData(1); 

	// get the selected subitem and then traverse to that subitems correct sublist
	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	CLeftView *leftView =mApp->m_oLeftView;
	CModuleButton * tempBut;
	CModuleButton::SubItem  thisItem;  
	CString csTemp;
	bool bres;
	//get the correct button class for the selected object

	for(i=leftView->mylist.begin();i!=leftView->mylist.end();++i)
	{	
		tempBut=(CModuleButton * )*i;
		if(tempBut->csLabel.CompareNoCase(leftView->csSelButtonText)==0) 
			break;
    }
	
	//go to the correct subitem in the subitem list

	for(nsub = tempBut->lSubItem.begin();nsub!=tempBut->lSubItem.end();++nsub)  
	{

		thisItem =*nsub;
		if(AfxIsValidString(csTitle)) 
		if(thisItem.csName==csTitle)
		{	
			//erase the previous item and insert the new one

			thisItem.csName=csTitle;
			m_type .GetWindowText(csTemp);
			thisItem.csType=csTemp;
			m_prompt.GetWindowText(csTemp);
			thisItem.csPrompt=csTemp;
			m_timeout.GetWindowText(csTemp);
			thisItem.TimeOut=csTemp;
			m_Next.GetWindowText(csTemp);
		    thisItem.csNext=csTemp;

			m_playtillend.GetWindowText(csTemp);
			if(csTemp =="YES")
				thisItem.PlayTillEnd="1";
             else
				thisItem.PlayTillEnd="0";
		
		
			bres=m_chkFirst.GetCheck();
			if(bres)
					thisItem.csBegin="1";
                else
					thisItem.csBegin="0";
		
			m_enabled.GetWindowText(csTemp);
			if(csTemp =="YES")
				thisItem.bEnabled="1";
             else
				thisItem.bEnabled="0";
			
			if(m_promptenabled.GetCheck())
				thisItem.bPromptEnabled="1";
             else
				thisItem.bPromptEnabled="0";
			
			 m_Variable.MakeUpper(); 
			 thisItem.csVariable = m_Variable ;
			 nsub=tempBut->lSubItem.erase(nsub);
			 tempBut->lSubItem.insert(nsub,thisItem);
			
	
			break;
		}
	}
}

void CSubItemPage::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CPropertyPage::OnShowWindow(bShow, nStatus);
	
	if(lastCheckedPage != this) 
	{
		myItem.csBegin="0";
	
	}
	else
		myItem.csBegin="1";

	if(myItem.csBegin=="1")
	{
		//m_chkFirst.SetCheck(1);
	}
	else
		m_chkFirst.SetCheck(0);
   UpdateData(0);
	
}

void CSubItemPage::OnChkfirst() 
{
	lastCheckedPage	=this;
}




