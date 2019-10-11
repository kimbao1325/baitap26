#pragma once
class Hinh
{
public:
	CPoint point1, point2;
	Hinh();
	~Hinh();
	virtual void draw(CClientDC* pdc);
	virtual int tronghinh(CPoint p1);
	virtual void dichuyen(int dx, int dy);
};

