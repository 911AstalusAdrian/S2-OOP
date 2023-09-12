cmake_minimum_required(VERSION 3.17)
project(a45_911AstalusAdrian)

set(CMAKE_CXX_STANDARD 14)

include_directories(Dog)

add_executable(a45_911AstalusAdrian
        Dog/dog.cpp
        Dog/dog.h
        DynamicArray/dynamic_array.cpp
        DynamicArray/dynamic_array.h Repository/reopsitory.cpp Repository/reopsitory.h Service/service.cpp Service/service.h UI/ui.cpp UI/ui.h main.cpp userService/userservice.cpp userService/userservice.h Tests/testing.cpp Tests/testing.h Validation/validators.cpp Validation/validators.h)
