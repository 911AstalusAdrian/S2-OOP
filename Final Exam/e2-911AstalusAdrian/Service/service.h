#pragma once
#ifndef E2_911ASTALUSADRIAN_SERVICE_H
#define E2_911ASTALUSADRIAN_SERVICE_H
#endif //E2_911ASTALUSADRIAN_SERVICE_H
#include "../Repo/repo.h"
#include "../Observer.h"

class Service: public Observable{
private:
    Repo& repo;
public:
    Service(Repo& r);
    ~Service() = default;
    std::vector<Building> getBuildingsServ();
    std::vector<Ethnologist> getEthnologistsServ();
    std::string giftShop(){return repo.getGiftShop();};
    std::vector<int> getBuildingCoordinates(Building& b);
    Building getBuildingByIndex(int index);
    void addBuilding(int i, std::string d, std::string a, std::vector<std::string> s);
};