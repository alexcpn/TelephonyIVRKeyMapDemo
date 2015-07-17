#if !defined(AFX_LEFTVIEW_H__175A10CC_22FB_4DD1_9FD9_F4452DF165D1__INCLUDED_)
#define AFX_LEFTVIEW_H__175A10CC_22FB_4DD1_9FD9_F4452DF165D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftView.h : header file

#include "LeftButton.h"
#include <list>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// CLeftView view

class CLeftView : public CView
{
protected:
	CLeftView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLeftView)
	
// Attributes
public:
	static CLeftView * oLeftView;
	static list<CButton *> mylist;
	static list<CString> selnodelist;
	static CString csSelButtonText;

// Operations
public:
	static LRESULT CALLBACK MouseProc(int nCode,WPARAM wParam,LPARAM lParam);
	CMyIVR1Doc* GetDocument();
	CString GetDragLabel();
	void DeleteButton();
	void OnLabelButton(CString csLabel) ;
	void SetXMLFile(CString &cs);
	void LoadXML(int nId);
	void OnGenscript();

private:
	static int bDrag;
	static HCURSOR hCross;
	static HHOOK hHook;
	static CString csDragLabel;
	static int nButtonIndex;
	static CButton * arrButton[50];
	CString csClassNames[50];
	CString m_csFileName;
	CLeftButton *myButton1[50];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftView)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLeftView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CLeftView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTVIEW_H__175A10CC_22FB_4DD1_9FD9_F4452DF165D1__INCLUDED_)
