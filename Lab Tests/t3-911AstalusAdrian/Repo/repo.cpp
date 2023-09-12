#include <fstream>
#include <sstream>
#include "repo.h"

void Repo::write(std::vector<Weather> weather) {
    std::ofstream  out(this->file_name);
    for(const auto& w: weather)
        out<< w<<"\n";
}

Repo::Repo(const std::string &filename) {
    this->file_name = filename;
}

void Repo::addWeather(const Weather &w) {
    std::vector<Weather> weathers = read();
    if(getIndex(w) >= 0)
        throw RepositoryException("this weather already exists");
    weathers.push_back(w);
    write(weathers);
}

Repo::~Repo() {

}

void Repo::removeDog(const Weather &w) {
    std::vector<Weather> weathers = read();
    int index = getIndex(w);
    if(index<0)
        throw RepositoryException("This weather does not exist");
    weathers.erase(weathers.begin() + index);
    write(weathers);
}

void Repo::updateWeather(const Weather &w, const Weather &new_weather) {
    std::vector<Weather> weathers = read();
    int index = getIndex(w);
    if (index < 0)
        throw RepositoryException("This weather does not exist");
    weathers[index] = new_weather;
    write(weathers);
}

Weather Repo::getWeather(int index) {
    if (index < 0 || index >= nrWeathers())
        throw RepositoryException("invalid index");
    std::vector<Weather> weathers = read();
    return weathers[index];
}

int Repo::nrWeathers() {
    std::vector<Weather> weathers = read();
    return (int)weathers.size();
}

int Repo::getIndex(const Weather &w) {
    std::vector<Weather> weathers = read();
    int i = 0;
    for(const auto& each_w: weathers){
        if(each_w == w)
            return i;
        i++;
    }
    return -1;
}

std::vector<Weather> Repo::getRepo() {
    std::vector<Weather> weathers;
    std::vector<Weather> w = read();
    weathers.reserve(nrWeathers());
    for(const auto& weather: w)
        weathers.push_back(weather);
    return weathers;
}

std::vector<Weather> Repo::read() {
    std::ifstream in(this->file_name);
    std::string line, temp, desc;
    int start, end, prob;
    std::vector<Weather> all_weathers;
    while(std::getline(in, line)){
            std::stringstream ss(line);
            std::getline(ss, temp, ';');
            start = stoi(temp);
            std::getline(ss, temp, ';');
            end = stoi(temp);
            std::getline(ss, temp, ';');
            prob = stoi(temp);
            std::getline(ss, desc, ';');
            all_weathers.push_back(Weather(start, end, prob, desc));
    }
    return all_weathers;
}

RepositoryException::RepositoryException(std::string message) {
    this->repo_error = message;
}

RepositoryException::~RepositoryException() {

}

std::string RepositoryException::getRepoError() {
    return this->repo_error;
}
