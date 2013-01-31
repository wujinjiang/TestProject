// exe1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "exe1.h"
#include "exe1Dlg.h"
#include <dll.h>
#include <dll2.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Cexe1Dlg dialog




Cexe1Dlg::Cexe1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cexe1Dlg::IDD, pParent)
	, m_strDll1_full(_T(""))
	, m_strDll1_perID(_T(""))
	, m_strDll1_perName(_T(""))
	, m_nDll1_perIndex(0)
	, m_strDll1_bookID(_T(""))
	, m_strDll1_bookName(_T(""))
	, m_nDll1_bookIndex(0)
	, m_strDll2_Full(_T(""))
	, m_strDll2_perID(_T(""))
	, m_strDll2_perName(_T(""))
	, m_strDll2_bookID(_T(""))
	, m_strDll2_bookName(_T(""))
	, m_nDll2_bookindex(0)
	, m_nDll2_perIndex(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cexe1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DLL1_FULL, m_strDll1_full);
	DDX_Text(pDX, IDC_DLL1_PERID, m_strDll1_perID);
	DDX_Text(pDX, IDC_DLL1_PERNAME, m_strDll1_perName);
	DDX_Text(pDX, IDC_DLL1_PERINDEX, m_nDll1_perIndex);
	DDX_Text(pDX, IDC_DLL1_BOOKID, m_strDll1_bookID);
	DDX_Text(pDX, IDC_DLL1_BOOKNAME, m_strDll1_bookName);
	DDX_Text(pDX, IDC_DLL1_BOOKINDEX, m_nDll1_bookIndex);
	DDX_Text(pDX, IDC_DLL2_FULL, m_strDll2_Full);
	DDX_Text(pDX, IDC_DLL2_PERID, m_strDll2_perID);
	DDX_Text(pDX, IDC_DLL2_PERNAME, m_strDll2_perName);
	DDX_Text(pDX, IDC_DLL2_BOOKID, m_strDll2_bookID);
	DDX_Text(pDX, IDC_DLL2_BOOKNAME, m_strDll2_bookName);
	DDX_Text(pDX, IDC_DLL2_BOOKINDEX, m_nDll2_bookindex);
	DDX_Text(pDX, IDC_DLL2_PERINDEX, m_nDll2_perIndex);
}

BEGIN_MESSAGE_MAP(Cexe1Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_DLL1GET, &Cexe1Dlg::OnBnClickedBtnDll1get)
	ON_BN_CLICKED(IDC_BTN_DLL1SET, &Cexe1Dlg::OnBnClickedBtnDll1set)
	ON_BN_CLICKED(IDC_BTN_DLL2GET, &Cexe1Dlg::OnBnClickedBtnDll2get)
	ON_BN_CLICKED(IDC_BTN_DLL2SET, &Cexe1Dlg::OnBnClickedBtnDll2set)
END_MESSAGE_MAP()


// Cexe1Dlg message handlers

BOOL Cexe1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cexe1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cexe1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cexe1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Cexe1Dlg::OnBnClickedBtnDll1get()
{
	// TODO: Add your control notification handler code here
	CusInfo info1,info2;
    GetPersonInfo(&info1);
	GetBookInfo(&info2);

	m_strDll1_perID = info1.id.c_str();
	m_strDll1_perName = info1.name.c_str();
	m_nDll1_perIndex = info1.index;

	m_strDll1_bookID = info2.id.c_str();
	m_strDll1_bookName = info2.name.c_str();
	m_nDll1_bookIndex = info2.index;

	m_strDll1_full = GetFullValue().c_str();

	UpdateData(FALSE);

}

void Cexe1Dlg::OnBnClickedBtnDll1set()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CusInfo info1,info2;

	info1.id = m_strDll1_perID.GetBuffer(-1);
	info1.name = m_strDll1_perName.GetBuffer(-1);
	info1.index = m_nDll1_perIndex;

    info2.id = m_strDll1_bookID.GetBuffer(-1);
	info2.name = m_strDll1_bookName.GetBuffer(-1);
	info2.index = m_nDll1_bookIndex;

	SetPersonInfo(info1);
	SetBookInfo(info2);

	SetFullValue(std::string(m_strDll1_full.GetBuffer(-1)));
}

void Cexe1Dlg::OnBnClickedBtnDll2get()
{
	// TODO: Add your control notification handler code here
	CusInfo1 info1,info2;
	GetPersonInfo1(&info1);
	GetBookInfo1(&info2);

	m_strDll2_perID = info1.id.c_str();
	m_strDll2_perName = info1.name.c_str();
	m_nDll2_perIndex = info1.index;

	m_strDll2_bookID = info2.id.c_str();
	m_strDll2_bookName = info2.name.c_str();
	m_nDll2_bookindex = info2.index;

	m_strDll2_Full = GetFullValue1().c_str();

	UpdateData(FALSE);

}

void Cexe1Dlg::OnBnClickedBtnDll2set()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CusInfo1 info1,info2;

	info1.id = m_strDll2_perID.GetBuffer(-1);
	info1.name = m_strDll2_perName.GetBuffer(-1);
	info1.index = m_nDll2_perIndex;

	info2.id = m_strDll2_bookID.GetBuffer(-1);
	info2.name = m_strDll2_bookName.GetBuffer(-1);
	info2.index = m_nDll2_bookindex;

	SetPersonInfo1(info1);
	SetBookInfo1(info2);

	SetFullValue1(std::string(m_strDll2_Full.GetBuffer(-1)));
}
