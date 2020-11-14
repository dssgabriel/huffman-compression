#ifndef ARBREB_HPP
#define ARBREB_HPP

#include "Sommet.hpp"
#include <iostream>
#include <cstring>

/**
 * The class ArbreB represents a binary tree.
 */
class ArbreB
{
private:

public:
    /**
     * Represents a pointer to the root of the binary tree.
     */
    Sommet* m_Root;
    /**
     * Creates a default object ArbreB.
     * m_Root = nullptr
     */
    ArbreB();

    /**
     * Creates an object ArbreB from the specified parameters.
     * @param data
     *     The character to store in the Sommet m_Root.
     * @param freq
     *     The frequency to store in the Sommet m_Root.
     */
    ArbreB(const char& data, const double& freq);

    /**
     * Creates an object ArbreB from the specified Sommet.
     * @param node
     *     The Sommet to initialize m_Root from.
     */
    ArbreB(const Sommet& node);

    /**
     * Creates a copy of the specified ArbreB.
     * @param other
     *     The ArbreB to copy.
     */
    ArbreB(const ArbreB& other);

    /**
     * Frees the memory of an ArbreB.
     */
    ~ArbreB();

    /**
     * Overload of the operator '=' to redefine its behavior.
     * @param other
     *     The ArbreB to assign the values from.
     *  @return
     *     A reference to a copy of other.
     */
    ArbreB& operator=(const ArbreB& other);

    /**
     * Gets the root of the binary tree.
     * @return
     *     A reference to the root.
     */
    Sommet& get_m_Root();

    /**
     * Overload the operator ">>" and redefines its behavior.
     * @param stream
     *     The output stream.
     * @param tree
     *     The binary tree.
     * @return
     *     The output stream to print with std::cout.
     */
    friend std::ostream& operator<<(std::ostream& stream, const ArbreB& tree);

    /**
     * Inserts a new node in the binary tree.
     * The behavior of this method assumes that we are inserting
     * a value in a Binary Search Tree (BST).
     * By design decision, insertion is based on the m_Freq field of an object Sommet.
     * This means that an ArbreB can have multiple Sommets with the same
     * character (m_Data), but with different frequencies (m_Freq).
     * @param current_node
     *     A reference of the pointer of the current Sommet.
     *     Allows to initialize the actual Sommet and not a copy of it.
     * @param new_node
     *     The Sommet to insert in the binary tree.
     */
    void insert(Sommet*& current_node, Sommet& new_node);

    /**
     * Searches for the specified character in the binary tree.
     * This method is implemented with a breadth first search (BFS) algorithm.
     * @param current
     *     A reference of the pointer of the current Sommet.
     * @param data
     *     The character to search for.
     * @return
     *     'True' if the character was found, 'False' otherwise.
     */
    bool search(Sommet*& current, const char& data);

    /**
     * Searches for the specified character in the binary tree.
     * This method is implemented assuming the ArbreB is Binary Search Tree (BST).
     * Allows for an average time complexity of O(log(n)).
     *  @param current
     *     A reference of the pointer of the current Sommet.
     * @param data
     *     The character to search for.
     * @param path
     *     A string that stores the path to the character.
     *     '0's mean the path takes a left branch, '1's means it takes a right branch.
     * @return
     *     'True' if the character was found, 'False' otherwise.
     */
    bool bst_search(Sommet*& current, const char& data, std::string& path);

    /**
     * Removes a Sommet from the binary tree.
     * Searches for a Sommet containing the specified character.
     * If found, deletes the Sommet, else does not do anything.
     * @param data
     *     The character to delete the corresponding Sommet.
     * @return
     *     A reference of the ArbreB with the removed Sommet.
     */
    ArbreB& remove(const char& data);

    /**
     * Overload of the operator '+=' to redefine its behavior.
     * Fuses two ArbreB together to creates a new ArbreB.
     * m_Left of the new root is 'this'.
     * m_Right of the new root is 'other'.
     * m_Data of the new root is ?? (find something).
     * m_Freq of the new root is the sum of this.m_Freq and other.m_Freq.
     * @param other
     *     The ArbreB to fuse.
     * @return
     *     A fused ArbreB.
     */
    ArbreB operator+=(const ArbreB& other);

    /**
     * Decomposes one ArbreB into two.
     * TODO.
     */
};

#endif
