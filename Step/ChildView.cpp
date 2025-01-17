
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Step.h"
#include "ChildView.h"
#include "CLineDlg.h"
#include "CHeptagramDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW

#endif


// CChildView

CChildView::CChildView()
{
	m_linefmx = 0.5;
	m_linefmy = 0.1;
	m_linetox = 0.2;
	m_linetoy = 0.12;
	m_starcx = 0.5;
	m_starcy = 0.13;
	m_length = 0.13;


	//angle from heptagram
	m_angle = (2 * pi) / 7;
	m_squareAngle = (2 * pi) / 4;
	m_RotationAngleRadians = 0;
	//m_angle = (77.143*(pi/180));
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_STEPSTUFF_LINEENDTO0, &CChildView::OnStepstuffLineendto0)
	ON_COMMAND(ID_STEPSTUFF_LINEDIALOG, &CChildView::OnStepstuffLinedialog)
	ON_COMMAND(ID_STEPSTUFF_STARDIALOG, &CChildView::OnStepstuffStardialog)
	ON_COMMAND(ID_STEPSTUFF_ROTATE, &CChildView::OnStepstuffRotate)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!COpenGLWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}





void CChildView::OnGLDraw(CDC*pDC)
{
	// TODO: Add your implementation code here.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Simple rectangle example
	int width, height;
	GetSize(width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, // left
		1.0, // right
		0.0, // bottom
		GLdouble(height) / GLdouble(width), // top
		1.0, // near
		-1.0); // far

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	double r = (m_length / 2.0) / cos(25.714 / 2.0 * pi / 180.0);

	//double m_squareLength = r * 2.0;
	//double r_square = (m_squareLength / 2.0) / cos(90.0 / 2.0 * pi / 180.0);

	glColor3d(1., 0., 0.);
	//star this should rotate and produce up to 7 points
	glBegin(GL_LINES);

	//calc points first
	double x_val[7] = { 0.0 };
	double y_val[7] = { 0.0 };

	for (int i = 0; i < 7; i++)
	{
		x_val[i] = m_starcx + r * cos(i*m_angle + m_RotationAngleRadians + (90.0 * pi / 180.0));
		y_val[i] = m_starcy + r * sin(i*m_angle + m_RotationAngleRadians + (90.0 * pi / 180.0));

	}

	//connect the dots
	glVertex2d(x_val[0], y_val[0]);
	glVertex2d(x_val[4], y_val[4]);

	glVertex2d(x_val[4], y_val[4]);
	glVertex2d(x_val[1], y_val[1]);

	glVertex2d(x_val[1], y_val[1]);
	glVertex2d(x_val[5], y_val[5]);

	glVertex2d(x_val[5], y_val[5]);
	glVertex2d(x_val[2], y_val[2]);

	glVertex2d(x_val[2], y_val[2]);
	glVertex2d(x_val[6], y_val[6]);

	glVertex2d(x_val[6], y_val[6]);
	glVertex2d(x_val[3], y_val[3]);

	glVertex2d(x_val[3], y_val[3]);
	glVertex2d(x_val[0], y_val[0]);


	glEnd();
	
	glColor3d(0., 1., 0.);
	//glLineWidth(4.0f);



	//Rectangle CCW
	glBegin(GL_LINES);

	double max_x_val = 0.0;
	double min_x_val = 1000.0;
	double max_y_val = 0.0;
	double min_y_val = 1000.0;

	for (int i = 0; i<7;i++)
	{
		if (x_val[i] > max_x_val)
		{
			max_x_val = x_val[i];
		}
		if (x_val[i] < min_x_val)
		{
			min_x_val = x_val[i];
		}
		if (y_val[i] > max_y_val)
		{
			max_y_val = y_val[i];
		}
		if (y_val[i] < min_y_val)
		{
			min_y_val = y_val[i];
		}
	}

	//double r_rectangle = sqrt( pow((max_x_val - min_x_val), 2.0) + pow((max_y_val - min_y_val), 2.0) ) / 2.0;
	


	glVertex2d(max_x_val, max_y_val);
	glVertex2d(max_x_val, min_y_val);

	glVertex2d(max_x_val, min_y_val);
	glVertex2d(min_x_val, min_y_val);

	glVertex2d(min_x_val, min_y_val);
	glVertex2d(min_x_val, max_y_val);

	glVertex2d(min_x_val, max_y_val);
	glVertex2d(max_x_val, max_y_val);


	//for (int i = 0; i < 4; i++)
	//{
	//	x_val[i] = m_starcx + r_rectangle * cos(i*m_squareAngle + m_RotationAngleRadians + (45.0 * pi / 180.0));
	//	y_val[i] = m_starcy + r_rectangle * sin(i*m_squareAngle + m_RotationAngleRadians + (45.0 * pi / 180.0));
	//}
	//glVertex2d(x_val[0], y_val[0]);
	//glVertex2d(x_val[1], y_val[1]);

	//glVertex2d(x_val[1], y_val[1]);
	//glVertex2d(x_val[2], y_val[2]);

	//glVertex2d(x_val[2], y_val[2]);
	//glVertex2d(x_val[3], y_val[3]);

	//glVertex2d(x_val[3], y_val[3]);
	//glVertex2d(x_val[0], y_val[0]);

	glEnd();

	//glColor3d(0., 0., 1.);

	/*glBegin(GL_LINES);
	glVertex2d(m_linefmx, m_linefmy);
	glVertex2d(m_linetox, m_linetoy);
	glEnd();*/
}


void CChildView::OnStepstuffLineendto0()
{
	// TODO: Add your command handler code here
	m_linetox = 0.1;
	m_linetoy = 0.1;

	Invalidate();
}


void CChildView::OnStepstuffLinedialog()
{
	CLineDlg dlg;

	dlg.m_fmx = m_linefmx;
	dlg.m_fmy = m_linefmy;
	dlg.m_tox = m_linetox;
	dlg.m_toy = m_linetoy;

	if (dlg.DoModal() == IDOK)
	{
		m_linefmx = dlg.m_fmx;
		m_linefmy = dlg.m_fmy;
		m_linetox = dlg.m_tox;
		m_linetoy = dlg.m_toy;

		Invalidate();
	}
}


void CChildView::OnStepstuffStardialog()
{
	CHeptagramDlg dlg;
	dlg.m_heptangle = m_angle;
	dlg.m_heptlength = m_length;
	dlg.m_cx = m_starcx;
	dlg.m_cy = m_starcy;

	if (dlg.DoModal() == IDOK)
	{
		m_angle = dlg.m_heptangle;
		m_length = dlg.m_heptlength;
		m_starcx = dlg.m_cx;
		m_starcy = dlg.m_cy;

		Invalidate();
	}

}


void CChildView::OnStepstuffRotate()
{
	
	//m_RotationAngleRadians = 0.15 ;
	m_RotationAngleRadians = (15.0 * pi / 180.0);

	if (m_clickedOn >= 1)
	{
		//m_RotationAngleRadians = m_RotationAngleRadians + (0.15*(m_clickedOn));
		m_RotationAngleRadians = m_RotationAngleRadians + ((15.0 * pi / 180.0)*(m_clickedOn));

	}
	m_clickedOn++;
	Invalidate();
}
