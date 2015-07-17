// LeftView.cpp : implementation file
//

#include "stdafx.h"
#include "MyIVR1.h"
//#include "MyIVR1View.h" Both are already in MyIVR1.h header
//#include "LeftView.h"
#include "ModuleButton.h"
#include "KeyMapping2.h"
#define SUBITEM 2
#include "SubItemPage.h"
#include "typeinfo.h"
#include "MyPropertySheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CLeftView *CLeftView::oLeftView=0;
CString CLeftView::csDragLabel="DragLabel";
CString CLeftView::csSelButtonText="SelText";
CButton * CLeftView::arrButton[50];
int   CLeftView::nButtonIndex=-1;
list<CButton *> CLeftView::mylist;
list<CButton *>::iterator i;
list<CString> CLeftView::selnodelist;
list<CString>::iterator sellist;
extern list<CModuleButton::SubItem>::iterator nsub;
extern 	list<CModuleButton::KeyPadMapping >::iterator j;
	

/////////////////////////////////////////////////////////////////////////////
// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CView)

CLeftView::CLeftView()
{
	hCross=0;
}

CLeftView::~CLeftView()
{
	//delete	[] myButton1;
	for(int j=0;j<22;j++)
		delete myButton1[j] ;

	for(i=mylist.begin();i!=mylist.end();++i)
	 delete *i;
	UnhookWindowsHookEx(hHook);
	if(hCross!=0)
	 CloseHandle(hCross);
	
}


BEGIN_MESSAGE_MAP(CLeftView, CView)
	//{{AFX_MSG_MAP(CLeftView)
	ON_WM_CREATE()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
int CLeftView::bDrag =0;
HHOOK CLeftView::hHook=0;
HCURSOR CLeftView::hCross=0;
/////////////////////////////////////////////////////////////////////////////
// CLeftView drawing

void CLeftView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	CBrush blackBrush;
	blackBrush.CreateSolidBrush(RGB(0,0,125)); 
	pDC->SelectObject(&blackBrush);
	pDC->FloodFill(0,0,RGB(0,0,125));

}

/////////////////////////////////////////////////////////////////////////////
// CLeftView diagnostics

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftView message handlers

BOOL CLeftView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CLeftView::OnInitialUpdate() 
{
	oLeftView =this;
	
	CView::OnInitialUpdate();
	

}
CMyIVR1Doc* CLeftView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyIVR1Doc)));
	return (CMyIVR1Doc*)m_pDocument;
}
int CLeftView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	mApp->m_oLeftView =this;	
	
	csClassNames[0]="Login";
	csClassNames[1]="Menu";
	csClassNames[2]="Review";
	csClassNames[3]="Listen";
	csClassNames[4]="Record";
	csClassNames[5]="Send";
	csClassNames[6]="Disconnect";
	csClassNames[7]="Prompt";
	csClassNames[8]="PendCheck";
	csClassNames[9]="<----------->";
	csClassNames[10]="Insert";
	csClassNames[11]="Append";
	csClassNames[12]="Ovrwrite";
	csClassNames[13]="Forward";
	csClassNames[14]="Rewind";
	csClassNames[15]="Play";
	csClassNames[16]="Pause";
	csClassNames[17]="Next";
	csClassNames[18]="Prev";
	csClassNames[19]="NewSrch";
	csClassNames[20]="ToBegin";
	//csClassNames[21]="Stop";
	csClassNames[21]="NewDic";


	CRect rc(0,10,BUTWIDTH,BUTHEIGHT+10);
	BOOL bres;
	
		
int res=157;
for(int i=0;i<22;i++)
{
	myButton1[i] =new CLeftButton;

	if(i==10)
		rc.right=rc.right/2; 

	if(i!=9)
		bres =	myButton1[i]->Create(csClassNames[i], WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON|BS_FLAT,//BS_OWNERDRAW, 
		rc, this,12+i);
	
   	
	if(i>=10)
	{
		myButton1[i]->type =2;
		if(i % 2==0)
		{
			rc.left =rc.right+1; 
			rc.right =rc.left+BUTWIDTH/2;
		}
		else
		{
			rc.left=1;//BUTWIDTH/2;
			rc.right =rc.left+BUTWIDTH/2;
			rc.top=rc.bottom+1 ;//3
			rc.bottom =rc.top +BUTHEIGHT;
			
		}
	}
	else 
	{
		rc.top=rc.bottom+1 ;//3
		rc.bottom =rc.top +BUTHEIGHT;
	}
}
	hCross =AfxGetApp()->LoadCursor((IDC_POINTER_COPY));
	hHook = SetWindowsHookEx(WH_MOUSE,MouseProc,0,GetCurrentThreadId());
	
	return 0;
}
LRESULT CALLBACK CLeftView::MouseProc(int nCode,WPARAM wParam,LPARAM lParam)
{
	 // Select the item that is at the point myPoint.
	

	MOUSEHOOKSTRUCT *mouseHook =(MOUSEHOOKSTRUCT *)lParam;
	SIZE sz;
	sz.cx =BUTWIDTH;
	sz.cy =BUTHEIGHT;

	if(nCode==HC_ACTION)
	{
		if(wParam ==WM_LBUTTONDOWN ) //selectin the button 
		{
			char szClassName[50];
			int res =GetClassName(mouseHook->hwnd,szClassName,50);
			if(res)
				if(strcmp(szClassName,"Button")==0)
				{
					CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
					CLeftButton *draggedButton=0;
					CModuleButton *pModuleButton=0;
					draggedButton=dynamic_cast<CLeftButton *>(draggedButton->FromHandle(mouseHook->hwnd));
					if(draggedButton==0)
					{	pModuleButton=dynamic_cast<CModuleButton *>(pModuleButton->FromHandle(mouseHook->hwnd));
						if(	pModuleButton==0)
							return CallNextHookEx(hHook,nCode,wParam,lParam);
						else
							draggedButton=(CLeftButton *)pModuleButton;

					}
					draggedButton->GetWindowText(csDragLabel); 
					if(draggedButton->GetParent() !=mApp->m_oMainView)
					{
						bDrag=1;//CREATENEW
					  if(draggedButton->type==2)bDrag=3;
					}
					else
					{
						bDrag=2;//DRAGEXISTING
					}
				}
		}
 		else if((wParam ==WM_LBUTTONUP)&& bDrag) //getting the node where the item is dropped
		{
			
			CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
			POINT mPoint=mouseHook->pt;
			CView* pView =mApp->m_oMainView;	

			if(bDrag==2 )  //this was a drag operation do not create any button here
			{
				CRect rect;
				bDrag=0;
				mApp->m_oMainView->GetClientRect(&rect);
				mApp->m_oMainView->InvalidateRect(rect,TRUE);

				return CallNextHookEx(hHook,nCode,wParam,lParam);
			}
			{
			CRect rect;
			CButton *draggedButton=(CButton *)draggedButton->FromHandle(mouseHook->hwnd);
			draggedButton->GetClientRect(&rect);
			if(draggedButton->GetParent() != mApp->m_oLeftView)
				return CallNextHookEx(hHook,nCode,wParam,lParam);;
		
			if( (rect.Height() != BUTHEIGHT)  && ((rect.Width() != BUTWIDTH)||(rect.Width() != BUTWIDTH/2))  )
			{
				bDrag=0;
				return CallNextHookEx(hHook,nCode,wParam,lParam);
			}
			}
			
			if(1)//csDragLabel!="OK" && csDragLabel !="Cancel" && csDragLabel !="&Open")
			{	
				if(bDrag==3)
					sz.cx =BUTWIDTH/2;
			
				pView->ScreenToClient(&mPoint);
				CRect rc(mPoint,sz);
				CModuleButton *temp =new CModuleButton;
				int ngo=1;
				int doitagain=1;
				CString csOrginal;
				csOrginal=csDragLabel;
				//------------------------------------------------
				// checking the selected button name in hte selected list if so rename it 
				//-------------------------------------------------
				while(doitagain)
				{
					char sztemp[20];
					doitagain=0;
					for(sellist=selnodelist.begin();sellist!=selnodelist.end();++sellist)  
					{
						if(!csDragLabel.CompareNoCase(*sellist))
						{
							itoa(ngo,sztemp,10);
							csDragLabel=csOrginal;
							csDragLabel.Insert(csDragLabel.GetLength(),sztemp); 
							ngo++;
							doitagain=1;
							if(bDrag==3)
								return CallNextHookEx(hHook,nCode,wParam,lParam);
							break;
						}
						doitagain=0;
					}
				}
				bool bres =temp->Create(csDragLabel, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON|BS_FLAT,rc, pView,mylist.size()+1);
				if(bres)	
				{
					temp->nID =mylist.size();
					temp->csNodeName =csDragLabel;
					temp->csLabel =csDragLabel;
					temp->clientRect =rc;
					if(bDrag==3)
						temp->type =SUBITEM;
					
					//--------------------------------------------------------
					//Insert the address of the newly created CModuleButton to the list mylist
					//--------------------------------------------------------
					
					mylist.insert(mylist.end(),temp);
					selnodelist.insert(selnodelist.end(),csDragLabel);  
					if(temp->type ==SUBITEM)
					{
						bDrag=0;
						return CallNextHookEx(hHook,nCode,wParam,lParam);
					}
						
					
					//*********************************************************
					//now read from the xml and populate the subitem list here
					//*********************************************************
					
					CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
					CString	csQuery;
					LONG dwCount;
					csDragLabel.MakeUpper();
					csOrginal.MakeUpper(); 
				
					csQuery.Format("TDSA/STEP[@NAME=%c%s%c]",'"',csOrginal ,'"');
					bool bres =mApp->mScriptXML.GoToNode(csQuery);
				    bres =mApp->mScriptXML.GoToNode("SUBSTEP",1);
					bres =mApp->mScriptXML.GetNodesList("SUBSTEP",1);
					bres =mApp->mScriptXML.GetNoOfChildNodes(dwCount); 
					bres =mApp->mScriptXML.NextChildNode();
					CString csTemp;
					char Attribute[4][20] ={"INPUTTYPE","TIMEOUT","ENABLE","ISMUST"};
					CString csValue[4];
					int begin=0;
					CModuleButton::SubItem  thisItem; 

					do{
						mApp->mScriptXML.GetCurrentNodeName(csTemp);
						thisItem.csName =csTemp;
						bres =mApp->mScriptXML.GetNodeText("ENABLE",csTemp,1); //this is the node name
						thisItem.bEnabled =csTemp;
						bres =mApp->mScriptXML.GetNodeText("PROMPT",csTemp,1); //this is the node name
						thisItem.csPrompt =csTemp;
						begin++;
						
						for(int t=0;t<4;t++)
						   mApp->mScriptXML.GetAttributeValue("PROMPT",Attribute[t],csValue[t],TRUE); 
						
						thisItem.csType			= csValue[0];
						thisItem.TimeOut		= csValue[1];
						thisItem.bPromptEnabled = csValue[2];
						thisItem.PlayTillEnd	= csValue[3];
						
						bres =mApp->mScriptXML.GetNodeText("NEXT",csTemp,1); //this is the node name
						thisItem.csNext =csTemp;
						if(begin==1)
							thisItem.csBegin="1";
						else
							thisItem.csBegin="0";
						//---------------------------------------
						//now add the subitem to the sub item list
						//---------------------------------------
						temp->lSubItem.insert(temp->lSubItem.end(),thisItem);
						   
					}while(mApp->mScriptXML.NextSibling()) ;
				}	
			}
		bDrag=0;
		}
		if(wParam ==WM_RBUTTONUP)
		{
			char szClassName[50];
			
			CModuleButton::SubItem thisItem; 
			int res =GetClassName(mouseHook->hwnd,szClassName,50);
			if(res)
				if(strcmp(szClassName,"Button")==0)
				{
					CModuleButton *draggedButton=0;
					CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
					draggedButton=(CModuleButton *)(draggedButton->FromHandle(mouseHook->hwnd));
					
					draggedButton=dynamic_cast<CModuleButton *>(draggedButton);	//checking if it is of type module button or something else				
				
					if((draggedButton==0)||(draggedButton->GetParent() ==mApp->m_oLeftView))
							return CallNextHookEx(hHook,nCode,wParam,lParam); 
				
					draggedButton->GetWindowText(csSelButtonText); 
									
					//--------------------------------------------------------------------------------
					// Okay here show the property sheet containing the properties and keppad mapping
					//---------------------------------------------------------------------------------

					CSubItemPage *thisPage[10];
					CKeyMapping2 KeyPage;
					CString cslabel;
					int i=0;

					CMyPropertySheet *propertSheet =new CMyPropertySheet("Sub Item Property");
					cslabel =csSelButtonText + " SubItem Property";
					propertSheet->SetTitle(cslabel); 

					KeyPage.Construct(IDD_KEYDLG,IDS_KEY);
					
					for(nsub = draggedButton->lSubItem.begin();nsub!=draggedButton->lSubItem.end();++nsub)  
					{
						thisItem =*nsub;
						thisPage[i] =new CSubItemPage;
						thisPage[i]->m_psp.pszTitle =thisItem.csName;  
						thisPage[i]->csTitle=thisItem.csName;  
						thisPage[i]->m_psp.dwFlags |= PSP_USETITLE;
						thisPage[i]->SetItemProperty(&thisItem);  
						propertSheet->AddPage(thisPage[i]); 
						i++;
					}
					propertSheet->AddPage(&KeyPage); 
				//	if(propertSheet->DoModal()==IDOK)
					propertSheet->DoModal();	
					for(int t=0;t<i;t++)
						delete thisPage[t];
					delete propertSheet;

					oLeftView->GetDocument()->UpdateAllViews(NULL);
				}
				
		}
	}
 	if(bDrag==1)  //for expanding the tree when icon is on top of tree node
	{
		SetCursor(hCross);
	}
	else if(bDrag==2)
	{
			
			POINT mPoint=mouseHook->pt;
			CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
			CModuleButton  *draggedButton=(CModuleButton  *)draggedButton->FromHandle(mouseHook->hwnd);
		 
		    mApp->m_oMainView->ScreenToClient(&mPoint);
				
			if (draggedButton->clientRect.PtInRect(mPoint) )
				return CallNextHookEx(hHook,nCode,wParam,lParam);
		  
			if(draggedButton->type ==SUBITEM)
			 {
				 ::MoveWindow(mouseHook->hwnd,mPoint.x,mPoint.y,BUTWIDTH/2,BUTHEIGHT,1);
				 sz.cx =BUTWIDTH/2;
			 }
			 else
				 ::MoveWindow(mouseHook->hwnd,mPoint.x,mPoint.y,BUTWIDTH,BUTHEIGHT,1);
			CRect rect(mPoint,sz);
			draggedButton->clientRect =rect;
			//mApp->m_oMainView->GetClientRect(&rect);
			mApp->m_oMainView->InvalidateRect(rect,TRUE);
					
	}
	return CallNextHookEx(hHook,nCode,wParam,lParam);
}




BOOL CLeftView::PreCreateWindow(CREATESTRUCT& cs) 
{
	cs.style =cs.style;
		
	return CView::PreCreateWindow(cs);
}

void CLeftView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnVScroll(nSBCode, nPos, pScrollBar);
}
 
///Function that generates the xml script 
/**
 This is a recursive function that generates the script xml that is 
 used by the new TDS Engine .

*/
void CLeftView::OnGenscript()
{
	//okay here  is the mammoth task of going thru the buttons and creating the xml
	if(m_csFileName.Compare("")==0)
	{
		MessageBox("Please Specify file name","Telescriber",MB_ICONEXCLAMATION);
		return;
	}
	CXML m_oFileXml;
	char chTemp[12];
	CModuleButton *tempBut,*tempButTo;
	CString csAttributes[15]={"ID","NAME","ID","INPUTTYPE","TIMEOUT","RETRYCOUNT","ENABLE","LRANGE","HRANGE","ISMUST","VARIABLE"};
	CString csValues[15]={"ID","NAME","INPUTTYPE","TIMEOUT","ENABLE","ISMUST"}; 
	CString csKeyPadAttr[7]={"PRESSED","ID","ACTION","SUBITEM"};
	CString csTemp;
	CModuleButton::KeyPadMapping thisMap;
	CModuleButton::SubItem thisItem;
	CString csEnabled;
	if(!m_oFileXml.Initialize())
		return;

	m_oFileXml.LoadString("<TDSA/>");  // the xml starts with this tag

	// enumerate through this list of module buttons

	for(i=mylist.begin();i!=mylist.end();++i)
	{	
	
		tempBut=(CModuleButton * )*i;
		
		if(tempBut->type ==2)//if it is a subitem
			continue;        // dont put it as a main xml node
		
		itoa(tempBut->nID,chTemp,10);
		csValues[0]=chTemp;
		csTemp=tempBut->csNodeName;
		int t =csTemp.FindOneOf("1234567890");
		if(t>0)
			csTemp.SetAt(t,0); //clean the node names for eg Login2 to Login
		csTemp.MakeUpper();
		csValues[1] =csTemp;
		m_oFileXml.CreateElement("STEP",0,(char **)(LPCTSTR)csAttributes,(char **)(LPCTSTR)csValues,2,1); 
		m_oFileXml.CreateElement("ENABLE","1",0,0,0); 
		m_oFileXml.CreateElement("LABEL",tempBut->csLabel,0,0,0); 
 		m_oFileXml.CreateElement("SUBSTEP",0,0,0,0); 
		m_oFileXml.GoToNode("SUBSTEP",1); 
		
		//-------------------------------------------------
		//now create the substeps in XML
		//-------------------------------------------------
		
	//	tempBut->lSubItem.sort(thisItem.sort_begin());
	
		for(nsub=tempBut->lSubItem.begin();nsub !=tempBut->lSubItem.end();++nsub)
		{
			thisItem = *nsub;
			m_oFileXml.CreateElement(thisItem.csName,0,0,0,0);
			m_oFileXml.GoToNode(thisItem.csName,1); 
			if(thisItem.csBegin=="1")
				m_oFileXml.CreateElement("ID","1",0,0,0); // if is first is marked
			if(thisItem.bEnabled=="YES")
				csEnabled="1";
			else
				csEnabled="0";
	
			csValues[2]="0";
			csValues[3] =thisItem.csType;
			csValues[4]=thisItem.TimeOut;
			csValues[5]="2"; 
			csValues[6]=thisItem.bPromptEnabled;
			csValues[7]="0";
			csValues[8]="0";
			csValues[9]=thisItem.PlayTillEnd;
			csValues[10]=thisItem.csVariable;
				
			m_oFileXml.CreateElement(csEnabled,"1",0,0,0); 
			m_oFileXml.CreateElement("PROMPT",thisItem.csPrompt,(char **)(LPCTSTR)csAttributes+2,(char **)(LPCTSTR)csValues+2,9,0); 
			m_oFileXml.CreateElement("NEXT",thisItem.csNext,0,0,0); 
			m_oFileXml.MoveToParentNode(1); 

		}
			m_oFileXml.MoveToParentNode(1); 
		//------------------------------------------
		//creating the key pad mapping in xml
		//------------------------------------------

		m_oFileXml.CreateElement("KEYPAD",0,0,0,0);
		m_oFileXml.GoToNode("KEYPAD",1); 
		
		for(j=tempBut->lKeyMapping.begin();j!=tempBut->lKeyMapping.end();++j)
		{
			
			thisMap =(*j);
			itoa(thisMap.KeyPressed,chTemp,10);
			csValues[0]=chTemp;
			if(thisMap.KeyPressed==STAR)
				csValues[0]="*";
			else if(thisMap.KeyPressed==POUND)
				csValues[0] ="#";
			else if(thisMap.KeyPressed==NILL)
				csValues[0] ="NILL";
			tempButTo =thisMap.NextButton;
			itoa(tempButTo->nID,chTemp,10);
			csValues[1]=chTemp;
			csValues[2] =tempButTo->csNodeName;
			csValues[2].MakeUpper(); 
		
			csValues[3] =csValues[2] ;
			if(tempButTo->type ==2) //if it is a subitem
			{
				itoa(tempBut->nID,chTemp,10);
				csValues[1]=chTemp;
				csValues[2] =tempBut->csNodeName;
				csValues[2].MakeUpper();  
				if(csValues[2]=="NEXT")
					csValues[2] ="NEXT_REPORT";
				else if (csValues[2] =="PREV")
					csValues[2] ="PREV_REPORT";
				else if (csValues[2] =="NEWSRCH")
					csValues[2] ="NEW_SEARCH";
			}
				
			if((t=csValues[2].FindOneOf("1234567890")) >0)
				csValues[2].SetAt(t,0); 	
			m_oFileXml.CreateElement("KEY",0,(char **)(LPCTSTR)csKeyPadAttr,(char **)(LPCTSTR)csValues,4,0); 
				
		}
		m_oFileXml.MoveToParentNode(1); 
		m_oFileXml.GoToRootNode(); 
					
	}
	//ADD THE PROPERTIES TAG HERE
	
	m_oFileXml.CreateElement("PROP",0,0,0,0);
	m_oFileXml.GoToNode("PROP",1); 
	CRect thisRect;
	CString csAttProp[4]={"ID","T","L"};
	for(i=mylist.begin();i!=mylist.end();++i)
	{	
		tempBut=(CModuleButton * )*i;
		thisRect =tempBut->clientRect ;
		if(tempBut->type ==2)//if it is a subitem
		{
			csValues[0]=tempBut->csNodeName;
			csValues[0].MakeUpper();  
		}
		else
			csValues[0].Format("%d",tempBut->nID); 
		csValues[1].Format("%d",thisRect.top);
		csValues[2].Format("%d",thisRect.left);
		m_oFileXml.CreateElement("BUT",0,(char **)(LPCTSTR)csAttProp,(char **)(LPCTSTR)csValues,3,0); 
	}
	
		

	m_oFileXml.Save(m_csFileName); 
}


void CLeftView::LoadXML(int nId)
{
	CRect rect,rc;
	CXML mLoadedXml;
	
	static CMyIVR1App * thisApp ;
	static bool bfirst=0;
	static CString csSubItem;
	static int nSub=1;
	CString csQuery,csName;
	CModuleButton *butto; 
	bool bres;
	int nLevel=3;
	
	mLoadedXml.Initialize();
	if(!mLoadedXml.LoadFile(m_csFileName))
		return;
	
	if(!bfirst)
	{
		thisApp =(CMyIVR1App * )AfxGetApp();
	    bfirst=1;	
		mLoadedXml.GoToNode("TDSA",0);
		nId=0;
	}
	else
	{
		//first search in the list to see if button is already created or bail out
		if(nSub!=0)
		for(i=mylist.begin();i!=mylist.end();++i)
		{
			butto =(CModuleButton *)(*i);
			if(butto->nID ==nId)
				return;
		}
	}


		CString csButName;
		CString csLabel;
		csQuery.Format("TDSA/STEP[@ID=%c%d%c]",'"',nId ,'"');
		bres =mLoadedXml.GoToNode(csQuery);
		if( (nSub!=0) && (bres==0) )
			return;
		
		if(nSub!=0) // if it is not a subitem
		{
			bres=mLoadedXml.GetAttributeValue("NAME",csName); 
			csButName =csName;
			mLoadedXml.GoToNode("LABEL",1); 
			mLoadedXml.GetNodeText(csLabel);
		}
		else
		{
			csButName =csSubItem;
			csLabel=csSubItem;
		}
		
		int ngo=1;
		int doitagain=1;
		//------------------------------------------------
		// checking the selected button name in the selected list if so rename it 
		//-------------------------------------------------
		while(doitagain)
		{
			char sztemp[20];
			doitagain=0;
			for(sellist=selnodelist.begin();sellist!=selnodelist.end();++sellist)  
			{
				if(!csButName.CompareNoCase(*sellist))
				{
					if(csButName=="INSERT" || csButName=="FORWARD" || csButName=="REWIND" ||
						 csButName=="APPEND" || csButName=="OVRWRITE" || csButName=="PLAY" ||
						 csButName=="PAUSE" || csButName=="NEXT" || csButName=="PREV" ||
						 csButName=="NEWSRCH" || csButName=="TOBEGIN")
					{
						return; //we do not need duplicate subitems
					}
					itoa(ngo,sztemp,10);
					csButName.Insert(csButName.GetLength(),sztemp);  
					ngo++;
					doitagain=1;
				}
				doitagain=0;
			}
		}
	
		CModuleButton *temp =new CModuleButton;
	
		if(nSub!=0)
		{
			csQuery.Format("TDSA/PROP/BUT[@ID=\"%d\"]",nId);
			temp->type =1;
		}
		else
		{
		    csQuery.Format("TDSA/PROP/BUT[@ID=\"%s\"]",csSubItem);
			temp->type =SUBITEM;
		}
		bres =mLoadedXml.GoToNode(csQuery);
		bres=mLoadedXml.GetAttributeValue("T",csQuery); 
		rc.top=atoi(csQuery);
		bres=mLoadedXml.GetAttributeValue("L",csQuery); 
		rc.left=atoi(csQuery);
		rc.bottom =rc.top+BUTHEIGHT;
		
		if(nSub!=0)
			rc.right=rc.left+BUTWIDTH;
		else
			rc.right=rc.left+BUTWIDTH/2;
	
		csLabel.MakeLower();
		char ch =csLabel.GetAt(0); 
		ch =toupper(ch); 
		csLabel.SetAt(0,ch); 
		bres =temp->Create(csLabel,WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON|BS_FLAT,rc, thisApp->m_oMainView,mylist.size()+1);
		csButName.MakeUpper();
		temp->csNodeName =csButName;
		temp->csLabel = csLabel;
		temp->nID =nId;
		
		if(!bres)	
			return;
		
		temp->clientRect =rc;
							
		//--------------------------------------------------------
		//Insert the address of the newly created CModuleButton to the list mylist
		//--------------------------------------------------------
		
		mylist.insert(mylist.end(),temp);
		selnodelist.insert(selnodelist.end(),csButName);  

		csQuery.Format("TDSA/STEP[@ID=%c%d%c]",'"',nId ,'"');
		bres =mLoadedXml.GoToNode(csQuery);

		CModuleButton::SubItem  thisItem; 

		bres =mLoadedXml.GetNodeText("ENABLE",csQuery,1); 
		thisItem.bEnabled =csQuery;

		
		if(temp->type ==1)
		{
			//-------------------------------------------------------------
			// Adding the subitems
			//-------------------------------------------------------------

			bres =mLoadedXml.GoToNode("SUBSTEP",1);
			bres =mLoadedXml.GetNodesList("SUBSTEP",1);
			bres =mLoadedXml.NextChildNode();
			CString csTemp;
			char Attribute[5][20] ={"INPUTTYPE","TIMEOUT","ENABLE","ISMUST","VARIABLE"};
			CString csValue[5];
			int begin=0;
		

			do{
				mLoadedXml.GetCurrentNodeName(csTemp);//this is the node name
				thisItem.csName =csTemp;
				bres =mLoadedXml.GetNodeText("ID",csTemp,1);
				if(bres)
					thisItem.csBegin="1";
				else
					thisItem.csBegin="0";
				
				bres =mLoadedXml.GetNodeText("PROMPT",csTemp,1); //this is the node name
				thisItem.csPrompt =csTemp;
				
				begin++;
				
				for(int t=0;t<5;t++)
				   mLoadedXml.GetAttributeValue("PROMPT",Attribute[t],csValue[t],TRUE); 
				
				thisItem.csType			= csValue[0];
				thisItem.TimeOut		= csValue[1];
				thisItem.bPromptEnabled = csValue[2];
				thisItem.PlayTillEnd	= csValue[3];
				thisItem.csVariable		= csValue[4];
				
				bres =mLoadedXml.GetNodeText("NEXT",csTemp,1); //this is the node name
				thisItem.csNext =csTemp;
				
		
			    //---------------------------------------
				//now add the subitem to the sub item list
				//---------------------------------------
				temp->lSubItem.insert(temp->lSubItem.end(),thisItem);
				   
			}while(mLoadedXml.NextSibling()) ;
			bres=mLoadedXml.MoveToParentNode(2);
		
			//-----------------------------------------------------
			// Now recurse through the keypad mapping
			//-----------------------------------------------------
			
			bres =mLoadedXml.GoToNode("KEYPAD/KEY",1);
			bres =mLoadedXml.GetCurrentNodeName(csTemp);
			char csAttribute[5][20]={"PRESSED","ID","ACTION","SUBITEM"};
			CString csValues[5];
			CModuleButton::KeyPadMapping thisMap;   
			do{
				for(int t=0;t<4;t++)
				{
					bres =mLoadedXml.GetAttributeValue(csAttribute[t],csValues[t]); 
					if(bres==0)
						break;
				}
				if(bres==0)
				  break;
				nId=atoi(csValues[1]);
				csValues[3].MakeUpper(); 
				 if(csValues[3]=="INSERT" || csValues[3]=="FORWARD" || csValues[3]=="REWIND" ||
					 csValues[3]=="APPEND" || csValues[3]=="OVRWRITE" || csValues[3]=="PLAY" ||
					 csValues[3]=="PAUSE" || csValues[3]=="NEXT" || csValues[3]=="PREV" ||
					 csValues[3]=="NEWSRCH" || csValues[3]=="TOBEGIN")
				 {	
					 csSubItem=csValues[3];
					  nSub=0;
				 }
				 else
					 nSub=1;
				
				 nLevel=2;
				 LoadXML(nId);
		
				//--------------------------------------------------------
				// Inserting key pad mapping to keypad list
				//---------------------------------------------------------
							
				//first search in the list to see the correct button
				for(i=mylist.begin();i!=mylist.end();++i)
				{
					butto =(CModuleButton *)(*i);
					  if(nSub!=0)
					 {
						 if(butto->nID ==nId)
							break;
					  }
					  else
					  {		  if(butto->csNodeName ==csSubItem)
							break;
					  }
				}
				int nKey=atoi(csValues[0]);
				if(csValues[0]=="*")
					nKey=STAR;
				else if(csValues[0]=="#")
					nKey =POUND;
				else if(csValues[0]=="NILL")
					nKey =NILL;
				thisMap.KeyPressed=nKey;
				thisMap.NextButton=butto;
				temp->lKeyMapping.insert(temp->lKeyMapping.end(),thisMap);

			}while(mLoadedXml.NextSibling()) ;

		//going through the main nodes
		nSub=1;
		mLoadedXml.MoveToParentNode(nLevel); // 3 no key  and 2 for key         
		mLoadedXml.GetCurrentNodeName(csName);
		if(mLoadedXml.NextSibling() && csName !="#document")
		{
			mLoadedXml.GetAttributeValue("ID",csTemp); 
			int nIDOut =atoi(csTemp);
			LoadXML(nIDOut); 
		}

	}

	return;
}

void CLeftView::SetXMLFile(CString &cs)
{
	m_csFileName=cs;
}

void CLeftView::DeleteButton()
{
	//search in the main list for the button with the name
	//search through the sub pads for the name
	
	CModuleButton * thisButton; 
	CModuleButton * eraseButton=0; 
	CModuleButton::KeyPadMapping thisMap; 
	bool flag=0;
	CString csTemp =csDragLabel;
	csDragLabel.MakeUpper(); 

	for(sellist =selnodelist.begin();sellist!=selnodelist.end();++sellist)
	{
		if(csDragLabel.CompareNoCase(*sellist)==0 )
		{
			selnodelist.erase(sellist); 
			break;
		}
	}	
	
	for(i = mylist.begin();i!=mylist.end();++i)
	{
	
		thisButton =(CModuleButton *)(*i);
		if(csDragLabel.CompareNoCase(thisButton->csLabel)==0  )
		{
			if(thisButton->nID ==0) 
				flag=1;
			i=mylist.erase(i);
			i--;
			eraseButton =thisButton;
			
		}
		for(j=thisButton->lKeyMapping.begin();j !=thisButton->lKeyMapping.end();++j)
		{
			thisMap=(*j);
			if(csDragLabel.CompareNoCase(thisMap.NextButton->csLabel)==0  )
				j=thisButton->lKeyMapping.erase(j);
		}
	
	}
	if(eraseButton!=0)
			delete eraseButton;
	if(flag==1)
	{
		for(i = mylist.begin();i!=mylist.end();++i)
		{
			thisButton =(CModuleButton *)(*i);
			thisButton->nID--;  
		}
	}
	csDragLabel=csTemp;

}
void CLeftView::OnLabelButton(CString csLabel) 
{
	CModuleButton * thisButton; 
	
	/*for(sellist =selnodelist.begin();sellist!=selnodelist.end();++sellist)
	{
		if(csDragLabel.CompareNoCase(*sellist)==0 )
		{
			selnodelist.erase(sellist); 
			selnodelist.insert(sellist++,csLabel);
			break;
		}
	}*/

	
	for(i = mylist.begin();i!=mylist.end();++i)
	{
	
		thisButton =(CModuleButton *)(*i);
		if(csDragLabel.CompareNoCase(thisButton->csLabel)==0  )
		{
			if(thisButton->type == SUBITEM)
				return;
			thisButton->csLabel = csLabel;
			thisButton->SetWindowText(csLabel); 
			selnodelist.insert(selnodelist.end(),csLabel);
			break;
			
		}
	
	}


 
}

CString CLeftView::GetDragLabel()
{
	return csDragLabel;
}
