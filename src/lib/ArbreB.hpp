#ifndef ARBREB_HPP
#define ARBREB_HPP

#include "Sommet.hpp"
#include <iostream>
#include <cstring>
#include <tuple>

/**
 * The class `ArbreB` represents a binary tree.
 * @author Gabriel Dos Santos
 * @version 0.1.0
 * @date 2020/11/17
 */
class ArbreB {
    private:
        /**
         * Represents a pointer to the root of the object `ArbreB`.
         */
        Sommet* m_Root;

        /**
         * Recursively performs a preorder traversal of the object `ArbreB`.
         * @param current A reference of the pointer of the current `Sommet`.
         */
        void preorder_traversal(Sommet*& current);

        /**
         * Recursively performs an inorder traversal of the object `ArbreB`.
         * @param current A reference of the pointer of the current `Sommet`.
         */
        void inorder_traversal(Sommet*& current);

        /**
         * Recursively performs a postorder traversal of the object `ArbreB`.
         * @param current A reference of the pointer of the current `Sommet`.
         */
        void postorder_traversal(Sommet*& current);

        /**
         * Inserts a new node in the object `ArbreB`.
         * The behavior of this method assumes that the value is inserted in a Binary Search Tree (BST).
         * By design decision, insertion is based on `m_Data` field of an object `Sommet`.
         * If the specified `Sommet`'s character is already present in the `ArbreB`, the new Sommet will not be inserted.
         * However, the frequency of that character will be updated by adding the specified `Sommet`'s `m_Freq` to the one of the already present `Sommet`.
         * @param current_node A reference of the pointer of the current `Sommet`.
         * @param new_node The Sommet to insert in the `ArbreB`.
         */
        void insert(Sommet*& current_node, Sommet& new_node);

        /**
         * Searches for the specified character in the object 'ArbreB'.
         * This method is implemented with a breadth first search (BFS) algorithm.
         * @param current A reference of the pointer of the current `Sommet`.
         * @param data The character to search for.
         * @return `True` if the character was found, `False` otherwise.
         */
        bool search(Sommet*& current, const char& data);

        /**
         * Searches for the specified character in the object `ArbreB`.
         * This method is implemented assuming the `ArbreB` is a Binary Search Tree (BST).
         * It allows for an average time complexity of O(log(n)).
         * @param current A reference of the pointer of the current `Sommet`.
         * @param data The character to search for.
         * @param path A string that stores the path to the character. '0's mean the path takes a left branch, '1's means it takes a right branch.
         * @return `True` if the character was found, `False` otherwise.
         */
        bool bst_search(Sommet*& current, const char& data, std::string& path);

        /**
         * Removes a node from the object `ArbreB`.
         * Searches for a `Sommet` holding the specified character.
         * Deletes the `Sommet` if found, returns the object unchanged otherwise.
         * @param current A reference of the pointer of the current `Sommet`.
         * @param data The character to find and remove.
         * @return A reference of the `ArbreB` with the removed `Sommet`.
         */
        ArbreB& remove(Sommet*& current, const char& data);

    public:
        /**
         * Creates a default object `ArbreB`.
         * Sets `m_Root` at `nullptr`.
         */
        ArbreB();

        /**
         * Creates an object `ArbreB` from the specified parameters.
         * @param data The character to store in the root of the `ArbreB`.
         * @param freq The character's frequency to store in the root of the `ArbreB`.
         */
        ArbreB(const char& data, const double& freq);

        /**
         * Creates an object `ArbreB` from the specified `Sommet`.
         * @param node The `Sommet` to initialize `m_Root` from.
         */
        ArbreB(const Sommet& node);

        /**
         * Creates a copy of the specified `ArbreB`.
         * @param other The `ArbreB` to copy.
         */
        ArbreB(const ArbreB& other);

        /**
         * Frees the memory of an `ArbreB`.
         */
        ~ArbreB();

        /**
         * Overloads the operator `=` to redefine its behavior.
         * @param other The `ArbreB` to assign the values from.
         * @return A reference to a copy of `other`.
         */
        ArbreB& operator=(const ArbreB& other);

        /**
         * Gets the root of the object `ArbreB`.
         * @return A reference to the root of the `ArbreB`.
         */
        Sommet& get_m_Root();

        /**
         * Overloads the operator `>>` and redefines its behavior.
         * @param stream The output stream.
         * @param tree The `ArbreB`.
         * @return The output stream to print to `std::cout`.
         */
        friend std::ostream& operator<<(std::ostream& stream, ArbreB& tree);

        /**
         * Inserts a new node in the object `ArbreB`.
         * Internaly calls private method `insert()`.
         * @param new_node The `Sommet` to insert in the `ArbreB`.
         */
        void insert(Sommet& new_node);

        /**
         * Inserts a new node in the object `ArbreB`.
         * Internaly calls private method `insert()`.
         * @param data The character to insert in the `ArbreB`.
         * @param freq The frequency of the character to insert.
         */
        void insert(const char& data, const double& freq);

        /**
         * Searches for the specified character in the object `ArbreB`.
         * Internaly calls private method `search()`.
         * @param data The character to search for.
         * @return `True` if the character was found, `False` otherwise.
         */
        bool search(const char& data);

        /**
         * Searches for the specified character in the object `ArbreB`.
         * Internaly calls private method `bst_search()`.
         * @param data The character to search for.
         * @param path A string that stores the path to the character. '0's mean the path takes a left branch, '1's means it takes a right branch.
         * @return `True` if the character was found, `False` otherwise.
         */
        bool bst_search(const char& data, std::string& path);

        /**
         * Removes a `Sommet` from the object `ArbreB`.
         * Internaly calls private method `remove()`.
         * @param data The character to delete.
         * @return A reference of the `ArbreB` with the removed `Sommet`.
         */
        ArbreB& remove(const char& data);

        /**
         * Overloads the operator `+` to redefine its behavior.
         * Fuses two `ArbreB` together to creates a new one.
         * Sets `m_Root->m_Left` as `this`, `m_Root->m_Right` as `other`.
         * Sets `m_Root->m_Data` as `\0`, `m_Root->m_Freq` as `this.m_Root->m_Freq + other.m_Root->m_Freq`.
         * @param other The `ArbreB` to fuse.
         * @return The fusion of the two `ArbreB`s.
         */
        ArbreB operator+(const ArbreB& other);

        /**
         * Decomposes one object `ArbreB` into two.
         * @return An std::tuple that holds two `ArbreB`. The first one is the left branch of the original tree. The second one is the right branch of the original tree.
         */
        std::tuple<ArbreB, ArbreB> decompose();

        /**
         *
         */
        Sommet* get_root();

        /**
         * Function written by Rapahel Marouani
         */
        void print(int a, ArbreB& other);

        /**
         * Prints an ArbreB.
         */
        void print();

};

#endif
