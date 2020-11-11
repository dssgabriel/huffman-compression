#include "Sommet.hpp"

Sommet::Sommet()
    : m_Left(nullptr), m_Right(nullptr) {}

Sommet::Sommet(char& data, double& freq)
    : m_Data(data), m_Freq(freq), m_Left(nullptr), m_Right(nullptr) {}

Sommet::Sommet(const Sommet& other)
    : m_Data(other.m_Data), m_Freq(other.m_Freq)
{
    m_Left = other.m_Left;
    m_Right = other.m_Right;
}

Sommet& Sommet::operator=(const Sommet& other)
{
    m_Data = other.m_Data;
    m_Freq = other.m_Freq;
    // TODO
    return *this;
}
