#if !defined(AFX_LEFTBUTTON_H__7E8668F0_71DE_4C66_A07B_F45993ED3197__INCLUDED_)
#define AFX_LEFTBUTTON_H__7E8668F0_71DE_4C66_A07B_F45993ED3197__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeftButton window

class CLeftButton : public CButton
{
// Construction
public:
	CLeftButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftButton)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	int type;
	virtual ~CLeftButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CLeftButton)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTBUTTON_H__7E8668F0_71DE_4C66_A07B_F45993ED3197__INCLUDED_)
