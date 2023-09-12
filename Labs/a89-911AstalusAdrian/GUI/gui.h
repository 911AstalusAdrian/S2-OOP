#ifndef A89_911ASTALUSADRIAN_GUI_H
#define A89_911ASTALUSADRIAN_GUI_H
#pragma once


#endif //A89_911ASTALUSADRIAN_GUI_H
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include "../Service/service.h"
#include "../userService/userservice.h"
class GUI: public QWidget
{
private:
    Service* service;
    userService* uservice;
    AbstractAdoptionList* ad;

    /// graphical elements
    QWidget* user;
    QListWidget* dogsList;
    QLineEdit *dogName, *dogBreed, *dogAge, *dogLink;
    QPushButton *addButton, *updateButton, *deleteButton, *toUserButton, *exitButton;

    QLineEdit *userDogName, *userDogBreed, *userDogAge, *userDogLink;
    QPushButton *adoptButton, *nextButton, *filterButton, *toAdminButton, *csvButton, *htmlButton, *userExitButton, *statisticsButton;
    int dogIndex = 0;



    void switchToUser();
    void switchToAdmin();
    void startGUI();
    void addDogGUI();
    void updateDogGUI();
    void removeDogGUI();
    void setUser();
    void populate();
    void connections();
    void nextDog();
    void addToAdoption();
    void showCSVAdoption();
    void filterDogs();
    void showHTMLAdoption();
    void statistics();
    int getListIndex() const;

    std::vector<std::string> sortBreeds();
public:
    GUI(Service* s, userService* us);
};