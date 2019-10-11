#pragma once
#include "diChuyenHCN.h"
class nutBam :	public diChuyenHCN
{
public:
	CString chu;
	nutBam();
	~nutBam();
	void draw(CClientDC* pdc);
};
