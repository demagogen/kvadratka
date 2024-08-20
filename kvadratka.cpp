// kvadratka.cpp -- программа для решения квадратных уравнений
#include <math.h>
#include "kvadratka_header.h"

int main() {
    double a = NAN, b = NAN, c = NAN; // коэффициенты кв.
    SE_SOLUTIONS solutions {
        NAN, NAN,
        ERROR_NUMBER
    };

    enter_se_parameters(&a, &b, &c);
    solve_square_equation(a, b, c, &solutions);
    print_solutions(&solutions);

    return 0;
}
