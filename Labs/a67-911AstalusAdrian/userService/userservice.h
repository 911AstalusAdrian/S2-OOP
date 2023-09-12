#include "../FileRepo/filerepo.h"
#include "AdoptionList.h"

#ifndef A45_911ASTALUSADRIAN_USERSERVICE_H
#define A45_911ASTALUSADRIAN_USERSERVICE_H
#endif //A45_911ASTALUSADRIAN_USERSERVICE_H
#pragma once

class userService{
private:
    FileRepository* repo;
    std::vector<Dog> adoption_list;

public:

    /// Constructor for a User Service
    /// \param repo - the Repository this service is using
    userService(FileRepository* repo);

    /// Destructor for a userService
    ~userService();

    /// Function that returns a user's adoption list
    std::vector<Dog> seeAdoptionList();


    /// Function that filters the Dogs from the Repository and creates an array with these
    /// \param breed - the breed that we're looking for
    /// \param age - the maximum age of a Dog
    /// \return - a new array with Dogs that meet the requirements
    std::vector<Dog> filterDogs(const string& breed, int age);

    /// Function that adds a dog to the adoption list
    /// \param doge - the Dog entity which will be added to the list
    /// Throws an exception if the Dog is already on the list
    void addToAdoption(Dog& doge);
};