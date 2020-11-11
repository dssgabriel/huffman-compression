#ifndef SOMMET_HPP
#define SOMMET_HPP


/// The class `Sommet` represents a node of a Huffman binary tree.
class Sommet
{
private:
    /// Stores a character present in the input text.
    char m_Data;
    /// Stores the frequency of a character in the text.
    double m_Freq;
    /// Pointer to the left child of the node.
    Sommet* m_Left;
    /// Pointer to the right child of the node.
    Sommet* m_Right;

public:
    /// Default constructor.
    Sommet();

    /// Parameter constructor.
    /// #Arguments:
    /// `data` - The character to store.
    /// ``freq` - The frequency of this character.
    Sommet(const char& data, const double& freq);

    /// Copy constructor.
    /// #Argument:
    /// `other` - The Sommet to copy.
    Sommet(const Sommet& other);

    /// Overload of the assign operator.
    /// #Argument:
    /// `other` - The Sommet to assign the object's fields from.
    Sommet& operator=(const Sommet& other);

    /// Returns the character stored in m_Data.
    char& get_m_Data();

    /// Returns the frequency stored in m_Freq.
    double& get_m_Freq();

    /// Set the value of m_Data.
    /// #Argument:
    /// `data` - The character to assign to m_Data.
    void set_m_Data(const char& data);

    /// Set the value of m_Freq.
    /// #Argument:
    /// `freq` - The value to assign to m_Freq.
    void set_m_Freq(const double& freq);
};

#endif
