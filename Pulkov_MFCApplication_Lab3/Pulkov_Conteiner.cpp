#include "pch.h"
#include "Pulkov_Conteiner.h"


void Pulkov_Conteiner::output_in_console()
{
	cout << "Количество объектов:" << vectorOfCar.size() << endl;
	for (auto ptr : vectorOfCar)
	{
		ptr->output_in_console();
		cout << "-----------------------------------------------------------------------" << endl;
	}
}

void Pulkov_Conteiner::input_by_console()
{
	cout << "Введите 0, если хотите добавить легковой автомобиль, 1 - если грузовой" << endl;
	int command;
	cin >> command;
	if (command == 0)
	{
		auto ptr = make_shared<Pulkov_Car>();
		ptr->input_from_console();
		vectorOfCar.push_back(ptr);
	}
	else
	{
		auto ptr = make_shared<Pulkov_Truck>();
		ptr->input_from_console();
		vectorOfCar.push_back(ptr);
	}
}

void Pulkov_Conteiner::AddF(CArchive& ar)
{
	// CFile f("out.dat", CFile::modeRead);
	// CArchive ar(&f, CArchive::load);
	int n;
	ar >> n;
	for (int i = 0; i < n; ++i)
	{
		Pulkov_Car* ptr;
		ar >> ptr;
		shared_ptr<Pulkov_Car> ptr1(ptr);
		vectorOfCar.push_back(ptr1);
	}
}

void GetPTM(CArchive& ar, shared_ptr<Pulkov_Car>& iter) 
{
	ar << iter.get();
}

void Pulkov_Conteiner::PrintF(CArchive& ar)
{
	// CFile f("out.dat", CFile::modeCreate | CFile::modeWrite);
	//  CArchive ar(&f, CArchive::store);
	ar << vectorOfCar.size();
	//for (auto ptr : vectorOfCar)
	//{
	for_each(vectorOfCar.begin(), vectorOfCar.end(), bind(GetPTM, ref(ar), placeholders::_1));
	//}

}

CSize Pulkov_Conteiner::DrawCars(CDC* pDC) 
{
	CSize s(0, 0);
	CString information;
	information = "Autopark: " + CString(name_of_autopark.c_str());
	pDC->TextOut(s.cx, s.cy, information);
	s.cy += 20;

	information = "Count of Cars: " + CString(to_string(vectorOfCar.size()).c_str());
	pDC->TextOut(s.cx, s.cy, information);
	s.cy += 20;
	int y = s.cy;

	for_each(vectorOfCar.begin(), vectorOfCar.end(), bind(&Pulkov_Car::DrawCar, placeholders::_1, pDC, ref(y)));

	return s;
}


void Pulkov_Conteiner::clear_autopark()
{

	if (vectorOfCar.size() > 0)
	{
		vectorOfCar.clear();
	}
	else cout << "Вы не ввели ни одного объекта!" << endl;

}

