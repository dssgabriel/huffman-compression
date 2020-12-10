#include "Sommet.hpp"

Sommet::Sommet()
    : m_Data('\0'), m_Freq(0.0), m_Left(nullptr), m_Right(nullptr) {}

Sommet::Sommet(const char& data, const double& freq)
    : m_Data(data), m_Freq(freq), m_Left(nullptr), m_Right(nullptr) {}

// Using the overloaded operator= to copy the specified Sommet
Sommet::Sommet(const Sommet& other) {
    *this = other;
}

Sommet::~Sommet() {
    // Delete only if pointers to m_Left/m_Right are not nullptr
    if (m_Left != nullptr) {
        delete m_Left;
    }
    if (m_Right != nullptr) {
        delete m_Right;
    }
}

Sommet& Sommet::operator=(const Sommet& other) {
    // Copy `other`'s m_Data and m_Freq
    m_Data = other.m_Data;
    m_Freq = other.m_Freq;

    // Check that other.m_Left is not a nullptr before assigning m_Left
    if (other.m_Left != nullptr) {
        m_Left = new Sommet();
        *m_Left = *other.m_Left;
    } else {
        m_Left = nullptr;
    }
    // Check that other.m_Right is not a nullptr before assigning m_Right
    if (other.m_Right != nullptr) {
        m_Right = new Sommet();
        *m_Right = *other.m_Right;
    } else {
        m_Right = nullptr;
    }

    return *this;
}

char& Sommet::get_data() {
    return m_Data;
}

double& Sommet::get_freq() {
    return m_Freq;
}

Sommet* Sommet::get_left() {
    return m_Left;
}

Sommet* Sommet::get_right() {
    return m_Right;
}

void Sommet::set_data(const char& data) {
    m_Data = data;
}

void Sommet::set_freq(const double& freq) {
    m_Freq = freq;
}

void Sommet::print(int spacing) {
    std::cout.precision(3);
    if (m_Right) {
        m_Right->print(spacing + 1);
    }

    for (int i = 0; i < spacing; i++) {
        std::cout << "    ";
    }
    if (m_Data == '\0') {
        std::cout << "(" << m_Freq << "), " << std::endl;
    }
    else if (m_Data == '\n') {
        std::cout << "(\\n, " << m_Freq << ")" << std::endl;
    }
    else {
        std::cout << "(" << m_Data << ", " << m_Freq << ")" << std::endl;
    }

    if (m_Left) {
        m_Left->print(spacing + 1);
    }
}
