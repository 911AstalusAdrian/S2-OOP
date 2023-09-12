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
#include "../Service/urservice.h"
class GUI: public QWidget
{
private:
    Service* service;
    userService* uservice;
    URService* urservice, *adoption_urservice;
    AbstractAdoptionList* ad;

    /// graphical elements
    QWidget* user;
    QListWidget* dogsList;
    QLineEdit *dogName, *dogBreed, *dogAge, *dogLink;
    QPushButton *addButton, *updateButton, *deleteButton, *toUserButton, *exitButton;
    QPushButton *undoButton, *redoButton;

    QLineEdit *userDogName, *userDogBreed, *userDogAge, *userDogLink;
    QPushButton *adoptButton, *nextButton, *filterButton, *toAdminButton, *csvButton, *htmlButton, *adoptionButton, *userExitButton, *statisticsButton;
    QPushButton *userUndo, *userRedo;
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
    void showHTMLAdoption();
    void showTableAdoption();
    void filterDogs();
    void statistics();
    int getListIndex() const;
    void undo();
    void redo();
    void adoptionUndo();
    void adoptionRedo();
    std::vector<std::string> sortBreeds();
public:
    GUI(Service* s, userService* us, URService* urs, URService* adoption_urs);
};