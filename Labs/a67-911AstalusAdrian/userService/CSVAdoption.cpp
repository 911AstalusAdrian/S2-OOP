#include "CSVAdoption.h"
#include "../Exceptions/exception.h"
#include <fstream>
#include <windows.h>

CSVAdoptionList::CSVAdoptionList() {
    this->fileName = R"(D:\Uni\OOP\a67-911AstalusAdrian\example.csv)";
}

CSVAdoptionList::~CSVAdoptionList() {

}

void CSVAdoptionList::write() {
    std::ofstream out(this->fileName, ios::in);
    if(!out.is_open())
        throw RepositoryException("Could not open file!");
    for(const auto& dog: this->list)
        out<<dog.CSVRepresentation()<<"\n";
}

void CSVAdoptionList::open() {
    std::ifstream in(this->fileName);
    if(!in.is_open())
        throw RepositoryException("Could not open file!");

    ShellExecute(nullptr, "open", "example.csv", nullptr, nullptr, SW_SHOWNORMAL);
    in.close();
}

//void CSVAdoptionList::createList(std::vector<Dog> adoptionList) {
//    for(const auto& dog: adoptionList)
//        list.push_back(dog);
//}
