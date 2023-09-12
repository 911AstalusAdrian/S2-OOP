#pragma once
#ifndef E3_911ASTALUSADRIAN_SERVICE_H
#define E3_911ASTALUSADRIAN_SERVICE_H
#endif //E3_911ASTALUSADRIAN_SERVICE_H
#include "../Player/player.h"
#include "../Repo/repo.h"
#include "../Observer.h"
#include <vector>
#include <string>
#include <algorithm>

class Exception{
private:
    std::string error;

public:
    Exception(std::string message):error(message){};
    ~Exception() = default;
    std::string getError(){return error;};
};
class EndException{
private:
    std::string error;

public:
    EndException(std::string message):error(message){};
    ~EndException() = default;
    std::string getError(){return error;};
};

class Service: public Observable{
private:
    Repo& repo;
    int turn = 0;
    int correctMines = 0;
    int activePlayers;

public:
    int** tableData;

    Service(Repo& r);
    ~Service() = default;
    std::vector<Player> getServicePlayers();
    int getMinefieldSize();
    int getNrOfMines();
    int getMinefieldValue(int line, int col);
    void markMine(int col, int line);
    void revealCell(int col, int line, Observer* o);
    void markAdjacentCells(int line, int col);
    int getTurn();
};