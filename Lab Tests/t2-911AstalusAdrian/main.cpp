#include <iostream>
#include "../Person/person.h"
#include "../Measurement/Measurement.h"
#include "../UI/UI.h"

int main(){
    std::string s = "John";
    Person p = Person(s);
    UI ui = UI(&p);
    ui.start();
    return 0;
}