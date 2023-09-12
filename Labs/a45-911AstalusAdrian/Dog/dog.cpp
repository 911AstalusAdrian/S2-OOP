#include "dog.h"
#include <iostream>

/// Constructor function for the Dog entity
/// \param _breed Dog's breed (string)
/// \param _name Dog's name (string)
/// \param _age Dog's age (int)
/// \param _pic Dog's picture link (string)
Dog::Dog(const std::string& _breed, const std::string& _name, int _age, const std::string& _pic): breed(_breed),
    name(_name),
    age(_age),
    photo(_pic)
{}

/// Copy-constructor for the Dog entity
/// \param copyDog the Dog entity that's being copied
Dog::Dog(const Dog& copyDog):   breed{copyDog.breed},
                                name{copyDog.name},
                                age{copyDog.age},
                                photo{copyDog.photo}
                                {}

/// Default destructor for Dog entity
Dog::~Dog() {

}

/// Getter for a Dog's breed
const string Dog::getBreed() const{
    return breed;
}

/// Getter for a Dog's name
const std::string& Dog::getName() const{
    return name;
}

/// Getter for a Dog's age
const int Dog::getAge() const {
    return age;
}

/// Getter for a Dog's photo link
const std::string& Dog::getPhoto() const{
    return photo;
}

/// Setter for a Dog's new breed
/// \param new_breed the Dog's new breed
void Dog::setBreed(const string &new_breed) {
    Dog::breed = new_breed;
}

/// Setter for a Dog's new name
/// \param new_name the Dog's new name
void Dog::setName(const string &new_name) {
    Dog::name = new_name;
}

/// Setter for a Dog's new age
/// \param new_age the Dog's new age
void Dog::setAge(int new_age) {
    Dog::age = new_age;
}

/// Setter for a Dog's new picture link
/// \param new_pic the Dog's new picture link
void Dog::setPhoto(const string &new_pic) {
    Dog::photo = new_pic;
}

/// Dog Entity string representation
std::string Dog::toString() const {
    std::string finalString = name + " - " + breed + ", " + std::to_string(age) + " year(s) old, and here's a pic: " + photo;
    return finalString;
}

/// '==' operator overloading
/// Checking if two Dog entities are equal
/// \param checkDog the Dog entity that we're comparing with
/// \return truth value of the expression below
bool Dog::operator==(const Dog &checkDog) const {
    return (name==checkDog.name && breed==checkDog.breed && age==checkDog.age && photo==checkDog.photo);
}
