#ifndef kvadratka_functions
#define kvadratka_functions
enum NUMBER_OF_SOLUTIONS {
    ERROR_NUMBER,
    NO_SOLUTIONS,
    ONE_SOLUTION,
    TWO_SOLUTIONS,
    INF_NUMBER_OF_SOLUTIONS
};

struct SE_SOLUTIONS{
    double x1, x2;
    NUMBER_OF_SOLUTIONS num_of_sol;
};

bool is_var_equal_to_zero(double val);
void enter_se_parameters(double *a, double *b, double *c);
void solve_square_equation(double a, double b, double c, SE_SOLUTIONS *solutions);
void print_solutions(SE_SOLUTIONS *solutions);
#endif
