#pragma once
#ifndef A45_911ASTALUSADRIAN_VALIDATORS_H
#define A45_911ASTALUSADRIAN_VALIDATORS_H
#endif //A45_911ASTALUSADRIAN_VALIDATORS_H
#include <string>
#include <dog.h>

class Validation{
public:
    /// Constructor for Validation class
    Validation();

    /// Destructor
    ~Validation();

    /// Function that validates a given breed
    /// \param breed - the breed to be validated
    /// Throws an exception if the breed is invalid
    static void validate_breed(const std::string& breed);

    /// Function that validates a given name
    /// \param name - the name to be validated
    /// Throws an exception if the name is invalid
    static void validate_name(const std::string& name);

    /// Function that validates a given age
    /// \param age - the age to be validated
    /// Throws an exception if the age is invalid
    static void validate_age(int age);

    /// Age validation, but without throwing an exception
    /// \param age - the age to be validated
    /// \return - 1 if the age is invalid, 0 otherwise
    static int int_validate_age(int age);

    /// Function that validates a given picture link
    /// \param link - the link to be validated
    /// Throws an exception if the link is invalid
    static void validate_link(const std::string& link);

    /// Function that validates an entire Dog entity (breed, name, age, link)
    /// \param dog - the entity to be validated
    /// using the previously defined validators, checks if the Dog attributes are valid
    static void validate_entity(const Dog& dog);

    /// Function that validates a given index
    /// \param index - the index to be validated
    /// \param count - the maximum value the index can have + 1
    /// Throws an exception if the index is invalid
    static void validate_index(int index, int count);
};
