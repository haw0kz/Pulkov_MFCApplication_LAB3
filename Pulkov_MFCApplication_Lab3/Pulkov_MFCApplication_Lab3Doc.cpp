
// Pulkov_MFCApplication_Lab3Doc.cpp: реализация класса CPulkovMFCApplicationLab3Doc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Pulkov_MFCApplication_Lab3.h"
#endif

#include "Pulkov_MFCApplication_Lab3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CPulkovMFCApplicationLab3Doc

IMPLEMENT_DYNCREATE(CPulkovMFCApplicationLab3Doc, CDocument)

BEGIN_MESSAGE_MAP(CPulkovMFCApplicationLab3Doc, CDocument)
END_MESSAGE_MAP()


// Создание или уничтожение CPulkovMFCApplicationLab3Doc

CPulkovMFCApplicationLab3Doc::CPulkovMFCApplicationLab3Doc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CPulkovMFCApplicationLab3Doc::~CPulkovMFCApplicationLab3Doc()
{
}

BOOL CPulkovMFCApplicationLab3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	autopark.clear_autopark();
	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CPulkovMFCApplicationLab3Doc

void CPulkovMFCApplicationLab3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		autopark.PrintF(ar);
	}
	else
	{
		autopark.AddF(ar);
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CPulkovMFCApplicationLab3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CPulkovMFCApplicationLab3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CPulkovMFCApplicationLab3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CPulkovMFCApplicationLab3Doc

#ifdef _DEBUG
void CPulkovMFCApplicationLab3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPulkovMFCApplicationLab3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CPulkovMFCApplicationLab3Doc
