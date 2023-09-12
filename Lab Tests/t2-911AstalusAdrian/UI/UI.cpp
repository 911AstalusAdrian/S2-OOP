#include "iostream"
#include "UI.h"
#include "../Validation/validation.h"

void UI::start() {
    std::cout<<"Hello there!\n";
    int option;
    bool done = false;
    while(!done) {
        print();
        std::cout << "Option~";
        std::cin>>option;
        switch (option) {
            case 1:
                add();
                continue;
            case 2:
                allMeasurements();
                continue;
            case 3:
                isHealthy();
                continue;
            case 4:
                toFile();
                continue;
            case 0:
                done = true;
                continue;
            default:
                std::cout<<"Invalid option!\n";
        }
    }

}

void UI::print() {
    std::string option;
    std::cout<<"1. Add measurement\n";
    std::cout<<"2. Display measurements\n";
    std::cout<<"3. Check health\n";
    std::cout<<"4. Write data to file\n";
    std::cout<<"0. Exit\n";

}

void UI::allMeasurements() {
    std::vector<Measurement*> measurements = p->getAllMeasurements();
    std::cout<<p->getName()<<"\n";
    for(auto m: measurements){
        std::cout<<m->toString()<<"\n";
    }
}

void UI::isHealthy() {
    int month;
    std::cout<<"Give the month~";
    std::cin>>month;
    if(p->isHealthy(month))
        std::cout<<"Person is healthy!\n";
    else
        std::cout<<"Person is not healthy\n";
}

void UI::toFile() {
    std::string filename, buffer, date;
    std::cout<<"Give the file name~";
    getline(std::cin, buffer);
    getline(std::cin, filename);
    getline(std::cin, date);
    try{
        Validation::check_date(date);
        p->writeToFile(filename, date);
        std::cout<<"Successful write!\n";
    }
    catch (Exception &e){
        std::cout<<e.getError();
    }
}

void UI::add() {
    Measurement* m;
    std::string buffer, date, option;
    std::cout<<"Give measurement date~";
    getline(std::cin, buffer);
    getline(std::cin, date);
    try{
        Validation::check_date(date);
        std::cout<<"Option (BP or BMI)~";
        std::getline(std::cin, option);
        if(option == "BP"){
            int sys, dia;
            std::cout<<"Give values (systolic and diastolic)";
            std::cin>>sys;
            std::cin>>dia;
            m = new BP(sys, dia);
        }
        if(option == "BMI"){
            double val;
            std::cout<<"Give value";
            std::cin>>val;
            m = new BMI(val);
        }
    }
    catch (Exception &e) {
        std::cout<<e.getError();
    }
}

UI::UI(Person* p) {
    this->p = p;
}
