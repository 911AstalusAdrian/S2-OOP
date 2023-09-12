#include "building.h"

Building::Building(int i, std::string d, std::string a, std::vector<std::string> s):
id(i), desc(d), correspArea(a), squares(s)
{}


std::string Building::squaresToString() {
    std::string message;
    for(auto x:squares){
        message.append(x);
        message.append(";");
    }
    return message;
}
