cmake_minimum_required(VERSION 3.19)
project(untitled)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "D:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)

add_executable(untitled main.cpp
        TemplatedStack/TStack.cpp
        TemplatedStack/TStack.h
        ToDoList/ToDo.cpp
        ToDoList/ToDo.h
        CarList/carlist.cpp
        CarList/carlist.h
        SaleItem/saleitem.cpp
        SaleItem/saleitem.h
        Hospital/hospital.cpp Hospital/hospital.h Written/start.cpp Written/file2.cpp Written/file2.h Written/handrail.cpp Written/handrail.h)


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})