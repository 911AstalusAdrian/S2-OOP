#pragma once
#ifndef T2_911ASTALUSADRIAN_1_VALIDATION_H
#define T2_911ASTALUSADRIAN_1_VALIDATION_H
#endif //T2_911ASTALUSADRIAN_1_VALIDATION_H
#include "string"
#include "../Exceptions/exception.h"
#include "../Measurement/Measurement.h"
class Validation{
public:
    static void check_date(std::string date);
    static void check_measurement(Measurement *m);
};