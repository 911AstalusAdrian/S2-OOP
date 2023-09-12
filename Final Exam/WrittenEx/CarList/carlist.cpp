#include "carlist.h"

Car::Car(const std::string &n,  int c): name(n), cap(c) {}

int Car::getCap() {
    return cap;
}

bool Car::operator<(Car &c) {
    return cap < c.getCap();
}

std::string Car::getName() {
    return name;
}

std::ostream &operator<<(std::ostream &o, Car &c) {
    std::string mes;
    mes.append(c.getName());
    mes.append(" ");
    mes.append(std::to_string(c.getCap()));
    o << mes;
    return o;
}
