#pragma once
#ifndef PRACTICALEX_SERVICE_H
#define PRACTICALEX_SERVICE_H
#endif //PRACTICALEX_SERVICE_H
#include "../Issue/issue.h"
#include "../User/user.h"
#include "../Repo/repo.h"
#include "../Observer.h"
#include <vector>
#include <string>
#include <algorithm>

class Service: public Observable{
private:
    Repo& repo;
public:
    Service(Repo& r);
    ~Service() = default;
    std::vector<Issue> getServiceIssues();
    std::vector<User> getServiceUsers();
    Issue getIssueIndex(int idx);
    std::vector<Issue> sortedIssues();
    void addServiceIssue(std::string desc, std::string stat, std::string rep, std::string sol);
    void deleteServiceIssue(Issue &i);
    void updateServiceIssue(Issue& i, std::string solver_name);
};