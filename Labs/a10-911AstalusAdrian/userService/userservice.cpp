#include "userservice.h"
#include <string.h>
#include <algorithm>
#include "../Exceptions/exception.h"
#include "HTMLAdoption.h"
#include "CSVAdoption.h"

userService::userService(FileRepository *repo) {
    this->repo = repo;
}

userService::~userService() {

}

std::vector<Dog> userService::filterDogs(const string& breed, int age) {

    // We create a new array for Dogs
    std::vector<Dog> filter;
    std::vector<Dog> dogs = repo->getRepo();


    // For each dog in the Repository, we check the conditions
    for (const auto& dog : dogs){
        size_t found = dog.getBreed().find(breed);
        if(found != string::npos && dog.getAge() < age)
            filter.push_back(dog);
    }
    return filter;
}

std::vector<Dog> userService::seeAdoptionList() {
    return this->adoption_list;
}

void userService::addToAdoption(Dog &doge) {

    //checking if the Dog already is in the adoption list
    for (const auto& dog : this->adoption_list){
        if (doge == dog)
            throw Exception("This dog is already in your adoption list!\n");
    }
    // If not, we add it
    this->adoption_list.push_back(doge);
}

int userService::findInAdoption(Dog &doge) {
    for(int index=0; index <adoption_list.size(); index++){
        if(adoption_list[index] == doge)
            return index;
    }
    return -1;
}


void userService::removeFromAdoption(Dog &doge) {
    int index = findInAdoption(doge);
    if (index == -1)
        throw Exception("This dog is not in your adoption list!\n");
    adoption_list.erase(adoption_list.begin() + index);
}
