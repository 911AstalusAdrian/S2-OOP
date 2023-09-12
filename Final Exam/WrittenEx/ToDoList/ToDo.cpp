#include "ToDo.h"

Activity::Activity(std::string a, std::string d): activity(a), date(d)
{}

std::ostream &operator<<(std::ostream &o, const Activity &ac) {
    std::string message;
    message.append("Activity ");
    message.append(ac.activity);
    message.append(" will take place at ");
    message.append(ac.date);
    o << message;
    return o;
}

bool Activity::operator<(Activity &a) {
    return this->date < a.date;
}

