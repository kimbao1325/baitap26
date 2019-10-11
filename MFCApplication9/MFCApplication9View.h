
// MFCApplication9View.h : interface of the CMFCApplication9View class
//

#pragma once
#include "nutBam.h"
#include "diChuyenHCN.h"
#include "Hinh.h"


class CMFCApplication9View : public CView
{
protected: // create from serialization only
	CMFCApplication9View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication9View)

// Attributes
public:
	CMFCApplication9Doc* GetDocument() const;

// Operations
public:
	nutBam b2, b4;// nut b2 la ve hinh con b4 la de di chuyen hinh
	CClientDC* pdc;
	CPoint p1, p2;

	int control;
	Hinh *ph[20];
	int n;

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMFCApplication9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MFCApplication9View.cpp
inline CMFCApplication9Doc* CMFCApplication9View::GetDocument() const
   { return reinterpret_cast<CMFCApplication9Doc*>(m_pDocument); }
#endif

