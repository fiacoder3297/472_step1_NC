
// ChildView.h : interface of the CChildView class
//


#pragma once

#include "graphics/OpenGLWnd.h"
// CChildView window

class CChildView : public COpenGLWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	void OnGLDraw(CDC*pDC);
private:
	double m_linefmx;
	double m_linefmy;
	double m_linetox;
	double m_linetoy;
	double pi = 3.14159265358;
	//center position of star x
	double m_starcx;
	double m_starcy;
	double m_length;
	double m_angle;
	double m_RotationAngleRadians;
	double m_squareAngle;
	double m_clickedOn = 0;
public:
	afx_msg void OnStepstuffLineendto0();
	afx_msg void OnStepstuffLinedialog();
	afx_msg void OnStepstuffStardialog();
	afx_msg void OnStepstuffRotate();
};

