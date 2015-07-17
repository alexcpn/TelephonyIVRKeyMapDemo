// LeftButton.cpp : implementation file
//

#include "stdafx.h"
#include "LeftButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftButton

CLeftButton::CLeftButton()
{
	type=1;
}

CLeftButton::~CLeftButton()
{
}


BEGIN_MESSAGE_MAP(CLeftButton, CButton)
	//{{AFX_MSG_MAP(CLeftButton)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftButton message handlers

BOOL CLeftButton::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class

	return CButton::PreCreateWindow(cs);
}
