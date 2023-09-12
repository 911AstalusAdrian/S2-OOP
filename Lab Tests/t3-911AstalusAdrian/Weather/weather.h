#pragma once
#ifndef T3_911ASTALUSADRIAN_WEATHER_H
#define T3_911ASTALUSADRIAN_WEATHER_H
#endif //T3_911ASTALUSADRIAN_WEATHER_H
#include <string>
class Weather{
private:
    int start, end, prob;
    std::string  desc;

public:
    Weather(int s = 0, int e = 0, int p = 0, const std::string& d = "");
    ~Weather();
    int getStart();
    int getEnd();
    int getProb();
    std::string getDesc(const Weather& w);
    std::string toString();


    bool operator==(const Weather& cw) const;
    friend std::ostream& operator<<(std::ostream& out, const Weather& w);
    friend std::istream& operator>>(std::istream& in, Weather& w);

};