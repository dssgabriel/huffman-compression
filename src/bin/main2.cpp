#include "../lib/PartTwo.hpp"
#include "../lib/Window.hpp"

//
int main(int argc, char** argv) {
    if (argc < 2) {
        return std::cout << "Error: not enough arguments" << std::endl, 1;
    }

    std::string file_content = parse_file_to_string(argv[1]);
    print_input(file_content);

    std::vector<ArbreB> btrees = build_btree_vector(file_content);
    ArbreB huffman = build_huffman_tree(btrees);

    std::cout << "Corresponding Huffman tree:" << std::endl;
    huffman.print();

    std::map<char, std::string> huffman_code_map = huffman.build_huffman_map();
    print_map(huffman_code_map);

    std::string compressed = compress_to_bin(huffman_code_map, file_content);
    print_output(compressed);

    QApplication app(argc, argv);
    
    Window window;
    window.show();

    return app.exec();
}
