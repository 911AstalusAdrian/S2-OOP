#ifndef A45_911ASTALUSADRIAN_DOG_H
#define A45_911ASTALUSADRIAN_DOG_H
#endif //A45_911ASTALUSADRIAN_DOG_H
#pragma once
#include <string>

using namespace std;

class Dog{
private:
    std::string breed;
    std::string name;
    int age;
    std::string photo;

public:
    Dog(const std::string& _breed = "", const std::string& _name = "", int age =  1, const std::string& _pic = "");
    Dog(const Dog& copyDog);
    ~Dog();

    /// getters
    const string getBreed() const;
    const std::string& getName() const;
    const int getAge() const;
    const std::string& getPhoto() const;

    /// setters
    void setBreed(const std::string& new_breed);
    void setName(const std::string& new_name);
    void setAge(int new_age);
    void setPhoto(const std::string& new_pic);

    /// create string for Dog
    std::string toString() const;

    /// operator overloading
    bool operator==(const Dog& checkDog) const;
};