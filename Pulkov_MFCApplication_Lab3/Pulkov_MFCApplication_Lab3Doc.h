
// Pulkov_MFCApplication_Lab3Doc.h: интерфейс класса CPulkovMFCApplicationLab3Doc 
//


#pragma once
#include "Pulkov_Conteiner.h"


class CPulkovMFCApplicationLab3Doc : public CDocument
{
protected: // создать только из сериализации
	CPulkovMFCApplicationLab3Doc() noexcept;
	DECLARE_DYNCREATE(CPulkovMFCApplicationLab3Doc)

// Атрибуты
public:
	Pulkov_Conteiner autopark;

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CPulkovMFCApplicationLab3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
