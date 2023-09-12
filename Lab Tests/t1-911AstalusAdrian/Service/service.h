#pragma once
#ifndef T1_911ASTALUSADRIAN_1_SERVICE_H
#include "../Repo/repo.h"
#include <string>
#define T1_911ASTALUSADRIAN_1_SERVICE_H

#endif //T1_911ASTALUSADRIAN_1_SERVICE_H
class Service{
private:
    Repository* repo;
public:
    void initialise();
    Service(Repository* repo);
    ~Service();
    int addGeneService(const std::string& organism, const std::string& name, const std::string& sequence);
    Repository filterGenes(const std::string& subsequence);
    void commonSubseq(const Gene& gene1, const Gene& gene2);
    Repository* getRepo();
    int countGenes();
    Gene getGeneService(int index);
};