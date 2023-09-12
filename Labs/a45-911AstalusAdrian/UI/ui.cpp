#include "ui.h"
#include <iostream>
#include "../DynamicArray/dynamic_array.h"
#include "../Validation/validators.h"
#include "dog.h"


using namespace std;

UI::UI(Service *service, userService* uservice) {
    this->service = service;
    this->uservice = uservice;
}

UI::~UI() {

}

void UI::initialise() {
    this->service->addDogService("German Shepherd", "Hula", 4, "https://bit.ly/31jwL15");
    this->service->addDogService("English Bulldog", "Lucas", 5, "https://bit.ly/3vNuUzQ");
    this->service->addDogService("Australian Shepherd", "Buster", 3, "https://bit.ly/319dKOM");
    this->service->addDogService("American Bulldog", "Riley", 2, "https://bit.ly/3tIyo4S");
    this->service->addDogService("Boxer", "Edison", 7, "https://bit.ly/3f3Q8U0");
    this->service->addDogService("Poodle", "Harry", 6, "https://bit.ly/3f9mEV3");
    this->service->addDogService("Shepherd", "Tink", 4, "https://bit.ly/3cQMLgy");
    this->service->addDogService("Doberman", "Max", 3, "https://bit.ly/31lr1E9");
    this->service->addDogService("Husky", "Nate", 1, "https://bit.ly/3dapkih");
    this->service->addDogService("Hound", "Marvin", 1, "https://bit.ly/3tVJ5kv");

}

void UI::printMenuAdmin() {
    cout<<endl<<"1. A new doge has entered the Shelter! (add dog)"<<endl;
    cout<<"2. Lucky doggo has found a family! (remove dog)"<<endl;
    cout<<"3. Pupper has changed identity! (update dog)"<<endl;
    cout<<"4. SHOW ME ALL THE PUPPIES"<<endl;
    cout<<"0. Exit"<<endl;
}

void UI::printMenuUser() {
    cout<<endl<<"1. See dogs"<<endl;
    cout<<"2. Filter dogs"<<endl;
    cout<<"3. See adoption list"<<endl;
    cout<<"0. Exit"<<endl;
}

void UI::printStartMenu() {
    cout<<endl<<"1. User"<<endl;
    cout<<"2. Admin"<<endl;
    cout<<"0. Exit"<<endl;
}

void UI::start() {
    cout<<"Hello and welcome to the Pupper Shelter!";
    bool done = false;
    while (!done){
        printStartMenu();
        int option;
        cout<<"Option~";
        cin>>option;
        switch (option) {
            case 1:
                userStart();
                continue;
            case 2:
                adminStart();
                continue;
            case 0:
                done = true;
                cout<<"See you later alligator!"<<endl;
                continue;
            default:
                cout<<"Invalid option!";
        }
    }
}

void UI::adminStart() {
    cout<<"Admin mode initiated";
    bool done = false;
    while (!done){
        printMenuAdmin();
        int option;
        cout<<"Option~";
        cin>>option;
        switch (option) {
            case 1:
                addDogUI();
                continue;
            case 2:
                removeDogUI();
                continue;
            case 3:
                updateDogUI();
                continue;
            case 4:
                listDogsUI();
                continue;
            case 0:
                done = true;
                cout<<"See you later alligator!"<<endl;
                continue;
            default:
                cout<<"Invalid option!";
        }
    }
}

void UI::userStart() {
    cout<<"Hello, User!";
    bool done = false;
    while(!done){
        printMenuUser();
        int option;
        cout<<"Option~";
        cin>>option;
        switch (option) {
            case 1:
                showUserDogs();
                continue;
            case 2:
                filterUserDogs();
                continue;
            case 3:
                adoptionList();
                continue;
            case 0:
                done = true;
                cout<<"Goodbye!"<<endl;
                continue;
            default:
                cout<<"Invalid command!";
        }
    }
}

void UI::addDogUI() {
    string breed, name, pic_link, buffer;
    int age;
    getline(cin, buffer);
    cout<<"Breed:";
    getline(cin, breed);
    cout<<"Name:";
    cin>>name;
    cout<<"Age:";
    cin>>age;
    cout<<"Picture link:";
    cin>>pic_link;
    if(this->service->addDogService(breed, name, age, pic_link) == -1)
        cout<<"Oops! there was a problem with this dog (maybe it's already here)"<<endl;
    else
        cout<<"Pupper successfully added!"<<endl;
}

void UI::removeDogUI() {
    int index;
    cout<<"Current number of dogs: "<<this->service->getNumberOfDogs()<<endl;
    cout << "Give the index:";
    cin>>index;
    if (index >= this->service->getNumberOfDogs() || index < 0)
        cout<<"Invalid index!";
    else
        if(this->service->removeDogServiceByIndex(index) == -1)
            cout<<"Invalid pupper credentials!"<<endl;
        else
            cout<<"Pupper has left the shelter successfully!";
}

void UI::updateDogUI() {
    cout<<"Current number of dogs: "<<this->service->getNumberOfDogs()<<endl;
    int index, new_age;
    string new_name, new_breed, new_pic, buffer;
    cout<<"Dog index: ";
    cin>>index;
    Dog initial_dog = this->service->getDogByIndex(index);
    getline(cin, buffer);
    cout<<"Breed: ";
    getline(cin, new_breed);
    cout<<"Name: ";
    cin>>new_name;
    cout<<"Age: ";
    cin>>new_age;
    cout<<"Picture link: ";
    cin>>new_pic;
    Dog new_dog = Dog(new_breed, new_name, new_age, new_pic);
    if (validate_entity(new_dog) == 1 || this->service->updateDogService(initial_dog, new_dog) == -1)
        cout<<"Something wrong with this pupper!";
    else
        cout<<"Pupper updated!";
}

void UI::listDogsUI() {
    int count = this->service->getNumberOfDogs();
    if (count == 0)
        cout<<"No dogs in the shelter! Yay!"<<endl;
    else {
        DynamicArray<Dog> *da = this->service->getArray();
        for (int i = 0; i < count; i++) {
            Dog dog = da->getElem(i);
            cout<<i<<". "<< dog.toString() << endl;
        }
    }
}

void UI::showUserDogs() {
    bool exit = false;
    int dog_index = 0, option;
    while (!exit){
        Dog dog = this->service->getDogByIndex(dog_index);
        cout<<dog.toString();
        cout<<endl<<"1. Adopt"<<endl;
        cout<<"2. Next"<<endl;
        cout<<"0. Exit"<<endl;
        cin>>option;
        switch (option) {
            case 1:
                if(this->uservice->addToAdoption(dog)== 1)
                    dog_index++;
                else
                    cout<<"This dog is already in the list!"<<endl;
                continue;
            case 2:
                dog_index++;
                if(dog_index == this->service->getNumberOfDogs())
                    dog_index = 0;
                continue;
            case 0:
                exit = true;
                continue;
            default:
                cout<<"Invalid option!";
        }
    }
}

void UI::filterUserDogs() {
    string breed, buffer;
    int age;
    getline(cin, buffer);
    cout<<"Select the breed:";
    getline(cin, breed);
    cout<<"Maximum age:";
    cin>>age;
    if (validate_age(age) == 0) {
        DynamicArray<Dog> filtered = this->uservice->filterDogs(breed, age);
        bool exit = false;
        int dog_index = 0, option;
        while (!exit) {
            Dog dog = filtered.getElem(dog_index);
            cout << dog.toString();
            cout << endl << "1. Adopt" << endl;
            cout << "2. Next" << endl;
            cout << "0. Exit" << endl;
            cin >> option;
            switch (option) {
                case 1:
                    this->uservice->addToAdoption(dog);
                    dog_index++;
                    continue;
                case 2:
                    dog_index++;
                    if (dog_index == filtered.arrayLength())
                        dog_index = 0;
                    continue;
                case 0:
                    exit = true;
                    continue;
                default:
                    cout << "Invalid option!" << endl;
            }
        }
    }
    else
        cout<<"Invalid age given!"<<endl;
}

void UI::adoptionList() {
    DynamicArray<Dog> adoptions = this->uservice->seeAdoptionList();
    if (adoptions.arrayLength() == 0)
        cout<<"Adoption list empty!"<<endl;
    else
        for (int i=0; i<adoptions.arrayLength(); i++){
            Dog dog = adoptions.getElem(i);
            cout<<dog.toString()<<endl;
        }
}