#include "repocommands.h"
#include <algorithm>
#include <QDebug>

AddCommand::AddCommand(Service *serv, const string &breed, const string &name, int age, const string &link):
service{serv},
breed{breed},
name{name},
age{age},
link{link}
{}

void AddCommand::undo() {
    Dog d = Dog(breed,name,age,link);
    service->removeDogServiceByIndex(this->service->getDogIndex(d));
}

void AddCommand::redo() {
    service->addDogService(breed,name,age,link);
}

void AddCommand::execute() {
    service->addDogService(breed,name,age,link);
}

RemoveCommand::RemoveCommand(Service *serv, int position, const Dog& d):
service{serv},
dog{d},
position{position}
{}

void RemoveCommand::undo() {
    service->addDogService(dog.getBreed(), dog.getName(), dog.getAge(), dog.getPhoto());
}

void RemoveCommand::redo() {
    service->removeDogServiceByIndex(position);
}

void RemoveCommand::execute() {
    service->removeDogServiceByIndex(position);
}

UpdateCommand::UpdateCommand(Service *serv, const Dog &d, const string &new_breed, const string &new_name, int new_age,const string &new_link):
service{serv},
dog{d},
breed{new_breed},
name{new_name},
age{new_age},
link{new_link}
{}

void UpdateCommand::undo() {
    Dog new_dog = Dog(breed, name, age, link);
    service->updateDogService(new_dog, dog);
}

void UpdateCommand::redo() {
    Dog new_dog = Dog(breed, name, age, link);
    service->updateDogService(dog, new_dog);
}

void UpdateCommand::execute() {
    Dog new_dog = Dog(breed, name, age, link);
    service->updateDogService(dog, new_dog);
}

AdoptCommand::AdoptCommand(userService *userv, const Dog &d): uservice{userv}, dog{d}
{}

void AdoptCommand::undo() {
    uservice->removeFromAdoption(dog);
}

void AdoptCommand::redo() {
    uservice->addToAdoption(dog);
}

void AdoptCommand::execute() {
    uservice->addToAdoption(dog);
}
