#include <math.h>

#include "utils.h"
#include "names.h"
#include "structures.h"
#include "solve_square_equation.h"

void solve_square_equation(double a, double b, double c, SE_SOLUTIONS *solutions) {
    double discriminant = NAN;
    double summand1 = -b/(2*a), summand2 = NAN;

    if (is_var_equal_to_zero(a)) {
        if (is_var_equal_to_zero(b)) {
            if (is_var_equal_to_zero(c)) {
                solutions->num_of_sol = INF_NUMBER_OF_SOLUTIONS;
            }
            else {
                solutions->num_of_sol = NO_SOLUTIONS;
            }
        }
        else {
            solutions->x1 = solutions->x2 = -c/b;
            solutions->num_of_sol = ONE_SOLUTION;
        }
    }
    else {
        discriminant = b*b - 4*a*c;
        summand2 = sqrt(discriminant)/(2*a);
        if (discriminant > EPS) {
            solutions->x1 = summand1 + summand2;
            solutions->x2 = summand1 - summand2;
            solutions->num_of_sol = TWO_SOLUTIONS;
        }
        else if (is_var_equal_to_zero(discriminant)) {
            solutions->x1 = summand1;
            solutions->num_of_sol = ONE_SOLUTION;
        }
        else {
            solutions->num_of_sol = NO_SOLUTIONS;
        }
    }
}
