#include <math.h>
#include <stdio.h>

#include "utils.h"

COMPARE_RESULT comparing_function(double var1, double var2) {
    if (var1 > var2) {
        return MORE;
    }
    else if (var1 < var2) {
        return LESS;
    }
    else {
        return EQUAL;
    }
};

void clear_buffer() {
    while (getchar() != '\n');
}

bool is_parameters_valid(double a, double b, double c){
    return (isfinite(a) && isfinite(b) && isfinite(c));
}
