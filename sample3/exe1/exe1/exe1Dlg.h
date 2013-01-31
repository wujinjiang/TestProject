// exe1Dlg.h : header file
//

#pragma once


// Cexe1Dlg dialog
class Cexe1Dlg : public CDialog
{
// Construction
public:
	Cexe1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_EXE1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strDll1_full;
public:
	CString m_strDll1_perID;
public:
	CString m_strDll1_perName;
public:
	int m_nDll1_perIndex;
public:
	CString m_strDll1_bookID;
public:
	CString m_strDll1_bookName;
public:
	int m_nDll1_bookIndex;
public:
	CString m_strDll2_Full;
public:
	CString m_strDll2_perID;
public:
	CString m_strDll2_perName;
public:
	CString m_strDll2_bookID;
public:
	CString m_strDll2_bookName;
public:
	int m_nDll2_bookindex;
public:
	int m_nDll2_perIndex;
public:
	afx_msg void OnBnClickedBtnDll1get();
public:
	afx_msg void OnBnClickedBtnDll1set();
public:
	afx_msg void OnBnClickedBtnDll2get();
public:
	afx_msg void OnBnClickedBtnDll2set();
};
