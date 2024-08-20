#include <math.h>

#include "utils.h"
#include "names.h"
#include "structures.h"
#include "solve_square_equation.h"

void a_equal_to_zero(double b, double c, SE_SOLUTIONS *solutions){// TODO rename to linear equation
    if (is_var_equal_to_zero(b)) {
        if (is_var_equal_to_zero(c)) {
            solutions->num_of_sol = INF_NUMBER_OF_SOLUTIONS;
        }
        else {
            solutions->num_of_sol = NO_SOLUTIONS;
        }
    }
    else {
        solutions->x1 = -c/b;
        solutions->num_of_sol = ONE_SOLUTION;
    }
}

void a_not_equal_to_zero(double a, double b, double c, SE_SOLUTIONS *solutions){ // TODO quadratic equation
    double discriminant = b*b - 4*a*c;
    double summand1 = -b/(2*a);
    // TODO USE BLANK LINES YOU FUCKING PEKUS
    if (var_is_bigger_than_zero(discriminant)) {
        double summand2 = sqrt(discriminant)/(2*a);











































































        solutions->x1 = summand1 + summand2;
        solutions->x2 = summand1 - summand2;
        solutions->num_of_sol = TWO_SOLUTIONS;
    }
    else if (is_var_equal_to_zero(discriminant)){
        solutions->x1 = summand1;
        solutions->num_of_sol = ONE_SOLUTION;
    }
    else {
        solutions->num_of_sol = NO_SOLUTIONS;
    }
}

void solve_square_equation(double a, double b, double c, SE_SOLUTIONS *solutions) {
    if (is_var_equal_to_zero(a)){
        a_equal_to_zero(b, c, solutions);
    }
    else {
        a_not_equal_to_zero(a, b, c, solutions);
    }
}
