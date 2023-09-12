#pragma once
#ifndef PRACTICALEX_ISSUE_H
#define PRACTICALEX_ISSUE_H
#endif //PRACTICALEX_ISSUE_H
#include <string>

class Issue{
private:
    std::string description, status, reporter, solver;
public:
    Issue(std::string desc, std::string stat, std::string rep, std::string sol);
    Issue();
    ~Issue() = default;
    std::string getDesc();
    std::string getStatus();
    std::string getReporter();
    std::string getSolver();
    void setStatus(std::string new_stat);
    void setReporter(std::string new_rep);
    void setSolver(std::string new_sol);
    std::string toStr();

    friend std::ostream& operator<<(std::ostream& os, Issue& i);
    friend std::istream& operator>>(std::istream& is, Issue& i);
};
