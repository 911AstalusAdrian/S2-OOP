cmake_minimum_required(VERSION 3.17)
project(a89_911AstalusAdrian)



set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "D:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)


add_executable(a89_911AstalusAdrian
        Dog/dog.cpp
        Dog/dog.h
        Exceptions/exception.h
        FileRepo/filerepo.cpp
        FileRepo/filerepo.h
        Service/service.cpp
        Service/service.h
        userService/AdoptionList.h
        userService/CSVAdoption.cpp
        userService/CSVAdoption.h
        userService/exception.cpp
        userService/HTMLAdoption.cpp
        userService/HTMLAdoption.h
        userService/userservice.cpp
        userService/userservice.h
        Validation/validators.cpp
        Validation/validators.h
        main.cpp
        GUI/gui.cpp
        GUI/gui.h AbstractModel/abstract_model.cpp AbstractModel/abstract_model.h)




find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})



