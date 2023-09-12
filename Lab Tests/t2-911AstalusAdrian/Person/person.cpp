#include "fstream"
#include "person.h"

void Person::addMeasurment(Measurement *const a) {
    measurements.push_back(a);
}

std::vector<Measurement*> Person::getAllMeasurements() {
    return measurements;
}

bool Person::isHealthy(int month) {
    if(month == 1){
        for(auto m: measurements){
            std::string date = m->getDate();
            int check_month = stoi(date.substr(3, 2));
            if(month == check_month){
                if(!m->isNormalValue())
                    return false;
            }
        }
    }
    else
        for(auto m: measurements){
        std::string date = m->getDate();
        int check_month = stoi(date.substr(3, 2));
        if(month - check_month < 2 && month >= check_month){
            if(!m->isNormalValue())
                return false;
        }
    }
    return true;
}

std::vector<Measurement*> Person::getMeasurementsNewerThan(const std::string& date) {
    std::vector<Measurement*> filter;
    for(auto m: measurements){
        std::string check_date = m->getDate();
        if(check_date > date)
            filter.push_back(m);
    }
    return filter;
}

void Person::writeToFile(const std::string& filename, const std::string& date) {
    std::ofstream out(filename);
    std::vector<Measurement*> filter = getMeasurementsNewerThan(date);
    for(auto m: filter){
        out<<m->toString()<<" "<<m->getDate()<<"\n";
    }
}

std::vector<Measurement*>Person::getMeasurementsByMonth(int month) {
    std::vector<Measurement*> filter;
    for(auto m: measurements){
        std::string check_date = m->getDate();
        int check_month = stoi(check_date.substr(3, 2));
        if(check_month == month)
            filter.push_back(m);
    }
    return filter;
}

std::string Person::getName() {
    return this->name;
}

Person::Person(std::string &name): name{name}
{}
