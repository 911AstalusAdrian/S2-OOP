#include "service.h"
#include "dog.h"
#include "../Validation/validators.h"

/// Constructor for a Service
/// \param repo - the Repository that the Service is using
Service::Service(Repository *repo) {
    this->repo = repo;
}

/// Destructor for Service
Service::~Service() {

}

/// Service function for adding a Dog
/// \param breed - Dog's breed
/// \param name - Dog's name
/// \param age - Dog's age
/// \param pic_link - Dog's picture link
/// \return - 1 if the action was performed, -1 otherwise
int Service::addDogService(const string& breed, const string& name, const int age, const string& pic_link) {
    Dog new_dog = Dog(breed, name, age, pic_link);

    /// we validate the inputs given first
    if (validate_entity(new_dog) == 1)
        return -1; /// Dog entity not valid

    if (this->repo->addDog(new_dog) == -1)
        return -1; /// operation was not performed
    else
        return 1; /// operation was performed
}

/// Service function that removes a Dog based on the index
/// \param index - the index from which we want to remove a Dog
/// \return - 1 if the action was performed, -1 otherwise
int Service::removeDogServiceByIndex(const int index) {
    if (index >= this->repo->nrDogs())
        return -1;
    Dog pupper = this->repo->getDog(index);
//    if (this->repo->removeDog(pupper) != -1)
//        return 1;
    this->repo->removeDog(pupper);
    return 1;
}

/// Service function for updating/replacing a Dog with a new one
/// \param doge - the initial Dog entity
/// \param new_doge - the new Dog entity
/// \return  - 1 if the action was performed, -1 otherwise
int Service::updateDogService(const Dog &doge, const Dog &new_doge) {
    if (this->repo->updateDog(doge, new_doge) == -1)
        return -1; /// Dog update not performed
    else
        return 1; /// Dog update performed successfully
}

/// Getter for the array of entities
DynamicArray<Dog> *Service::getArray() {
    return this->repo->getArray();
}

/// Getter for the number of entities in the array
int Service::getNumberOfDogs() {
    return this->repo->nrDogs();
}

/// Getter for an entity based on a given index
Dog Service::getDogByIndex(int index) {
    return this->repo->getDog(index);
}
