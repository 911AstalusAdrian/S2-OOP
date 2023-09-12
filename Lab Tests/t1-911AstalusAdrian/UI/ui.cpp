#include <iostream>
#include "ui.h"

UI::UI(Service *service) {
    this->service = service;
}

void UI::start() {
    this->service->initialise();
    bool done = false;
    while (!done){
        menu();
        int option;
        std::cout<<"Option~";
        std::cin>>option;
        switch (option) {
            case 1:
                addGeneUI();
                continue;
            case 2:
                listGenesUI();
                continue;
            case 3:
                filterGenesUI();
                continue;
            case 4:
                subsequenceUI();
                continue;
            case 0:
                done = true;
                std::cout<<"Bye!"<<"\n";
                continue;
            default:
                std::cout<<"Invalid command!"<<"\n";
        }
    }
}

void UI::menu() {
    std::cout<<"\n"<<"1. Add gene"<<"\n";
    std::cout<<"2. List genes"<<"\n";
    std::cout<<"3. Filter genes"<<"\n";
    std::cout<<"4. Longest subsequence"<<"\n";
    std::cout<<"0. Exit"<<"\n";
}

void UI::addGeneUI() {
    std::string organism, name, sequence, buffer;
    std::getline(std::cin,buffer);
    std::cout<<"Organism: ";
    std::getline(std::cin, organism);
    std::cout<<"Name: ";
    std::cin>>name;
    std::cout<<"Sequence: ";
    std::cin>>sequence;
    if(this->service->addGeneService(organism, name, sequence) == -1)
        std::cout<<"This gene could not be added!"<<"\n";
    else
        std::cout<<"Gene added!"<<"\n";
}

void UI::listGenesUI() {
    int number = this->service->countGenes();
    for(int i=0; i<number; i++){
        Gene gene = this->service->getGeneService(i);
        std::cout.width(15); std::cout<<std::left<<gene.getOrganism()<<" | "<<gene.getName()<<" | "<<std::right<<gene.getSequence()<<"\n";
    }
}

void UI::subsequenceUI() {

}

void UI::filterGenesUI() {
    std::string subseq, buffer;
    std::getline(std::cin, buffer);
    std::cout<<"Subsequence:";
    std::getline(std::cin, subseq);
    Repository filtered = this->service->filterGenes(subseq);
    for (int i=0;i<filtered.nrGenes(); i++){
        Gene gene = filtered.getGene(i);
        std::cout<<gene.toString()<<"\n";
    }
}
