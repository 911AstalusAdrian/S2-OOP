#include "FileRepo/filerepo.h"
#include "Service/service.h"
#include "UI/ui.h"
//using namespace std;
//
//
//
//
//#include "iostream"
//#include "FileRepo/CSVAdoption.h"
//#include "FileRepo/HTMLAdoption.h"

int main(){
    FileRepository repo = FileRepository("textfile.txt");
    Service service = Service(&repo);
    userService us = userService(&repo);
    UI ui = UI(&service, &us);
    ui.start();
//     HTMLAdoptionList hv = HTMLAdoptionList();
//     std::vector<Dog> doggies;
//     Dog dog_1 = Dog("Husky", "Luna", 5, "picture_link");
//     Dog dog_2 = Dog("German Shepherd", "Max", 7, "pic_link2");
//     Dog dog_3 = Dog("Bulldog", "Lucas", 4, "pic_link3");
//     Dog dog_4 = Dog("English Bulldog", "Terry", 6, "pic_link4");
//     std::cout<<dog_1.HTMLRepresentation();
//     doggies.push_back(dog_2);
//     doggies.push_back(dog_1);
//     doggies.push_back(dog_4);
//     doggies.push_back(dog_3);
//     hv.createList(doggies);
//     hv.write();
//     hv.open();

    return 0;
}