#pragma once
#ifndef E3_911ASTALUSADRIAN_WINDOW_H
#define E3_911ASTALUSADRIAN_WINDOW_H
#endif //E3_911ASTALUSADRIAN_WINDOW_H
#include "../Observer.h"
#include "../Service/service.h"
#include "../Player/player.h"
#include "../TableModel/model.h"
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTableView>

class userWindow: public Observer, public QWidget{
private:
    Service& serv;
    Player& player;

    QPushButton* revealBtn, *markBtn;
    QLineEdit* coordinate;
    QTableView* minefield;
    TModel* model;


    void initGUI();
    void connect();
    void updateObserver() override;
    void markCell();
    void revealCell();

public:
    userWindow(Service& s, Player& p);
    ~userWindow() = default;
};
