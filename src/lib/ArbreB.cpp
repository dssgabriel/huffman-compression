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

// Uses overloaded operator=
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

void ArbreB::insert(Sommet*& current_node, Sommet& new_node)
{
    if (current_node == nullptr)
    {
        current_node = new Sommet(new_node);
    }
    if (current_node->get_m_Freq() > new_node.get_m_Freq())
    {
        insert(current_node->m_Left, new_node);
    }
    if (current_node->get_m_Freq() < new_node.get_m_Freq())
    {
        insert(current_node->m_Right, new_node);
    }
}

bool ArbreB::search(Sommet*& current, const char& data)
{
    if (current == nullptr)
    {
        return false;
    }
    if (current->get_m_Data() == data)
    {
        return true;
    }
    else
    {
        return search(current->m_Left, data) || search(current->m_Right, data);
    }
}

// TODO
ArbreB& ArbreB::remove(const char& data)
{
}

// TODO
ArbreB ArbreB::fuse(const ArbreB& other)
{
}
