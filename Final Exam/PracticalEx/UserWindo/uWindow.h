#pragma once
#ifndef PRACTICALEX_UWINDOW_H
#define PRACTICALEX_UWINDOW_H
#endif //PRACTICALEX_UWINDOW_H
#include "../Observer.h"
#include "../Service/service.h"
#include "../User/user.h"
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>

class userWindow: public Observer, public QWidget{
private:
    Service& serv;
    User& user;

    QListWidget* issuesList;
    QPushButton* addBtn, *resolveBtn, *removeBtn;
    QLineEdit* issueDescription;


    void populateIssues();
    void initGUI();
    void connect();
    int getListIndex();
    void update() override;

    void AddIssue();
    void ResolveIssue();
    void RemoveIssue();

public:
    userWindow(Service& s, User& u);
    ~userWindow();
};
