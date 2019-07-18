
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "..\Common\Include\WinHttpClient.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


class CForm1Dlg : public CDialogEx
{
public:
	CForm1Dlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CForm1Dlg::CForm1Dlg() : CDialogEx(IDD_FORM1)
{
}

void CForm1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CForm1Dlg, CDialogEx)
END_MESSAGE_MAP()


class CForm2Dlg : public CDialogEx
{
public:
	CForm2Dlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CForm2Dlg::CForm2Dlg() : CDialogEx(IDD_FORM2)
{
}

void CForm2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CForm2Dlg, CDialogEx)
END_MESSAGE_MAP()

class CForm3Dlg : public CDialogEx
{
public:
	CForm3Dlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Form3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CForm3Dlg::CForm3Dlg() : CDialogEx(IDD_FORM3)
{
}

void CForm3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CForm3Dlg, CDialogEx)
END_MESSAGE_MAP()
// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_USER, m_User);
	DDX_Control(pDX, IDC_PASS, m_Pass);
	DDX_Control(pDX, IDC_ANIMATE1, m_avi);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

unsigned long MySimplePostTest(CString user, CString password);

void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();

	CString user;

	m_User.GetWindowText(user);
	CString pass;
	m_Pass.GetWindowText(pass);

	m_avi.ShowWindow(SW_SHOW);
	m_avi.Open(IDR_AVI1);
	m_avi.Play(0, -1, -1);

	int test = MySimplePostTest(user, pass);

	m_avi.Stop();
	m_avi.Close();
	m_avi.ShowWindow(SW_HIDE);

	switch (test)
	{
	case 0:
	{
		CForm3Dlg dlgForm3;
		dlgForm3.DoModal();
	}
		break;
	case 1:
	{
		CForm2Dlg dlgForm2;
		dlgForm2.DoModal();
	}
		break;
	case 2: 
	{
		CForm1Dlg dlgForm1;
		dlgForm1.DoModal();
	}
		break;
	default:
		break;
	}
}

unsigned long MySimplePostTest(CString user, CString password)
{
	WinHttpClient client(L"http://149.28.19.39/acml/api/index.php/api/v1/login");

	// Set post data.
	//"user_id=OfficeEngineer1&password=test123";
	int retcode = 2;

	CString s1("user_id=");
	CString s2("&password=");

	CString s3 = s1 + user + s2 + password;

	CStringA strA(s3);

	string data = strA;

	client.SetAdditionalDataToSend((BYTE *)data.c_str(), data.size());

	// Set request headers.
	wchar_t szSize[50] = L"";
	swprintf_s(szSize, L"%d", data.size());
	wstring headers = L"Content-Length: ";
	headers += szSize;
	headers += L"\r\nContent-Type: application/x-www-form-urlencoded\r\n";
	client.SetAdditionalRequestHeaders(headers);

	// Send http post request.
	client.SendHttpRequest(L"POST");

	wstring httpResponseHeader = client.GetResponseHeader();
	wstring httpResponseContent = client.GetResponseContent();


	if (httpResponseContent.find(L"\"status\":true") == 4294967295)
	{
		retcode = 0;
	}
	else
	{
		if (httpResponseContent.find(L"f_type\":\"OFFICE") == 4294967295)
			retcode = 1;
	}
	
	return retcode;
}