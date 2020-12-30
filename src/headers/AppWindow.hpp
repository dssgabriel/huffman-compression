/**
 * @file AppWindow.hpp
 * @author Gabriel Dos Santos
 * @brief Implementation of the class AppWindow for GUI with Qt5
 * @version 0.2.0
 * @date 2020/12/22
 */

#ifndef APP_WINDOW_HPP
#define APP_WINDOW_HPP

#include <QtCore/QObject>
#include <QtWidgets/QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include "Part2.hpp"
#include "Part3.hpp"

/**
 * @brief The class `AppWindow` represents the GUI that dislays the program.
 * @author Gabriel Dos Santos
 */
class AppWindow : public QWidget {
    Q_OBJECT

    private:
        /**
         * The huffman that is created each time the GUI is run.
         * It stores the Huffman tree for the last compressed text.
         */
        ArbreB huffman;

        /**
         * The button to click on to compress a text input.
         */
        QPushButton* compress;
        /**
         * The button to click on to uncompress a binary input.
         */
        QPushButton* uncompress;
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
         * The text box in which useful user informations are dispalyed.
         */
        QTextEdit* info;

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
         * Uncompresses the text in the input box.
         * It will raise an error if no text has been compressed before 
         * or if the text could not be fully uncompressed.
         */
        void run_uncompression();

        /**
         * Clears the text in the text boxes.
         */
        void clear_text();
};

#endif