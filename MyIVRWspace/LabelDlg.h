#if !defined(AFX_LABELDLG_H__013B1061_1DA4_4B9A_9736_39DEF550F398__INCLUDED_)
#define AFX_LABELDLG_H__013B1061_1DA4_4B9A_9736_39DEF550F398__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LabelDlg.h : header file
//
#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLabelDlg dialog

class CLabelDlg : public CDialog
{
// Construction
public:
	CLabelDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLabelDlg)
	enum { IDD = IDD_DIALOG_LABEL };
	CString	m_CLabel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLabelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLabelDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LABELDLG_H__013B1061_1DA4_4B9A_9736_39DEF550F398__INCLUDED_)
