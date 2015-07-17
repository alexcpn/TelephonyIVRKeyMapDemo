// MyPropertySheet.cpp : implementation file
//

#include "stdafx.h"
//#include "MyIVR1.h"
#include "MyPropertySheet.h"
#include "SubItemPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyPropertySheet

IMPLEMENT_DYNAMIC(CMyPropertySheet, CPropertySheet)

CMyPropertySheet::CMyPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CMyPropertySheet::CMyPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CMyPropertySheet::~CMyPropertySheet()
{
}


BEGIN_MESSAGE_MAP(CMyPropertySheet, CPropertySheet)
	//{{AFX_MSG_MAP(CMyPropertySheet)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyPropertySheet message handlers

int CMyPropertySheet::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CPropertySheet::DoModal();
}

void CMyPropertySheet::OnClose() 
{
	
	CPropertySheet::OnClose();
}

void CMyPropertySheet::OnDestroy() 
{

	CPropertySheet::OnDestroy();
	
}

BOOL CMyPropertySheet::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	if(wParam==IDOK)
	{
		CSubItemPage * thisPage; 
		int nPageCount =GetPageCount();
		for(int i =0; i<nPageCount;i++)
		{
			thisPage =(CSubItemPage *)GetPage(i); 
			if(thisPage->m_hWnd !=NULL)
			thisPage->OnSet();
		}
	}

	
	return CPropertySheet::OnCommand(wParam, lParam);
}

