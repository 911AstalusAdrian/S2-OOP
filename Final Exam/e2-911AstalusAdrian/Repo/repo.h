#pragma once
#ifndef E2_911ASTALUSADRIAN_REPO_H
#define E2_911ASTALUSADRIAN_REPO_H
#endif //E2_911ASTALUSADRIAN_REPO_H
#include <vector>
#include <string>
#include "../Buildings/building.h"
#include "../Ethnologists/ethnologist.h"

class Repo{
private:
    std::vector<Building> buildings;
    std::vector<Ethnologist> ethnologists;

    void readEthnologists();
    void readBuildings();

public:
    Repo();
    ~Repo() = default;
    void addBuilding(Building& b);
    void updateBuilding(int id, std::string new_desc, std::string new_loc);
    int getBuildingPos(Building& b);
    int getBuildingPosById(int index);
    Building& getBuildingByIndex(int idx);
    std::vector<Building> getBuildings(){return buildings;};
    std::vector<Ethnologist> getEthnologists(){return ethnologists;};
    std::string getGiftShop();
    std::vector<int> getBuildingCoordRepo(Building& b);

};
