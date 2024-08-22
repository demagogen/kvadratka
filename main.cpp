// kvadratka.cpp -- программа для решения квадратных уравнений
#include <math.h>
#include <stdio.h>

#include "utils.h"
#include "solve_square_equation.h"
#include "enter_print.h"
#include "tests.h"
#include "color_scheme_changing.h"

int main() {
    double a = NAN, b = NAN, c = NAN; // коэффициенты кв.
    int programm_option = 0;
    SE_SOLUTIONS solutions {
        NAN, NAN,
        ERROR_NUMBER
    };

    programm_option = programm_options_input();
    if (programm_option == 1) {
        enter_se_parameters(&a, &b, &c);
        solve_square_equation(a, b, c, &solutions);
        print_solutions(&solutions);
    }
    else if (programm_option == 2) {
        test_functions_runner();
    }
    else {
        graphic_printf("Ошибочный ввод\n", RED, BOLD);
    }

    return 0;
}
