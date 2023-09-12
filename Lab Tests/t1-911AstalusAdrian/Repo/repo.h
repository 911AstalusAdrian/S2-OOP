#ifndef T1_911ASTALUSADRIAN_1_REPO_H
#pragma once
#include <gene.h>

#define T1_911ASTALUSADRIAN_1_REPO_H
#endif //T1_911ASTALUSADRIAN_1_REPO_H

class Repository{
private:
    Gene* genes;
    int length;
    int capacity;

public:
    Repository(int capacity=10);
    ~Repository();
    void resize();
    int addGene(const Gene& gene);
    int findGene(const Gene& gene);
    Gene getGene(int index);
    int nrGenes() const;
    Gene* getAllGenes();

};