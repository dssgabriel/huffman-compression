#include "ArbreB.hpp"

// Private:
void ArbreB::preorder_traversal(Sommet*& current) {
    if (current == nullptr) {
        return;
    }

    std::cout << "(" << current->get_m_Data() << ", " << current->get_m_Freq() << ") ";
    preorder_traversal(current->m_Left);
    preorder_traversal(current->m_Right);
}

void ArbreB::inorder_traversal(Sommet*& current) {
    if (current == nullptr) {
        return;
    }

    inorder_traversal(current->m_Left);
    std::cout << "(" << current->get_m_Data() << ", " << current->get_m_Freq() << ") ";
    inorder_traversal(current->m_Right);
}

void ArbreB::postorder_traversal(Sommet*& current) {
    if (current == nullptr) {
        return;
    }

    postorder_traversal(current->m_Left);
    postorder_traversal(current->m_Right);
    std::cout << "(" << current->get_m_Data() << ", " << current->get_m_Freq() << ") ";
}

void ArbreB::insert(Sommet*& current_node, Sommet& new_node) {
    if (current_node == nullptr) {
        current_node = new Sommet(new_node);
    }
    else if (current_node->get_m_Data() == new_node.get_m_Data()) {
        // std::cout << "Warning: a Sommet of the same value is already in the ArbreB\n"
        //           << "Updating already present Sommet's frequency" << std::endl;

        current_node->set_m_Freq(current_node->get_m_Freq() + new_node.get_m_Freq());
        return;
    }
    else if (current_node->get_m_Data() > new_node.get_m_Data()) {
        insert(current_node->m_Left, new_node);
    }
    else {
        insert(current_node->m_Right, new_node);
    }
}

bool ArbreB::search(Sommet*& current, const char& data) {
    if (current == nullptr) {
        return false;
    }
    else if (current->get_m_Data() == data) {
        return true;
    }
    else {
        return search(current->m_Left, data) || search(current->m_Right, data);
    }
}

bool ArbreB::bst_search(Sommet*& current, const char& data, std::string& path) {
    if (current == nullptr) {
        // std::cout << "Character '" << data << "' was not found" << std::endl;
        return false;
    }
    else if (current->get_m_Data() == data) {
        // std::cout << "Character '" << data << "' was found, "
        //           << "its binary code is: " << path << std::endl;
        return true;
    }
    else if (current->get_m_Data() > data) {
        path.resize(path.size() + 1);
        path += "0";
        return bst_search(current->m_Left, data, path);
    }
    else {
        path.resize(path.size() + 1);
        path += "1";
        return bst_search(current->m_Right, data, path);
    }
}

ArbreB& ArbreB::remove(Sommet*& current, const char& data) {
    if (current->get_m_Data() > data) {
        return remove(current->m_Left, data);
    }
    else if (current->get_m_Data() < data) {
        return remove(current->m_Right, data);
    }
    else {
        if (current->m_Left == nullptr && current->m_Right == nullptr) { // If current node has no child
            delete current;
            current = nullptr;
        }
        else if (current->m_Left == nullptr) { // If current node has only a right child
            current->set_m_Data(current->m_Right->get_m_Data());
            current->set_m_Freq(current->m_Right->get_m_Freq());
            return remove(current->m_Right, current->m_Right->get_m_Data());
        }
        else if (current->m_Right == nullptr) { // If current node has only a left child
            current->set_m_Data(current->m_Left->get_m_Data());
            current->set_m_Freq(current->m_Left->get_m_Freq());
            return remove(current->m_Left, current->m_Left->get_m_Data());
        }
        else { // If current node has two children
            // Find the inorder successor of the current node
            Sommet tmp(*current->m_Right);
            if (tmp.m_Left == nullptr) {// Check if tmp has a left child (safety)
                current->set_m_Data(tmp.get_m_Data());
                current->set_m_Freq(tmp.get_m_Freq());
                return remove(current->m_Right, tmp.get_m_Data());
            }
            else {
                while(tmp.m_Left->m_Left != nullptr) {
                    tmp = *tmp.m_Left;
                }
                current->set_m_Data(tmp.m_Left->get_m_Data());
                current->set_m_Freq(tmp.m_Left->get_m_Freq());
                return remove(current->m_Right, tmp.m_Left->get_m_Data());
            }
        }
        return *this;
    }
}

// Public:
ArbreB::ArbreB()
    : m_Root(nullptr) {}

ArbreB::ArbreB(const char& data, const double& freq) {
    m_Root = new Sommet(data, freq);
}

ArbreB::ArbreB(const Sommet& node) {
    m_Root = new Sommet();
    *m_Root = node;
}

// Uses overloaded operator=
ArbreB::ArbreB(const ArbreB& other) {
    *this = other;
}

ArbreB::~ArbreB() {
    if (m_Root != nullptr) {
        delete m_Root;
    }
}

ArbreB& ArbreB::operator=(const ArbreB& other) {
    if (other.m_Root != nullptr) {
        m_Root = new Sommet();
        *m_Root = *other.m_Root;
    }
    return *this;
}

Sommet& ArbreB::get_m_Root() {
    return *m_Root;
}

std::ostream& operator<<(std::ostream& stream, ArbreB& tree) {
    std::cout << "Preorder traversal:\t";
    tree.preorder_traversal(tree.m_Root);

    std::cout << std::endl << "Inorder traversal:\t";
    tree.inorder_traversal(tree.m_Root);

    std::cout << std::endl << "Postorder traversal:\t";
    tree.postorder_traversal(tree.m_Root);

    return stream;
}

void ArbreB::insert(Sommet& new_node) {
    insert(m_Root, new_node);
}

void ArbreB::insert(const char& data, const double& freq) {
    Sommet s(data, freq);
    insert(m_Root, s);
}

bool ArbreB::search(const char& data) {
    return search(m_Root, data);
}

bool ArbreB::bst_search(const char& data, std::string& path) {
    return bst_search(m_Root, data, path);
}

ArbreB& ArbreB::remove(const char& data) {
    if (m_Root == nullptr) {
        // std::cout << "Warning: ArbreB is empty" << std::endl
        //           << "Aborting remove()..." << std::endl;
        return *this;
    }
    else if (!search(m_Root, data)) {
        // std::cout << "Warning: the character to remove was not in the ArbreB" << std::endl
        //           << "Aborting remove()..." << std::endl;
        return *this;
    }
    else {
        return remove(m_Root, data);
    }
}

ArbreB ArbreB::operator+(const ArbreB& other) {
    if (m_Root == nullptr) {
        return other;
    }
    if (other.m_Root == nullptr) {
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

std::tuple<ArbreB, ArbreB> ArbreB::decompose() {
    ArbreB new_left(*m_Root->m_Left);
    ArbreB new_right(*m_Root->m_Right);

    return std::make_tuple(new_left, new_right);
}
