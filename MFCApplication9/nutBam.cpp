#include "pch.h"
#include "nutBam.h"



nutBam::nutBam()
{
}


nutBam::~nutBam()
{
}


void nutBam::draw(CClientDC* pdc)
{
	// TODO: Add your implementation code here.
	pdc->Rectangle(getA().x, getA().y, getC().x, getC().y);
	pdc->TextOutW(getA().x + 18, getA().y + 18, chu);
}
