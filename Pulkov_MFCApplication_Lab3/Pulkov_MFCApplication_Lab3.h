
// Pulkov_MFCApplication_Lab3.h: основной файл заголовка для приложения Pulkov_MFCApplication_Lab3
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CPulkovMFCApplicationLab3App:
// Сведения о реализации этого класса: Pulkov_MFCApplication_Lab3.cpp
//

class CPulkovMFCApplicationLab3App : public CWinApp
{
public:
	CPulkovMFCApplicationLab3App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPulkovMFCApplicationLab3App theApp;
