
// Pulkov_MFCApplication_Lab3View.cpp: реализация класса CPulkovMFCApplicationLab3View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Pulkov_MFCApplication_Lab3.h"
#endif

#include "Pulkov_MFCApplication_Lab3Doc.h"
#include "Pulkov_MFCApplication_Lab3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPulkovMFCApplicationLab3View

IMPLEMENT_DYNCREATE(CPulkovMFCApplicationLab3View, CScrollView)

BEGIN_MESSAGE_MAP(CPulkovMFCApplicationLab3View, CScrollView)
END_MESSAGE_MAP()

// Создание или уничтожение CPulkovMFCApplicationLab3View

CPulkovMFCApplicationLab3View::CPulkovMFCApplicationLab3View() noexcept
{
	// TODO: добавьте код создания

}

CPulkovMFCApplicationLab3View::~CPulkovMFCApplicationLab3View()
{
}

BOOL CPulkovMFCApplicationLab3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование CPulkovMFCApplicationLab3View

void CPulkovMFCApplicationLab3View::OnDraw(CDC* pDC)
{
	CPulkovMFCApplicationLab3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->autopark.DrawCars(pDC);
	CSize sizeTotal = pDoc->autopark.DrawCars(pDC);
	SetScrollSizes(MM_TEXT, sizeTotal);


	// TODO: добавьте здесь код отрисовки для собственных данных
}

void CPulkovMFCApplicationLab3View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Диагностика CPulkovMFCApplicationLab3View

#ifdef _DEBUG
void CPulkovMFCApplicationLab3View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPulkovMFCApplicationLab3View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CPulkovMFCApplicationLab3Doc* CPulkovMFCApplicationLab3View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPulkovMFCApplicationLab3Doc)));
	return (CPulkovMFCApplicationLab3Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CPulkovMFCApplicationLab3View
