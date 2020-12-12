#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

class AppWindow : public QWidget {
    Q_OBJECT

    private:
        QPushButton* compress;
        QPushButton* exit;
        QGridLayout* layout_menu;

        QTextEdit* input;
        QTextEdit* output;
        QGridLayout* layout_text;
        
        QGridLayout* layout_global;

    public:
        AppWindow();
        ~AppWindow();

    public slots:
        void run();
};