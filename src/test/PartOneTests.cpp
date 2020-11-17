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

bool PartOneTests::should_update_freq_if_char_already_in_ArbreB() {
    bool ret = true;
    ArbreB a('m', 13.);
    a.insert('m', 13.);

    if (a.m_Root->get_m_Data() != 'm' ||
        a.m_Root->get_m_Freq() != 26.)
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

    a.remove('g');

    if (a.m_Root->m_Left->m_Right != nullptr) {
        ret = false;
        tests_failed++;
    }

    tests_run++;
    return ret;
}

bool PartOneTests::should_remove_Sommet_with_one_child() {
    bool ret = true;
    ArbreB a('m', 13.);
    a.insert('c', 3.);
    a.insert('r', 18.);
    a.insert('g', 7.);
    a.insert('y', 25.);
    a.insert('u', 21.);

    a.remove('y');

    if (a.m_Root->m_Right->m_Right->m_Left != nullptr ||
        a.m_Root->m_Right->m_Right->get_m_Data() != 'u' ||
        a.m_Root->m_Right->m_Right->get_m_Freq() != 21.)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_remove_Sommet_with_two_children() {
    bool ret = true;
    ArbreB a('m', 13.);
    a.insert('g', 7.);
    a.insert('u', 21.);
    a.insert('c', 3.);
    a.insert('k', 11.);
    a.insert('r', 18.);
    a.insert('y', 25.);

    a.remove('m');

    if (a.m_Root->get_m_Data() != 'r' ||
        a.m_Root->get_m_Freq() != 18. ||
        a.m_Root->m_Right->m_Left != nullptr)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_fuse_two_ArbreB() {
    bool ret = true;
    ArbreB a1('g', 7.);
    ArbreB a2('t', 20.);
    ArbreB a3 = a1 + a2;

    if (a3.m_Root->get_m_Data() != '\0' ||
        a3.m_Root->get_m_Freq() != 27. ||
        a3.m_Root->m_Left->get_m_Data() != 'g' ||
        a3.m_Root->m_Left->get_m_Freq() != 7. ||
        a3.m_Root->m_Right->get_m_Data() != 't' ||
        a3.m_Root->m_Right->get_m_Freq() != 20.)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_decompose_one_ArbreB_into_two() {
    bool ret = true;
    ArbreB a1('m', 13.);
    a1.insert('g', 7.);
    a1.insert('u', 21.);
    a1.insert('c', 3.);
    a1.insert('k', 11.);
    a1.insert('r', 18.);
    a1.insert('y', 25.);

    ArbreB a2, a3;
    std::tie(a2, a3) = a1.decompose();

    if (a2.m_Root->get_m_Data() != 'g' ||
        a2.m_Root->get_m_Freq() != 7. ||
        a3.m_Root->get_m_Data() != 'u' ||
        a3.m_Root->get_m_Freq() != 21.)
    { ret = false; tests_failed++; }

    tests_run++;
    return ret;
}

bool PartOneTests::should_find_character_y_with_bfs() {
    bool ret = true;
    ArbreB a('m', 13.);
    a.insert('c', 3.);
    a.insert('r', 18.);
    a.insert('g', 7.);
    a.insert('y', 25.);

    if (a.search('y') != true) {
        ret = false;
        tests_failed++;
    }

    tests_run++;
    return ret;
}

bool PartOneTests::should_not_find_character_s_with_bfs() {
    bool ret = true;
    ArbreB a('m', 13.);
    a.insert('c', 3.);
    a.insert('r', 18.);
    a.insert('g', 7.);
    a.insert('y', 25.);

    if (a.search('l') != false) {
        ret = false;
        tests_failed++;
    }


    tests_run++;
    return ret;
}
