#include <math.h>

#include "utils.h"

bool var_is_bigger_than_zero(double var) {
    return (var > EPS);
}

bool is_var_equal_to_zero(double var) {
    return (fabs(var) < EPS);
}
