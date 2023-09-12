#include "../FileRepo/filerepo.h"
#include "../Dog/dog.h"
#ifndef A45_911ASTALUSADRIAN_SERVICE_H
#define A45_911ASTALUSADRIAN_SERVICE_H
#endif //A45_911ASTALUSADRIAN_SERVICE_H
#pragma once

class Service{
private:
    FileRepository* repo;

public:
    /// Constructor for a Service
    /// \param repo - the Repository that the Service is using
    Service(FileRepository* repo);

    /// Destructor for Service
    ~Service();

    /// Service function for adding a Dog
    /// \param breed - Dog's breed
    /// \param name - Dog's name
    /// \param age - Dog's age
    /// \param pic_link - Dog's picture link
    void addDogService(const string& breed, const string& name, int age, const string& pic_link);

    /// Service function that removes a Dog based on the index
    /// \param index - the index from which we want to remove a Dog
    void removeDogServiceByIndex(int index);

    /// Service function for updating/replacing a Dog with a new one
    /// \param doge - the initial Dog entity
    /// \param new_doge - the new Dog entity
    void updateDogService(const Dog& doge, const Dog& new_doge);

    /// Getter for the array of entities
    std::vector<Dog> getArray();

    /// Getter for the number of entities in the array
    int getNumberOfDogs();

    /// Getter for an entity based on a given index
    Dog getDogByIndex(int index);

    int countBreed(const std::string& breed);


};