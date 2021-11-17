
// Pulkov_MFCApplication_Lab3View.h: интерфейс класса CPulkovMFCApplicationLab3View
//

#pragma once


class CPulkovMFCApplicationLab3View : public CScrollView
{
protected: // создать только из сериализации
	CPulkovMFCApplicationLab3View() noexcept;
	DECLARE_DYNCREATE(CPulkovMFCApplicationLab3View)

// Атрибуты
public:
	CPulkovMFCApplicationLab3Doc* GetDocument() const;

// Операции
public:


// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CPulkovMFCApplicationLab3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в Pulkov_MFCApplication_Lab3View.cpp
inline CPulkovMFCApplicationLab3Doc* CPulkovMFCApplicationLab3View::GetDocument() const
   { return reinterpret_cast<CPulkovMFCApplicationLab3Doc*>(m_pDocument); }
#endif

