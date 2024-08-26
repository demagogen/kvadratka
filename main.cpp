// main.cpp -- программа для решения квадратных уравнений
#include <math.h>
#include <stdio.h> //для тестов TODO удалить

#include "solve_square_equation.h"
#include "enter_print.h"
#include "tests.h"
#include "color_scheme_changing.h"
#include "utils.h"
#include "flags.h"

void help_flag(){
    graphic_printf(BLACK, BOLD, "Использование: ./kvadratka [options]\n");
    print_help();
    exit(0);
}

void test_flag(){
    test_functions_runner();
}

void version_flag() {
    graphic_printf(BLACK, BOLD, "Версия 1.0.0 Poltorashka Edition\n");
    //exit(0);
}

void solve_flag() {
    double a = NAN, b = NAN, c = NAN;
    ERROR_DATA error_inf = PROGRAM_ERROR;
    SE_SOLUTIONS solutions {
        NAN, NAN,
        ERROR_NUMBER
    };
    enter_se_parameters(&a, &b, &c);
    solve_square_equation(a, b, c, &solutions);
    print_solutions(&solutions);

    exit(0);
}

int main(int argc, char *argv[]) {
    register_flag("-h", "--help",    print_help,   "помощь");
    register_flag("-t", "--test",    test_flag,    "запуск тестов");
    register_flag("-V", "--version", version_flag, "версия программы");
    register_flag("-s", "--solve",   solve_flag,   "запуск решения квадратного уравнения");

    if (argc > 1) {
        parse_flags(argc, argv);
    }
    else {
        solve_flag();
    }

    return 0;
}
