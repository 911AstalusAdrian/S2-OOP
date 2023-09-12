
#include "service.h"

std::vector<Player> Service::getServicePlayers() {
    return repo.getPlayers();
}

int Service::getMinefieldSize() {
    return repo.getSize();
}

int Service::getNrOfMines() {
    return repo.getMineCount();
}

int Service::getMinefieldValue(int line, int col) {
    return repo.getValue(line, col);
}

Service::Service(Repo &r): repo(r) {
    this->activePlayers = repo.getPlayerCount();
    this->tableData = new int *[r.getSize()];
    for (int i = 0; i < r.getSize(); i++)
        this->tableData[i] = new int[r.getSize()];

    for (int i = 0; i < r.getSize(); i++)
        for (int j = 0; j < r.getSize(); j++)
            this->tableData[i][j] = 0;
}

void Service::markMine(int col, int line) {
    this->tableData[line][col] = 9;
    if(this->getMinefieldValue(line, col) == -1)
        correctMines++;
    if(this->correctMines == this->getNrOfMines())
        throw Exception("Game won!");
    this->turn ++;
    if(turn == this->repo.getPlayerCount())
        turn = 0;
    this->notify();
}

void Service::revealCell(int col, int line, Observer* o) {
    if(this->getMinefieldValue(line, col) == -1){ /// Revealed a mine
        this->activePlayers -= 1;
        if(this->activePlayers == 0){
            throw Exception("Game over!");
        }
        this->removeObserver(o);
        throw EndException("That's a mine! Game over!");
    }
    else{
        this->tableData[line][col] = 2; /// 2 marks it as revealed;
        markAdjacentCells(line, col);
    }
    this->turn ++;
    if(turn == this->repo.getPlayerCount())
        turn = 0;
    this->notify();
}

int Service::getTurn() {
    return turn;
}

void Service::markAdjacentCells(int line, int col) {
    if(line != 0){
        if(this->tableData[line-1][col] == 0 && getMinefieldValue(line-1, col) != -1)this->tableData[line-1][col] = 1;
        if(col != 0 && this->tableData[line-1][col-1] == 0 && getMinefieldValue(line-1, col-1) != -1) this->tableData[line-1][col-1] = 1;
        if(col != this->getMinefieldSize() - 1 && this->tableData[line-1][col+1] == 0 && getMinefieldValue(line-1, col+1) != -1) this->tableData[line-1][col+1] = 1;
    }
    if(line != this->getMinefieldSize() - 1){
        if(this->tableData[line+1][col] == 0 && getMinefieldValue(line+1, col) != -1) this->tableData[line+1][col] = 1;
        if(col != 0 && this->tableData[line+1][col-1] == 0 && getMinefieldValue(line+1, col-1) != -1) this->tableData[line+1][col-1] = 1;
        if(col != this->getMinefieldSize() - 1 && this->tableData[line+1][col+1] == 0 && getMinefieldValue(line+1, col+1) != -1) this->tableData[line+1][col+1] = 1;
    }
    if(col != 0 && this->tableData[line][col-1] == 0 && getMinefieldValue(line, col-1) != -1) this->tableData[line][col-1] = 1;
    if(col != this->getMinefieldSize() - 1 && this->tableData[line][col+1] == 0 && getMinefieldValue(line, col+1) != -1) this->tableData[line][col+1] = 1;
}
