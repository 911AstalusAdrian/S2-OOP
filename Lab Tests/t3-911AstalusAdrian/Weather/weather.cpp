#include <sstream>
#include "weather.h"

Weather::Weather(int s, int e, int p, const std::string& d):start(s),
end(e),
prob(p),
desc(d)
{}

Weather::~Weather() {

}

int Weather::getStart() {
    return start;
}

int Weather::getEnd() {
    return end;
}

int Weather::getProb() {
    return prob;
}

std::string Weather::getDesc(const Weather &w) {
    return desc;
}

bool Weather::operator==(const Weather &cw) const {
    return (start == cw.start && end == cw.end && prob == cw.prob && desc == cw.desc);
}

std::ostream &operator<<(std::ostream &out, const Weather &w) {
    out<<w.start<<";"<<w.end<<";"<<w.prob<<";"<<w.desc;
    return out;
}

std::istream &operator>>(std::istream &in, Weather &w) {
    in>>w.start>>w.end>>w.prob>>w.desc;
    return in;
}

std::string Weather::toString(){
    std::string  repr;
    repr.append(std::to_string(start));
    repr.append("->");
    repr.append(std::to_string(end));
    repr.append(" | ");
    repr.append(std::to_string(start));
    repr.append(" | ");
    repr.append(desc);
    return repr;
}

