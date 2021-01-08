cmake_minimum_required(VERSION 3.1.0)

project(huffman VERSION 0.3.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets Gui Core REQUIRED)

set(LIBS
    src/bin/main3.cpp
    src/lib/Part2.cpp
    src/lib/Part3.cpp
    src/lib/AppWindow.cpp
    src/lib/ArbreB.cpp
    src/lib/Sommet.cpp
)

set(HEADERS
    src/headers/Part2.hpp
    src/headers/Part3.hpp
    src/headers/AppWindow.hpp
    src/headers/ArbreB.hpp
    src/headers/Sommet.hpp
)

add_executable(huffman ${LIBS} ${HEADERS})

target_link_libraries(huffman Qt5::Widgets Qt5::Core Qt5::Gui)
