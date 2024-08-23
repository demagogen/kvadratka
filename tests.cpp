#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "utils.h"
#include "solve_square_equation.h"
#include "tests.h"
#include "color_scheme_changing.h"

const char* number_of_solutions_enum(NUMBER_OF_SOLUTIONS num_of_sol){
    switch(num_of_sol) {
        case ERROR_NUMBER:
            return "ERROR_NUMBER";
            break;
        case NO_SOLUTIONS:
            return "NO_SOLUTIONS";
            break;
        case ONE_SOLUTION:
            return "ONE_SOLUTION";
            break;
        case TWO_SOLUTIONS:
            return "TWO_SOLUTIONS";
            break;
        case INF_NUMBER_OF_SOLUTIONS:
            return "INF_NUMBER_OF_SOLUTIONS";
            break;
        default:
            return "ERROR_VALUE";
            break;
    }
}

static const TEST_DATA test_data_array[] {
    {
        .number_of_test = 1,
        .a = 0,
        .b = 0,
        .c = 0,
        .x1_ex = NAN,
        .x2_ex = NAN,
        .num_of_sol_ex = INF_NUMBER_OF_SOLUTIONS,
    },
    {
        .number_of_test = 2,
        .a = 0,
        .b = 0,
        .c = 1,
        .x1_ex = NAN, //TODO ISNAN and ISFINITE correct checker
        .x2_ex = NAN,
        .num_of_sol_ex = NO_SOLUTIONS,
    },
    {
        .number_of_test = 3,
        .a = 0,
        .b = 1,
        .c = 1,
        .x1_ex = -1.0,
        .x2_ex = NAN,
        .num_of_sol_ex = ONE_SOLUTION,
    },
    {
        .number_of_test = 4,
        .a = 0,
        .b = 1,
        .c = 0,
        .x1_ex = 0.0,
        .x2_ex = NAN,
        .num_of_sol_ex = ONE_SOLUTION,
    },
    {
        .number_of_test = 5,
        .a = 1,
        .b = 0,
        .c = 0,
        .x1_ex = 0.0,
        .x2_ex = NAN,
        .num_of_sol_ex = ONE_SOLUTION,
    },
    {
        .number_of_test = 6,
        .a = 1,
        .b = 2,
        .c = 1,
        .x1_ex = -1.0,
        .x2_ex = NAN,
        .num_of_sol_ex = ONE_SOLUTION,
    },
    {
        .number_of_test = 7,
        .a = 1,
        .b = 1,
        .c = -6,
        .x1_ex = 2.0,
        .x2_ex = -3.0,
        .num_of_sol_ex = TWO_SOLUTIONS,
    },
    {
        .number_of_test = 8,
        .a = 0.1,
        .b = 0.1,
        .c = 0.6,
        .x1_ex = 2.0,
        .x2_ex = -3.0,
        .num_of_sol_ex = TWO_SOLUTIONS,
    },
    {
        .number_of_test = 9,
        .a = 0.5,
        .b = -1,
        .c = 0.5,
        .x1_ex = 1.0,
        .x2_ex = NAN,
        .num_of_sol_ex = ONE_SOLUTION,
    }

};

static const int quantity_of_tests = sizeof(test_data_array) / sizeof(test_data_array[0]);

bool check_test_result(const TEST_DATA *test_data, SE_SOLUTIONS *solutions_test) {
    assert(solutions_test);

    solve_square_equation(test_data->a, test_data->b, test_data->c, solutions_test);

    if (comparing_function(solutions_test->x1, test_data->x1_ex) == EQUAL &&
        comparing_function(solutions_test->x2, test_data->x2_ex) == EQUAL &&
        comparing_function(isnan(solutions_test->x1), isnan(test_data->x1_ex)) == EQUAL &&
        comparing_function(isnan(solutions_test->x2), isnan(test_data->x2_ex)) == EQUAL &&
        comparing_function(solutions_test->num_of_sol, test_data->num_of_sol_ex) == EQUAL) {
        return true;
    }
    else {
        return false;
    }
}

void print_test_result(bool check_test_result, const TEST_DATA *test_data, SE_SOLUTIONS *solutions_test) {
    assert(test_data);
    assert(solutions_test);

    graphic_printf("Старт теста %d\n", BLACK, BOLD,test_data->number_of_test);
    if (check_test_result) {
        graphic_printf("тест %d пройден\n", GREEN, BOLD, test_data->number_of_test);
    }
    else {
        graphic_printf("Ошибка в тесте %d\na = %lf, b = %lf, c = %lf, num_of_sol = %s, x1 = %lf, x2 = %lf\n"
                       "num_of_sol = %s, x1 = %lf, x2 = %lf\n", RED, BOLD, test_data->number_of_test,
                       test_data->a, test_data->b, test_data->c, number_of_solutions_enum(test_data->num_of_sol_ex), test_data->x1_ex,
                       test_data->x2_ex, number_of_solutions_enum(solutions_test->num_of_sol), solutions_test->x1, solutions_test->x2);
    }
}

void test_functions_runner() {
    SE_SOLUTIONS solutions_test{
        NAN, NAN,
        ERROR_NUMBER
    };

    for (int test_index = 0; test_index < quantity_of_tests; test_index++) { // TODO print message when test is starting
        print_test_result(check_test_result(&test_data_array[test_index], &solutions_test),
                          &test_data_array[test_index],
                          &solutions_test); // TODO make mini library to print color output
    }
}
