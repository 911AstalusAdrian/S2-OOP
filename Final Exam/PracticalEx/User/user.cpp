
#include "user.h"

User::User(std::string u, std::string t): name(u), type(t) {}

std::string User::getName() {
    return name;
}

std::string User::getType() {
    return type;
}

std::istream &operator>>(std::istream &is, User &u) {
    is >> u.name >> u.type;
    return is;
}

User::User() {

}
