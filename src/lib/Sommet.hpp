#ifndef SOMMET_HPP
#define SOMMET_HPP

#include <iostream>

class ArbreB;

/**
 * The class `Sommet` represents a node of the class `ArbreB`.
 * @author Gabriel Dos Santos
 * @version 0.1.0
 * @date 2020/11/17
 */
class Sommet {
    friend class ArbreB;
    private:
        /**
         * Represents a character from a text.
         */
        char m_Data;
        /**
         * Represents the frequency of a character in a text.
         */
        double m_Freq;
        /**
         * Represents the left child of an object `Sommet`.
         */
        Sommet* m_Left;
        /**
         * Represents the right child of an object `Sommet`.
         */
        Sommet* m_Right;

    public:
        /**
         * Creates a default object `Sommet`.
         * Sets `m_Data` to `\0`, `m_Freq` to `0`, `m_Left` and `m_Right` to `nullptr`.
         */
        Sommet();

        /**
         * Creates an object `Sommet` with the specified parameters.
         * @param data The character to store.
         * @param freq The frequency of the stored character.
         */
        Sommet(const char& data, const double& freq);

        /**
         * Creates a copy of the specified object `Sommet`.
         * @param other The `Sommet` to copy.
         */
        Sommet(const Sommet& other);

        /**
         * Frees the memory for of an object `Sommet`.
         */
        ~Sommet();

        /**
         * Redefines the behavior of the operator `=`.
         * @param other The object `Sommet` to assign the values from.
         * @return A reference to a copy of `other`.
         */
        Sommet& operator=(const Sommet& other);

        /**
         * Gets the character.
         * @return A reference of the character.
         */
        char& get_data();

        /**
         * Gets the character's frequency.
         * @return A reference of the character's frequency.
         */
        double& get_freq();

        /**
         * Gets the left child.
         * @return A reference of the left child.
         */
        Sommet* get_left();

        /**
         * Gets the right child.
         * @return A reference of the right child.
         */
        Sommet* get_right();

        /**
         * Sets the value of the character.
         * @param data The character to assign to `m_Data`.
         */
        void set_m_Data(const char& data);

        /**
         * Sets the value of the frequency.
         * @param freq The value to assign to `m_Freq`.
         */
        void set_m_Freq(const double& freq);

        /** 
         * Function written by Raphael
         */
        void print(Sommet& other); //AJOUT

        /**
         * Prints an ArbreB.
         */
        void print(int spacing);
};

#endif
