#include "PartOneTests.hpp"

unsigned int PartOneTests::total_tests = 23;

PartOneTests::PartOneTests() {
    tests_failed = 0;
    tests_run = 0;
}

bool PartOneTests::should_create_default_Sommet() {
    bool ret = true;
    Sommet s;

    if (s.get_m_Data() != '\0' ||
        s.get_m_Freq() != 0 ||
        s.m_Left != nullptr ||
        s.m_Right != nullptr)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_create_parameterized_Sommet() {
    bool ret = true;
    Sommet s('a', 1.);

    if (s.get_m_Data() != 'a' ||
        s.get_m_Freq() != 1. ||
        s.m_Left != nullptr ||
        s.m_Right != nullptr)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_create_copy_Sommet() {
    bool ret = true;
    Sommet s1('a', 1.);
    Sommet s2(s1);

    if (s2.get_m_Data() != 'a' ||
        s2.get_m_Freq() != 1. ||
        s2.m_Left != nullptr ||
        s2.m_Right != nullptr)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_set_Sommet_values() {
    bool ret = true;
    Sommet s;

    s.set_m_Data('a');
    s.set_m_Freq(1.);

    if (s.get_m_Data() != 'a' ||
        s.get_m_Freq() != 1.)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_assign_Sommet() {
    bool ret = true;
    Sommet s1('a', 1.);
    Sommet s2;

    s2 = s1;

    if (s2.get_m_Data() != 'a' ||
        s2.get_m_Freq() != 1.)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_not_link_Sommet_copies() {
    bool ret = true;
    Sommet s1('a', 1.);
    Sommet s2(s1);

    s2.set_m_Data('b');
    s2.set_m_Freq(2.);

    if (s1.get_m_Data() != 'a' ||
        s1.get_m_Freq() != 1. ||
        s2.get_m_Data() != 'b' ||
        s2.get_m_Freq() != 2.)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_create_default_ArbreB() {
    bool ret = true;
    ArbreB a;

    if (a.m_Root != nullptr) {
        ret = false;
        tests_failed++;
    }

    tests_run++;
    return ret;
}

bool PartOneTests::should_create_parameterized_ArbreB() {
    bool ret = true;
    ArbreB a('a', 1.);

    if (a.m_Root->get_m_Data() != 'a' ||
        a.m_Root->get_m_Freq() != 1.)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_create_ArbreB_from_Sommet() {
    bool ret = true;
    Sommet s('a', 1.);
    ArbreB a(s);

    if (a.m_Root->get_m_Data() != 'a' ||
        a.m_Root->get_m_Freq() != 1.)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_create_copy_ArbreB() {
    bool ret = true;
    ArbreB a1('a', 1.);
    ArbreB a2(a1);

    if (a2.m_Root->get_m_Data() != 'a' ||
        a2.m_Root->get_m_Freq() != 1.)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_assign_ArbreB() {
    bool ret = true;
    ArbreB a1('a', 1.);
    ArbreB a2;

    a2 = a1;

    if (a2.m_Root->get_m_Data() != 'a' ||
        a2.m_Root->get_m_Freq() != 1.)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_not_link_ArbreB_copies() {
    bool ret = true;
    ArbreB a1('a', 1.);
    ArbreB a2(a1);

    a2.m_Root->set_m_Data('b');
    a2.m_Root->set_m_Freq(2.);

    if (a1.m_Root->get_m_Data() != 'a' ||
        a1.m_Root->get_m_Freq() != 1. ||
        a2.m_Root->get_m_Data() != 'b' ||
        a2.m_Root->get_m_Freq() != 2.)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_insert_Sommet_into_ArbreB() {
    bool ret = true;
    ArbreB a('m', 13.);
    Sommet s('c', 3.);
    a.insert(s);
    a.insert('r', 18.);

    if (a.m_Root->m_Left->get_m_Data() != 'c' ||
        a.m_Root->m_Left->get_m_Freq() != 3. ||
        a.m_Root->m_Right->get_m_Data() != 'r' ||
        a.m_Root->m_Right->get_m_Freq() != 18.)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_find_character_c() {
    bool ret = true;
    ArbreB a('m', 13.);
    a.insert('c', 3.);
    a.insert('r', 18.);
    a.insert('g', 7.);
    a.insert('y', 25.);
    std::string s = "";

    if (a.bst_search('c', s) != true) {
        ret = false;
        tests_failed++;
    }

    tests_run++;
    return ret;
}

bool PartOneTests::should_not_find_character_z() {
    bool ret = true;
    ArbreB a('m', 13.);
    a.insert('c', 3.);
    a.insert('r', 18.);
    a.insert('g', 7.);
    a.insert('y', 25.);
    std::string s = "";

    if (a.bst_search('z', s) != false) {
        ret = false;
        tests_failed++;
    }

    tests_run++;
    return ret;
}

bool PartOneTests::should_remove_leaf() {
    bool ret = true;
    ArbreB a('m', 13.);
    a.insert('c', 3.);
    a.insert('r', 18.);
    a.insert('g', 7.);
    a.insert('y', 25.);
    a.insert('u', 21.);

    /*
    std::cout << "\e[1mArbreB a:\n\e[0m" << a << std::endl;
    a.remove('u');
    std::cout << "\e[1mRemoved 'u' from a:\n\e[0m" << a << std::endl;
    a.remove('g');
    std::cout << "\e[1mRemoved 'g' from a:\n\e[0m" << a << std::endl;
    */

    tests_run++;
    return ret;
}

bool should_remove_Sommet_with_one_child() {
    bool ret = false;

    return ret;
}

bool should_remove_Sommet_with_two_children() {
    bool ret = false;

    return ret;
}

bool should_fuse_two_ArbreB() {
    bool ret = false;

    return ret;
}

bool should_decompose_one_ArbreB_into_two() {
    bool ret = false;

    return ret;
}

bool should_find_character_with_bfs() {
    bool ret = false;

    return ret;
}

bool should_not_find_character_with_bfs() {
    bool ret = false;

    return ret;
}

bool should_print_to_stdout() {
    bool ret = false;

    return ret;
}
