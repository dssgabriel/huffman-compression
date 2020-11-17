#ifndef PARTONETESTS_HPP
#define PARTONETESTS_HPP

#include <iostream>
#include "../lib/ArbreB.hpp"

class Sommet;

class PartOneTests {
friend class Sommet;
friend class ArbreB;

public:
    unsigned int tests_run;
    unsigned int tests_failed;
    static unsigned int total_tests;

    PartOneTests();

    bool should_create_default_Sommet();
    bool should_create_parameterized_Sommet();
    bool should_create_copy_Sommet();
    bool should_set_Sommet_values();
    bool should_assign_Sommet();
    bool should_not_link_Sommet_copies();

    bool should_create_default_ArbreB();
    bool should_create_parameterized_ArbreB();
    bool should_create_ArbreB_from_Sommet();
    bool should_create_copy_ArbreB();
    bool should_assign_ArbreB();
    bool should_not_link_ArbreB_copies();
    bool should_insert_Sommet_into_ArbreB();
    bool should_find_character_c();
    bool should_not_find_character_z();
    bool should_remove_leaf();
    bool should_remove_Sommet_with_one_child();
    bool should_remove_Sommet_with_two_children();
    bool should_fuse_two_ArbreB();
    bool should_decompose_one_ArbreB_into_two();

    bool should_find_character_with_bfs();
    bool should_not_find_character_with_bfs();
    bool should_print_to_stdout();
};

#endif
