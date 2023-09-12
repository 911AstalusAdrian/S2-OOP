#include "../Repository/reopsitory.h"

#ifndef A45_911ASTALUSADRIAN_USERSERVICE_H
#define A45_911ASTALUSADRIAN_USERSERVICE_H
#endif //A45_911ASTALUSADRIAN_USERSERVICE_H
#pragma once

class userService{
private:
    Repository* repo;
    DynamicArray<Dog> adoption_list;

public:
    userService(Repository* repo);
    ~userService();
    DynamicArray<Dog> seeAdoptionList();
    DynamicArray<Dog>  filterDogs(const string& breed, const int age);
    int addToAdoption(Dog& doge);

};