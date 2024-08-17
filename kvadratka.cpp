#include <stdio.h>
#include <TXLib.h>
#include <math.h>

#include "kvadratka_functions.h"

enum NUMBER_OF_SOLUTIONS {
    ERROR_NUMBER,
    NO_SOLUTIONS,
    ONE_SOLUTION,
    TWO_SOLUTIONS,
    INF_NUMBER_OF_SOLUTIONS
};

struct SE_SOLUTIONS{
    double x1 = NAN, x2 = NAN;
    NUMBER_OF_SOLUTIONS num_of_sol = ERROR_NUMBER;
};

int main() {
    double a = NAN, b = NAN, c = NAN; // коэффициенты кв.
    struct SE_SOLUTIONS solutions;

    enter_se_parameters(&a, &b, &c);
    solve_square_equation(a, b, c, &solutions);
    print_solutions(&solutions);

    return 0;
}
