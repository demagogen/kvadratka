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

    if (asking_choice() == 1) {
        enter_se_parameters(&a, &b, &c);
        solve_square_equation(a, b, c, &solutions);
        print_solutions(&solutions);
    }
    else {
        test_functions_runner();
    }

    return 0;
}
