// main.cpp -- программа для решения квадратных уравнений
#include <math.h>

#include "solve_square_equation.h"
#include "enter_print.h"
#include "tests.h"
#include "color_scheme_changing.h"

int main() {
    double a = NAN, b = NAN, c = NAN;
    int program_option = 0;
    SE_SOLUTIONS solutions {
        NAN, NAN,
        ERROR_NUMBER
    };

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
        graphic_printf(RED, BOLD, "Ошибочный ввод\n");
    }

    return 0;
}
