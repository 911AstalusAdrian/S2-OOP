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
    /// Constructor function for the Dog entity
    /// \param _breed Dog's breed (string)
    /// \param _name Dog's name (string)
    /// \param _age Dog's age (int)
    /// \param _pic Dog's picture link (string)
    Dog(const std::string& _breed = "", const std::string& _name = "", int age =  1, const std::string& _pic = "");

    /// Copy-constructor for the Dog entity
    /// \param copyDog the Dog entity that's being copied
    Dog(const Dog& copyDog);

    /// Default destructor for Dog entity
    ~Dog();

    /// Getter for a Dog's breed
    const string getBreed() const;

    /// Getter for a Dog's name
    const std::string& getName() const;

    /// Getter for a Dog's age
    const int getAge() const;

    /// Getter for a Dog's photo link
    const std::string& getPhoto() const;

    /// Dog Entity string representation
    std::string toString() const;

    std::string CSVRepresentation() const;

    std::string HTMLRepresentation() const;

    /// '==' operator overloading
    /// Checking if two Dog entities are equal
    /// \param checkDog the Dog entity that we're comparing with
    /// \return truth value of an expression
    bool operator==(const Dog& checkDog) const;

    /// Insertion operator overload
    /// \param out - the outstream where the entity will be inserted
    /// \param dog - the entity to be inserted
    /// \return - the outstream
    friend std::ostream& operator<<(std::ostream& out, const Dog &dog);

    /// Extraction operator overload
    /// \param in - the instream where the entity will be extracted from
    /// \param dog - the entity
    /// \return - the instream
    friend std::istream& operator>>(std::istream& in, Dog& dog);
};