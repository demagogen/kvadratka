#ifndef UTILS_H_
#define UTILS_H_
const double EPS = 1e-7;

enum COMPARE_RESULT{
    MORE  = 0, // TODO more often layout is more = 1, equal = 0, less = -1
    LESS  = 1,
    EQUAL = 2,
};

bool var_is_bigger_than_zero(double  var);
bool is_var_equal_to_zero(double var);
void clear_buffer();
bool is_parameters_valid(double a, double b, double c);
COMPARE_RESULT comparing_function(double var1, double var2);
#endif
