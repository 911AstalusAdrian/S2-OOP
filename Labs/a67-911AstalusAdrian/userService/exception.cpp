#include "../Exceptions/exception.h"

Exception::Exception(std::string message): error(message)
{}

Exception::~Exception() {

}

std::string Exception::getError() {
    return error;
}




RepositoryException::RepositoryException(std::string message): repo_error(message)
{}

RepositoryException::~RepositoryException() {

}

std::string RepositoryException::getRepoError() {
    return repo_error;
}
