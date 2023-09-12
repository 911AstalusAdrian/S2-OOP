#ifndef A67_911ASTALUSADRIAN_ABSTRACTADOPTIONLIST_H
#define A67_911ASTALUSADRIAN_ABSTRACTADOPTIONLIST_H
#endif //A67_911ASTALUSADRIAN_ABSTRACTADOPTIONLIST_H
#include <vector>
#include "../Dog/dog.h"
#pragma once
class AbstractAdoptionList{
protected:
    std::vector<Dog> list;

public:
    virtual void write() = 0;
    virtual void open() = 0;
    void createList(std::vector<Dog> adoptionList){
        list.insert(std::end(list), std::begin(adoptionList), std::end(adoptionList));
    }
    virtual ~AbstractAdoptionList() = default;
};
