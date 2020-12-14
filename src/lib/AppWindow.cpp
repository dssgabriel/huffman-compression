#include "../headers/AppWindow.hpp"
#include "../headers/Part2.hpp"

AppWindow::AppWindow() {
    setWindowTitle("Huffman - C++ Project: Part 2");
    setMinimumSize(960, 720);
    setMaximumSize(1920, 1080);

    // Setting up text box
    layout_text = new QGridLayout();

    input = new QTextEdit();
    QString text("Type your text here");
    input->setPlaceholderText(text);
    input->canPaste();
    input->show();
    layout_text->addWidget(input, 0, 0);

    output = new QTextEdit();
    output->setReadOnly(true);
    output->show();
    layout_text->addWidget(output, 0, 1);

    // Setting up button menu
    layout_menu = new QGridLayout();
    layout_menu->setAlignment(Qt::AlignTop);

    compress = new QPushButton("Compress text", this);
    compress->show();
    layout_menu->addWidget(compress, 0, 0);
    connect(compress, SIGNAL(clicked()), this, SLOT(run_compression()));

    clear = new QPushButton("Clear text", this);
    clear->show();
    layout_menu->addWidget(clear, 0, 1);
    connect(clear, SIGNAL(clicked()), this, SLOT(clear_text()));

    exit = new QPushButton("Quit", this);
    exit->show();
    layout_menu->addWidget(exit, 0, 2);
    connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));

    // Setting up layout for whole window
    layout_global = new QGridLayout();
    layout_global->addLayout(layout_menu, 0, 0);
    layout_global->addLayout(layout_text, 1, 0);
    setLayout(layout_global);
}

AppWindow::~AppWindow() {}

void AppWindow::run_compression() {
    std::string content = input->toPlainText().toStdString();
    if (content.empty() || content.length() == 1)  {
        std::cout << "Warning: input string is empty or too small (minimum 2 characters)" << std::endl;
        return;
    }
    // print_input(content);

    std::vector<ArbreB> vec = build_btree_vector(content);
    ArbreB huffman = build_huffman_tree(vec);

    std::cout << "\nHuffman tree for input text:" << std::endl;
    huffman.print();

    std::map<char, std::string> huffman_code_map = huffman.build_huffman_map();
    print_map(huffman_code_map);

    std::string compressed = compress_to_bin(huffman_code_map, content);
    // print_output(compressed);

    QString q_compressed = QString::fromStdString(compressed);
    output->setText(q_compressed);
}

void AppWindow::clear_text() {
    QString blank = "";
    QString info = "Type your text here";
    input->setText(blank);
    input->setPlaceholderText(info);
    output->setText(blank);
}
