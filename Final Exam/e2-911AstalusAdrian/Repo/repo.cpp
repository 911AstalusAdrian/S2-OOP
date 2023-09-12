#include "repo.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

Repo::Repo() {
    readEthnologists();
    readBuildings();
}

void Repo::readEthnologists() {
    ethnologists.clear();
    std::ifstream fin("ethnologists.txt",std::ios::in);
    std::vector<std::string> row;
    std::string line, word, temp;
    while (fin >> temp) {
        row.clear();
        std::stringstream s(temp);
        while (getline(s, word, ';')) {
            row.push_back(word);
        }
        if(row.size()==2){
            Ethnologist eth = Ethnologist(row[0], row[1]);
            ethnologists.push_back(eth);
        }
    }
}

void Repo::readBuildings() {
    buildings.clear();
    std::ifstream fin("buildings.txt",std::ios::in);
    std::vector<std::string> row;
    std::string word, temp;
    while (getline(fin, temp, '\n')) {
        row.clear();
        std::stringstream s(temp);
        while (getline(s, word, ';')) {
            row.push_back(word);
        }
        std::cout<<std::endl;
        std::vector<std::string> areas;
        for(int i=3; i<row.size();i++){
            areas.push_back(row[i]);
        }
        Building b = Building(stoi(row[0]), row[1], row[2], areas);
        buildings.push_back(b);

    }
}

void Repo::addBuilding(Building &b) {
    buildings.push_back(b);
}

int Repo::getBuildingPos(Building &b) {
    for(int i=0; i<buildings.size(); i++){
        if(b.getDescription() == buildings[i].getDescription())
            return i;
    }
    return -1;
}

void Repo::updateBuilding(int id, std::string new_desc, std::string new_loc) {
        int pos = getBuildingPosById(id);
        if(pos != -1){
//            buildings[pos].
        }
}

Building &Repo::getBuildingByIndex(int idx) {
    for(auto & building : buildings){
        if(building.getId() == idx)
            return building;
    }

}

int Repo::getBuildingPosById(int index) {
    for(int i=0; i<buildings.size(); i++){
        if(index == buildings[i].getId())
            return i;
    }
    return -1;
}

std::string Repo::getGiftShop() {
    for(auto b:buildings){
        if(b.getDescription() == "gift shop")
            return b.getSquares()[0];
    }
}

std::vector<int> Repo::getBuildingCoordRepo(Building &b) {
    std::vector<std::string> coords = b.getSquares();
    std::vector<int> values;
    for(auto c: coords){
        std::string square = c;
        int line = square.at(1) - '0' - 1;
        square[1] = 0;
        int col = square.at(0) - 64;
        int final = line*10+col;
        values.push_back(final);
    }

    return values;
}
