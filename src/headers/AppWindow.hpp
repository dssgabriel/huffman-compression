#include <QtWidgets/QTextEdit>
#include "AppMenu.hpp"

class AppWindow : public QWidget {
    private:
        AppMenu* menu;
        QGridLayout* layout_menu;
        QGridLayout* layout_text;
        QGridLayout* layout_global;
        QTextEdit* input;
        QTextEdit* output;

    public:
        AppWindow();
        ~AppWindow();
};