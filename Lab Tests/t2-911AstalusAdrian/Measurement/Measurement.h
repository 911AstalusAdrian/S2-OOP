#pragma once
#ifndef T2_911ASTALUSADRIAN_1_MEASUREMENT_H
#define T2_911ASTALUSADRIAN_1_MEASUREMENT_H
#endif //T2_911ASTALUSADRIAN_1_MEASUREMENT_H
#include "string"

class Measurement{
protected:
    std::string date;
public:
    virtual bool isNormalValue() = 0;
    virtual std::string toString() = 0;
    std::string getDate();
};

class BMI: public Measurement{
private:
    double value;
public:
    BMI(double val);
    bool isNormalValue() override;
    std::string toString() override;
    void setValue(double val);
};

class BP: public Measurement{
private:
    int systolicValue;
    int diastolicValue;
public:
    BP(int sys, int dia);
    bool isNormalValue() override;
    std::string toString() override;
    void setValues(int sys, int dia);
};