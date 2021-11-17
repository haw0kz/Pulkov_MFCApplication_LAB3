#include "pch.h"
#include "Pulkov_Car.h"


IMPLEMENT_SERIAL(Pulkov_Car, CObject, 0)

void Pulkov_Car::output_in_console()
{
	cout << "Name of car : " << name << endl;
	cout << "Model of car: " << model << endl;
	cout << "Capacity of capacity: " << capacity << endl;
	cout << "Volume of car:  " << volume << endl;
	cout << "Color of car: " << color << endl;
}

void Pulkov_Car::input_from_console()
{
	cout << "Input name of car: " << endl;
	string n;
	name = n.c_str();
	cout << "Input model of car: " << endl;
	string m;
	model = m.c_str();
	cout << "Input capacity of car: " << endl;
	cin >> capacity;
	cout << "Input volume of car: " << endl;
	cin >> volume;
	cout << "Input color of car: " << endl;
	string c;
	color = c.c_str();

}
void Pulkov_Car::DrawCar(CDC* pDC, int& y) {

	CString information;
	information = "Name of Car: " + name;
	pDC->TextOut(0, y, information);
	y += 20;

	information = "Model of Car: " + model;
	pDC->TextOut(0, y, information);
	y += 20;

	information = "Capacity of Car " + CString(to_string(capacity).c_str());
	pDC->TextOut(0, y, information);
	y += 20;

	information = "Volume of Car " + CString(to_string(volume).c_str());
	pDC->TextOut(0, y, information);
	y += 20;

	information = "Model of Car: " + color;
	pDC->TextOut(0, y, information);
	y += 20;

}

void Pulkov_Car::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << name;
		ar << model;
		ar << capacity;
		ar << volume;
		ar << color;


	}
	else
	{
		ar >> name;
		ar >> model;
		ar >> capacity;
		ar >> volume;
		ar >> color;
	}
}