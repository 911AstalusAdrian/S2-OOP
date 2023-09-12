#pragma once
#ifndef PRACTICALEX_REPO_H
#define PRACTICALEX_REPO_H
#endif //PRACTICALEX_REPO_H
#include <vector>
#include "../Issue/issue.h"
#include "../User/user.h"

class Repo{
private:
    std::vector<Issue> issues;
    std::vector<User> users;
    void readUsers();
    void readIssues();
    void write();

public:
    Repo();
    ~Repo() = default;
    std::vector<Issue> getIssues();
    std::vector<User> getUsers();
    void addIssue(Issue& i);
    void removeIssue(Issue& i);
    void updateIssue(Issue& i, std::string &solver);
    int findIssueIndex(Issue& i);
};
