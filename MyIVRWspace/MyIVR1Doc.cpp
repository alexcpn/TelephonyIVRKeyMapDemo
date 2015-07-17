// MyIVR1Doc.cpp : implementation of the CMyIVR1Doc class
//

#include "stdafx.h"
#include "MyIVR1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyIVR1Doc

IMPLEMENT_DYNCREATE(CMyIVR1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMyIVR1Doc, CDocument)
	//{{AFX_MSG_MAP(CMyIVR1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyIVR1Doc construction/destruction

CMyIVR1Doc::CMyIVR1Doc()
{
	// TODO: add one-time construction code here
	cstest="Hello";

}

CMyIVR1Doc::~CMyIVR1Doc()
{
}

BOOL CMyIVR1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyIVR1Doc serialization

void CMyIVR1Doc::Serialize(CArchive& ar)
{
	//CMyIVR1App *thisApp =(CMyIVR1App * )AfxGetApp();
	// thisApp->m_oLeftView->mylist; 
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar <<  cstest;
	}
	else
	{
		// TODO: add loading code here
		ar >>  cstest;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyIVR1Doc diagnostics

#ifdef _DEBUG
void CMyIVR1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyIVR1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyIVR1Doc commands
