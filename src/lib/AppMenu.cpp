#include "../headers/AppMenu.hpp"

AppMenu::AppMenu() {
    layout = new QGridLayout();
    setLayout(layout);

    compress = new QPushButton("Compresser", this);
    compress->show();
    layout->addWidget(compress, 0, 0);
    
    exit = new QPushButton("Quitter", this);
    exit->show();
    layout->addWidget(exit, 0, 1);
    QObject::connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

AppMenu::~AppMenu() {}
