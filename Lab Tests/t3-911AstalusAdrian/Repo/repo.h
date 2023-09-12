#pragma once
#include "../Weather/weather.h"
#ifndef T3_911ASTALUSADRIAN_REPO_H
#define T3_911ASTALUSADRIAN_REPO_H
#endif //T3_911ASTALUSADRIAN_REPO_H
#include <string>
#include <vector>

class RepositoryException{
private:
    std::string repo_error;

public:
    /// Constructor and destructor
    RepositoryException(std::string message);
    ~RepositoryException();
    /// Message getter
    std::string getRepoError();
};



class Repo{
private:
    std::string file_name;
    std::vector<Weather> read();
    void write(std::vector<Weather> weather);

public:
    Repo(const std::string& filename);
    ~Repo();
    void addWeather(const Weather& w);
    void removeDog(const Weather& w);
    void updateWeather(const Weather& w, const Weather& new_weather);
    Weather getWeather(int index);
    int nrWeathers();
    int getIndex(const Weather& w);
    std::vector<Weather> getRepo();
};
