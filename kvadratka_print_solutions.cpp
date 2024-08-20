#include <stdio.h>
#include "kvadratka_header.h"

void print_solutions(const SE_SOLUTIONS *solutions) {
    switch(solutions->num_of_sol) {
        case ERROR_NUMBER:
            printf("Ошибка решения\n");
            break;
        case NO_SOLUTIONS:
            printf("Нет решений\n");
            break;
        case ONE_SOLUTION:
            printf("Одно решение: %lf\n", solutions->x1);
            break;
        case TWO_SOLUTIONS:
            printf("Два решения: %lf %lf\n", solutions->x1, solutions->x2);
            break;
        case INF_NUMBER_OF_SOLUTIONS:
            printf("Бесконечное количество решений\n");
            break;
        default:
            printf("Ошибка\n");
            break;
    }
}
