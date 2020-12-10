#include <iostream>
#include <fstream>
#include <vector>
#include "../lib/ArbreB.hpp"

std::string parse_file_to_string(char* filename) {
    // Check that filename is not a nullptr
    if (!filename) {
        return std::cout << "Error: file name is nullptr" << std::endl, nullptr;
    }

    std::string file_content;
    std::ifstream fp;
    fp.open(filename, std::ifstream::in);

    // Check that fp has opened correctly
    if (!fp) {
        return std::cout << "Error: could not open file " << filename << std::endl, nullptr;
    }

    char read;
    // Read each character in the file
    while (!fp.eof()) {
        fp.get(read);
        file_content.push_back(read);
    }

    // Close file
    fp.close();

    return file_content;
}

unsigned int find(std::vector<ArbreB>& vec, char& content) {
    bool found = false;
    unsigned int index = 0;

    // Loop will stop if a matching character is found
    for (index = 0; !found && index < vec.size(); index++) {
        found = (vec[index].get_root()->get_data() == content);
    }

     return (found) ? index : 0;
}

std::vector<ArbreB> build_btree_vector(std::string& content) {
    std::vector<ArbreB> btrees;

    for (unsigned int i = 0; i < content.length(); i++) {
        // Check for a matching character in the vector
        unsigned int f = find(btrees, content[i]);

        // Update corresponding ArbreB's root frequency in the vector if found
        if (f) {
            btrees[f - 1].get_root()->set_freq(btrees[f - 1].get_root()->get_freq() + 1);
        }
        // Emplace an ArbreB with the new character otherwise
        else {
            if (btrees.size() == btrees.capacity()) {
                // Avoid reallocating memory with each call emplace_back()
                btrees.reserve(btrees.size() * 2);
            }
            btrees.emplace_back(ArbreB(content[i], 1.));
        }
    }
    // De-allocate unused memory
    btrees.shrink_to_fit();

    return btrees;
}

ArbreB find_lowest(std::vector<ArbreB>& btrees) {
    // Initialize index and frequency
    unsigned int index = 0;
    double freq = btrees[0].get_root()->get_freq();

    for (unsigned int i = 1; i < btrees.size(); i++) {
        // Update index and freq if current ArbreB's frequency is lower than freq
        if (btrees[i].get_root()->get_freq() < freq) {
            index = i;
            freq = btrees[i].get_root()->get_freq();
        }
    }

    ArbreB lowest = btrees[index];
    // Remove ArbreB with lowest frequency from the vector
    btrees.erase(btrees.begin() + index);

    return lowest;
}

ArbreB build_huffman_tree(std::vector<ArbreB>& btrees) {
    // Emplace fusions of ArbreBs when there is more than one in the vector
    while (btrees.size() > 1) {
        btrees.emplace_back(find_lowest(btrees) + find_lowest(btrees));
    }

    return btrees[0];
}

std::string crypt_text(std::map<char, std::string> map, std::string file_content) {
    std::string compressed;

    for (unsigned int i = 0; i < file_content.length(); i++) {
        auto char_code = map.find(file_content[i]);
        compressed += char_code->second;
    }

    return  compressed;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        return std::cout << "Error: not enough arguments" << std::endl, 1;
    }

    std::string file_content = parse_file_to_string(argv[1]);
    std::cout << "\nInput text:\n" << file_content;

    std::vector<ArbreB> btrees = build_btree_vector(file_content);
    ArbreB huffman = build_huffman_tree(btrees);

    std::cout << "Corresponding Huffman tree:" << std::endl;
    huffman.print();

    std::map<char, std::string> huffman_code_map = huffman.build_huffman_map();
    std::cout << "\nCode for each character:" << std::endl;
    for (auto i : huffman_code_map) {
        if (i.first == '\n') {
            std::cout << "\\n : " << i.second << std::endl;
        }
        else {
            std::cout << i.first << "  : " << i.second << std::endl;
        }
    }

    std::string crypted = crypt_text(huffman_code_map, file_content);
    std::cout << "\nCompressed text:\n" << crypted << std::endl;

    return 0;
}
