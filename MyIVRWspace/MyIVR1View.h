// MyIVR1View.h : interface of the CMyIVR1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYIVR1VIEW_H__07363C89_C328_4F87_9F2A_59FD51A21270__INCLUDED_)
#define AFX_MYIVR1VIEW_H__07363C89_C328_4F87_9F2A_59FD51A21270__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyIVR1Doc.h"

typedef struct myPen PenList;

typedef struct myPen
{
		CPen * thisPen;
		CBrush * thisBrush;
		PenList * nextPenNode;
}PenList;


class CMyIVR1View : public CView
{
private:
	CPen   bluePen,redPen,blackPen,greenPen;
	CBrush   blueBrush,redBrush,blackBrush,greenBrush;
	PenList *thisPenList,*topOfList;

protected: // create from serialization only
	CMyIVR1View();
	DECLARE_DYNCREATE(CMyIVR1View)

// Attributes
public:
	CMyIVR1Doc* GetDocument();
	

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyIVR1View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool LoadXML();
	CScrollBar m_ScrollBar;
	virtual ~CMyIVR1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyIVR1View)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyIVR1View.cpp
inline CMyIVR1Doc* CMyIVR1View::GetDocument()
   { return (CMyIVR1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYIVR1VIEW_H__07363C89_C328_4F87_9F2A_59FD51A21270__INCLUDED_)
