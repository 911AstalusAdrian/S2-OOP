#pragma once
#ifndef E2_911ASTALUSADRIAN_EWINDOW_H
#define E2_911ASTALUSADRIAN_EWINDOW_H
#endif //E2_911ASTALUSADRIAN_EWINDOW_H
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QTableWidget>
#include "../Observer.h"
#include "../Service/service.h"
#include "../Ethnologists/ethnologist.h"

class eWindow: public QWidget, public Observer{
private:
    Service& serv;
    Ethnologist& eth;

// /replace with QMatrix?

    QTableView* zone;
    QLineEdit* buildingIdx, *buildingDesc, *buildingCorresp, *buildingSquares;
    QPushButton* addBtn, *updateBtn;
    QLineEdit* issueDescription;

    void init();
    void populate();
    void connections();
    void update() override;
    int getListIndex() const;
public:
    eWindow(Service& s, Ethnologist& e);
    ~eWindow();
    void addBuilding();
};
