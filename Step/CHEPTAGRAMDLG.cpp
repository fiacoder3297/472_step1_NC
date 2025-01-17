// CHEPTAGRAMDLG.cpp : implementation file
//

#include "stdafx.h"
#include "Step.h"
#include "CHEPTAGRAMDLG.h"
#include "afxdialogex.h"


// CHEPTAGRAMDLG dialog

IMPLEMENT_DYNAMIC(CHeptagramDlg, CDialog)

CHeptagramDlg::CHeptagramDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_HEPTDLG, pParent)
	, m_heptangle(0)
	, m_heptlength(0)
	, m_cx(0)
	, m_cy(0)
{

}

CHeptagramDlg::~CHeptagramDlg()
{
}

void CHeptagramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ANGLE, m_heptangle);
	DDX_Text(pDX, IDC_LENGTH, m_heptlength);
	DDX_Text(pDX, IDC_XLOC, m_cx);
	DDX_Text(pDX, IDC_YLOC, m_cy);
}


BEGIN_MESSAGE_MAP(CHeptagramDlg, CDialog)
END_MESSAGE_MAP()


// CHEPTAGRAMDLG message handlers
