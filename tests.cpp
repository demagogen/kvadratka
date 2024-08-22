#include <math.h>
#include <stdio.h>

#include "utils.h"
#include "solve_square_equation.h"
#include "tests.h"

static const TEST_DATA test_data_array[] {
    {
        .number_of_test = 1, // TODO do this for all (optional)
        0, 0, 0, NAN, NAN,
        INF_NUMBER_OF_SOLUTIONS,
    },
    {
        2,
        0, 0, 1, NAN, NAN,
        NO_SOLUTIONS,
    },
    {
        3,
        0, 1, 1, -1.0, NAN,
        ONE_SOLUTION,
    },
    {
        4,
        0, 1, 0, 0.0, NAN,
        ONE_SOLUTION,
    },
    {
        5,
        1, 0, 0, 0.0, NAN,
        ONE_SOLUTION,
    }
};

static const int quantity_of_tests = sizeof(test_data_array) / sizeof(test_data_array[0]);

bool check_test_result(const TEST_DATA *test_data, SE_SOLUTIONS *solutions_test) {
    solve_square_equation(test_data->a, test_data->b, test_data->c, solutions_test);

    if (comparing_function(solutions_test->x1, test_data->x1_ex) == EQUAL &&
        comparing_function(solutions_test->x2, test_data->x2_ex) == EQUAL &&
        comparing_function(solutions_test->num_of_sol, test_data->num_of_sol_ex) == EQUAL) {
        return true;
    }
    else {
        return false;
    }
}

void print_test_result(bool check_test_result, const TEST_DATA *test_data, SE_SOLUTIONS *solutions_test) {
    if (check_test_result) {
        printf("%d тест пройден\n", test_data->number_of_test);
    }
    else {
        printf("Ошибка в тесте %d\na = %lf, b = %lf, c = %lf, num_of_sol = %d, x1 = %lf, x2 = %lf\n num_of_sol = "
        "%d, x1 = %lf, x2 = %lf\n", solutions_test->num_of_sol, test_data->a, test_data->b, test_data->c,
        test_data->num_of_sol_ex, test_data->x1_ex, test_data->x2_ex, solutions_test->num_of_sol,
        solutions_test->x1, solutions_test->x2);
    }
}

void test_functions_runner() {
    SE_SOLUTIONS solutions_test{
        NAN, NAN,
        ERROR_NUMBER
    };

    for (int test_index = 0; test_index < quantity_of_tests; test_index++) {
        print_test_result(check_test_result(&test_data_array[test_index], &solutions_test),
                          &test_data_array[test_index],
                          &solutions_test);
    }
}
