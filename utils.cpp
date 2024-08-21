#include <math.h>
#include <stdio.h>

#include "utils.h"

const double EPS = 0.0000001;

bool var_is_bigger_than_zero(double var) {
    return (var > EPS);
}

bool is_var_equal_to_zero(double var) {
    return (fabs(var) < EPS);
}

void clear_buffer() {
    while (getchar() != '\n');
}

bool is_parameters_valid(double a, double b, double c){
    return (isfinite(a) && isfinite(b) && isfinite(c));
}

bool null_pointer_check(double *a, double* b, double *c) {
    return (a != NULL && b != NULL && c != NULL);
}
