#ifndef A67_911ASTALUSADRIAN_CSVADOPTION_H
#define A67_911ASTALUSADRIAN_CSVADOPTION_H
#endif //A67_911ASTALUSADRIAN_CSVADOPTION_H
#include <string>
#include "AdoptionList.h"
#pragma once
class CSVAdoptionList: public AbstractAdoptionList{
private:
    std::string fileName;

public:
    CSVAdoptionList();
    ~CSVAdoptionList();
    void write();
    void open();

};
