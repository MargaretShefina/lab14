#include <afxwin.h> 
#include <string>  
#include <atltime.h>


class CMainWin : public CFrameWnd
{
public:
	CMainWin();
	afx_msg void OnChar(UINT ch, UINT, UINT);
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT flags, CPoint Loc);
	afx_msg void OnRButtonDown(UINT flags, CPoint Loc);
	int currentFigure;
	int n;
	CPen* oldPen;
	CFont *m_pFont;
	virtual void SetClientFont(CString Typeface, 
		int Size, 
		BOOL Bold,
	
		BOOL Italic
	
		);
	//char str[50];
	//int nMouseX, nMouseY, nOldMouseX, nOldMouseY;
	//char pszMouseStr[50];
	DECLARE_MESSAGE_MAP()
};
class CApp : public CWinApp
{
public:
	BOOL InitInstance();
};
BOOL CApp::InitInstance()
{
	m_pMainWnd = new CMainWin;
	m_pMainWnd->ShowWindow(SW_RESTORE);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
CMainWin::CMainWin()
{
	this->Create(0, L"Lab 14");
	currentFigure = 0;
	n = 0;
	m_pFont = new CFont;
	this->SetClientFont("Arial", 20, FALSE, FALSE);
	this->ShowWindow(SW_RESTORE);
	this->UpdateWindow();
}
BEGIN_MESSAGE_MAP
	(CMainWin , CFrameWnd )
	ON_WM_CHAR()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


afx_msg void CMainWin::OnChar(UINT ch, UINT, UINT)
{
	//sprintf(str, "%c", ch);
	this->InvalidateRect(0);
}


afx_msg void CMainWin::OnPaint()
{
	//int n=255;
	CPaintDC pDC(this);
	//pDC.SetTextColor(RGB(81, 145, n));


	CTime t = CTime::GetCurrentTime();
	CString s = t.Format(_T("%A, %B %d, %Y, %H:%M:%S"));

	switch (n)
	{
	case 1: { this->SetClientFont("Times new Roman", 290, FALSE, FALSE);
		pDC.SetTextColor(RGB(255, 255, 80));
		pDC.SelectObject(m_pFont);
		pDC.TextOutW(450, 400, s);
		break; }
	case 2: {this->SetClientFont("Veranda", 50, FALSE, FALSE);
		pDC.SetTextColor(RGB(255, 200, 100));
		pDC.SelectObject(m_pFont);
		pDC.TextOutW(300, 300, s);
		break; }
	case 3: { this->SetClientFont("Cambria", 60, FALSE, FALSE);
		pDC.SetTextColor(RGB(255, 0, 100));
		pDC.SelectObject(m_pFont);
		pDC.TextOutW(300, 300, s);
		break; }
	case 4: { this->SetClientFont("Cambria", 60, FALSE, FALSE);
		pDC.SetTextColor(RGB(255, 0, 100));
		pDC.SelectObject(m_pFont);
		pDC.TextOutW(300, 300, s);
		break; }
	case 5: { this->SetClientFont("Cambria", 60, FALSE, FALSE);
		pDC.SetTextColor(RGB(255, 0, 100));
		pDC.SelectObject(m_pFont);
		pDC.TextOutW(300, 300, s);
		break; }
	case 6: { this->SetClientFont("Cambria", 60, FALSE, FALSE);
		pDC.SetTextColor(RGB(255, 0, 100));
		pDC.SelectObject(m_pFont);
		pDC.TextOutW(300, 300, s);
		break; }
	case 7: { this->SetClientFont("Cambria", 60, FALSE, FALSE);
		pDC.SetTextColor(RGB(255, 0, 100));
		pDC.SelectObject(m_pFont);
		pDC.TextOutW(300, 300, s);
		break; }

	default:this->SetClientFont("Veranda", 50, FALSE, FALSE);
		pDC.SetTextColor(RGB(255, 150, 140));
		pDC.SelectObject(m_pFont);
		pDC.TextOutW(300, 300, s);
		break;
	}

	//


	switch (currentFigure)
	{
	case 1: {
		CPen aPen1(PS_DASH, 3, RGB(120, 255, 127));
		oldPen = pDC.SelectObject(&aPen1);
		pDC.Ellipse(50, 50, 100, 150);
		break; }
	case 2: {
		CPen aPen1(PS_DASH, 3, RGB(255, 221, 0));
		oldPen = pDC.SelectObject(&aPen1);
		pDC.Rectangle(50, 50, 150, 100);
		break;
	}
	case 3: {
		CPen aPen1(PS_DASH, 3, RGB(179, 78, 233));
		oldPen = pDC.SelectObject(&aPen1);
		pDC.Rectangle(50, 50, 100, 100);
		break;
	}
	case 4:
	{
		CPen aPen1(PS_DASH, 3, RGB(128, 0, 128));
		oldPen = pDC.SelectObject(&aPen1);
		pDC.Pie(50, 50, 100, 100, 40, 110, 120, 120);
		break;
	}
	case 5: {
		CPen aPen1(PS_DASH, 3, RGB(107, 142, 35));
		oldPen = pDC.SelectObject(&aPen1);
		pDC.Arc(50, 50, 150, 150, 100, 50, 150, 100);
		pDC.MoveTo(100, 50);
		pDC.LineTo(150, 100);
		break;
	}
	default: {
		CPen aPen1(PS_DASH, 3, RGB(255, 69, 0));
		oldPen = pDC.SelectObject(&aPen1);
		pDC.Ellipse(50, 50, 100, 100);
		currentFigure = 0;
		break; }
	}

	//pDC.TextOut(nOldMouseX, nOldMouseY, " ");
	//pDC.TextOut(nMouseX, nMouseY, pszMouseStr);
	//pDC.TextOut(1, 1, " ");
	//pDC.TextOut(1, 1, str);
	//pDC.TextOut(50, 50, "qwerty");
}
afx_msg void CMainWin::OnLButtonDown
(UINT, CPoint loc)
{
	
	LOGFONT lf;
	//m_pFont->GetLogFont(&lf);
	m_pFont->GetLogFont(&lf);

	if (CString(lf.lfFaceName) == "Arial"
		&& lf.lfWeight == FW_NORMAL && lf.lfItalic == 0) {
		this->SetClientFont("Arial", 20, FALSE, TRUE); // Arial Italic
	}
	else if (CString(lf.lfFaceName) == "Arial"
		&& lf.lfWeight == FW_NORMAL && lf.lfItalic == 1) {
		this->SetClientFont("Arial", 20, TRUE, FALSE); // Arial Bold
	}
	else if (CString(lf.lfFaceName) == "Arial" &&
		lf.lfWeight > FW_NORMAL) {
		// Times New Roman
		this->SetClientFont("Times New Roman", 20, FALSE, FALSE);
	}
	else if (CString(lf.lfFaceName) == "Times New Roman"
		&& lf.lfWeight == FW_NORMAL && lf.lfItalic == 0) {
		// Times New Roman Italic
		this->SetClientFont("Times New Roman", 20, FALSE, TRUE);
	}
	else if (CString(lf.lfFaceName) == "Times New Roman"
		&& lf.lfWeight == FW_NORMAL && lf.lfItalic == 1) {
		// Times New Roman Bold
		this->SetClientFont("Times New Roman", 20, TRUE, FALSE);
	}
	else if (CString(lf.lfFaceName) == "Times New Roman"
		&& lf.lfWeight > FW_NORMAL) {
		this->SetClientFont("Arial", 20, FALSE, FALSE); // Arial
	}

	this->InvalidateRect(0);
}
afx_msg void CMainWin::OnRButtonDown
(UINT, CPoint loc)
{
	currentFigure += 1;
	n += 1;

	this->InvalidateRect(0);
}

void CMainWin::SetClientFont(CString Typeface,
	int Size,
	BOOL Bold,
	BOOL Italic
	
	)

{

	CWindowDC winDC(this);

	int pixelsPerInch = winDC.GetDeviceCaps(LOGPIXELSY);

	int fontHeight = -MulDiv(Size, pixelsPerInch, 72);


	int Weight = FW_NORMAL;
	if (Bold)
		Weight = FW_BOLD;

	delete m_pFont;
	m_pFont = new CFont;

	m_pFont->CreateFont(10, 0, 0, 0, 20, Italic, 0, 0,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, PROOF_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, Typeface);
}




CApp App;
