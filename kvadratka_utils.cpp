#include <math.h>
#include "kvadratka_header.h"

bool is_var_equal_to_zero(double val) {
    return (fabs(val) < EPS);
}
