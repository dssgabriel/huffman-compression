/**
 * @file main3.cpp
 * @author Gabriel Dos Santos
 * @brief Main function for third part of the project.
 * @version 0.1.0
 * @date 2020/12/22
 */

#include "../headers/AppWindow.hpp"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    
    AppWindow window;
    window.show();

    return app.exec();
}
