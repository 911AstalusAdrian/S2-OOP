#include "HTMLAdoption.h"
#include "../Exceptions/exception.h"
#include <fstream>
#include <windows.h>

HTMLAdoptionList::HTMLAdoptionList() {
    this->fileName = "example.html";
}

HTMLAdoptionList::~HTMLAdoptionList() {

}

void HTMLAdoptionList::write() {
    std::ofstream out(this->fileName, ios::in);
    if(!out.is_open())
        throw Exception("The file could not be opened!");

    out<<createFirstPart();
    for(const auto&dog: this->list) {
        out << "\t<tr>\n";
        out << dog.HTMLRepresentation();
        out << "\t</tr>\n";
    }
    out<<createSecondPart();
}

void HTMLAdoptionList::open() {
    std::ifstream in(this->fileName);
    if(!in.is_open())
        throw Exception("Could not open file!");

    ShellExecute(nullptr, "open", "example.html", nullptr, nullptr, SW_SHOWNORMAL);
    in.close();
}

//void HTMLAdoptionList::createList(std::vector<Dog> adoptionList) {
//    for(const auto& dog: adoptionList)
//        list.push_back(dog);
//}

std::string HTMLAdoptionList::createFirstPart() {
    std::string part;
    part.append("<!DOCTYPE html>\n");
    part.append("<html>\n");
    part.append("<head>\n");
    part.append("\t<title>Adoption List</title>\n");
    part.append("</head>\n");
    part.append("<table border=\"1\">\n");
    return part;
}

std::string HTMLAdoptionList::createSecondPart() {
    std::string part;
    part.append("</table>\n");
    part.append("</body>\n");
    part.append("</html>\n");
    return part;
}
