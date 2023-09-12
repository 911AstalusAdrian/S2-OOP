#include "service.h"

Service::Service(Repo &r): repo(r) {}

std::vector<Building> Service::getBuildingsServ() {
    return repo.getBuildings();
}

std::vector<Ethnologist> Service::getEthnologistsServ() {
    return repo.getEthnologists();
}

std::vector<int> Service::getBuildingCoordinates(Building &b) {
    return repo.getBuildingCoordRepo(b);
}

Building Service::getBuildingByIndex(int index) {
    return repo.getBuildingByIndex(index);
}

void Service::addBuilding(int i, std::string d, std::string a, std::vector<std::string> s) {
    Building b = Building(i,d,a,s);
    this->repo.addBuilding(b);
}
