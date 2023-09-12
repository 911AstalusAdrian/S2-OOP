#pragma once
#ifndef UNTITLED_HOSPITAL_H
#define UNTITLED_HOSPITAL_H
#endif //UNTITLED_HOSPITAL_H
#include <string>
#include <vector>

class HospitalDepartment{
protected:
    std::string hospitalName;
    int numberOfDoctors;
public:
    HospitalDepartment(std::string name, int nd);
    HospitalDepartment();
    ~HospitalDepartment() = default;
    virtual bool isEfficient() = 0;
    virtual std::string toString() = 0;
};

class NeonatalUnit: public HospitalDepartment{
private:
    int numberOfMothers, numberOfNewborns;
    double averageGrade;
public:
    NeonatalUnit(std::string name, int nd, int m, int n, double g);
    ~NeonatalUnit() = default;
    bool isEfficient() override;
    std::string toString();
};

class Surgery: public HospitalDepartment{
private:
    int numberOfPatients;
public:
    Surgery(std::string name, int nd, int p);
    ~Surgery() = default;
    bool isEfficient() override;
    std::string toString() ;
};


class Controller{
private:
    std::vector<HospitalDepartment*> departments;
public:
    Controller();
    ~Controller() = default;
    void addDepartment(HospitalDepartment* d);
    std::vector<HospitalDepartment*> getAllDepartments();
    std::vector<HospitalDepartment*> getAllEfficientDepartments();
    void writeToFile(std::string name);
};