#include "service.h"
#include "../Dog/dog.h"

Service::Service(FileRepository *repo) {
    this->repo = repo;
}

Service::~Service() {

}

void Service::addDogService(const string& breed, const string& name, int age, const string& pic_link) {
    Dog new_dog = Dog(breed, name, age, pic_link);

    // we validate the inputs given first
    Validation::validate_entity(new_dog);
    this->repo->addDog(new_dog);
}

void Service::removeDogServiceByIndex(int index) {
    int nr_dogs = this->repo->nrDogs();
    Validation::validate_index(index, nr_dogs);
    Dog dog = this->repo->getDog(index);
    this->repo->removeDog(dog);
}

void Service::updateDogService(const Dog &doge, const Dog &new_doge) {

    // we validate the new Dog entity
    Validation::validate_entity(new_doge);
    this->repo->updateDog(doge, new_doge);
}

std::vector<Dog> Service::getArray() {
    return this->repo->getRepo();
}

int Service::getNumberOfDogs() {
    return this->repo->nrDogs();
}

Dog Service::getDogByIndex(int index) {
    Validation::validate_index(index, this->repo->nrDogs());
    return this->repo->getDog(index);
}

int Service::countBreed(const std::string& breed) {
    int count = 0;
    std::vector<Dog> allDogs = this->repo->getRepo();
    for(Dog &d: allDogs){
        if(d.getBreed() == breed)
            count++;
    }
    return count;
}

int Service::getDogIndex(const Dog &doge) {
    return this->repo->getIndex(doge);
}
