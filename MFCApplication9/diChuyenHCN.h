#pragma once
#include "Hinh.h"

class diChuyenHCN : public Hinh
{
private:
	int x1, x2, y1, y2;
public:
	diChuyenHCN(CPoint p1, CPoint p2);
	diChuyenHCN(int x1, int y1, int x2, int y2);
	void thietlap(int x1, int y1, int x2, int y2);
	CPoint getA();
	CPoint getC();
	void draw(CClientDC* pdc);
	int tronghinh(CPoint p);
	void dichuyen(int dx, int dy);
	diChuyenHCN();
	~diChuyenHCN();

};

