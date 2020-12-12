#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

class Menu : public QWidget {
    private:
        QGridLayout* layout;
        QPushButton* compress_from_file;
        QPushButton* compress_from_string;
        QPushButton* exit;

    public:
        Menu() {
            layout = new QGridLayout();
            setLayout(layout);

            compress_from_file = new QPushButton("Compresser le fichier", this);
            compress_from_file->show();
            layout->addWidget(compress_from_file, 0, 0);

            compress_from_string = new QPushButton("Compresser le texte", this);
            compress_from_string->show();
            layout->addWidget(compress_from_string, 0, 1);
           
            exit = new QPushButton("Quitter", this);
            exit->show();
            layout->addWidget(exit, 0, 2);
            QObject::connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));
        }

        ~Menu() {}
};