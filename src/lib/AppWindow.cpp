#include "../headers/AppWindow.hpp"

AppWindow::AppWindow() {
    setWindowTitle("Huffman - C++ Project: Part 3");
    setMinimumSize(960, 720);
    setMaximumSize(1920, 1080);

    // Initialize empty huffman tree
    ArbreB huffman;

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

    uncompress = new QPushButton("Uncompress binary", this);
    uncompress->show();
    layout_menu->addWidget(uncompress, 0, 1);
    connect(uncompress, SIGNAL(clicked()), this, SLOT(run_uncompression()));

    clear = new QPushButton("Clear text", this);
    clear->show();
    layout_menu->addWidget(clear, 0, 2);
    connect(clear, SIGNAL(clicked()), this, SLOT(clear_text()));

    exit = new QPushButton("Quit", this);
    exit->show();
    layout_menu->addWidget(exit, 0, 3);
    connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));

    // Setting up info text box
    info = new QTextEdit();
    info->setReadOnly(true);
    info->show();

    // Setting up layout for whole window
    layout_global = new QGridLayout();
    layout_global->addLayout(layout_menu, 0, 0);
    layout_global->addLayout(layout_text, 1, 0);
    layout_global->addWidget(info, 2, 0);
    setLayout(layout_global);
}

AppWindow::~AppWindow() {}

void AppWindow::run_compression() {
    info->setText("");
    output->setText("");
    std::string content = input->toPlainText().toStdString();
    if (content.empty() || content.length() == 1 || is_repeated_character(content))  {
        info->setText("Error: input string needs to be at least two different characters");
        return;
    }

    std::vector<ArbreB> vec = build_btree_vector(content);
    huffman = build_huffman_tree(vec);

    std::cout << "\nHuffman tree for input text:" << std::endl;
    huffman.print();

    std::map<char, std::string> huffman_code_map = huffman.build_huffman_map();
    print_map(huffman_code_map);

    std::string compressed = compress_to_bin(huffman_code_map, content);

    QString q_compressed = QString::fromStdString(compressed);
    output->setText(q_compressed);
}

void AppWindow::run_uncompression() {
    info->setText("");
    output->setText("");
    if (!huffman.get_root()) {
        info->setText("Error: No text has been compressed yet");
        return;
    }

    std::string content = input->toPlainText().toStdString();
    if (content.empty() || content.length() == 1 || is_repeated_character(content))  {
        info->setText("Error: input string needs to be at least two different characters");
        return;
    }

    if (is_huffman_code(content)) {
        std::string uncompressed = uncompress_binary(content, huffman);
        if (uncompressed.empty()) {
            info->setText("Error: input does not correspond to a known huffman tree");
        } else {
            QString q_uncompressed = QString::fromStdString(uncompressed);
            output->setText(q_uncompressed);
        }
    }
    else {
        info->setText("Error: input is not in binary");
    }
}

void AppWindow::clear_text() {
    input->setText("");
    input->setPlaceholderText("Type your text here");
    output->setText("");
    info->setText("");
}
