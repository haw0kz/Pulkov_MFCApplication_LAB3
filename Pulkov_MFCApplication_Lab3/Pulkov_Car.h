#pragma once
#include <iostream>
#include <vector>
#include "Pulkov_Car.h"

using namespace std;

class Pulkov_Car :public CObject
{
public:
    DECLARE_SERIAL(Pulkov_Car)
    CString name;
    CString model;
    float capacity;
    float volume;
    CString color;
    ~Pulkov_Car() {}
    virtual void DrawCar(CDC* pDC, int& y);
    virtual void Serialize(CArchive& ar);
    virtual void output_in_console();
    virtual void input_from_console();

};

