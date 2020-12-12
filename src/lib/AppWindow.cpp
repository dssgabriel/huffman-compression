#include "../headers/AppWindow.hpp"

AppWindow::AppWindow() {
    setWindowTitle("Projet C++ : Partie 2");
    setMinimumSize(720, 480);
    setMaximumSize(1920, 1080);

    layout_menu = new QGridLayout();
    layout_menu->setAlignment(Qt::AlignTop);

    layout_text = new QGridLayout();

    menu = new AppMenu();
    menu->show();
    layout_menu->addWidget(menu, 0, 0);

    input = new QTextEdit();
    QString text("Entrez votre texte ici");
    input->setText(text);
    input->show();
    layout_text->addWidget(input, 0, 0);

    output = new QTextEdit();
    output->setReadOnly(true);
    output->show();
    layout_text->addWidget(output, 0, 1);

    layout_global = new QGridLayout();
    layout_global->addLayout(layout_menu, 0, 0);
    layout_global->addLayout(layout_text, 1, 0);
    setLayout(layout_global);
}

AppWindow::~AppWindow() {}