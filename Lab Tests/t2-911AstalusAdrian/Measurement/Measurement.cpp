#include <sstream>
#include <iomanip>
#include "string.h"
#include "Measurement.h"

bool BMI::isNormalValue() {
    if (this->value > 25 || this->value < 18.5)
        return false;
    else
        return true;
}

std::string BMI::toString() {
    std::stringstream stream;
    stream<<"BMI - "<<std::setw(5)<<std::to_string(this->value)<<"\n";
    std::string the_string = stream.str();
    return the_string;
}

void BMI::setValue(double val) {
    this->value = val;
}

BMI::BMI(double val) {
    this->value = val;
}

bool BP::isNormalValue() {
    if((this->systolicValue >= 90 && this->systolicValue <= 119) && (this->diastolicValue >=60 && this->diastolicValue <=79))
        return true;
    else
        return false;
}

std::string BP::toString() {
    std::stringstream stream;
    stream<<"BP  - "<<std::setw(5)<<std::to_string(this->systolicValue)<<" "<<std::to_string(this->diastolicValue)<<"\n";
    std::string string = stream.str();
    return string;
}

void BP::setValues(int sys, int dia) {
    this->systolicValue = sys;
    this->diastolicValue = dia;
}

BP::BP(int sys, int dia) {
    this->systolicValue = sys;
    this->diastolicValue = dia;
}

std::string Measurement::getDate() {
    return this->date;
}
