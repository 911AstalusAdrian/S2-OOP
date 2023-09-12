//
// Created by ADYh3 on 26-Apr-21.
//

#include "exception.h"

Exception::Exception(std::string message) {
    this->error = message;
}

Exception::~Exception() {

}

std::string Exception::getError() {
    return this->error;
}
