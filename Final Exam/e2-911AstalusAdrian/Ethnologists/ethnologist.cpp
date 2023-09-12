#include "ethnologist.h"

Ethnologist::Ethnologist(std::string n, std::string a): name(n), area(a) {}

std::istream &operator>>(std::istream &is, Ethnologist &e) {
    std::string comma = ";";
    is >> e.name >> e.area;
    return is;
}
