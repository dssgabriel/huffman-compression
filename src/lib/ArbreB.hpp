#ifndef ARBREB_HPP
#define ARBREB_HPP

#include "Sommet.hpp"

/**
 * The class ArbreB represents a binary tree.
 */
class ArbreB
{
private:
    /**
     * Represents a pointer to the root of the binary tree.
     */
    Sommet* m_Root;

public:
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
     * Redefines the behavior of the operator "=".
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
     * Inserts a Sommet in the binary tree.
     * Insertion behaves like in Binary Search Tree (BST).
     * @param node
     *     The Sommet to insert in the binary tree.
     */
    void insert(const Sommet& node);

    /**
     * Searches for a character in the binary tree.
     * Does a breadth first search (parcours en largeur).
     * @param data
     *     The character to search for.
     * @return
     *     'True' if the character was found, 'False' otherwise.
     */
    bool search(const char& data);

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
     * Fuses two ArbreB together into one.
     * Creates a new ArbreB.
     * m_Left of the new root is 'this'.
     * m_Right of the new root is 'other'.
     * m_Data of the new root is ?? (find something).
     * m_Freq of the new root is the sum of this.m_Freq and other.m_Freq.
     * @param other
     *     The ArbreB to fuse.
     * @return
     *     A fused ArbreB.
     */
    ArbreB fuse(const ArbreB& other);

    /**
     * Decomposes one ArbreB into two.
     * TODO.
     */
};

#endif
