cmake_minimum_required(VERSION 3.6)
project(OpenFace)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Werror -Wextra -Wpedantic -Ofast")


find_package(OpenCV REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

set(SOURCE_FILES
        main.cpp
        Utils.hpp
        facemask.hpp
        facemask.cpp
        OpenFace.hpp
        OpenFace.cpp
        Interface.hpp
        Interface.cpp
        Button.hpp
        Button.cpp)

add_executable(OpenFace ${SOURCE_FILES})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(OpenFace ${OpenCV_LIBS})
target_link_libraries(OpenFace Qt5::Widgets Qt5::Core Qt5::Gui)
