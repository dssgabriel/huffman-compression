#ifndef PART_ONE_HPP
#define PART_ONE_HPP

#pragma once
#include "../headers/ArbreB.hpp"

/**
 * The class `Part1` implements tests to assert that the functions in classes `Sommet` and `ArbreB` have the expected behavior.
 * @author Gabriel Dos Santos
 * @version 0.1.0
 * @date 2020/11/17
 */
class Part1 {
    friend class Sommet;
    friend class ArbreB;

    public:
        /**
         * Represents the number of tests ran.
         */
        unsigned int tests_run;
        /**
         * Represents the number of tests failed.
         */
        unsigned int tests_failed;
        /**
         * Represents the total number of tests.
         */
        static unsigned int total_tests;

        /**
         * Creates an object `Part1`.
         */
        Part1();

        /**
         * Asserts that the default constructor of `Sommet` initializes the object correctly.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_create_default_Sommet();

        /**
         * Asserts that the parameterized constructor of `Sommet` initializes the object correctly.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_create_parameterized_Sommet();

        /**
         * Asserts that the copy constructor of `Sommet` initializes the object correctly.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_create_copy_Sommet();

        /**
         * Asserts that the setters for `Sommet` set the values correctly.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_set_Sommet_values();

        /**
         * Asserts that the overload of `operator=` for `Sommet` assign the object correctly.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_assign_Sommet();

        /**
         * Asserts that the copy of an object `Sommet` is not linked with the original.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_not_link_Sommet_copies();

        /**
         * Asserts that the default constructor of `ArbreB` initializes the object correctly.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_create_default_ArbreB();

        /**
         * Asserts that the parameterized constructor of `ArbreB` initializes the object correctly.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_create_parameterized_ArbreB();

        /**
         * Asserts that the constructor of `ArbreB` from a `Sommet` initializes the object correctly.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_create_ArbreB_from_Sommet();

        /**
         * Asserts that the copy constructor of `ArbreB` initializes the object correctly.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_create_copy_ArbreB();

        /**
         * Asserts that the overload of `operator=` for `ArbreB` assign the object correctly.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_assign_ArbreB();

        /**
         * Asserts that the copy of an object `ArbreB` is not linked with the original.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_not_link_ArbreB_copies();

        /**
         * Asserts that a `Sommet` is correctly inserted into an `ArbreB`.
         * This method tests for both `insert(const Sommet&)` and `insert(const char&, const double&)`.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_insert_Sommet_into_ArbreB();

        /**
         * Asserts that inserting a `Sommet` that already is in the `ArbreB` updates the `m_Freq` field of that `Sommet` accordingly.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_update_freq_if_char_already_in_ArbreB();

        /**
         * Asserts that the character `c` is found in an `ArbreB` that contains it.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_find_character_c();

        /**
         * Asserts that the character `z` is not found in an `ArbreB` that does not contain it.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_not_find_character_z();

        /**
         * Asserts that removing a `Sommet` that is a leaf deletes it correctly.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_remove_leaf();

        /**
         * Asserts that removing a `Sommet` that has only one child (left or right) deletes it correctly and replaces it with its child.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_remove_Sommet_with_one_child();

        /**
         * Asserts that removing a `Sommet` that has two children deletes it correctly and replaces it with its inorder succesor.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_remove_Sommet_with_two_children();

        /**
         * Asserts that the overload of `operator+` for `ArbreB` fuses two `ArbreB`s into one and has the expected values at its root.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_fuse_two_ArbreB();

        /**
         * Asserts that decomposing an `ArbreB` returns a tuple holding two `ArbreB`s with the expected values.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_decompose_one_ArbreB_into_two();

        /**
         * Asserts that using the method `search()` (BFS algorithm), the character `c` is found in an `ArbreB` that contains it.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_find_character_y_with_bfs();

        /**
         * Asserts that using the method `search()` (BFS algorithm), the character `s` is not found in an `ArbreB` that does not contain it.
         * @return `True` if the test passed, `false` if it failed.`
         */
        bool should_not_find_character_s_with_bfs();
};

#endif
