#include "ArbreB.hpp"

// Private:
void ArbreB::preorder_traversal(Sommet*& current)
{
    if (current == nullptr)
    {
        return;
    }
    std::cout << "(" << current->get_m_Data() << ", " << current->get_m_Freq() << ") ";
    inorder_traversal(current->m_Left);
    inorder_traversal(current->m_Right);
}

void ArbreB::inorder_traversal(Sommet*& current)
{
    if (current == nullptr)
    {
        return;
    }
    inorder_traversal(current->m_Left);
    std::cout << "(" << current->get_m_Data() << ", " << current->get_m_Freq() << ") ";
    inorder_traversal(current->m_Right);
}

void ArbreB::postorder_traversal(Sommet*& current)
{
    if (current == nullptr)
    {
        return;
    }
    inorder_traversal(current->m_Left);
    inorder_traversal(current->m_Right);
    std::cout << "(" << current->get_m_Data() << ", " << current->get_m_Freq() << ") ";
}

void ArbreB::insert(Sommet*& current_node, Sommet& new_node)
{
    if (current_node == nullptr)
    {
        current_node = new Sommet(new_node);
    }
    else if (current_node->get_m_Data() == new_node.get_m_Data())
    {
        std::cout << "Warning: a Sommet of the same value is already in the ArbreB\n"
            << "Updating already present Sommet's frequency" << std::endl;
        current_node->set_m_Freq(current_node->get_m_Freq() + new_node.get_m_Freq());
        return;
    }
    else if (current_node->get_m_Data() > new_node.get_m_Data())
    {
        insert(current_node->m_Left, new_node);
    }
    else if (current_node->get_m_Data() < new_node.get_m_Data())
    {
        insert(current_node->m_Right, new_node);
    }
    else
    {
        std::cout << "Error: undefined behavior" << std::endl;
        return;
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
    else if (current->get_m_Data() < data)
    {
        path.resize(path.size() + 1);
        path += "1";
        return bst_search(current->m_Right, data, path);
    }
    else
    {
        std::cout << "Error: undefined behavior" << std::endl;
        return false;
    }
}

ArbreB& ArbreB::remove(Sommet*& current, const char& data)
{
    if (current->get_m_Data() > data)
    {
        return remove(current->m_Left, data);
    }
    if (current->get_m_Data() < data)
    {
        return remove(current->m_Right, data);
    }
    return *this;
}

// Public:
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

std::ostream& operator<<(std::ostream& stream, ArbreB& tree)
{
    std::cout << "Pre-order traversal: ";
    tree.preorder_traversal(tree.m_Root);
    std::cout << std::endl << "In-order traversal: ";
    tree.inorder_traversal(tree.m_Root);
    std::cout << std::endl << "Post-order traversal: ";
    tree.postorder_traversal(tree.m_Root);
    std::cout << std::endl;
    return stream;
}

void ArbreB::insert(Sommet& new_node)
{
    insert(this->m_Root, new_node);
}

bool ArbreB::search(const char& data)
{
    return search(this->m_Root, data);
}

bool ArbreB::bst_search(const char& data, std::string& path)
{
    return bst_search(this->m_Root, data, path);
}

ArbreB& ArbreB::remove(const char& data)
{
    if (m_Root == nullptr)
    {
        std::cout << "Error: ArbreB is empty" << std::endl;
        return *this;
    }
    else if (search(m_Root, data))
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

ArbreB ArbreB::operator+(const ArbreB& other)
{
    if (m_Root == nullptr)
    {
        return other;
    }
    if (other.m_Root == nullptr)
    {
        return *this;
    }
    // Initialize new fields for new tree
    char new_char = '\0';
    double new_freq = m_Root->get_m_Freq() + other.m_Root->get_m_Freq();
    // Create tree with these fields
    ArbreB new_tree(new_char, new_freq);
    // Link child branches
    new_tree.m_Root->m_Left = new Sommet(*m_Root);
    new_tree.m_Root->m_Right = new Sommet(*other.m_Root);

    return new_tree;
}
