#include "../Service/service.h"
#include "../userService/userservice.h"

#ifndef A45_911ASTALUSADRIAN_UI_H
#define A45_911ASTALUSADRIAN_UI_H
#endif //A45_911ASTALUSADRIAN_UI_H

class UI{
private:
    Service* service;
    userService* uservice;
    AbstractAdoptionList* ad;
public:
    /// Initialisation
    UI(Service* service, userService* uservice);
    ~UI();
//    void initialise();

    /// Menus & Starts
    static void printMenuAdmin();
    static void printMenuUser();
    static void printStartMenu();
    void adminStart();
    void userStart();
    void start();

    /// Admin functions
    void addDogUI();
    void removeDogUI();
    void updateDogUI();
    void listDogsUI();

    /// User functions
    void showUserDogs();
    void filterUserDogs();
    void adoptionList();

};