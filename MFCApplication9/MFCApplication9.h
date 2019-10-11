
// MFCApplication9.h : main header file for the MFCApplication9 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCApplication9App:
// See MFCApplication9.cpp for the implementation of this class
//

class CMFCApplication9App : public CWinApp
{
public:
	CMFCApplication9App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication9App theApp;
