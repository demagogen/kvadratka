#include <TXLib.h>
#include <math.h>

#include "kvadratka_functions.h"

const double EPS = 0.0000001;

bool is_var_equal_to_zero(double val) {
    return (fabs(val) < EPS);
}

void enter_se_parameters(double *a, double *b, double *c) {
    int tryCounter = NAN;
    printf("Введите значения трех коэффициентов через пробел\n");
    for (tryCounter = 0; tryCounter < 3; tryCounter++) {
        if (scanf("%lf %lf %lf", a, b, c) != 3) {break;} {
            if (tryCounter == 2) {
                printf("Не были введены возможные значения коэффициентов\nКонец программы");
            }
            printf("Были введены недопустимые значения\nВведите допустимые значения\n");
        }
    }
}

void solve_square_equation(double a, double b, double c, SE_SOLUTIONS *solutions) {
    double discriminant = NAN;
    double summand1 = -b/(2*a), summand2 = NAN;

    if (is_var_equal_to_zero(a)) {
        if (is_var_equal_to_zero(b)) {
            if (is_var_equal_to_zero(c)) {
                solutions->num_of_sol =
                    INF_NUMBER_OF_SOLUTIONS;
            }
            else {
                solutions->num_of_sol = NO_SOLUTIONS;
            }
        }
        else {
            solutions->x1 = solutions->x2 = -c/b;
            solutions->num_of_sol = ONE_SOLUTION;
        }
    }
    else {
        discriminant = b*b - 4*a*c;
        summand2 = sqrt(discriminant)/(2*a);
        if (discriminant > EPS) {
            solutions->x1 = summand1 + summand2;
            solutions->x2 = summand1 - summand2;
            solutions->num_of_sol = TWO_SOLUTIONS;
        }
        else if (is_var_equal_to_zero(discriminant)) {
            solutions->x1 = summand1;
            solutions->num_of_sol = ONE_SOLUTION;
        }
        else {
            solutions->num_of_sol = NO_SOLUTIONS;
        }
    }
}

void print_solutions(SE_SOLUTIONS *solutions) {
    switch(solutions->num_of_sol) {
        case ERROR_NUMBER:
            printf("ERROR");
            break;
        case NO_SOLUTIONS:
            printf("Нет решений");
            break;
        case ONE_SOLUTION:
            printf("Одно решение: %lf", solutions->x1);
            break;
        case TWO_SOLUTIONS:
            printf("Два решения: %lf %lf",
            solutions->x1, solutions->x2);
            break;
        case INF_NUMBER_OF_SOLUTIONS:
            printf("Бесконечное количество решений");
            break;
        default:
            printf("ERRORdefault");
            break;
    }
}

