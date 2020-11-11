#include <iostream>
#include "../lib/ArbreB.hpp"

int main() {
    // Testing constructors
    Sommet s1;
    Sommet s2('y', 1.0);
    Sommet s3(s2);
    // Testing getters
    std::cout << "s2: Data: " << s2.get_m_Data() << ", Freq: " << s2.get_m_Freq() << std::endl;
    std::cout << "s3: Data: " << s3.get_m_Data() << ", Freq: " << s3.get_m_Freq() << std::endl;

    // Testing setters
    s2.set_m_Data('g');
    s2.set_m_Freq(2.0);
    std::cout << "s2: Data: " << s2.get_m_Data() << ", Freq: " << s2.get_m_Freq() << std::endl;
    std::cout << "s3: Data: " << s3.get_m_Data() << ", Freq: " << s3.get_m_Freq() << std::endl;

    // Testing overload assign operator
    s2 = s3;
    std::cout << "s2: Data: " << s2.get_m_Data() << ", Freq: " << s2.get_m_Freq() << std::endl;
    std::cout << "s3: Data: " << s3.get_m_Data() << ", Freq: " << s3.get_m_Freq() << std::endl;

    // Testing values with default constructor
    Sommet s4 = s1;
    std::cout << "s1: Data: " << s1.get_m_Data() << ", Freq: " << s1.get_m_Freq() << std::endl;
    std::cout << "s4: Data: " << s4.get_m_Data() << ", Freq: " << s4.get_m_Freq() << std::endl;
    return 0;
}
