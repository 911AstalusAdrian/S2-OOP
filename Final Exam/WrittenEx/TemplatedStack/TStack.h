#pragma once
#ifndef UNTITLED_TSTACK_H
#define UNTITLED_TSTACK_H
#endif //UNTITLED_TSTACK_H
#include <exception>
#include <string>
#include <vector>

class MyException: public std::exception{
private:
    std::string message;
public:
    MyException(std::string& m): message(m){};
    const char *what() const noexcept{
        return message.c_str();
    }
};

template<typename T>
class Stack{
private:
    int cap;
    std::vector<T> elems;
public:
    Stack(int maxCap);
    ~Stack() = default;
    int getMaxCapacity();
    T pop();
    Stack<T> operator+(const T& el);
};

template<typename T>
Stack<T>::Stack(int maxCap): cap(maxCap) {}

template<typename T>
int Stack<T>::getMaxCapacity() {
    return cap;
}

template<typename T>
T Stack<T>::pop() {
    if(this->elems.empty()){
        std::string message;
        message.append("Stack is empty!");
        throw MyException(message);
    }
    else{
        T elem = this->elems[this->elems.size()-1];
        this->elems.pop_back();
        return elem;
    }
}

template<typename T>
Stack<T> Stack<T>::operator+(const T &el) {
    Stack<T> temp {this->cap};
    if(this->elems.size() == 2){
        std::string m;
        m.append("Stack is full!");
        throw MyException(m);
    }
    else{
        temp.elems = this->elems;
        temp.elems.push_back(el);
        return temp;
    }
}
