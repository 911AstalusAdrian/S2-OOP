#include "gene.h"

Gene::Gene(const std::string &_organism, const std::string &_name, const std::string &_sequence) : organism(_organism),
name(_name),
sequence(_sequence)
{}

Gene::Gene(const Gene &copy_gene) : organism{copy_gene.organism},
name{copy_gene.name},
sequence{copy_gene.sequence}
{}

Gene::~Gene() {

}

std::string Gene::toString() const {
    std::string final = organism + " | " + name + " | " + sequence;
    return final;
}

const std::string &Gene::getOrganism() const {
    return this->organism;
}

const std::string &Gene::getName() const {
    return this->name;
}

const std::string &Gene::getSequence() const {
    return this->sequence;
}

