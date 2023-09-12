#pragma once
#ifndef E2_911ASTALUSADRIAN_ETHNOLOGIST_H
#define E2_911ASTALUSADRIAN_ETHNOLOGIST_H
#endif //E2_911ASTALUSADRIAN_ETHNOLOGIST_H
#include <string>


class Ethnologist{
private:
    std::string name, area;
public:
    Ethnologist(std::string n, std::string a);
    Ethnologist(){};
    ~Ethnologist() = default;
    std::string getName(){return name;};
    std::string getArea(){return area;};
    friend std::istream& operator>>(std::istream& is, Ethnologist& e);
};