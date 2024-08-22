#include <math.h>
#include <assert.h>

#include "utils.h"
#include "solve_square_equation.h"
#include "tests.h"

void linear_equation(double b, double c, SE_SOLUTIONS *solutions){
    assert(solutions);

    if (comparing_function(EPS, b) == MORE && comparing_function(b, -EPS) == MORE) {
        if (comparing_function(EPS, c) == MORE && comparing_function(c, -EPS) == MORE) {
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

void quadratic_equation(double a, double b, double c, SE_SOLUTIONS *solutions){
    assert(solutions != NULL);

    double discriminant = b*b - 4*a*c;
    double summand1 = -b/(2*a);

    if (comparing_function(discriminant, EPS) == MORE || comparing_function(discriminant, EPS) == EQUAL) {
        double summand2 = sqrt(discriminant)/(2*a);
        solutions->x1 = summand1 + summand2;
        solutions->x2 = summand1 - summand2;
        solutions->num_of_sol = TWO_SOLUTIONS;
    }
    else if (comparing_function(EPS, discriminant) == MORE && comparing_function(discriminant, -EPS) == MORE){
        solutions->x1 = summand1;
        solutions->num_of_sol = ONE_SOLUTION;
    }
    else {
        solutions->num_of_sol = NO_SOLUTIONS;
    }
}

void solve_square_equation(double a, double b, double c, SE_SOLUTIONS *solutions) {
    assert(solutions != NULL);
    if (comparing_function(EPS, a) == MORE && comparing_function(a, -EPS) == MORE){
        linear_equation(b, c, solutions);
    }
    else {
        quadratic_equation(a, b, c, solutions);
    }
}
