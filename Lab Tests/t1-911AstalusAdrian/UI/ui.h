#ifndef T1_911ASTALUSADRIAN_1_UI_H

#define T1_911ASTALUSADRIAN_1_UI_H
#include "../Service/service.h"
#endif //T1_911ASTALUSADRIAN_1_UI_H
#pragma once

class UI{
private:
    Service* service;

public:
    UI(Service* service);
    void start();
    void menu();
    void addGeneUI();
    void listGenesUI();
    void filterGenesUI();
    void subsequenceUI();
};