#include <stdio.h>
#include <TXLib.h>
#include <math.h>

#include "kvadratka_functions.h"

int main() {
    double a = NAN, b = NAN, c = NAN; // коэффициенты кв.
    struct SE_SOLUTIONS solutions {
        NAN, NAN,
        ERROR_NUMBER
    };

    enter_se_parameters(&a, &b, &c);
    solve_square_equation(a, b, c, &solutions);
    print_solutions(&solutions);

    return 0;
}
