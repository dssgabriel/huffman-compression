#ifndef SOMMET_HPP
#define SOMMET_HPP

class ArbreB;

/**
 * The class `Sommet` represents a node of a Huffman binary tree.
 */
class Sommet
{
private:
    friend class ArbreB;
    /**
     * Represents a character from a text.
     */
    char m_Data;
    /**
     * Represents the frequency of a character in a text.
     */
    double m_Freq;

public:
    /**
     * Represents the left child of a Sommet.
     */
    Sommet* m_Left;
    /**
     * Represents the right child of a Sommet.
     */
    Sommet* m_Right;
    /**
     * Creates a default object Sommet.
     * m_Data = '\0', m_Freq = 0, m_Left and m_Right = nullptr.
     */
    Sommet();

    /**
     * Creates an object Sommet with the specified parameters.
     * @param data
     *     The character to store.
     * @param freq
     *     The frequency of the stored character.
     */
    Sommet(const char& data, const double& freq);

    /**
     * Creates a copy of the specified Sommet.
     * @param other
     *     The Sommet to copy.
     */
    Sommet(const Sommet& other);

    /**
     * Frees the memory for of a Sommet.
     */
    ~Sommet();

    /**
     * Redefines the behavior of the operator "=".
     * @param other
     *     The Sommet to assign the values from.
     *  @return
     *     A reference to a copy of other.
     */
    Sommet& operator=(const Sommet& other);

    /**
     * Gets the character.
     * @return
     *     A reference of the character.
     */
    char& get_m_Data();

    /**
     * Gets the character's frequency.
     * @return
     *     A reference of the character's frequency.
     */
    double& get_m_Freq();

    /**
     * Gets the Sommet's left child.
     * @return
     *     A reference of the Sommet's left child.
     */
    Sommet& get_m_Left();

    /**
     * Gets the Sommet's right child.
     * @return
     *     A reference of the Sommet's right child.
     */
    Sommet& get_m_Right();

    /**
     * Sets the value of the character.
     * @param data
     *     The character to assign to m_Data.
     */
    void set_m_Data(const char& data);

    /**
     * Sets the value of the frequency.
     * @param freq
     *     The value to assign to m_Freq.
     */
    void set_m_Freq(const double& freq);
};

#endif
