#include <iostream>
#include "../lib/ArbreB.hpp"

int main() {
// class Sommet:
    std::cout << "\nTesting class Sommet:" << std::endl;

    // Testing constructors
    Sommet s1;
    Sommet s2('g', 67.0);
    Sommet s3(s2);
    // Testing values with default constructor
    std::cout << "\tSommet s1():\n\t\tData: " << s1.get_m_Data()
        << ", Freq: " << s1.get_m_Freq() << std::endl;
    // Testing values for parameter constructor
    std::cout << "\tSommet s2('g', 67.0):\n\t\tData: " << s2.get_m_Data()
        << ", Freq: " << s2.get_m_Freq() << std::endl;
    // Testing values for copy constructor
    std::cout << "\tSommet s3(s2):\n\t\tData: " << s3.get_m_Data()
        << ", Freq: " << s3.get_m_Freq() << std::endl;

    // Testing setters
    s2.set_m_Data('r');
    s2.set_m_Freq(72.0);
    std::cout << "\tSetting s2('r', 72.0):\n\t\tData: " << s2.get_m_Data()
        << ", Freq: " << s2.get_m_Freq() << std::endl;
    std::cout << "\tUnchanged s3:\n\t\tData: " << s3.get_m_Data()
        << ", Freq: " << s3.get_m_Freq() << std::endl;

    // Testing overloaded operator=
    s2 = s3;
    std::cout << "\ts2 = s3:\n\t\tData: " << s2.get_m_Data()
        << ", Freq: " << s2.get_m_Freq() << std::endl;
    std::cout << "\ts3:\n\t\tData: " << s3.get_m_Data()
        << ", Freq: " << s3.get_m_Freq() << std::endl;


// class ArbreB:
    std::cout << "\nTesting class ArbreB:" << std::endl;

    // Testing constructors
    ArbreB a1();
    ArbreB a2('i', 69.0);
    ArbreB a3(s3);
    ArbreB a4(a2);
    // Testing values with parameter constructor
    std::cout << "\tArbreB a2('i', 69.0):\n\tm_Root:\n\t\tData: " << a2.get_m_Root().get_m_Data()
        << ", Freq: " << a2.get_m_Root().get_m_Freq() << std::endl;
    // Testing values with Sommet constructor
    std::cout << "\tArbreB a3(s3):\n\tm_Root:\n\t\tData: " << a3.get_m_Root().get_m_Data()
        << ", Freq: " << a3.get_m_Root().get_m_Freq() << std::endl;
    // Testing values with copy constructor
    std::cout << "\tArbreB a4(a3):\n\tm_Root:\n\t\tData: " << a4.get_m_Root().get_m_Data()
        << ", Freq: " << a4.get_m_Root().get_m_Freq() << std::endl;

    // Inserting a Sommet
    a2.insert(s2);
    s2 = Sommet('y', 79.0);
    a2.insert(s2);
    s3 = Sommet('.', 0.1);
    a2.insert(s3);
    std::cout
        << "\tArbreB a2.insert(a2.m_Root, s2):\n\tm_Root:\n\t\tData: " << a2.get_m_Root().get_m_Data()
        << ", Freq: " << a2.get_m_Root().get_m_Freq()
        << "\n\tm_Left:\n\t\tData: " << a2.get_m_Root().m_Left->get_m_Data()
        << ", Freq: " << a2.get_m_Root().m_Left->get_m_Freq()
        << "\n\tm_Right:\n\t\tData: " << a2.get_m_Root().m_Right->get_m_Data()
        << ", Freq: " << a2.get_m_Root().m_Right->get_m_Freq() << std::endl;

    // Bst_Searching for a character
    std::string a = "";
    a2.bst_search('.', a);
    std::string b = "";
    a2.bst_search('z', b);
    std::string c = "";
    a2.bst_search('i', c);
    std::string d = "";
    a2.bst_search('y', d);
    std::string e = "";
    a2.bst_search('g', e);

    Sommet s5('y', 1.2);
    a2.insert(s5);
    a2.remove('d');
    std::cout << "\n\tArbreB a2:\n" << a2;
    a2.remove('i');
    std::cout << "\n\tRemoved 'i' from a2:\n" << a2;
    a2.remove('y');
    std::cout << "\n\tRemoved 'y' from a2:\n" << a2;

    ArbreB a5(a2);
    ArbreB a6 = a2 + a5;
    std::cout << "\n\tArbreB a6 (a2 + a5):\n" << a6;

    ArbreB s7, s8;
    std::tie(s7, s8) = a6.decompose();

    std::cout << "\n\tArbreB a7(decomp a6 (== a2))\n" << s7
        << "\n\tArbreB a8(decomp a6 (== a5))\n" << s8 << std::endl;

    return 0;
}
