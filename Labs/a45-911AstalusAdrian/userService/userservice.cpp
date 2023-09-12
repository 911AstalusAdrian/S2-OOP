#include "userservice.h"
#include <string.h>

/// Constructor for a User Service
/// \param repo - the Repository this service is using
userService::userService(Repository *repo) {
    this->repo = repo;
    this->adoption_list = DynamicArray<Dog>(10); /// creating an adoption list for the user
}

/// Destructor for a userService
userService::~userService() {

}

/// Function that filters the Dogs from the Repository and creates an array with these
/// \param breed - the breed that we're looking for
/// \param age - the maximum age of a Dog
/// \return - a new array with Dogs that meet the requirements
DynamicArray<Dog> userService::filterDogs(const string& breed, const int age) {

    /// We create a new array for Dogs
    DynamicArray<Dog> filter = DynamicArray<Dog>(this->repo->nrDogs());

    /// For each dog in the Repository, we check the conditions
    for(int i=0; i<repo->nrDogs(); i++){
        Dog dog = repo->getDog(i);
        size_t found = dog.getBreed().find(breed);
        if(found != string::npos && dog.getAge() < age)
            filter.add(dog); /// adding a dog that meets the requirements
    }
    return filter;
}

/// Function that returns a user's adoption list
DynamicArray<Dog> userService::seeAdoptionList() {
    return this->adoption_list;
}

/// Function that adds a dog to the adoption list
int userService::addToAdoption(Dog &doge) {

    /// checking if the Dog already is in the adoption list
    for(int i=0;i<this->adoption_list.arrayLength(); i++)
        if(doge == this->adoption_list.getElem(i))
            return -1;

    /// If not, we add it
    this->adoption_list.add(doge);
    return 1;
}
