#pragma once
#ifndef UNTITLED_CARLIST_H
#define UNTITLED_CARLIST_H
#endif //UNTITLED_CARLIST_H
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

class Car{
private:
    std::string name;
    int cap;
public:
    Car(const std::string& n,  int c);
    int getCap();
    std::string getName();
    bool operator<(Car& c);
    friend std::ostream& operator<<(std::ostream& o, Car& c);
};

template<typename T, typename V>
class List{
private:
    std::vector<T> tlist;
    std::vector<V> vlist;
public:
    List();
    ~List() = default;
    void add(T elem, V value);
    void sortByFirstComponent();
    void sortBySecondComponent();
    void printReverse(std::ostream &o);
};

template<typename T, typename V>
List<T, V>::List() = default;

template<typename T, typename V>
void List<T, V>::add(T elem, V value) {
    tlist.push_back(elem);
    vlist.push_back(value);
}

template<typename T, typename V>
void List<T, V>::sortByFirstComponent() {
    if(vlist.empty() || tlist.empty()){
        throw std::runtime_error("List is empty!");
    }
    int n = tlist.size()-1;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n;j++){
            if(tlist[j] < tlist[i]){
                std::swap(vlist[j], vlist[i]);
                std::swap(tlist[j], tlist[i]);
            }
        }
}

template<typename T, typename V>
void List<T, V>::sortBySecondComponent() {
    if(vlist.empty() || tlist.empty()){
        throw std::runtime_error("List is empty!");
    }
    int n = tlist.size() - 1;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n;j++){
            if(vlist[j] < vlist[i]){
                std::swap(vlist[j], vlist[i]);
                std::swap(tlist[j], tlist[i]);
            }
        }
}

template<typename T, typename V>
void List<T, V>::printReverse(std::ostream &o) {
    int n = tlist.size()-1;
    for(int i=n;i>=0;i--){
        std::cout<<tlist[i]<<" -> "<<vlist[i]<<"; ";
    }
    std::cout<<"\n";
}
