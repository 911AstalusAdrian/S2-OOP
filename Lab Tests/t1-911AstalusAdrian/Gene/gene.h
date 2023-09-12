#ifndef T1_911ASTALUSADRIAN_1_GENE_H
#define T1_911ASTALUSADRIAN_1_GENE_H
#endif //T1_911ASTALUSADRIAN_1_GENE_H
#include <string>
#pragma once
class Gene{
private:
    std::string organism;
    std::string name;
    std::string sequence;

public:
    Gene(const std::string& _organism="", const std::string& _name="", const std::string& _sequence="");
    Gene(const Gene& copy_gene);
    ~Gene();

    const std::string& getOrganism() const;
    const std::string& getName() const;
    const std::string& getSequence() const;

    std::string toString() const;
};