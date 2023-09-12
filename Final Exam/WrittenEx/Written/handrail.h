#pragma once
#ifndef UNTITLED_HANDRAIL_H
#define UNTITLED_HANDRAIL_H
#endif //UNTITLED_HANDRAIL_H
#include <string>

class Handrail{
public:
    virtual double computePrice() = 0;
};

class MetalHandrail: public Handrail{
public:
    MetalHandrail() {};
    ~MetalHandrail() = default;
    double computePrice() override{return 2.5;}
};

class WoodHandrail: public Handrail{
public:
    WoodHandrail() {};
    ~WoodHandrail() = default;
    double computePrice() override{return 2.0;}
};

class HandrailWithVerticalElements: public Handrail{
private:
    int noElements;
    Handrail* h;
public:
    HandrailWithVerticalElements(Handrail* hr, int e): h(hr), noElements(e){};
    double computePrice() override{
        return h->computePrice() + 5.0* noElements;
    }
    ~HandrailWithVerticalElements() = default;
};


class Stair{
private:
    int noSteps;
public:
    Stair(int n): noSteps(n){};
    Stair(){};
    double getPrice(){
        return getCoefficient() * noSteps;
    };
    virtual std::string getDescription() = 0;
    virtual double getCoefficient() = 0;
    int steps(){return noSteps;}
};

class WoodStair: public Stair{
public:
    WoodStair(int s): Stair(s){};
    std::string getDescription() override{return "wood stair";};
    double getCoefficient() override{return 1.5;};
};

class MetalStair: public Stair{
public:
    MetalStair(int s): Stair(s){};
    std::string getDescription() override{return "metal stair";};
    double getCoefficient() override{return 2.0;};
};


class StairWithHandrail: public Stair{
private:
    Stair* stair;
    Handrail* handrail;
    double handrailLinearMeters;
public:
    StairWithHandrail(Stair* s, Handrail* h, double meters):stair(s), handrail(h), handrailLinearMeters(meters){};
    ~StairWithHandrail() = default;
    double Price(){
        double val = 0;
        val += stair->getPrice();
        val += handrailLinearMeters * handrail->computePrice();
        return val;
    };
    std::string getDescription() override{
        std::string message;
        message.append(stair->getDescription());
        message.append(" - ");
        message.append(std::to_string(handrailLinearMeters));
        message.append(" linear meters");
        return message;
    };
    double getCoefficient() override {return 0;};
};