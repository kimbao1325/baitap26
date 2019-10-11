
// MFCApplication9View.cpp : implementation of the CMFCApplication9View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication9.h"
#endif

#include "MFCApplication9Doc.h"
#include "MFCApplication9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication9View

IMPLEMENT_DYNCREATE(CMFCApplication9View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication9View, CView)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication9View construction/destruction

CMFCApplication9View::CMFCApplication9View() noexcept
{
	b2.thietlap(40, 25, 140, 80);
	b2.chu = CString("Rectangle");
	b4.thietlap(180, 25, 280, 80);
	b4.chu = CString("move");
	control = 1;
	n = 0;
	// TODO: add construction code here

}

CMFCApplication9View::~CMFCApplication9View()
{
}

BOOL CMFCApplication9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplication9View drawing

void CMFCApplication9View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pdc = new CClientDC(this);
	b2.draw(pdc);
	b4.draw(pdc);


	// TODO: add draw code for native data here
}


// CMFCApplication9View diagnostics

#ifdef _DEBUG
void CMFCApplication9View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication9Doc* CMFCApplication9View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication9Doc)));
	return (CMFCApplication9Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication9View message handlers


void CMFCApplication9View::OnLButtonUp(UINT nFlags, CPoint point)
{
	p2.x = point.x;
	p2.y = point.y;
	pdc = new CClientDC(this);
	CPen* oldP, * pen1, * pen2;//Set 2pen
	pen1 = new CPen(PS_SOLID, 1, RGB(0, 0, 0));
	pen2 = new CPen(PS_SOLID, 1, RGB(255, 255, 255));
	CBrush* oldB, * B1, * B2;
	B1 = new CBrush(RGB(0, 0, 0));
	B2 = new CBrush(RGB(255, 255, 255));//

	// khi an chuot vao b2 ve hcn
	if (b2.tronghinh(point) == 1)

		control = 2;
	else
		// di chuyen
		if (b4.tronghinh(point) == 1)
			control = 4;
		else
			if (control == 2)
			{
				ph[n] = new diChuyenHCN(p1, p2);
				ph[n]->draw(pdc);
				n++;
			}

			else//dichuyenhinh
			{
				int i = 0;
				for (i = 0; i < n; i++)
				{
					if (ph[i]->tronghinh(p1) == 1)
					{
						oldP = pdc->SelectObject(pen2);//Chọn Pen Và ghi đè lên hình cũ lúc kéo thả
						oldB = pdc->SelectObject(B2);//
						ph[i]->draw(pdc);
						ph[i]->dichuyen(p2.x - p1.x, p2.y - p1.y);
						oldP = pdc->SelectObject(pen1);
						oldB = pdc->SelectObject(B2);
						ph[i]->draw(pdc);

					}

				}
			}
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication9View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	p1.x = point.x;
	p1.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}
