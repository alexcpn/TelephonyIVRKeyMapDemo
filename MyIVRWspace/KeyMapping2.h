#if !defined(AFX_KEYMAPPING2_H__A5657292_7CA6_4857_8DD0_DE5B19406FDA__INCLUDED_)
#define AFX_KEYMAPPING2_H__A5657292_7CA6_4857_8DD0_DE5B19406FDA__INCLUDED_

#include "resource.h"       // main symbols
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KeyMapping2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKeyMapping2 dialog

//Class Used for Key Mappping in the Sub Item Property Page
class CKeyMapping2 : public CPropertyPage
{
	DECLARE_DYNCREATE(CKeyMapping2)

// Construction
public:
	bool AssignPrompt(CString csKeyAssigned);
	bool IsAssigned(CString csActionName,CString csKey);
	BOOL PopulateKeyList();
	bool UpdateKeyList();
	CKeyMapping2();
	~CKeyMapping2();
private:
	bool m_bKeyInNumber;
	CString m_csKeyInNumber;

// Dialog Data
	//{{AFX_DATA(CKeyMapping2)
	enum { IDD = IDD_KEYDLG };
	CListCtrl	m_liNextActionList;
	CListCtrl	m_MapList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CKeyMapping2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CKeyMapping2)
	virtual BOOL OnInitDialog();
	afx_msg void OnClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYMAPPING2_H__A5657292_7CA6_4857_8DD0_DE5B19406FDA__INCLUDED_)
