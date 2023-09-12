#pragma once
#ifndef UNTITLED_FILE2_H
#define UNTITLED_FILE2_H
#endif //UNTITLED_FILE2_H
#include "string.h"
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

class HTMLElement{
protected:
    std::string text;
public:
    HTMLElement(std::string m);
    ~HTMLElement() = default;
    virtual std::string getHTMLString() = 0;

};


class HTMLParagraph: public HTMLElement{
public:
    HTMLParagraph(std::string m);
    ~HTMLParagraph() = default;
    std::string getHTMLString() override;
};
class HTMLImage: public HTMLElement{
public:
    HTMLImage(std::string m);
    ~HTMLImage() = default;
    std::string getHTMLString() override;
};

template <typename TElem>
class HTMLBuilder {
    vector<TElem> code;
public:
    HTMLBuilder() {}

    vector<TElem> get_code(){return code;};

    HTMLBuilder &operator+=(TElem &t) {
        if (t != nullptr)
            this->code.push_back(t);
        else {
            throw runtime_error("Cannot add a null element!");
        }
        return *this;
    }

    friend std::ostream &operator<<(ostream &o, HTMLBuilder<TElem> &b){
        std::cout<<"<html><body>";
        std::vector<TElem> elems = b.get_code();
        for(auto x: elems){
            std::cout << x->getHTMLString();
        }
        std::cout<<"</html></body>";
    }
};

