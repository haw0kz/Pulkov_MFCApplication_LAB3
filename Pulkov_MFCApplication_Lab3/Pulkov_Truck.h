#pragma once
#pragma region MFC Serialization
#include "Pulkov_Car.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


class Pulkov_Truck : public Pulkov_Car
{
public:
    DECLARE_SERIAL(Pulkov_Truck)

    short int count_of_axles;
    CString body_type;
    Pulkov_Truck() {}
    ~Pulkov_Truck() {}
    virtual void Serialize(CArchive& ar);
    virtual void DrawTruck(CDC* pDC, int& y);
    void input_from_console();
    void output_in_console();
};

