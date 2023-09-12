#pragma once
#ifndef E3_911ASTALUSADRIAN_PLAYER_H
#define E3_911ASTALUSADRIAN_PLAYER_H
#endif //E3_911ASTALUSADRIAN_PLAYER_H
#include <iostream>
#include <string>

class Player{
private:
    std::string name;
    int nr;
public:
    Player(std::string n, int number): name(n), nr(number){};
    Player(){};
    ~Player() = default;
    std::string getName(){return name;}
    void setNr(int number){nr = number;}
    int getNr(){return nr;};
    friend std::istream& operator>>(std::istream& is, Player& p);
};