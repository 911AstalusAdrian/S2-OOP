cmake_minimum_required(VERSION 3.19)
project(t2_911AstalusAdrian_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Person)

add_executable(t2_911AstalusAdrian_1
        Person/person.cpp
        Person/person.h Measurement/Measurement.cpp Measurement/Measurement.h main.cpp UI/UI.cpp UI/UI.h Exceptions/exception.cpp Exceptions/exception.h Validation/validation.cpp Validation/validation.h)
