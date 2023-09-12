#include "validators.h"

int validate_breed(const std::string& breed){
    if(breed.length() == 0)
        return 1;
    return 0;
}

int validate_name(const std::string& name){
    if(name.length() == 0)
        return 1;
    return 0;
}

int validate_age(int age){
    if(age <= 0)
        return 1;
    return 0;
}

int validate_link(const std::string& link){
    if(link.length() == 0)
        return 1;
    return 0;
}

int validate_entity(Dog& dog){
    if(validate_breed(dog.getBreed()) == 1 || validate_name(dog.getName()) == 1 || validate_age(dog.getAge()) == 1 || validate_link(dog.getPhoto()) == 1)
        return 1;
    return 0;
}