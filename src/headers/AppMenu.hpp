#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtGui/QPainter>

class AppMenu : public QWidget {
    private:
        QGridLayout* layout;
        QPushButton* compress;
        QPushButton* exit;

    public:
        AppMenu();
        ~AppMenu();
};