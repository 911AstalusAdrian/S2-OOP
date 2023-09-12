cmake_minimum_required(VERSION 3.17)
project(t1_911AstalusAdrian_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Gene)

add_executable(t1_911AstalusAdrian_1
        Gene/gene.cpp
        Gene/gene.h main.cpp Repo/repo.cpp Repo/repo.h Service/service.cpp Service/service.h UI/ui.cpp UI/ui.h Validate/validate.cpp Validate/validate.h)
