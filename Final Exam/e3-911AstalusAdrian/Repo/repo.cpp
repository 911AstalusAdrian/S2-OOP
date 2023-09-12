#include "repo.h"
#include <fstream>

Repo::Repo() {
    this->readData();
}

void Repo::readData() {
    int count = 0;
    std::string name;
    players.clear();
    std::ifstream in("input.txt");
    in >> size;
    in >> mines;
    Player p;
    while (in >> p) {
        p.setNr(count);
        players.push_back(p);
        count++;
    }

    this->minefield = new int *[size];
    for (int i = 0; i < size; i++)
        this->minefield[i] = new int[size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            minefield[i][j] = 0;

    setMines();
}
std::vector<Player> Repo::getPlayers() {
    return players;
}

void Repo::setMines() {
    int i = 0;
    while( i < mines)
    {
        int line = rand() % size;
        int col = rand() % size;
        if(minefield[line][col] == 0){
            minefield[line][col] = -1;
            if(line != 0){
                this->minefield[line-1][col] += 1;
                if(col != 0) this->minefield[line-1][col-1] += 1;
                if(col != size-1) this->minefield[line-1][col+1] += 1;
            }
            if(line != size - 1){
                this->minefield[line+1][col] += 1;
                if(col != 0) this->minefield[line+1][col-1] += 1;
                if(col != size-1) this->minefield[line+1][col+1] += 1;
            }
            if(col != 0) this->minefield[line][col-1] += 1;
            if(col != size-1) this->minefield[line][col+1] += 1;

            i++;
        }
    }
}



