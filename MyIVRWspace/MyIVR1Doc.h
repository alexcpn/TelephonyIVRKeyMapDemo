// MyIVR1Doc.h : interface of the CMyIVR1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYIVR1DOC_H__07428437_5E21_439B_960E_76A4CC4C66F5__INCLUDED_)
#define AFX_MYIVR1DOC_H__07428437_5E21_439B_960E_76A4CC4C66F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyIVR1Doc : public CDocument
{
protected: // create from serialization only
	CMyIVR1Doc();
	DECLARE_DYNCREATE(CMyIVR1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyIVR1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyIVR1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	CString cstest;
	//{{AFX_MSG(CMyIVR1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYIVR1DOC_H__07428437_5E21_439B_960E_76A4CC4C66F5__INCLUDED_)
