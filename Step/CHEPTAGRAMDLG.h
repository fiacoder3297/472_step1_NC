#pragma once


// CHEPTAGRAMDLG dialog

class CHeptagramDlg : public CDialog
{
	DECLARE_DYNAMIC(CHeptagramDlg)

public:
	CHeptagramDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CHeptagramDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HEPTDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_heptangle;
	double m_heptlength;
	double m_cx;
	double m_cy;
};
