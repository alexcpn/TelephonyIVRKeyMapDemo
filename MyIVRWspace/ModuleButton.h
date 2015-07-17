#if !defined(AFX_MODULEBUTTON_H__30753996_15D5_4B5C_8B80_1D22942468A5__INCLUDED_)
#define AFX_MODULEBUTTON_H__30753996_15D5_4B5C_8B80_1D22942468A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModuleButton.h : header file
//
#include <list>
using namespace std;
/////////////////////////////////////////////////////////////////////////////
// CModuleButton window

class CModuleButton : public CButton
{
// Construction
public:
	CModuleButton();

// Attributes
public:
	int nID;
	CString csNodeName;
	CString csLabel;
	
	typedef	struct
	{
		CModuleButton *NextButton;
		int KeyPressed;
	}KeyPadMapping;
	
	typedef  struct
	{
		CString csName;
		CString bEnabled;
		CString bPromptEnabled;
		CString	csPrompt;
		CString	csType;
		CString PlayTillEnd;
		CString TimeOut;
		CString	csNext;
		CString csBegin;
		CString csVariable;
		
		struct  sort_begin  ;
		
	}SubItem;


	 list<KeyPadMapping > lKeyMapping;
	 list <SubItem> lSubItem;
	// Operations
public:
   // Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModuleButton)
	public:
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual BOOL  IsOfTypeModuleButton();
	int type;
	CRect clientRect;
	virtual ~CModuleButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CModuleButton)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODULEBUTTON_H__30753996_15D5_4B5C_8B80_1D22942468A5__INCLUDED_)
