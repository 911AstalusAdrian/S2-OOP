#pragma once
#ifndef UNTITLED_TODO_H
#define UNTITLED_TODO_H
#endif //UNTITLED_TODO_H
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Activity{
private:
    std::string activity, date;
public:
    Activity(std::string a, std::string d);
    ~Activity() = default;
    friend std::ostream &operator<<(std::ostream& o, const Activity &ac);
    bool operator<(Activity& a);
};

template<typename T>
class ToDo: public std::vector<T>{
public:
    void reversePrint(std::ostream& o);
    void operator+=(const T& el);
};

template<typename T>
void ToDo<T>::reversePrint(std::ostream& o) {
    for (auto it = this->rbegin(); it != this->rend(); it++)
        std::cout << *it << "\n";
}

template<typename T>
void ToDo<T>::operator+=(const T &el) {
    this->push_back(el);
    std::sort(this->begin(), this->end());

}