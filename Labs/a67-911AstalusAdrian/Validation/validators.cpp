#include "validators.h"
#include "../Exceptions/exception.h"

void Validation::validate_breed(const std::string& breed){
    if(breed.length() == 0)
        throw Exception("Invalid breed!\n");
}

void Validation::validate_name(const std::string& name){
    if(name.length() == 0)
        throw Exception("Invalid name!\n");
}

void Validation::validate_age(int age){
    if(age <= 0)
        throw Exception("Invalid age!\n");
}

void Validation::validate_link(const std::string& link){
    if(link.length() == 0)
        throw Exception("Invalid link!\n");
}

void Validation::validate_entity(const Dog& dog){
    validate_breed(dog.getBreed());
    validate_name(dog.getName());
    validate_age(dog.getAge());
    validate_link(dog.getPhoto());
}

void Validation::validate_index(int index, int count){
    if(index < 0 || index >= count)
        throw Exception("Invalid index!\n");
}

int Validation::int_validate_age(int age){
    if(age <= 0)
        return 1;
    return 0;
}

Validation::Validation() {

}

Validation::~Validation() {

}
