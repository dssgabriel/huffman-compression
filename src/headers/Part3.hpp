/**
 * @file Part3.hpp
 * @author Gabriel Dos Santos
 * @brief Collection of functions for the third part of the project.
 * @version 0.1.0
 * @date 2020-12-21
 */

#ifndef PART_THREE_HPP
#define PART_THREE_HPP

#pragma once
#include "Part2.hpp"

/**
 * Verifies that the specified input is in binary format.
 * @param input The input string.
 * @return True if the input is binary, false otherwise.
 */
bool is_huffman_code(std::string& input);

/**
 *
 */
bool is_repeated_character(std::string input);

/** 
 * Uncompresses a binary string to its ASCII format.
 * Performs a inorder traversal of the specified Huffman tree to uncompress the input binary.
 * @param input The input string in binary format.
 * @param huffman The huffman tree to traverse to uncompress the input string.
 * @return std::string The uncompressed string in ASCII format.
 */
std::string uncompress_binary(std::string& input, ArbreB& huffman);

#endif
