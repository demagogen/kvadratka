#include <stdio.h>
#include <string.h>
#include <math.h>

#include "flags.h"
#include "tests.h"
#include "color_scheme_changing.h"
#include "utils.h"
#include "enter_print.h"

int flag_input(int argc, char *argv[]) {
    if (strcmp(argv[1], "-h") || strcmp(argv[1], "--help")) {
        graphic_printf(BLACK, BOLD, "Использование: kvadratka [options] [value]");
        //TODO
    }
    else if (strcmp(argv[1], "-V") || strcmp(argv[1], "--version")) {
        graphic_printf(BLACK, BOLD, "1.0.0");
    }
    else if (strcmp(argv[1], "-t") || strcmp(argv[1], "--test")) {
        test_functions_runner();
    }
    else if (strcmp(argv[1], "-s") || strcmp(argv[1], "--solve")) {
        double a = NAN, b = NAN, c = NAN;
        SE_SOLUTIONS solutions {
            NAN, NAN,
            ERROR_NUMBER,
        };
        enter_se_parameters(&a, &b, &c);
        solve_square_equation(a, b, c, &solutions);
        print_solutions(&solutions);
    }
    else {
        graphic_printf(RED, BOLD, "%s\n", error_data_enum(ENTER_ERROR));
        graphic_printf(BLACK, BOLD, "Воспользуйтесь флагом \"-h\" или \"--help\"");
    }
    return 0;
}
