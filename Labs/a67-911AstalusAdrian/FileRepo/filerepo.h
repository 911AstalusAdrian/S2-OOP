#ifndef A67_911ASTALUSADRIAN_FILEREPO_H
#define A67_911ASTALUSADRIAN_FILEREPO_H
#endif //A67_911ASTALUSADRIAN_FILEREPO_H
#pragma once
#include <vector>
#include <fstream>
#include <dog.h>
#include "../Validation/validators.h"

class FileRepository{
private:
    std::string file_name;
    std::vector<Dog> read();
    void write(std::vector<Dog> dogs);

public:
    /// Constructor for the FileRepo class
    /// \param filename - the name of the file used to read and write the data
    FileRepository(const std::string& filename);

    /// Destructor
    ~FileRepository();

    /// Repository function to add a Dog to the repository
    /// \param dog - the Dog that will be added
    /// Throws exception if the Dog to be added is already in the Repository
    void addDog(const Dog& dog);

    /// Repository function to remove a Dog from the repository
    /// \param dog - the Dog that will be removed
    /// Throws exception if the Dog to be removed does not exist in the Repository
    void removeDog(const Dog& dog);

    /// Repository function to update a Dog from the repository
    /// \param dog - the Dog that will be replaced
    /// \param new_dog - the new Dog entity
    /// Throws an exception if the Dog to be updated/replaced does not exist in the Repository
    void updateDog(const Dog& dog, const Dog& new_dog);

    /// Function to get the Dog entity from a certain index
    /// \param index - the given index
    /// \return - the Dog entity from the respective index in the Repository
    /// Throws an exception if the index is not valid
    Dog getDog(int index);

    /// Function that returns the number of Dog entities currently in the Repository
    /// \return - an integer corresponding to the number of entries in the Repository
    int nrDogs();

    /// Function that gets the index at which a Dog entity is located in the repostitory
    /// \param dog - the Dog we're looking for
    /// \return - the index if the Dog is in the Repository, -1 otherwise
    int getIndex(const Dog& dog);

    /// Function that gets the Repository data
    /// \return - the current Repository of Dogs
    vector<Dog> getRepo();

};