#include "../DynamicArray/dynamic_array.h"
#include "dog.h"
#ifndef A45_911ASTALUSADRIAN_REOPSITORY_H
#define A45_911ASTALUSADRIAN_REOPSITORY_H
#endif //A45_911ASTALUSADRIAN_REOPSITORY_H
#pragma once

class Repository{
private:
    DynamicArray<Dog>* array;

public:
    Repository(DynamicArray<Dog>* da);
    ~Repository();
    int addDog(const Dog& doge);
    int removeDog(const Dog& doge);
    int updateDog(const Dog& current_doge, const Dog& new_doge);
    Dog getDog(int index);
    int findDog(const Dog& doge);
    DynamicArray<Dog>* getArray();
    int nrDogs();
};