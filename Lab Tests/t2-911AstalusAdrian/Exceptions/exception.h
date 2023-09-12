#pragma once
#ifndef T2_911ASTALUSADRIAN_1_EXCEPTION_H
#define T2_911ASTALUSADRIAN_1_EXCEPTION_H
#endif //T2_911ASTALUSADRIAN_1_EXCEPTION_H
#include "string"
class Exception{
private:
    std::string error;
public:
    Exception(std::string message);
    ~Exception();
    std::string getError();
};
