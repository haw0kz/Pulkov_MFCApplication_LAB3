#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "Pulkov_Car.h"
#include "Pulkov_Truck.h"
using namespace std;


class Pulkov_Conteiner
{
private:
    string name_of_autopark = "Коллективная автостоянка №2";
    vector <shared_ptr<Pulkov_Car>> vectorOfCar;
public:

    void output_in_console();
    void input_by_console();
    void PrintF(CArchive& ar);
    void AddF(CArchive& ar);
    void clear_autopark();
    CSize DrawCars(CDC* pDC);

    ~Pulkov_Conteiner()
    {
        cout << "Сработал деструктор!";
        clear_autopark();
    }

};
