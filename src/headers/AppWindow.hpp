/**
 * @file AppWindow.hpp
 * @author Gabriel Dos Santos
 * @brief Implementation of the class AppWindow for GUI with Qt5
 * @version 0.1.0
 * @date 2020-12-14
 */

#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

/**
 * @brief The class `AppWindow` represents the GUI that dislays the program. 
 * @author Gabriel Dos Santos
 * @version 0.1.0
 * @date 2020/12/13
 */
class AppWindow : public QWidget {
    Q_OBJECT

    private:
        /**
         * The button to click on to compress a text file.
         */
        QPushButton* compress;
        /**
         * The button to click on to clear the text boxes.
         */
        QPushButton* clear;
        /**
         * The button to click on to quit the application.
         */
        QPushButton* exit;
        /**
         * The layout of the menu.
         */
        QGridLayout* layout_menu;

        /**
         * The text box in which the user types its text.
         */
        QTextEdit* input;
        /**
         * The text box in which the compressed text appears.
         */
        QTextEdit* output;
        /**
         * The layout of the text boxes.
         */
        QGridLayout* layout_text;
        
        /**
         * The global layout.
         */
        QGridLayout* layout_global;

    public:
        /**
         * Creates a new App Window object.
         */
        AppWindow();
        /**
         * Destroys the App Window object
         */
        ~AppWindow();

    public slots:
        /**
         * Compresses the text in the input text box.
         */
        void run_compression();
        /**
         * Clears the text in the text boxes.
         */
        void clear_text();
};