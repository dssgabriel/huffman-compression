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


// class ArbreB
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
    std::cout << "ArbreB a4(a3):\n\tm_Root:\n\t\tData: " << a4.get_m_Root().get_m_Data()
        << ", Freq: " << a4.get_m_Root().get_m_Freq() << std::endl;

    return 0;
}
