#ifndef PART_TWO_HPP
#define PART_TWO_HPP

#pragma once
#include <fstream>
#include <vector>
#include "ArbreB.hpp"

/**
 * Checks if an ArbreB holding the specified character is present in the vector.
 * @param vec A reference to the vector to search in.
 * @param content The character to search for.
 * @return The index of the ArbreB holding the character + 1 if found, 0 otherwise.
 */
unsigned int find(std::vector<ArbreB>& vec, char& content);

/**
 * Finds the ArbreB with the lowest frequency and deletes it from the vector.
 * @param btrees A reference of the vector to search in.
 * @return A copy of the ArbreB with the lowest frequency.
 */
ArbreB find_lowest(std::vector<ArbreB>& btrees);

/**
 * Parses a given text file into a string.
 * @param filename The name of the file to parse.
 * @return A string holding the content of the file.
 */
std::string parse_file_to_string(char* filename);

/**
 * Constructs a vector of ArbreBs for each character present in a string and their frequency.
 * @param content The string to build the vector from.
 * @return A vector of ArbreB for each character.
 */
std::vector<ArbreB> build_btree_vector(std::string& content);

/**
 * Builds the huffman tree for a vector of the characters present in a text.
 * Fuses the ArbreBs of the vector together following the huffman algorithm.
 * @param btrees The vector of ArbreBs to fuse.
 * @return An Huffman tree for the given vector of ArbreB.
 */
ArbreB build_huffman_tree(std::vector<ArbreB>& btrees);

/**
 * Compresses a given string to binary from a given map.
 * @param map The map of a character and its binary equivalent.
 * @param file_content The string to compress.
 * @return The compressed string.
 */
std::string compress_to_bin(std::map<char, std::string> map, std::string file_content);

void print_input(std::string input);

void print_map(std::map<char, std::string> map);

void print_output(std::string output);

#endif
