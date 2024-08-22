// kvadratka.cpp -- программа для решения квадратных уравнений
#include <math.h>

#include "utils.h"
#include "solve_square_equation.h"
#include "enter_print.h"
#include "tests.h"

int main() {
    double a = NAN, b = NAN, c = NAN; // коэффициенты кв.
    SE_SOLUTIONS solutions {
        NAN, NAN,
        ERROR_NUMBER
    };

    TEST_DATA test_data_array[1] {
    1,
    0, 0, 0, NAN, NAN,
    INF_NUMBER_OF_SOLUTIONS,
};

    enter_se_parameters(&a, &b, &c);
    solve_square_equation(a, b, c, &solutions);
    test_functions_runner(quantity_of_tests, test_data_array);
    print_solutions(&solutions);

    return 0;
}
