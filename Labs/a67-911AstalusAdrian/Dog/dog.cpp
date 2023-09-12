#include "dog.h"
#include <iostream>

Dog::Dog(const std::string& _breed, const std::string& _name, int _age, const std::string& _pic): breed(_breed),
    name(_name),
    age(_age),
    photo(_pic)
{}

Dog::Dog(const Dog& copyDog):   breed{copyDog.breed},
                                name{copyDog.name},
                                age{copyDog.age},
                                photo{copyDog.photo}
                                {}

Dog::~Dog() {

}

const string Dog::getBreed() const{
    return breed;
}

const std::string& Dog::getName() const{
    return name;
}

const int Dog::getAge() const {
    return age;
}

const std::string& Dog::getPhoto() const{
    return photo;
}

std::string Dog::toString() const {
    std::string finalString = name + " - " + breed + ", " + std::to_string(age) + " year(s) old, and here's a pic: " + photo;
    return finalString;
}

bool Dog::operator==(const Dog &checkDog) const {
    return (name==checkDog.name && breed==checkDog.breed && age==checkDog.age && photo==checkDog.photo);
}

std::ostream &operator<<(ostream &out, const Dog &dog) {
    out<<dog.breed<<" "<<dog.name<<" "<<dog.age<<" "<<dog.photo;
    return out;
}

std::istream &operator>>(istream &in, Dog &dog) {
    in>>dog.breed>>dog.name>>dog.age>>dog.photo;
    return in;
}

std::string Dog::CSVRepresentation() const {
    std::string representation;
    representation.append(breed);
    representation.append(",");
    representation.append(name);
    representation.append(",");
    representation.append(to_string(age));
    representation.append(",");
    representation.append(photo);
    return representation;
}

std::string Dog::HTMLRepresentation() const {
    std::string representation;
    representation.append("\t\t<td>");
    representation.append(breed);
    representation.append("</td>\n");
    representation.append("\t\t<td>");
    representation.append(name);
    representation.append("</td>\n");
    representation.append("\t\t<td>");
    representation.append(to_string(age));
    representation.append("</td>\n");
    representation.append("\t\t<td><a href=");
    representation.append(photo);
    representation.append("\">Link</a></td>\n");
    return representation;
}
