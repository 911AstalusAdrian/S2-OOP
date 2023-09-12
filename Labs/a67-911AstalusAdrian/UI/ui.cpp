#include <iostream>
#include "dog.h"
#include "ui.h"
#include "../Exceptions/exception.h"
#include "CSVAdoption.h"
#include "HTMLAdoption.h"


using namespace std;

UI::UI(Service *service, userService* uservice) {
    this->service = service;
    this->uservice = uservice;
}

UI::~UI() {

}

//void UI::initialise() {
//    this->service->addDogService("German Shepherd", "Hula", 4, "https://bit.ly/31jwL15");
//    this->service->addDogService("English Bulldog", "Lucas", 5, "https://bit.ly/3vNuUzQ");
//    this->service->addDogService("Australian Shepherd", "Buster", 3, "https://bit.ly/319dKOM");
//    this->service->addDogService("American Bulldog", "Riley", 2, "https://bit.ly/3tIyo4S");
//    this->service->addDogService("Boxer", "Edison", 7, "https://bit.ly/3f3Q8U0");
//    this->service->addDogService("Poodle", "Harry", 6, "https://bit.ly/3f9mEV3");
//    this->service->addDogService("Shepherd", "Tink", 4, "https://bit.ly/3cQMLgy");
//    this->service->addDogService("Doberman", "Max", 3, "https://bit.ly/31lr1E9");
//    this->service->addDogService("Husky", "Nate", 1, "https://bit.ly/3dapkih");
//    this->service->addDogService("Hound", "Marvin", 1, "https://bit.ly/3tVJ5kv");
//
//}

void UI::printMenuAdmin() {
    cout<<endl<<"1. A new dog has entered the Shelter! (add dog)"<<endl;
    cout<<"2. Lucky dog has found a family! (remove dog)"<<endl;
    cout<<"3. A dog has changed identity! (update dog)"<<endl;
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
    cout<<"Hello and welcome to the Dog Shelter!\n";

    std::string option;
    std::cout<<"Select view mode (CSV or HTML):";
    getline(cin, option);
    if(option == "csv" || option == "CSV") {
        ad = new CSVAdoptionList();
    }
    else
    if(option == "HTML" || option == "html"){
        ad = new HTMLAdoptionList();
    } else
        std::cout<<"Invalid option!\n";

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
    try {
        this->service->addDogService(breed, name, age, pic_link);
        std::cout<<"Dog successfully added!\n";
    }
    catch (Exception &e) {
        std::cout<<e.getError();
    }
    catch (RepositoryException &re) {
        std::cout<<re.getRepoError();
    }
}

void UI::removeDogUI() {
    int index;
    cout<<"Current number of dogs: "<<this->service->getNumberOfDogs()<<endl;
    cout << "Give the index:";
    cin>>index;
    try{
        this->service->removeDogServiceByIndex(index);
        std::cout<<"Dog has left the shelter!\n";
    }
    catch(Exception &e){
        std::cout<<e.getError();
    }
    catch (RepositoryException &re) {
        std::cout<<re.getRepoError();
    }

}

void UI::updateDogUI() {
    cout<<"Current number of dogs: "<<this->service->getNumberOfDogs()<<endl;
    int index, new_age;
    string new_name, new_breed, new_pic, buffer;
    cout<<"Dog index: ";
    cin>>index;
    try{
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
        this->service->updateDogService(initial_dog, new_dog);
        std::cout<<"Dog successfully updated!\n";
    }
    catch (Exception &e) {
        std::cout<<e.getError();
    }
    catch (RepositoryException &re){
        std::cout<<re.getRepoError();
    }
}

void UI::listDogsUI() {
    int count = this->service->getNumberOfDogs();
    if (count == 0)
        cout<<"No dogs in the shelter."<<endl;
    else {
        std::vector<Dog> dogs = this->service->getArray();
        for (int i = 0; i < count; i++) {
            Dog dog = dogs[i];
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
                try {
                    this->uservice->addToAdoption(dog);
                    dog_index++;
                    if(dog_index == this->service->getNumberOfDogs())
                        dog_index = 0;
                    std::cout<<"This dog is now in your list!\n";
                }
                catch (Exception &e) {
                    std::cout<<e.getError();
                }
                catch (RepositoryException &re){
                    std::cout<<re.getRepoError();
                }
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
    if (Validation::int_validate_age(age) == 0) {
        std::vector<Dog> filtered = this->uservice->filterDogs(breed, age);
        bool exit = false;
        int dog_index = 0, option;
        while (!exit) {
            Dog dog = filtered[dog_index];
            cout << dog.toString();
            cout << endl << "1. Adopt" << endl;
            cout << "2. Next" << endl;
            cout << "0. Exit" << endl;
            cin >> option;
            switch (option) {
                case 1:
                    try{
                        this->uservice->addToAdoption(dog);
                        dog_index++;
                        if(dog_index == filtered.size())
                            dog_index = 0;
                        std::cout<<"This dog is now in your adoption list!\n";
                    }
                    catch (Exception &e) {
                        std::cout<<e.getError();
                    }
                    catch (RepositoryException &re) {
                        std::cout<<re.getRepoError();
                    }
                    continue;
                case 2:
                    dog_index++;
                    if (dog_index == filtered.size())
                        dog_index = 0;
                    continue;
                case 0:
                    exit = true;
                    continue;
                default:
                    cout << "Invalid option!\n";
            }
        }
    }
    else
        cout<<"Invalid age given!\n";
}

void UI::adoptionList() {
    std::vector<Dog> adoptions = this->uservice->seeAdoptionList();
    if (adoptions.empty())
        std::cout<<"Adoption list empty!\n";
    else{
        ad->createList(adoptions);
        ad->write();
        ad->open();
    }
}