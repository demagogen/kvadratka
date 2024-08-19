#include <math.h>
#include "kvadratka_header.h"

const double EPS = 0.0000001;

bool is_var_equal_to_zero(double val) {
    return (fabs(val) < EPS);
}