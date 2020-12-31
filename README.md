# IN505 - C++ Project: Compression and Uncompression

## Description of the project

The goal of this project is to write an application for compressing and uncompressing text based on a C++ implementation of the Huffman compression algorithm.

The Huffman code aims at converting a text in binary (with '0's and '1's) and compressing the size of the output file without losing any data. For each letters in the text to compress, we count how much instances of each letters there are and then apply the following algorithm on each one:

-   Initially, each letter is represented by a binary tree labeled with the occurrence of that character in the text. While there are more than one binary tree, do the following operations:
    1.  Take `A1` and `A2`, the two binary trees with the smallest label `e1` and `e2`.
    2.  Create a new binary tree `A` of which the root `r` has for left and right branches the roots of `A1` and `A2`.
    3.  Label the root `r` of `A` with `e1 + e2`.
-   For each node of the final tree, the left branches are labeled with '0's, and the right branches with '1's.
-   The code associated with each character is the binary word corresponding to the path from the root of the final binary tree to the leaf representing the letter.

This project is made up of three parts.

### Part 1: Abstract data structures

The goal of this part is to propose an object-oriented implementation of the structure and behavior of a labeled binary tree. In that regard, the objective will be to:

-   Propose two classes, the class `Sommet` of which each instance represents the node of a binary tree, and the class `ArbreB` of which each instance represents a binary tree.
-   Implement the operations for inserting and removing nodes from the tree, modifying the label of a node, researching an element in the tree, as well as the operations of fusion and decomposition of binary trees. You may also overload the necessary operators.
-   Propose a test program that demonstrates the features of a binary tree.
-   Implement a simple graphical user interface (GUI) that allows, amongst other things, to print the created binary tree.

### Part 2: Compression

The goal of this part is to take an input text (it can be in English, French, or any other language that you want) and to output a compressed text using the Huffman code. Your application must support the following operations:

1.  Compute the percentage of occurrence for each letter of the alphabet of the input text.
2.  Using the previously defined model of a binary tree, create a compression binary tree that implements the aforementioned algorithm and the statistics evaluated in step 1.
3.  Compress an input text with the letter compression made in step 2.
4.  Enhance the GUI to allow the user to print the text to compress and its binary output.

### Part 3: Uncompression

The goal of this third and last part is to take a compressed text with the Huffman code and to uncompress this text. Your application should be able to:

-   Verify if a text has been compressed using the binary tree created in part 2.
-   Uncompress a text compressed with the Huffman code.
-   Display the text to uncompress in the GUI and print the result of the uncompression process.


## Building the project

The project uses the CMake toolchain to build the project.
In order to simplify this process, the project comes with a `build.sh` script that you can run with the following:
``` sh
./build.sh
```

Then simply follow the instructions on the screen to complete the build process.

If, for whatever reason the script is not executable, you can use the following command:
``` sh
chmod +x build.sh .check_dependencies.sh
```

To run the application, simply type:
``` sh
./partie_3
```
