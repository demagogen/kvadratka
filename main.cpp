// main.cpp -- программа для решения квадратных уравнений
#include <math.h>

#include "solve_square_equation.h"
#include "enter_print.h"
#include "tests.h"
#include "color_scheme_changing.h"
#include "utils.h"
#include "flags.h"

int main(int argc, char *argv[]) {
    double a = NAN, b = NAN, c = NAN;
    int program_option = 0;
    ERROR_DATA error_inf = PROGRAM_ERROR;
    SE_SOLUTIONS solutions {
        NAN, NAN,
        ERROR_NUMBER
    };

    flag_input(argc, argv);

    program_option = program_options_input();
    if (program_option == 1) {
        enter_se_parameters(&a, &b, &c);
        solve_square_equation(a, b, c, &solutions);
        print_solutions(&solutions);
    }
    else if (program_option == 2) {
        test_functions_runner();
    }
    else {
        error_inf = ENTER_ERROR;
        graphic_printf(RED, BOLD, "%s\nОшибочный ввод: %d\n", error_data_enum(error_inf), program_option);
    }

    return 0;
}
