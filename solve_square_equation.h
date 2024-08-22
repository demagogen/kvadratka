#ifndef SOLVE_SQUARE_EQUATION_H_
#define SOLVE_SQUARE_EQUATION_H_
enum NUMBER_OF_SOLUTIONS {
    ERROR_NUMBER            = 0,
    NO_SOLUTIONS            = 1,
    ONE_SOLUTION            = 2,
    TWO_SOLUTIONS           = 3,
    INF_NUMBER_OF_SOLUTIONS = 4,
};

struct SE_SOLUTIONS{
    double x1, x2;
    NUMBER_OF_SOLUTIONS num_of_sol;
};

void linear_equation(double b, double c, SE_SOLUTIONS *solutions);
void quadratic_equation(double a, double b, double c, SE_SOLUTIONS *solutions);
void solve_square_equation(double a, double b, double c, SE_SOLUTIONS *solutions);
#endif
