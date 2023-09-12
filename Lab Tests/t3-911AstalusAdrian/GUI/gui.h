#pragma once

#include <QWidget>
#include <QListWidget>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPushButton>
#include "../Repo/repo.h"
#include "../Weather/weather.h"
#ifndef T3_911ASTALUSADRIAN_GUI_H
#define T3_911ASTALUSADRIAN_GUI_H
#endif //T3_911ASTALUSADRIAN_GUI_H

class GUI: public QWidget{

    Q_OBJECT

private:
    Repo* repo;
    QWidget* user;
    QListWidget* list;
    QHBoxLayout* hL;
    QSpinBox* spinner;
    QSlider* slider;
    QCheckBox* overcast;
    QCheckBox* foggy;
    QCheckBox* sunny;
    QCheckBox* rain;
    QCheckBox* thunderstorm;
    QPushButton* reset;
    int value;
    void start();
    void populate(std::vector<Weather> repo);
    void connections();
    void resetSlider();
    int getListIndex() const;
    void filter(int val);

public slots:
    void setFValue(int val);

public:
    GUI(Repo* r);
};
