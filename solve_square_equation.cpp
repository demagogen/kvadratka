#include <math.h>
#include <assert.h>

#include "utils.h"
#include "solve_square_equation.h"

void linear_equation(double b, double c, SE_SOLUTIONS *solutions){
    assert(solutions);

    if (comparing_function(b, 0) == EQUAL) {
        if (comparing_function(c, 0) == EQUAL) {
            solutions->num_of_sol = INF_NUMBER_OF_SOLUTIONS;
        }
        else {
            solutions->num_of_sol = NO_SOLUTIONS;
        }
    }
    else {
        solutions->x1 = -c / b;
        solutions->num_of_sol = ONE_SOLUTION;
    }
}

void quadratic_equation(double a, double b, double c, SE_SOLUTIONS *solutions){
    assert(solutions);

    double discriminant = b*b - 4*a*c;
    double summand1 = -b / (2*a);

    if (comparing_function(c, 0) == EQUAL) {
        solutions->x1 = 0;
        solutions->x2 = 2 * summand1;
    }
    else {
        if (comparing_function(discriminant, 0) == MORE) {
            double summand2 = sqrt(discriminant) / (2*a);
            solutions->x1 = summand1 + summand2;
            solutions->x2 = summand1 - summand2;
            solutions->num_of_sol = TWO_SOLUTIONS;
        }
        else if (comparing_function(discriminant, 0) == EQUAL){
            solutions->x1 = summand1;
            solutions->x2 = NAN;
            solutions->num_of_sol = ONE_SOLUTION;
        }
        else {
            solutions->x1 = NAN;
            solutions->x2 = NAN;
            solutions->num_of_sol = NO_SOLUTIONS;
        }
    }
}

void solve_square_equation(double a, double b, double c, SE_SOLUTIONS *solutions) {
    assert(solutions);

    if (comparing_function(a, 0) == EQUAL){
        linear_equation(b, c, solutions);
    }
    else {
        quadratic_equation(a, b, c, solutions);
    }
}
