#include <iostream>
#include <fstream>
#include <vector>
#include "../lib/ArbreB.hpp"

std::vector<ArbreB> parse_file_to_vector(char* filename) {
    std::vector<ArbreB> vec_btree;
    std::ifstream file;

    file.open(filename, std::ifstream::in);

    if (!file) {
        std::cerr << "Error: could not open file " << filename << std::endl;
    }

    double char_count = 0.;
    char read_char;
    while (not file.eof()) {
        file.get(read_char);
        char_count += 1.;
        bool known = false;
        for (unsigned int i = 0; i < vec_btree.size(); i++) {
            if (read_char == vec_btree[i].get_root()->get_data()) {
                known = true;
                vec_btree[i].get_root()->set_m_Freq(vec_btree[i].get_root()->get_freq() + 1);
                break;
            }
        }

        if (known == false) {
            ArbreB new_char(read_char, 1.);
            vec_btree.push_back(new_char);
        }
    }
    file.close();

    for (unsigned int i = 0; i < vec_btree.size(); i++) {
        vec_btree[i].get_root()->set_m_Freq(vec_btree[i].get_root()->get_freq() / char_count);
    }

    return vec_btree;
}

ArbreB get_lowest(std::vector<ArbreB>& vec_btree) {
    int index = 0;
    double freq = vec_btree[0].get_root()->get_freq();

    for (unsigned int i = 0; i < vec_btree.size(); i++) {
        if (vec_btree[i].get_root()->get_freq() < freq) {
            index = i;
            freq = vec_btree[i].get_root()->get_freq();
        }
    }

    ArbreB lowest = vec_btree[index];
    vec_btree.erase(vec_btree.begin() + index);

    return lowest;
}

ArbreB build_huffman_tree(std::vector<ArbreB>& vec_btree) {
    while (vec_btree.size() > 1) {
        ArbreB first = get_lowest(vec_btree);
        ArbreB second = get_lowest(vec_btree);
        ArbreB fused_lowests = first + second;
        vec_btree.push_back(fused_lowests);
    }

    return vec_btree[0];
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: not enough arguments" << std::endl;
        return 1;
    }

    std::vector<ArbreB> vec_btree = parse_file_to_vector(argv[1]);
    ArbreB huffman = build_huffman_tree(vec_btree);
    huffman.print();

    return 0;
}
