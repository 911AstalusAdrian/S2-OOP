#pragma once
#ifndef UNTITLED1_REPO_H
#define UNTITLED1_REPO_H
#endif //UNTITLED1_REPO_H
#include <vector>
#include <string>
#include "../Player/player.h"
class Repo{
private:

    int mines, size;
    std::vector<Player> players;
    int** minefield;
    void readData();
    void setMines();

public:
    Repo();
    ~Repo() = default;
    std::vector<Player> getPlayers();
    int getMineCount(){return mines;};
    int getSize(){return size;};
    int getValue(int line, int col){return minefield[line][col];};
    int getPlayerCount(){return players.size();};
};
