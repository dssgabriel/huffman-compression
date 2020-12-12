cmake_minimum_required(VERSION 3.0.0)
project(Cours_1)

find_package(Qt4 REQUIRED)

SET(CMAKE_AUTOMOC True)

SET{SRCS
	
	MainMenu.cpp
	MainWindow.cpp
	
	
}

SET{HEADERS
	Affichage.hpp
	MainWindow.hpp
	MainMenu.hpp
}

add_executable(Main ${SRCS} ${HEADERS})
target_link_libraries(Main Qt4::QtCore Qt4::QtGui)


