#include "pch.h"
#include "Pulkov_Truck.h"


IMPLEMENT_SERIAL(Pulkov_Truck, Pulkov_Car, VERSIONABLE_SCHEMA | 0)

void Pulkov_Truck::input_from_console()
{
	Pulkov_Car::input_from_console();
	cout << "Input count of axles: " << endl;
	cin >> count_of_axles;
	cout << "Input body type: " << endl;
	string body;
	cin.ignore(1, '\n');
	getline(cin, body);
	body_type = body.c_str();
}

void Pulkov_Truck::output_in_console()
{
	Pulkov_Car::output_in_console();
	cout << "Count of axles: " << count_of_axles << endl;
	cout << "Body type : " << body_type << endl;
}

void Pulkov_Truck::DrawTruck(CDC* pDC, int& y) {

	CString information;
	information = "	Count of axles: " + count_of_axles;
	pDC->TextOut(0, y, information);
	y += 20;

	information = "Body type: " + body_type;
	pDC->TextOut(0, y, information);
	y += 20;
}

void Pulkov_Truck::Serialize(CArchive& ar)
{
	Pulkov_Car::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << count_of_axles;
		ar << body_type;

	}
	else
	{
		ar >> count_of_axles;
		ar >> body_type;

	}
}
