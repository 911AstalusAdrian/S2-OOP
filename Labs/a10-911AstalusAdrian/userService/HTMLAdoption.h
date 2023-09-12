#ifndef A67_911ASTALUSADRIAN_HTMLADOPTION_H
#define A67_911ASTALUSADRIAN_HTMLADOPTION_H
#endif //A67_911ASTALUSADRIAN_HTMLADOPTION_H
#include <string>
#include "AdoptionList.h"
#pragma once
class HTMLAdoptionList: public AbstractAdoptionList{
private:
    std::string fileName;
    std::string createFirstPart();
    std::string createSecondPart();

public:
    HTMLAdoptionList();
    ~HTMLAdoptionList();
    void write();
    void open();

};
