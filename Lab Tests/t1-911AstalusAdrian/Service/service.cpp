#include "service.h"
#include "../Validate/validate.h"
#include <string.h>

Service::Service(Repository *repo) {
    this->repo = repo;
}

Service::~Service() {

}


/// Given the user input, we create a gene and try to add it to te repo
/// \param organism - Gene organism
/// \param name - gene name
/// \param sequence - gene sequence
/// \return 1 if the gene was successfully addded, -1 otherwise
int Service::addGeneService(const std::string &organism, const std::string &name, const std::string &sequence) {
        Gene new_gene = Gene(organism, name, sequence);
        if(this->repo->addGene(new_gene) == -1)
            return -1;
        else
            return 1;
}

Repository Service::filterGenes(const std::string &subsequence) {
    Repository filter = Repository(repo->nrGenes());
    for (int i=0; i<repo->nrGenes(); i++){
        Gene gene = repo->getGene(i);
        size_t found = gene.getSequence().find(subsequence);
        if (found != std::string::npos)
            filter.addGene(gene);
    }
    return filter;
}

void Service::commonSubseq(const Gene &gene1, const Gene &gene2) {

}

Repository *Service::getRepo() {
    return this->repo;
}

void Service::initialise() {
    addGeneService("E_Coli_K12", "yqgE", "ATGACATCATCATTG");
    addGeneService("M_tuberculosis", "ppiA", "TCTTCATCATCATCGG");
    addGeneService("Mouse", "Col2a1", "TTAAAGCATGGCTCTGTG");
    addGeneService("E_Coli_ETEC", "yqgE", "GTGACAGCGCCCTTCTTTCCACG");
    addGeneService("E_Coli_K12", "hokC", "TTAATGAAGCATAAGCTTGATTTC");
}

int Service::countGenes() {
    return this->repo->nrGenes();
}

Gene Service::getGeneService(int index) {
    return this->repo->getGene(index);
}
