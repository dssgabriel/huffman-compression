#include <iostream>
#include "../lib/ArbreB.hpp"

int main() {
    Sommet s1;
    Sommet s2('y', 1.0);
    Sommet s3(s2);

    std::cout << "s2: Data: " << s2.get_m_Data() << ", Freq: " << s2.get_m_Freq() << std::endl;
    std::cout << "s3: Data: " << s3.get_m_Data() << ", Freq: " << s3.get_m_Freq() << std::endl;

    s2.set_m_Data('g');
    s2.set_m_Freq(2.0);

    std::cout << "s2: Data: " << s2.get_m_Data() << ", Freq: " << s2.get_m_Freq() << std::endl;
    std::cout << "s3: Data: " << s3.get_m_Data() << ", Freq: " << s3.get_m_Freq() << std::endl;

    return 0;
}
