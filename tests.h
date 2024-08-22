#ifndef TESTS_H_
#define TESTS_H_

#include "utils.h"
#include "solve_square_equation.h"

const int quantity_of_tests = 1;

struct TEST_DATA {
    int number_of_test;
    double a, b, c, x1_ex, x2_ex;
    NUMBER_OF_SOLUTIONS num_of_sol_ex;
};

bool check_test_result(TEST_DATA *test_data);
void print_test_result(bool check_test_result, TEST_DATA *test_data, SE_SOLUTIONS *solutions_test);
void test_functions_runner(const int quantity_of_tests, TEST_DATA *test_data_array);
#endif
