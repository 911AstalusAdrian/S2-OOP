#include "file2.h"
HTMLElement::HTMLElement(std::string m): text(m) {}

HTMLParagraph::HTMLParagraph(std::string m) : HTMLElement(m) {}

std::string HTMLParagraph::getHTMLString() {
    std::string message;
    message.append("<p>");
    message.append(this->text);
    message.append("</p>");
    return message;
}

HTMLImage::HTMLImage(std::string m) : HTMLElement(m) {}

std::string HTMLImage::getHTMLString() {
    std::string message;
    message.append("<img>");
    message.append(this->text);
    message.append("</img>");
    return message;
}
