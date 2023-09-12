cmake_minimum_required(VERSION 3.17)
project(a67_911AstalusAdrian)

set(CMAKE_CXX_STANDARD 14)

include_directories(Dog)
include_directories(DynamicArray)
include_directories(Service)
include_directories(Tests)
include_directories(UI)
include_directories(userService)
include_directories(Validation)

add_executable(a67_911AstalusAdrian
        Dog/dog.cpp
        Dog/dog.h
        Service/service.cpp
        Service/service.h
        Tests/testing.cpp
        Tests/testing.h
        UI/ui.cpp
        UI/ui.h
        userService/userservice.cpp
        userService/userservice.h
        Validation/validators.cpp
        Validation/validators.h
        main.cpp
        FileRepo/filerepo.cpp
        FileRepo/filerepo.h
        userService/exception.cpp
        Exceptions/exception.h
        userService/AdoptionList.h
        userService/HTMLAdoption.cpp
        userService/HTMLAdoption.h
        userService/CSVAdoption.cpp
        userService/CSVAdoption.h)
