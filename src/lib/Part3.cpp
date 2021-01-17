/**
 * @file Part3.cpp
 * @author Gabriel Dos Santos
 * @brief Implementation of the functions for the third part of the project.
 * @version 0.1.0
 * @date 2020/12/22
 */

#include "../headers/Part3.hpp"

bool is_huffman_code(std::string& input) {
    bool binary = true;
    // Iterate over string and check that every characters are '0's or '1's
    for (unsigned int i = 0; i < input.length() && binary; i++) {
        binary = (input[i] == '0' || input[i] == '1');
    }

    // Check if string is empty before returning
    return input.empty() ? false : binary;
}

bool is_repeated_character(std::string input) {
    bool repeated = true;
    for (unsigned int i = 0; i < input.length() - 1 && repeated; i++) {
        repeated = (input[i] == input[i + 1]);
    }

    return repeated;
}

std::string uncompress_binary(std::string& input, ArbreB& huffman) {
    std::string uncompressed;
    Sommet* current = huffman.get_root();

    // Iterate over string
    for (unsigned int i = 0; i < input.length(); i++) {
        if (current->get_left() && current->get_right()) {
            // Go right or left depending on what is read in the input
            input[i] == '0' ? current = current->get_left() : current = current->get_right();
            // When on a leaf, add the character to the output string and go back to the root
            if (!current->get_left() && !current->get_right()) {
                uncompressed += current->get_data();
                current = huffman.get_root();
            }
        }
    }

    // Check that we are not in the middle of the tree when finishing the uncompression
    if (current != huffman.get_root()) {
        uncompressed = "";
    }

    return uncompressed;
}
