#include "ArbreB.hpp"

// Private:
void ArbreB::preorder_traversal(Sommet*& current) {
    if (current == nullptr) {
        return;
    }

    std::cout << "(" << current->m_Data << ", " << current->m_Freq << ") ";
    preorder_traversal(current->m_Left);
    preorder_traversal(current->m_Right);
}

void ArbreB::inorder_traversal(Sommet*& current) {
    if (current == nullptr) {
        return;
    }

    inorder_traversal(current->m_Left);
    std::cout << "(" << current->m_Data << ", " << current->m_Freq << ") ";
    inorder_traversal(current->m_Right);
}

void ArbreB::postorder_traversal(Sommet*& current) {
    if (current == nullptr) {
        return;
    }

    postorder_traversal(current->m_Left);
    postorder_traversal(current->m_Right);
    std::cout << "(" << current->m_Data << ", " << current->m_Freq << ") ";
}

void ArbreB::insert(Sommet*& current_node, Sommet& new_node) {
    // Base case
    if (current_node == nullptr) {
        current_node = new Sommet(new_node);
    }
    // If the Sommet to insert is already in the ArbreB
    else if (current_node->m_Data == new_node.m_Data) {
        /* std::cout << "Warning: a Sommet of the same value is already in the ArbreB\n"
           << "Updating already present Sommet's frequency" << std::endl; */
        current_node->set_freq(current_node->m_Freq + new_node.m_Freq);
        return;
    }
    // If current Sommet > Sommet to insert, insert left
    else if (current_node->m_Data > new_node.m_Data) {
        insert(current_node->m_Left, new_node);
    }
    // If current Sommet < Sommet to insert, insert right
    else {
        insert(current_node->m_Right, new_node);
    }
}

bool ArbreB::search(Sommet*& current, const char& data) {
    // Reached end of branch, character was not found
    if (current == nullptr) {
        return false;
    }
    // Character found
    else if (current->m_Data == data) {
        return true;
    }
    // Call recursively on both children of the current Sommet
    else {
        return search(current->m_Left, data) || search(current->m_Right, data);
    }
}

bool ArbreB::bst_search(Sommet*& current, const char& data, std::string& path) {
    // Reached end of branch, character was not found
    if (current == nullptr) {
        /* std::cout << "Character '" << data << "' was not found" << std::endl; */
        return false;
    }
    // Character found
    else if (current->m_Data == data) {
        /* std::cout << "Character '" << data << "' was found, "
           << "its binary code is: " << path << std::endl; */
        return true;
    }
    // If current > data, search left, update string
    else if (current->m_Data > data) {
        path.resize(path.size() + 1);
        path += "0";
        return bst_search(current->m_Left, data, path);
    }
    // If current < data, search right, update string
    else {
        path.resize(path.size() + 1);
        path += "1";
        return bst_search(current->m_Right, data, path);
    }
}

ArbreB& ArbreB::remove(Sommet*& current, const char& data) {
    // If current > data, remove left
    if (current->m_Data > data) {
        return remove(current->m_Left, data);
    }
    // If current < data, remove right
    else if (current->m_Data < data) {
        return remove(current->m_Right, data);
    }
    // If current == data
    else {
        // If current node has no child, delete it
        if (current->m_Left == nullptr && current->m_Right == nullptr) {
            delete current;
            current = nullptr;
        }
        // If current node has only a right child, set current from right, delete right
        else if (current->m_Left == nullptr) {
            current->set_data(current->m_Right->m_Data);
            current->set_freq(current->m_Right->m_Freq);
            return remove(current->m_Right, current->m_Right->m_Data);
        }
        // If current node has only a left child, set current from left, delete left
        else if (current->m_Right == nullptr) {
            current->set_data(current->m_Left->m_Data);
            current->set_freq(current->m_Left->m_Freq);
            return remove(current->m_Left, current->m_Left->m_Data);
        }
        // If current node has two children
        else {
            // Find the inorder successor of current
            Sommet tmp(*current->m_Right);
            // First check if tmp has a left child (memory safety precaution)
            if (tmp.m_Left == nullptr) {
                // Set current from tmp, delete on tmp
                current->set_data(tmp.m_Data);
                current->set_freq(tmp.m_Freq);
                return remove(current->m_Right, tmp.m_Data);
            }
            // If tmp has left child
            else {
                // Traverse tree to inorder successor
                while(tmp.m_Left->m_Left != nullptr) {
                    tmp = *tmp.m_Left;
                }
                // Set current from tmp, delete on tmp
                current->set_data(tmp.m_Left->m_Data);
                current->set_freq(tmp.m_Left->m_Freq);
                return remove(current->m_Right, tmp.m_Left->m_Data);
            }
        }

        return *this;
    }
}

void ArbreB::map_char_to_code(Sommet*& current, std::map<char, std::string>& char_code, std::string& path) {
    if (current->m_Left == nullptr && current->m_Right == nullptr) {
        char_code.emplace(current->m_Data, path);
        return;
    }

    if (current->m_Left != nullptr) {
        path.push_back('0');
        map_char_to_code(current->m_Left, char_code, path);
        path.pop_back();
    }

    if (current->m_Right != nullptr) {
        path.push_back('1');
        map_char_to_code(current->m_Right, char_code, path);
        path.pop_back();
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
        *m_Root = *other.m_Root; // Using overload of operator= for class Sommet
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
    // Create Sommet from arguments and use private insert() method
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
    // If ArbreB is empty
    if (m_Root == nullptr) {
        /* std::cout << "Warning: ArbreB is empty" << std::endl
            << "Aborting remove()..." << std::endl; */
        return *this;
    }
    // If character to remove is not in the tree
    else if (!search(m_Root, data)) {
        /* std::cout << "Warning: the character to remove was not in the ArbreB" << std::endl
            << "Aborting remove()..." << std::endl; */
        return *this;
    }
    else {
        return remove(m_Root, data);
    }
}

ArbreB ArbreB::operator+(const ArbreB& other) {
    // Bases cases
    if (m_Root == nullptr) {
        return other;
    }
    else if (other.m_Root == nullptr) {
        return *this;
    }
    // ArbreB has two children
    else {
        // Initialize new fields for new tree
        char new_char = '\0';
        double new_freq = m_Root->m_Freq + other.m_Root->m_Freq;

        // Create tree with these fields
        ArbreB new_tree(new_char, new_freq);

        // Link child branches
        new_tree.m_Root->m_Left = new Sommet(*m_Root);
        new_tree.m_Root->m_Right = new Sommet(*other.m_Root);

        return new_tree;
    }
}

std::tuple<ArbreB, ArbreB> ArbreB::decompose() {
    // Create new ArbreBs from left and right children
    ArbreB new_left(*m_Root->m_Left);
    ArbreB new_right(*m_Root->m_Right);

    // Return an std::tuple
    return std::make_tuple(new_left, new_right);
}

Sommet* ArbreB::get_root() {
    return m_Root;
}

void ArbreB::print() {
    m_Root->print(0);
}

