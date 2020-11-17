#include <iostream>
#include "../test/PartOneTests.hpp"

int main() {
    PartOneTests test;

    std::cout << "\n\t\e[1;34mRunning tests for class Sommet...\e[0m" << std::endl;

    std::cout << "Test for default constructor:\t\t";
    if (test.should_create_default_Sommet() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "Test for parameterized constructor:\t";
    if (test.should_create_parameterized_Sommet() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "Test for copy constructor:\t\t";
    if (test.should_create_copy_Sommet() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "Test for setting values:\t\t";
    if (test.should_set_Sommet_values() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "Test for overload of '=' operator:\t";
    if (test.should_assign_Sommet() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "Test that copies are not linked:\t";
    if (test.should_not_link_Sommet_copies() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "\n\t\e[1;34mRunning tests for class ArbreB...\e[0m" << std::endl;

    std::cout << "Test for default constructor:\t\t";
    if (test.should_create_default_ArbreB() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "Test for parameterized constructor:\t";
    if (test.should_create_parameterized_ArbreB() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "Test for constructor from Sommet:\t";
    if (test.should_create_ArbreB_from_Sommet() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "Test for copy constructor:\t\t";
    if (test.should_create_copy_ArbreB() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }
    std::cout << "Test for overload of '=' operator:\t";
    if (test.should_assign_ArbreB() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "Test that copies are not linked:\t";
    if (test.should_not_link_ArbreB_copies() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "Test for inserting Sommets:\t\t";
    if (test.should_insert_Sommet_into_ArbreB() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "Test for finding a character:\t\t";
    if (test.should_find_character_c() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "Test for not finding a character:\t";
    if (test.should_not_find_character_z() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    std::cout << "Test for removing a Sommet:\t\t";
    if (test.should_remove_leaf() == true) {
        std::cout << "\e[1;32mPASSED!\e[0m" << std::endl;
    } else {
        std::cout << "\e[1;31mFAILED!\e[0m" << std::endl;
    }

    int skipped_tests = test.total_tests - test.tests_run;
    std::cout << "\n\e[1mTests run: \e[32m" << test.tests_run
              << "\e[0m\e[1m,  Tests failed: \e[31m" << test.tests_failed
              << "\e[0m\e[1m,  Tests skipped: \e[34m" << skipped_tests
              << "\n\e]0m" << std::endl;

    return 0;
}
