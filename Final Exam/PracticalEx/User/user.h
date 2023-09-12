#pragma once
#ifndef PRACTICALEX_USER_H
#define PRACTICALEX_USER_H
#endif //PRACTICALEX_USER_H
#include <string>

class User{
private:
    std::string name, type;
public:
    User(std::string u, std::string t);
    User();
    ~User() = default;
    std::string getName();
    std::string getType();
    friend std::istream& operator>>(std::istream& is, User& u);
};