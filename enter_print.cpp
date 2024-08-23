#include <stdio.h>
#include <assert.h>

#include "solve_square_equation.h"
#include "enter_print.h"
#include "utils.h"
#include "color_scheme_changing.h"

int programm_options_input() {
    int choice = 0;

    graphic_printf(BLACK, BOLD, "Выберите действие"
           "\n\tРешение квадратного уравнения (введите 1)"
           "\n\tЗапустить тест программы      (введите 2)\n");
    scanf("%1d", &choice);
    return choice;
}

void enter_se_parameters(double *a, double *b, double *c) {
    const int max_tries = 3;

    assert(a);
    assert(b);
    assert(c);

    graphic_printf(BLACK, BOLD, "Введите значения трех коэффициентов через пробел\n");

    for (int tryCounter = 0; tryCounter < max_tries; tryCounter++) {
        int scanfResult = scanf("%lf %lf %lf", a, b, c);

        if (!is_parameters_valid(*a, *b, *c)) {
            graphic_printf(RED, BOLD, "Невозможные значения\n");
        }

        if (scanfResult == 3) {
            break;
        }
        else if (tryCounter == 2) {
            graphic_printf(RED, BOLD, "Ошибка\n");
            graphic_printf(BLACK, BOLD, "Конец программы\n");
        }
        else {
            graphic_printf(RED, BOLD, "Ошибка, введите снова\n");
        }

        clear_buffer();
    }
}

void print_solutions(const SE_SOLUTIONS *solutions) {
    assert(solutions != NULL);

    switch(solutions->num_of_sol) {
        case ERROR_NUMBER:
            graphic_printf(RED, BOLD, "Ошибка решения\n");
            break;
        case NO_SOLUTIONS:
            graphic_printf(BLACK, BOLD, "Нет решений\n");
            break;
        case ONE_SOLUTION:
            graphic_printf(BLACK, BOLD, "Одно решение: %lf\n", solutions->x1);
            break;
        case TWO_SOLUTIONS:
            graphic_printf(BLACK, BOLD, "Два решения: %lf %lf\n", solutions->x1, solutions->x2);
            break;
        case INF_NUMBER_OF_SOLUTIONS:
            graphic_printf(BLACK, BOLD, "Бесконечное количество решений\n");
            break;
        default:
            graphic_printf(RED, BOLD, "Ошибка\n");
            break;
    }
}
