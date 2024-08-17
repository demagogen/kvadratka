#include <TXLib.h>
#include <math.h>

#include "kvadratka_functions.h"

struct SE_SOLUTIONS solutions {
    NAN, NAN,
    ERROR_NUMBER
};

const double EPS = 0.0000001;

bool is_var_equal_to_zero(double val) {
    return (fabs(val) < EPS);
}

void enter_se_parameters(double *a, double *b, double *c) {
    printf("Введите значения коэффициентов\n");

    printf("Первый коэффициент: ");
    scanf("%lf", a);

    printf("Второй коэффициент: ");
    scanf("%lf", b);

    printf("Третий коэффициент: ");
    scanf("%lf", c);
}

void solve_square_equation(double a, double b, double c,
struct SE_SOLUTIONS *ptr_struct) {
    double discriminant = NAN;

    if (is_var_equal_to_zero(a)) {
        if (is_var_equal_to_zero(b)) {
            if (is_var_equal_to_zero(c)) {
                ptr_struct->num_of_sol =
                    INF_NUMBER_OF_SOLUTIONS;
            }
            else {
                ptr_struct->num_of_sol
                    = NO_SOLUTIONS;
            }
        }
        else {
            ptr_struct->x1 =
                ptr_struct->x2 = -c/b;
            ptr_struct->num_of_sol
                = ONE_SOLUTION;
        }
    }
    else {
        discriminant = b*b - 4*a*c;
        if (discriminant > EPS) {
            ptr_struct->x1 =
                (-b + sqrt(discriminant))/(2*a);
            ptr_struct->x2 =
                (-b - sqrt(discriminant))/(2*a);
            ptr_struct->num_of_sol =
                TWO_SOLUTIONS;
        }
        else if (is_var_equal_to_zero(discriminant)) {
            ptr_struct->x1 =
                ptr_struct->x2 = -b/(2*a);
            ptr_struct->num_of_sol =
                ONE_SOLUTION;
        }
        else {
            ptr_struct->num_of_sol =
                NO_SOLUTIONS;
        }
    }
}

void print_solutions(struct SE_SOLUTIONS *ptr_struct) {
    switch(ptr_struct->num_of_sol) {
        case ERROR_NUMBER:
            printf("ERROR");
            break;
        case NO_SOLUTIONS:
            printf("Нет решений");
            break;
        case ONE_SOLUTION:
            printf("Одно решение: %lf", ptr_struct->x1);
            break;
        case TWO_SOLUTIONS:
            printf("Два решения: %lf %lf",
            ptr_struct->x1, ptr_struct->x2);
            break;
        case INF_NUMBER_OF_SOLUTIONS:
            printf("Бесконечное количество решений");
            break;
        default:
            printf("ERRORdefault");
    }
}

