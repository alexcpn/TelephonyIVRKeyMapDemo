// MyIVR1View.cpp : implementation of the CMyIVR1View class
//

#include "stdafx.h"
#include "MyIVR1.h"
#include "MyIVR1Doc.h"
#include "ModuleButton.h"
#include "SubItemPage.h"

#define IDSKEY "HEEL"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern list<CButton *>::iterator i;
extern 	list<CModuleButton::KeyPadMapping >::iterator j;


/////////////////////////////////////////////////////////////////////////////
// CMyIVR1View

IMPLEMENT_DYNCREATE(CMyIVR1View, CView)

BEGIN_MESSAGE_MAP(CMyIVR1View, CView)
	//{{AFX_MSG_MAP(CMyIVR1View)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyIVR1View construction/destruction

CMyIVR1View::CMyIVR1View()
{
	// TODO: add construction code here
		
	bluePen.CreatePen(PS_SOLID,0,RGB(48,48,197));
	redPen.CreatePen(PS_SOLID,0,RGB(108,183,77));
	greenPen.CreatePen(PS_SOLID,0,RGB(190,158,190));
	//blackPen.CreatePen(PS_SOLID,0,RGB(220,118,156));
	blackPen.CreatePen(PS_SOLID,0,RGB(27,186,179));
	//29,203,194
	blueBrush.CreateSolidBrush(RGB(176,224,253));
	redBrush.CreateSolidBrush(RGB(152,241,185));
	greenBrush.CreateSolidBrush(RGB(245,183,247));
	//blackBrush.CreateSolidBrush(RGB(248,182,220));
	blackBrush.CreateSolidBrush(RGB(153,240,238));
	//153,240,238

	PenList *tempPenList;

	thisPenList = new PenList;
	topOfList =thisPenList;
	
	thisPenList->thisPen =&bluePen;
	thisPenList->thisBrush =&blueBrush;

	tempPenList = new PenList;
	tempPenList->thisPen =&greenPen;
	tempPenList->thisBrush =&greenBrush;

	thisPenList->nextPenNode  =tempPenList;
	thisPenList=tempPenList;
	
	tempPenList = new PenList;
	tempPenList->thisPen =&redPen;
	tempPenList->thisBrush =&redBrush;

	thisPenList->nextPenNode  =tempPenList;
	thisPenList=tempPenList;

	tempPenList = new PenList;
	tempPenList->thisPen =&blackPen;
	tempPenList->thisBrush =&blackBrush;
	
	thisPenList->nextPenNode  =tempPenList;
	thisPenList=tempPenList;
	thisPenList->nextPenNode  =topOfList;


}

CMyIVR1View::~CMyIVR1View()
{
	PenList *tempPenList;
	thisPenList =topOfList;
	thisPenList =thisPenList->nextPenNode;
	while(thisPenList->nextPenNode!=topOfList)
	{
		tempPenList =thisPenList;
		thisPenList =thisPenList->nextPenNode;
		delete tempPenList;

	}
	delete thisPenList;
	delete topOfList;
}

BOOL CMyIVR1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
		cs.style =cs.style | WS_VSCROLL  | WS_HSCROLL;
		

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyIVR1View drawing

void CMyIVR1View::OnDraw(CDC* pDC)
{
	CMyIVR1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	// this is going to be a resource intensive task
	//---------adding an offscreen dc
	
	CRect rcPaint;  
	 CDC pDC2;
	 GetClientRect((LPRECT)rcPaint);
     pDC2.CreateCompatibleDC(pDC );
	 CBitmap bmp;
     bmp.CreateCompatibleBitmap( pDC, rcPaint.Width(), rcPaint.Height() );
	CBitmap *pOld = pDC2.SelectObject( &bmp );
	CBrush  mBrush;
	mBrush.CreateSolidBrush(GetSysColor(COLOR_WINDOW));
    pDC2.FillRect((LPRECT)rcPaint,&mBrush);
       


//---------end addding an ofscreen dc


	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	CLeftView *leftView =mApp->m_oLeftView;
	CModuleButton * tempBut;
	CModuleButton * tempButNew;
	CModuleButton::KeyPadMapping thismap;
	CString csTemp1;
	CRect rc1,rc2;

	CBrush blackBrush;
	
	CBrush *oldBrush,*pblackBrush;
	//blackBrush.CreateSolidBrush(RGB(0,255,125)); 
	blackBrush.CreateSolidBrush(RGB(151,251,83)); 
	oldBrush=pDC2.SelectObject(&blackBrush);

	

	thisPenList=topOfList;
	//pDC2.SelectObject(thisPenList->thisPen );
	//get the correct button class for the selected object

	for(i=leftView->mylist.begin();i!=leftView->mylist.end();++i)
	{	
		
		pDC2.SelectObject(thisPenList->thisPen );
		//thisPenList = thisPenList->nextPenNode;
		
		tempBut=(CModuleButton * )*i;
		rc1=tempBut->clientRect; 
		for(j=tempBut->lKeyMapping.begin();j!=tempBut->lKeyMapping.end();++j)
		{		
			thismap =(*j);
			csTemp1.Format("%d",thismap.KeyPressed);
			if(thismap.KeyPressed==STAR)
					csTemp1="*";
			else if(thismap.KeyPressed==POUND)
				csTemp1 ="#";
			else if(thismap.KeyPressed==NILL)
				csTemp1 ="N";
			tempButNew =thismap.NextButton;
			rc2=tempButNew->clientRect;
			pDC2.MoveTo((rc2.left +rc2.right)/2,(rc2.top +rc2.bottom)/2); 
			pDC2.LineTo((rc2.left +rc2.right)/2,(rc1.top +rc1.bottom)/2); 
			pDC2.LineTo((rc1.left +rc1.right)/2,(rc1.top +rc1.bottom)/2); 
			
			CPoint pts[3];

			if(rc1.top <rc2.top )
			{
				pts[0].x = (rc2.left+rc2.right)/2 -8 ;
				pts[0].y = rc2.top-15;
				pts[1].x = (rc2.left+rc2.right)/2 +8 ;
				pts[1].y = rc2.top-15;
				pts[2].x = (rc2.left+rc2.right)/2  ;
				pts[2].y = rc2.top;
				pblackBrush =pDC2.SelectObject(oldBrush); 
				pDC2.Ellipse(pts[2].x-9,pts[2].y-42,pts[2].x-6+20,pts[2].y-42+20);
				//oldBrush =pDC2.SelectObject(pblackBrush); 
				oldBrush =pDC2.SelectObject(thisPenList->thisBrush );
				pDC2.TextOut(pts[2].x-3,pts[2].y-40,csTemp1);
			}
			else
			{
				pts[0].x = (rc2.left+rc2.right)/2 -8 ;
				pts[0].y = rc2.bottom +15;
				pts[1].x = (rc2.left+rc2.right)/2 +8 ;
				pts[1].y = rc2.bottom +15;
				pts[2].x = (rc2.left+rc2.right)/2  ;
				pts[2].y = rc2.bottom;
				pblackBrush =pDC2.SelectObject(oldBrush); 
				pDC2.Ellipse(pts[2].x-9,pts[2].y+38,pts[2].x-6+20,pts[2].y+38   +20);
				//oldBrush =pDC2.SelectObject(pblackBrush); 
				oldBrush =pDC2.SelectObject(thisPenList->thisBrush );
				
				pDC2.TextOut(pts[2].x-3,pts[2].y+40,csTemp1);
			}
			pDC2.Polygon(pts, 3);
         
			
		}
		thisPenList = thisPenList->nextPenNode;
	}	

	//---------added for off screen bitmap-------------
	
	pDC->BitBlt(rcPaint.left, rcPaint.top,rcPaint.right-rcPaint.left, rcPaint.bottom-rcPaint.top,
           &pDC2,0, 0,SRCCOPY);

    // Done with off-screen bitmap and DC.
    
	pDC2.SelectObject(&bmp);
    pDC2.DeleteDC();

	//---------end added for off screen bitmap-------------


}

/////////////////////////////////////////////////////////////////////////////
// CMyIVR1View printing

BOOL CMyIVR1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyIVR1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyIVR1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyIVR1View diagnostics

#ifdef _DEBUG
void CMyIVR1View::AssertValid() const
{
	CView::AssertValid();
}

void CMyIVR1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyIVR1Doc* CMyIVR1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyIVR1Doc)));
	return (CMyIVR1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyIVR1View message handlers

int CMyIVR1View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	mApp->m_oMainView =this;

	
	return 0;
}
 


BOOL CMyIVR1View::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return 1;//CView::OnEraseBkgnd(pDC);
}

void CMyIVR1View::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	
}



bool CMyIVR1View::LoadXML()
{
	return TRUE;
}

void CMyIVR1View::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CModuleButton *temp;
	CLeftView* pView;
	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	pView =mApp->m_oLeftView;	
	int t=0;
	int y = GetScrollPos(SB_HORZ);


	switch(nSBCode)
	{
		case SB_PAGELEFT:   
			t=50;
			break;
		case SB_PAGERIGHT:   
			t=-50;
			break;
		case SB_LINELEFT:
			if(y==0)
				break;
			t=10;
			break;
		case SB_LINERIGHT:
			t=-10;
			break;
		case SB_THUMBTRACK:   
			if(nPos<y)
				t=10 ;
			else
				t=-10;
			break;

		case SB_THUMBPOSITION: 
			//t = nPos;    
			break;


	}
	ScrollWindow(t,0,NULL,NULL );
	SetScrollPos(SB_HORZ,y +(-t/10),TRUE );
	
	for(i =mApp->m_oLeftView->mylist.begin();i !=mApp->m_oLeftView->mylist.end(); ++i)
	{
		temp =(CModuleButton * )*i;
		temp->clientRect.left+=t;
		temp->clientRect.right+=t;
		
	}
		
	
	CView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CMyIVR1View::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CModuleButton *temp;
	CLeftView* pView;
	CMyIVR1App * mApp = (CMyIVR1App *)AfxGetApp();
	pView =mApp->m_oLeftView;	
	int t=0;
	int y = GetScrollPos(SB_VERT);

	switch(nSBCode)
	{
		case SB_PAGEUP:   
			t=50;
			break;
		case SB_PAGEDOWN:   
			t=-50;
			break;
		case SB_LINEUP: 
			if(y==0)
				break;
			t=10;
			break;
		case SB_LINEDOWN:
			t=-10;
			break;
		case SB_THUMBTRACK:   
			if(nPos<y)
				t=10 ;
			else
				t=-10;
			break;
	}
	ScrollWindow(0,t,NULL,NULL );
	SetScrollPos(SB_VERT,y+(-t/10),TRUE );
	
	for(i =mApp->m_oLeftView->mylist.begin();i !=mApp->m_oLeftView->mylist.end(); ++i)
	{
		temp =(CModuleButton * )*i;
		temp->clientRect.top+=t;
		temp->clientRect.bottom+=t;
		
	}
	CView::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CMyIVR1View::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
//	pDC->SetMapMode(MM_LOENGLISH); 	
	OnDraw(pDC);
//	CView::OnPrint(pDC, pInfo);
}

void CMyIVR1View::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CView::OnPrepareDC(pDC, pInfo);

   if(pDC->IsPrinting()) // Is the DC a printer DC.
   {
      CRect rect;
      GetClientRect (&rect);

         int oldMapMode = pDC->SetMapMode(MM_ANISOTROPIC);
		CSize ptOldWinExt = pDC->SetWindowExt(1000, 1000);
		ASSERT( ptOldWinExt.cx != 0 && ptOldWinExt.cy != 0 );
		CSize ptOldViewportExt = pDC->SetViewportExt(7000,10000);
	/*		rect.Width()*2,
		   -rect.Height()*2);
		ASSERT( ptOldViewportExt.cx != 0 && ptOldViewportExt.cy != 0 );
		CPoint ptOldOrigin = pDC->SetViewportOrg(0,0);//rect.Width()/2,
		   rect.Height()/2);

	  */
   }

}
