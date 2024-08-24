#include <math.h>
#include <stdio.h>

#include "utils.h"

const char* error_data_enum(ERROR_DATA error_inf){
    switch(error_inf) {
        case ENTER_ERROR:
            return "ENTER_ERROR";
            break;
        case PROGRAM_ERROR:
            return "PROGRAM_ENTER";
            break;
        case VALIDATION_ERROR:
            return "VALIDATION_ERROR";
            break;
        default:
            return "UNKNOWN_ERROR";
            break;
    }
}

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
