// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MyIVR1.h"
#include "MainFrm.h"
#include "LabelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern list<CButton *>::iterator i;

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_ACTIVATE()
	ON_BN_CLICKED(IDC_GENSCRIPT, OnGenscript)
	ON_BN_CLICKED(IDC_LABEL, OnLabelButton)
	ON_BN_CLICKED(IDC_LOADXML, OnLoadxml)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	if (!m_wndDlgBar.Create(this, IDR_MAINFRAME, 
		CBRS_ALIGN_TOP, AFX_IDW_DIALOGBAR))
	{
		TRACE0("Failed to create dialogbar\n");
		return -1;		// fail to create
	}

	if (!m_wndReBar.Create(this) ||
		!m_wndReBar.AddBar(&m_wndToolBar) ||
		!m_wndReBar.AddBar(&m_wndDlgBar))
	{
		TRACE0("Failed to create rebar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Remove this if you don't want tool tips
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext *pContext)
{
	// create a splitter with 1 row, 2 columns
	if (!m_oSplitterWnd.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to CreateStaticSplitter\n");
		return FALSE;
	}

	// add the first splitter pane - the default view in column 0
	if (!m_oSplitterWnd.CreateView(0, 0, //115 40 137
		RUNTIME_CLASS(CLeftView), CSize(120 ,40), pContext))
	{
		TRACE0("Failed to create first pane\n");
		return FALSE;
	}

	// add the second splitter pane - an input view in column 1
	if (!m_oSplitterWnd.CreateView(0, 1,
		RUNTIME_CLASS(CMyIVR1View), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create second pane\n");
		return FALSE;
	}

	// activate the input view
	SetActiveView((CView*)m_oSplitterWnd.GetPane(0,1));

	return TRUE;

}

BOOL CMainFrame::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CMainFrame::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CFrameWnd::OnActivate(nState, pWndOther, bMinimized);
}


void CMainFrame::OnBproperties() 
{
	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	CMyIVR1View *pView =(CMyIVR1View *)mApp->m_oLeftView;	
	pView->LoadXML();; 
	
}

void CMainFrame::OnGenscript() 
{

	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	CLeftView *pView =(CLeftView *)mApp->m_oLeftView;
	CFileDialog fileDialog(FALSE, NULL,NULL,
         OFN_HIDEREADONLY , "xml files(*.xml)|*.xml||",NULL); 
	CString csTemp;
	int rt =0;
	
		if (fileDialog.DoModal() == IDOK)
		{
			csTemp =fileDialog.GetPathName();

			rt= csTemp.ReverseFind('.'); 
			if(rt<0)
			{
				rt =csTemp.GetLength(); 
			}
			else
				csTemp.Delete(rt,csTemp.GetLength()-rt); 
			csTemp.Insert(rt,".xml");
				 
			pView->SetXMLFile(csTemp); 
			pView->OnGenscript(); 
		
		}

	 
}

void CMainFrame::OnLoadxml() 
{
    CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	CLeftView *pView =(CLeftView *)mApp->m_oLeftView;	
	CFileDialog fileDialog(TRUE, NULL,NULL,
         OFN_HIDEREADONLY , "xml files(*.xml)|*.xml||",NULL); 
	
	 if (fileDialog.DoModal() == IDOK)
         pView->SetXMLFile(fileDialog.GetPathName()); 
	 for(i=pView->mylist.begin();i!=pView->mylist.end();++i)
	 delete *i;
	pView->mylist.clear();
	pView->selnodelist.clear();
	pView->LoadXML(0); 
	mApp->m_oMainView->Invalidate(TRUE);  

}

void CMainFrame::OnFileNew() 
{
	CString csTemp= "";
	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	CLeftView *pView =(CLeftView *)mApp->m_oLeftView;
	for(i=pView->mylist.begin();i!=pView->mylist.end();++i)
	 delete *i;
		pView->mylist.clear();
		pView->selnodelist.clear();
		pView->SetXMLFile(csTemp); 
	mApp->m_oMainView->Invalidate(TRUE); 
	
}

void CMainFrame::OnFileOpen() 
{
	OnLoadxml();
	
}


BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	if(wParam==ID_FILE_SAVE_AS)
	{
		OnGenscript();
			return TRUE;
	}
	if(wParam==ID_FILE_SAVE )
	{
		OnGenscript();
			return TRUE;

	}	
	return CFrameWnd::OnCommand(wParam, lParam);
}

void CMainFrame::OnEditCut() 
{
	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	CLeftView *pView =(CLeftView *)mApp->m_oLeftView;
	pView->DeleteButton(); 
	mApp->m_oMainView->Invalidate(TRUE); 
	
	
}
void CMainFrame::OnLabelButton() 
{
	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	CLeftView *pLeftView =(CLeftView *)mApp->m_oLeftView;
	CMyIVR1View *pView =(CMyIVR1View *)mApp->m_oMainView;
	CLabelDlg myDialog;
	
	myDialog.m_CLabel =pLeftView->GetDragLabel();
	myDialog.m_CLabel.MakeLower();
	char ch= myDialog.m_CLabel.GetAt(0);
	ch = toupper(ch);
	myDialog.m_CLabel.SetAt(0,ch);
	myDialog.DoModal();
	pLeftView->OnLabelButton(myDialog.m_CLabel); 

}
