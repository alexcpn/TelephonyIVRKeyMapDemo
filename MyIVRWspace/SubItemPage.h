#if !defined(AFX_SUBITEMPAGE_H__85A94828_3D83_44A8_A250_98213B9FC867__INCLUDED_)
#define AFX_SUBITEMPAGE_H__85A94828_3D83_44A8_A250_98213B9FC867__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubItemPage.h : header file
//
#include "ModuleButton.h"
#include "resource.h"
/////////////////////////////////////////////////////////////////////////////
// CSubItemPage dialog

class CSubItemPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSubItemPage)

// Construction
public:
	bool SetItemProperty(CModuleButton::SubItem *thisItem);
	void SetTitle(CString &);
	CString csTitle;
	CSubItemPage();
	~CSubItemPage();
	 void OnSet();

// Dialog Data
	//{{AFX_DATA(CSubItemPage)
	enum { IDD = IDD_SUBITEM };
	CButton	m_chkFirst;
	CButton	m_promptenabled;
	CComboBox	m_Next;
	CComboBox	m_type;
	CEdit	m_timeout;
	CEdit	m_prompt;
	CComboBox	m_playtillend;
	CComboBox	m_enabled;
	CString	m_Variable;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSubItemPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSubItemPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnChkfirst();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	CModuleButton::SubItem myItem;
	static CString	m_csNext[10];
	static int nNext;
	static CSubItemPage * lastCheckedPage;
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBITEMPAGE_H__85A94828_3D83_44A8_A250_98213B9FC867__INCLUDED_)
