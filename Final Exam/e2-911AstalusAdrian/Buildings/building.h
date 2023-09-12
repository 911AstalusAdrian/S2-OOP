#pragma once
#ifndef E2_911ASTALUSADRIAN_BUILDING_H
#define E2_911ASTALUSADRIAN_BUILDING_H
#endif //E2_911ASTALUSADRIAN_BUILDING_H
#include <string>
#include <vector>

class Building{
private:
    int id;
    std::string desc, correspArea;
    std::vector<std::string> squares;

public:
    Building(int i, std::string d, std::string a, std::vector<std::string> s);
    Building(){};
    ~Building() = default;
    int getId(){return id;};
    std::string getDescription(){return desc;};
    std::string getArea(){return correspArea;};
    std::vector<std::string> getSquares(){return squares;}
    std::string squaresToString();
};
