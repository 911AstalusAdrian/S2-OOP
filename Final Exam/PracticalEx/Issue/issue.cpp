
#include "issue.h"

Issue::Issue(std::string desc, std::string stat, std::string rep, std::string sol):
description(desc), status(stat), reporter(rep), solver(sol)
{}

std::string Issue::getDesc() {
    return description;
}

std::string Issue::getStatus() {
    return status;
}

std::string Issue::getReporter() {
    return reporter;
}

std::string Issue::getSolver() {
    return solver;
}

void Issue::setStatus(std::string new_stat) {
    this->status = new_stat;
}

void Issue::setReporter(std::string new_rep) {
    this->reporter = new_rep;
}

void Issue::setSolver(std::string new_sol) {
    this->solver = new_sol;
}

std::ostream &operator<<(std::ostream &os, Issue &i) {
    std::string mes;
    mes.append(i.description);
    mes.append(" ");
    mes.append(i.status);
    mes.append(" ");
    mes.append(i.reporter);
    mes.append(" ");
    mes.append(i.solver);
    os << mes;
    return os;
}

std::istream &operator>>(std::istream &is, Issue &i) {
    is >> i.description >> i.status >> i.reporter >> i.solver;
    return is;
}

Issue::Issue() {

}

std::string Issue::toStr() {
    std::string final;
    final.append(description);
    final.append(" | ");
    final.append(status);
    final.append(" | ");
    final.append(reporter);
    final.append(" | ");
    final.append(solver);

    return final;
}
