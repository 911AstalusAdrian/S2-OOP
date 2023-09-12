#pragma once
#include <iostream>
#ifndef A67_911ASTALUSADRIAN_EXCEPTION_H
#define A67_911ASTALUSADRIAN_EXCEPTION_H
#endif //A67_911ASTALUSADRIAN_EXCEPTION_H

/// General Exception class
class Exception{
private:
    std::string error;

public:
    /// Constructor and destructor
    Exception(std::string message);
    ~Exception();
    /// Message getter
    std::string getError();
};

/// Exception class for the Repository errors
class RepositoryException{
private:
    std::string repo_error;

public:
    /// Constructor and destructor
    RepositoryException(std::string message);
    ~RepositoryException();
    /// Message getter
    std::string getRepoError();
};