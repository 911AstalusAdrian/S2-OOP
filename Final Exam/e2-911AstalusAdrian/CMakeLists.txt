cmake_minimum_required(VERSION 3.19)
project(e2_911AstalusAdrian)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "D:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)


add_executable(e2_911AstalusAdrian
        main.cpp Buildings/building.cpp Buildings/building.h Ethnologists/ethnologist.cpp Ethnologists/ethnologist.h Repo/repo.cpp Repo/repo.h Service/service.cpp Service/service.h UI/ui.cpp UI/ui.h Observer.h EthnologistWindow/eWindow.cpp EthnologistWindow/eWindow.h AbstractModel/model.cpp AbstractModel/model.h)


find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})