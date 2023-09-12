#include "reopsitory.h"
#include "dog.h"
#include <iostream>

/// Constructor for a Repository
/// \param da - the Dynamic Array that the Repo's using
Repository::Repository(DynamicArray<Dog> *da) {
    this->array = da;
}

/// Destructor for a Repository
Repository::~Repository() {

}

/// Function for adding a Dog in the Repository
/// \param doge - the Dog to be added
/// \return - 1 if the action was performed successfully, -1 otherwise
int Repository::addDog(const Dog &doge) {
    int search_doge = this->array->findElem(doge);

    /// -1 means that there is no such entity already in the repo
    if (search_doge == -1){
        this->array->add(doge);
        return 1;
    }

    /// returns -1 if this Dog entity already exists in the repo
    else{
        return -1;
    }
}

/// Function for removing a Dog from the Repository
/// \param doge - the Dog to be removed
/// \return - 1 if the action was performed successfully, -1 otherwise
int Repository::removeDog(const Dog &doge) {
    int search_doge = this->array->findElem(doge); // 'search_doge' will have the index at which the searched Dog is in the array

    /// if 'search_doge' is positive, it means that there exists the respective Dog entity
    if (search_doge >= 0){
        this->array->remove(doge);
        return 1; /// returns 1 if the operation was performed
    }

    /// returns -1 if there is no such Dog entity to be removed
    else{
        return -1;
    }
}

/// Function for updating (replacing) a Dog in the Repository
/// \param current_doge - the Dog entity that will be updated/replaced
/// \param new_doge - the new Dog entity that will be put
/// \return - 1 if the action was performed successfully, -1 otherwise
int Repository::updateDog(const Dog &current_doge, const Dog &new_doge) {
    int search_doge = this->array->findElem(current_doge);
    if (search_doge != -1){
        Dog doggo = this->array->getElem(search_doge);
        this->array->update(doggo, new_doge);
        return 1; /// returns 1 if the operation was performed
    }

    /// returns -1 if the initial Dog entity was not found
    else{
        return -1;
    }
}

/// Function that returns a the array from the Repo
DynamicArray<Dog> *Repository::getArray() {
    return this->array;
}

/// Function that gets a Dog from an index
/// \param index - the index from which we want to get a Dog
/// \return - the Dog entity from the given index (if it exists)
Dog Repository::getDog(int index) {
    return this->array->getElem(index);
}

/// Search function to see whether a Dog is in the Repo or not
/// \param doge - the Dog we're looking for
/// \return - 1 if the dog exists, -1 otherwise
int Repository::findDog(const Dog &doge) {
    for (int i=0; i< this->array->arrayLength(); i++){
        Dog find = this->getDog(i);
        if (find == doge)
            return 1; /// returns 1 if the Dog entity was found
    }
    return -1; /// returns -1 if the Dog entity was not found
}

/// Function that returns the number of entities currently in the Repository
int Repository::nrDogs() {
    return this->array->arrayLength();
}
