#include "repo.h"
#include <fstream>

Repo::Repo() {
    this->readUsers();
    this->readIssues();
}

void Repo::readUsers() {
    users.clear();
    std::ifstream in("users.txt");
    User usr;
    while(in >> usr){
        this->users.push_back(usr);
    }
}

void Repo::readIssues() {
    issues.clear();
    std::ifstream in("issues.txt");
    Issue i;
    while (in >> i){
        this->issues.push_back(i);
    }
}

void Repo::write() {
    std::ofstream out("issues.txt");
    for(auto i:issues)
        out << i << "\n";
}

std::vector<Issue> Repo::getIssues() {
    return this->issues;
}

std::vector<User> Repo::getUsers() {
    return this->users;
}

void Repo::addIssue(Issue &i) {
    if(findIssueIndex(i) == -1) {
        issues.push_back(i);
        write();
    }

}

void Repo::removeIssue(Issue &i) {
    if(findIssueIndex(i) != -1){
        issues.erase(issues.begin() + findIssueIndex(i));
        write();
    }
}

void Repo::updateIssue(Issue &i, std::string &solver) {
    int p = findIssueIndex(i);
    if(p != -1){
        issues[p].setStatus("closed");
        issues[p].setSolver(solver);
        write();
    }
}

int Repo::findIssueIndex(Issue &i) {
    for(int idx = 0; idx < issues.size(); idx++){
        if (issues[idx].getDesc() == i.getDesc())
            return idx;
    }
    return -1;
}
