#include <QtWidgets/QTextEdit>
#include <QtWidgets/QLineEdit>
#include "Menu.hpp"

class Window : public QWidget {
    private:
        Menu* menu;
        QGridLayout* layout;
        QLineEdit* input_file;
        QTextEdit* input_string;
        QTextEdit* output;

    public:
        Window() {
            layout = new QGridLayout();
            setLayout(layout);

            input_file = new QLineEdit();
            QString txt_file("Entrez un nom de fichier");
            input_file->setText(txt_file);
            input_file->show();
            layout->addWidget(input_file, 0, 0);

            menu = new Menu();
            menu->show();
            layout->addWidget(menu, 0, 1);

            input_string = new QTextEdit();
            QString txt_str("Entrez votre texte");
            input_string->setText(txt_str);
            input_string->show();
            layout->addWidget(input_string, 1, 0);

            output = new QTextEdit();
            output->setReadOnly(true);
            output->show();
            layout->addWidget(output, 1, 1);
        }

        ~Window() {}
};