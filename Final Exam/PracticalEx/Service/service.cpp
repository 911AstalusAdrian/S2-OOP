#include "service.h"

Service::Service(Repo &r): repo(r) {}

std::vector<Issue> Service::getServiceIssues() {
    return repo.getIssues();
}

std::vector<User> Service::getServiceUsers() {
    return repo.getUsers();
}

void Service::addServiceIssue(std::string desc, std::string stat, std::string rep, std::string sol) {
    Issue i = Issue(desc, stat, rep, sol);
    repo.addIssue(i);
    notify();
}

void Service::deleteServiceIssue(Issue &i) {
    repo.removeIssue(i);
    notify();
}

void Service::updateServiceIssue(Issue &i, std::string solver_name) {
    repo.updateIssue(i, solver_name);
    notify();
}

std::vector<Issue> Service::sortedIssues() {
    std::vector<Issue> s = getServiceIssues();
    std::sort(s.begin(), s.end(), [](Issue& i1, Issue &i2){
        if (i1.getDesc() != i2.getDesc()) return i1.getDesc() < i2.getDesc();
        return i1.getStatus() < i2.getStatus();
    });
    return s;
}

Issue Service::getIssueIndex(int idx) {
    std::vector<Issue> issues = this->getServiceIssues();
    return issues[idx];
}
