#include "../Repository/reopsitory.h"
#include "dog.h"
#ifndef A45_911ASTALUSADRIAN_SERVICE_H
#define A45_911ASTALUSADRIAN_SERVICE_H
#endif //A45_911ASTALUSADRIAN_SERVICE_H
#pragma once

class Service{
private:
    Repository* repo;

public:
    Service(Repository* repo);
    ~Service();
    int addDogService(const string& breed, const string& name, const int age, const string& pic_link);
    int removeDogServiceByIndex(const int index);
    int updateDogService(const Dog& doge, const Dog& new_doge);
    DynamicArray<Dog>* getArray();
    int getNumberOfDogs();
    Dog getDogByIndex(int index);
};