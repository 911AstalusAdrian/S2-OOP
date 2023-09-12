#pragma once
#ifndef T2_911ASTALUSADRIAN_1_UI_H
#define T2_911ASTALUSADRIAN_1_UI_H
#endif //T2_911ASTALUSADRIAN_1_UI_H
#include "../Person/person.h"
#include "../Measurement/Measurement.h"

class UI{
private:
    Person* p;
public:
    UI(Person *p);
    void start();
    void print();
    void add();
    void allMeasurements();
    void isHealthy();
    void toFile();
};