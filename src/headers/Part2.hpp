/**
 * @file Part2.hpp
 * @author Gabriel Dos Santos (gabriel.dos-santos@ens.uvsq.fr)
 * @brief Collection of functions used for the second part of C++ Project for module IN505.
 * @version 0.1.0
 * @copyright Copyright (c) 2020
 */

#ifndef PART_TWO_HPP
#define PART_TWO_HPP

#pragma once
#include <fstream>
#include <vector>
#include "ArbreB.hpp"

/**
 * Checks if an ArbreB holding the specified character is present in the vector.
 * Uses a boolean expression to break the for loop early if the characcter is found.
 * @param vec A reference to the vector to search in.
 * @param content The character to search for.
 * @return The index of the ArbreB holding the character + 1 if found, 0 otherwise.
 */
unsigned int find(std::vector<ArbreB>& vec, char& content);

/**
 * Finds the ArbreB with the lowest frequency in the specified vector.
 * Creates a copy of the ArbreB with the lowest frequency.
 * Deletes the original from the vector.
 * @param btrees A reference of the vector to search in.
 * @return A copy of the ArbreB with the lowest frequency.
 */
ArbreB find_lowest(std::vector<ArbreB>& btrees);

/**
 * Parses a given text file into a string.
 * Reads each character of the file and appends it to a string.
 * @param filename The name of the file to parse.
 * @return A string holding the content of the file.
 */
std::string parse_file_to_string(char* filename);

/**
 * Constructs a vector of ArbreBs from the specified string.
 * For each character present in the string, creates an ArbreB in the vector.
 * The ArbreB is initialized with the read character if it is unknown and a frequency of 1.
 * If the read character is already know, increments its frequency by one.
 * When the whole string is read, transforms the frequency of each character to a percentage.
 * @param content The string to build the vector from.
 * @return A vector of ArbreB for each character of the string and their frequency.
 */
std::vector<ArbreB> build_btree_vector(std::string& content);

/**
 * Builds the Huffman tree for a given vector of ArbreBs.
 * Fuses the ArbreBs of the vector together following the Huffman algorithm.
 * @param btrees The vector of ArbreBs to fuse.
 * @return An Huffman tree for the given vector of ArbreB.
 */
ArbreB build_huffman_tree(std::vector<ArbreB>& btrees);

/**
 * Compresses a given string to its binary representation.
 * Reads the string and for each character (key), appends the corresponding binary value to be returned.
 * @param map A map of characters (keys) and their binary representations (values).
 * @param file_content The string to compress.
 * @return The compressed string.
 */
std::string compress_to_bin(std::map<char, std::string> map, std::string file_content);

/**
 * Utility function that simply prints the input text to the terminal.
 * @param input A string holding the content of a text file.
 */
void print_input(std::string input);

/**
 * Utility function that prints the binary representation of each character in a string.
 * @param map A map holding characters as keys and their binary representations as values.
 */
void print_map(std::map<char, std::string> map);

/**
 * Utility function that simply prints the compressed input text as binary to the terminal.
 * @param output A string holding the binary representation of the content of a text file.
 */
void print_output(std::string output);

#endif
