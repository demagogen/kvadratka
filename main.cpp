// main.cpp -- программа для решения квадратных уравнений
#include <math.h>
#include <stdio.h> //для тестов TODO удалить

#include "solve_square_equation.h"
#include "enter_print.h"
#include "tests.h"
#include "color_scheme_changing.h"
#include "utils.h"
#include "flags.h"


int main(int argc, char *argv[]) {
    register_flag("-h", "--help", help_flag);
    register_flag("-t", "--test", test_flag);
    register_flag("-V", "--version", version_flag);
    register_flag("-s", "--solve", solve_flag);

    if (argc > 1) {
        parse_flags(argc, argv);
    }
    else {
        solve_flag();
    }

    return 0;
}
