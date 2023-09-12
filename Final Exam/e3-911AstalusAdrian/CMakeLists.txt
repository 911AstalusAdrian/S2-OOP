cmake_minimum_required(VERSION 3.19)
project(e3_911AstalusAdrian)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "D:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)

include_directories(Player)

add_executable(e3_911AstalusAdrian
        Player/player.cpp
        Player/player.h
        Repo/repo.h
        Repo/repo.cpp main.cpp Service/service.cpp Service/service.h PlayerWindow/window.cpp PlayerWindow/window.h
        Observer.h
        TableModel/model.cpp
        TableModel/model.h)


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})