#include "ArbreB.hpp"

ArbreB::ArbreB()
    : m_Root(nullptr)
{
}

ArbreB::ArbreB(const char& data, const double& freq)
{
    m_Root = new Sommet(data, freq);
}

ArbreB::ArbreB(const Sommet& node)
{
    m_Root = new Sommet();
    *m_Root = node;
}

ArbreB::ArbreB(const ArbreB& other)
{
    *this = other;
}

ArbreB::~ArbreB()
{
    if (m_Root != nullptr)
    {
        delete m_Root;
    }
}

ArbreB& ArbreB::operator=(const ArbreB& other)
{
    if (other.m_Root != nullptr)
    {
        m_Root = new Sommet();
        *m_Root = *other.m_Root;
    }
    return *this;
}

Sommet& ArbreB::get_m_Root()
{
    return *m_Root;
}

void ArbreB::insert(const Sommet& node, const double& freq)
{
    if (m_Root == nullptr)
    {
        *m_Root = node;
    }
}

bool ArbreB::search(const double& freq)
{
}

ArbreB& ArbreB::remove(const double& freq)
{
}

ArbreB ArbreB::fuse(const ArbreB& other)
{
}
