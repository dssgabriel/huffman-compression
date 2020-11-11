#include "Sommet.hpp"

Sommet::Sommet()
    : m_Left(nullptr), m_Right(nullptr) {}

Sommet::Sommet(const char& data, const double& freq)
    : m_Data(data), m_Freq(freq), m_Left(nullptr), m_Right(nullptr) {}

Sommet::Sommet(const Sommet& other)
{
    *this = other;
}

Sommet& Sommet::operator=(const Sommet& other)
{
    m_Data = other.m_Data;
    m_Freq = other.m_Freq;
    if (other.m_Left != nullptr)
    {
        m_Left = new Sommet();
        *m_Left = *other.m_Left;
    }
    else
    {
        m_Left = nullptr;
    }
    if (other.m_Right != nullptr)
    {
        m_Right = new Sommet();
        *m_Right = *other.m_Right;
    }
    else
    {
        m_Right = nullptr;
    }

    return *this;
}

char& Sommet::get_m_Data()
{
    return m_Data;
}

double& Sommet::get_m_Freq()
{
    return m_Freq;
}

void Sommet::set_m_Data(const char& data)
{
    m_Data = data;
}

void Sommet::set_m_Freq(const double& freq)
{
    m_Freq = freq;
}
