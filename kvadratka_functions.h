#ifndef kvadratka_functions
#define kvadratka_functions
bool is_var_equal_to_zero(double val);
void enter_se_parameters(double *a, double *b, double *c);
void solve_square_equation(double a, double b,
double c, struct SE_SOLUTIONS *ptr_struct);
void print_solutions(struct SE_SOLUTIONS *ptr_struct);
#endif
