#include "hospital.h"
#include <fstream>

HospitalDepartment::HospitalDepartment(std::string name, int nd): hospitalName(name), numberOfDoctors(nd) {}

HospitalDepartment::HospitalDepartment() {}

NeonatalUnit::NeonatalUnit(std::string name, int nd, int m, int n, double g) : HospitalDepartment(name, nd), numberOfMothers(m), numberOfNewborns(n), averageGrade(g) {

}

bool NeonatalUnit::isEfficient() {
    if (averageGrade > 8.5 && numberOfNewborns >= numberOfMothers)
        return true;
    else return false;
}

std::string NeonatalUnit::toString() {
    std::string message;
    message.append("Neonatal Unit ");
    message.append(hospitalName);
    message.append(" - ");
    message.append(std::to_string(numberOfDoctors));
    message.append(" doctors - ");
    message.append(std::to_string(numberOfMothers));
    message.append(" mothers, ");
    message.append(std::to_string(numberOfMothers));
    message.append(" babies, average grade: ");
    message.append(std::to_string(averageGrade));
    message.append("\n");
    return message;
}

Surgery::Surgery(std::string name, int nd, int p): HospitalDepartment(name, nd), numberOfPatients(p) {}

bool Surgery::isEfficient() {
    if(numberOfPatients >= 2 * numberOfDoctors)
        return true;
    else return false;
}

std::string Surgery::toString() {
    std::string message;
    message.append("Surgery ");
    message.append(hospitalName);
    message.append(" - ");
    message.append(std::to_string(numberOfDoctors));
    message.append(" doctors - ");
    message.append(std::to_string(numberOfPatients));
    message.append(" patients\n");
    return message;
}

Controller::Controller() {

}

void Controller::addDepartment(HospitalDepartment *d) {
    departments.push_back(d);
}

std::vector<HospitalDepartment *> Controller::getAllDepartments() {
    return departments;
}

std::vector<HospitalDepartment *> Controller::getAllEfficientDepartments() {
    std::vector<HospitalDepartment*> efficient;
    for(auto dep: departments){
        if(dep->isEfficient())
            efficient.push_back(dep);
    }
    return efficient;
}

void Controller::writeToFile(std::string name) {
//    std::ifstream in(name);
    std::ofstream out(name);
    for (auto dep: departments){
        std::string mes = dep->toString();
        out << mes;
    }
}

