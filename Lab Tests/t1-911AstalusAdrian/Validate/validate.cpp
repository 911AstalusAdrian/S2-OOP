#include "validate.h"
#include "../Repo/repo.h"
#include <assert.h>
void tests(){
    Repository repo = Repository(2);
    Gene gene1 = Gene("E_Coli_K12", "yqgE", "ATGACATCATCATTG");
    Gene gene2 = Gene("M_tuberculosis", "ppiA", "TCTTCATCATCATCGG");
    Gene gene3 = Gene("Mouse", "Col2a1", "TTAAAGCATGGCTCTGTG");
    assert(repo.addGene(gene1) == 1);
    assert(repo.addGene(gene2) == 1);
    assert(repo.addGene(gene1) == -1);
}