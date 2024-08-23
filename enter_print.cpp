#include <stdio.h>
#include <assert.h>
#include <math.h> // TODO unused header
#include <stdarg.h> // TODO unused header

#include "solve_square_equation.h"
#include "enter_print.h"
#include "utils.h"
#include "color_scheme_changing.h"

int programm_options_input() {
    int choice = 0;

    graphic_printf("Выберите действие"
           "\n\tРешение квадратного уравнения (введите 1)"
           "\n\tЗапустить тест программы      (введите 2)\n", BLACK, BOLD);
    scanf("%1d", &choice);
    return choice;
}

void enter_se_parameters(double *a, double *b, double *c) {
    assert(a);
    assert(b);
    assert(c);

    graphic_printf("Введите значения трех коэффициентов через пробел\n", BLACK, BOLD);

    for (int tryCounter = 0; tryCounter < 3; tryCounter++) { // TODO come up with a name for '3'
        int scanfResult = scanf("%lf %lf %lf", a, b, c);

        if (!is_parameters_valid(*a, *b, *c)) {
            graphic_printf("Невозможные значения\n", RED, BOLD);
        }

        if (scanfResult == 3) {
            break;
        }
        else if (tryCounter == 2) {
            graphic_printf("Ошибка\n", RED, BOLD);
            graphic_printf("Конец программы\n", BLACK, BOLD);
        }
        else {
            graphic_printf("Ошибка, введите снова\n", RED, BOLD);
        }

        clear_buffer();
    }
}

void print_solutions(const SE_SOLUTIONS *solutions) {
    assert(solutions != NULL);

    switch(solutions->num_of_sol) {
        case ERROR_NUMBER:
            graphic_printf("Ошибка решения\n", RED, BOLD);
            break;
        case NO_SOLUTIONS:
            graphic_printf("Нет решений\n", BLACK, BOLD);
            break;
        case ONE_SOLUTION:
            graphic_printf("Одно решение: %lf\n", BLACK, BOLD, solutions->x1);
            break;
        case TWO_SOLUTIONS:
            graphic_printf("Два решения: %lf %lf\n", BLACK, BOLD, solutions->x1, solutions->x2);
            break;
        case INF_NUMBER_OF_SOLUTIONS:
            graphic_printf("Бесконечное количество решений\n", BLACK, BOLD);
            break;
        default:
            graphic_printf("Ошибка\n", RED, BOLD);
            break;
    }
}
