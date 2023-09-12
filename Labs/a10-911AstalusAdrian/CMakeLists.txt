cmake_minimum_required(VERSION 3.19)
project(a10_911AstalusAdrian_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "D:\\Qt\\5.15.2\\mingw81_64\\lib\\cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)

include_directories(AbstractModel)
include_directories(Dog)
include_directories(Exceptions)
include_directories(FileRepo)
include_directories(GUI)
include_directories(Service)
include_directories(userService)
include_directories(Validation)

add_executable(a10_911AstalusAdrian_1
        AbstractModel/abstract_model.cpp
        AbstractModel/abstract_model.h
        Dog/dog.cpp
        Dog/dog.h
        Exceptions/exception.h
        FileRepo/filerepo.cpp
        FileRepo/filerepo.h
        GUI/gui.cpp
        GUI/gui.h
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
        Delegate/delegate.cpp
        Delegate/delegate.h
        UndoRedo/command.h
        UndoRedo/repocommands.cpp UndoRedo/repocommands.h Service/urservice.cpp Service/urservice.h)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})