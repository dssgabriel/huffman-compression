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

std::ostream& operator<<(std::ostream& stream, const ArbreB& tree)
{
    // TODO
    return stream;
}

void ArbreB::insert(Sommet*& current_node, Sommet& new_node)
{
    if (current_node == nullptr)
    {
        current_node = new Sommet(new_node);
    }
    else if (current_node->get_m_Freq() == new_node.get_m_Freq())
    {
        std::cout << "Error: a Sommet of the same value is already in the ArbreB" << std::endl;
        return;
    }
    else if (current_node->get_m_Freq() > new_node.get_m_Freq())
    {
        insert(current_node->m_Left, new_node);
    }
    else
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
    else if (current->get_m_Data() == data)
    {
        return true;
    }
    else
    {
        return search(current->m_Left, data) || search(current->m_Right, data);
    }
}

bool ArbreB::bst_search(Sommet*& current, const char& data, std::string& path)
{
    if (current == nullptr)
    {
        std::cout << "Character '" << data << "' was not found!" << std::endl;
        return false;
    }
    else if (current->get_m_Data() == data)
    {
        std::cout << "Character '" << data << "' was found!\t"
            << "Path is: " << path << std::endl;
        return true;
    }
    else if (current->get_m_Data() > data)
    {
        path.resize(path.size() + 1);
        path += "0";
        return bst_search(current->m_Left, data, path);
    }
    else
    {
        path.resize(path.size() + 1);
        path += "1";
        return bst_search(current->m_Right, data, path);
    }
}

ArbreB& ArbreB::remove(const char& data)
{
    if (!search(m_Root, data))
    {
        std::cout << "Error: the character to remove was not in the ArbreB" << std::endl;
        return *this;
    }
    else
    {
        // TODO

        return *this;
    }
}

ArbreB ArbreB::operator+=(const ArbreB& other)
{
    if (other.m_Root == nullptr)
    {
        return *this;
    }
    else
    {
        // TODO
        return *this;
    }
}
