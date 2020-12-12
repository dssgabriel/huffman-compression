cmake_minimum_required(VERSION 3.1.0)

project(huffman VERSION 0.2.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets Gui Core REQUIRED)

set(SRC
    src/bin/main2.cpp
    src/lib/Sommet.cpp
    src/lib/ArbreB.cpp
    src/lib/PartTwo.cpp
    src/lib/Menu.hpp
    src/lib/Window.hpp
)

add_executable(main2
    ${SRC}
)

target_link_libraries(main2 Qt5::Widgets Qt5::Core Qt5::Gui)