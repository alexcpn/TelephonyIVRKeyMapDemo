// MyIVR1.h : main header file for the MYIVR1 application
//

#if !defined(AFX_MYIVR1_H__96DE0D53_E576_4BF6_8025_97E3F71A3FC2__INCLUDED_)
#define AFX_MYIVR1_H__96DE0D53_E576_4BF6_8025_97E3F71A3FC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "MyIVR1View.h"
#include "resource.h"
#include "LeftView.h"
#include "xml.h"

/////////////////////////////////////////////////////////////////////////////
// CMyIVR1App:
// See MyIVR1.cpp for the implementation of this class
//

class CMyIVR1App : public CWinApp
{
public:
	CMyIVR1View * m_oMainView;
	CLeftView * m_oLeftView;
	CXML mScriptXML;
	CMyIVR1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyIVR1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyIVR1App)
	afx_msg void OnAppAbout();
	afx_msg void OnFileSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYIVR1_H__96DE0D53_E576_4BF6_8025_97E3F71A3FC2__INCLUDED_)
