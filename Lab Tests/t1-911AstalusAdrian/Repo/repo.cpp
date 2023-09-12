

#include "repo.h"

Repository::Repository(int capacity) {
    this->capacity = capacity;
    this->length = 0;
    this->genes = new Gene[this->capacity];
}

Repository::~Repository() {
    delete[] genes;
}

void Repository::resize() {
    Gene* new_list = new Gene[this->capacity*2];
    for (int i=0; i<this->length; i++){
        new_list[i] = genes[i];
    }
    this->capacity = this->capacity*2;
    delete[] genes;
    genes = new_list;
}

/// Function to add a gene in the repo
/// \param gene - the gene that need adding
/// \return - 1 if it was successfully added, -1 otherwise
/// first, we search if the gene is already existent, using findGene
/// if it's already there, findGene returns 0 so the gene is not added
/// otherwise, we add the Gene to the repo and increase the length of the repo
int Repository::addGene(const Gene &gene) {
    int found = findGene(gene);
    if(found == -1)
        return -1;
    else{
        if(length == capacity)
            resize();
        genes[length] = gene;
        length++;
        return 1;
    }
}

/// Returns the index at which the gene is found, or -1 if it is not found
int Repository::findGene(const Gene &gene) {
    if (this->nrGenes() == 0)
        return 0;
    for (int i=0; i<length; i++){
        Gene each_gene = getGene(i);
        if (each_gene.getOrganism() == gene.getOrganism() && each_gene.getName() == gene.getName())
            return -1;
    }
    return 0;
}

int Repository::nrGenes() const {
    return this->length;
}

Gene *Repository::getAllGenes() {
    return this->genes;
}

Gene Repository::getGene(int index) {
    return genes[index];
}
