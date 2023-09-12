#pragma once
#ifndef T2_911ASTALUSADRIAN_1_PERSON_H
#define T2_911ASTALUSADRIAN_1_PERSON_H
#endif //T2_911ASTALUSADRIAN_1_PERSON_H
#include "string"
#include "vector"
#include "../Measurement/Measurement.h"

class Person{
    friend class Measurement;
private:
    std::string name;
    std::vector<Measurement*> measurements;
public:
    Person(std::string& name);
    void addMeasurment(Measurement *a);
    std::vector<Measurement*> getAllMeasurements();
    std::vector<Measurement*> getMeasurementsByMonth(int month);
    bool isHealthy(int month);
    std::vector<Measurement*>getMeasurementsNewerThan(const std::string& date);
    void writeToFile(const std::string& filename, const std::string& date);
    std::string getName();
};