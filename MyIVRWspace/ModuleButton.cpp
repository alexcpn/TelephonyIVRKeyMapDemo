// ModuleButton.cpp : implementation file
//

#include "stdafx.h"
#include "ModuleButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define ITEM 1
list<CModuleButton::KeyPadMapping>::iterator j;
list<CModuleButton::SubItem>::iterator nsub;

/////////////////////////////////////////////////////////////////////////////
// CModuleButton

CModuleButton::CModuleButton()
{
	type=ITEM;
}

CModuleButton::~CModuleButton()
{
}


BEGIN_MESSAGE_MAP(CModuleButton, CButton)
	//{{AFX_MSG_MAP(CModuleButton)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModuleButton message handlers

void CModuleButton::Serialize(CArchive& ar) 
{
	if (ar.IsStoring())
	{	// storing code
	}
	else
	{	// loading code
	}
}

BOOL CModuleButton::IsOfTypeModuleButton()
{
	return TRUE;
}
