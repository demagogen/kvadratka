#include<stdio.h>
#include<TXLib.h>
#include<math.h>

bool is_variable_equal_to_zero(double val);
void enter_se_parameters(double *a, double *b, double *c);
void solve_square_equation(double a, double b, \
double c, double *x1, double *x2, char *flag);
void print_solutions(double x1, double x2, char flag);

int main() {
    double a = NAN, b = NAN, c = NAN; // коэффициенты кв. ур.
    double x1 = NAN, x2 = NAN; // корни
    char flag = NAN; //количество корней

    enter_se_parameters(&a, &b, &c);
    solve_square_equation(a, b, c, &x1, &x2, &flag);
    print_solutions(x1, x2, flag);

    return 0;
}

bool is_variable_equal_to_zero(double val) {
    const double EPS = 0.0000001;
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

void solve_square_equation(double a, double b, double c, \
double *x1, double *x2, char *flag) {
    const double EPS = 0.0000001;
    double discriminant = NAN;

    if (is_variable_equal_to_zero(a) && \
    is_variable_equal_to_zero(b) && \
    is_variable_equal_to_zero(c)) {
        *flag = '3'; // бесконечное количество корней
    }
    else if (is_variable_equal_to_zero(a) && \
    is_variable_equal_to_zero(b) && \
    !is_variable_equal_to_zero(c)) {
        *flag = '0'; // нет корней
    }
    else if (is_variable_equal_to_zero(a) && \
    !is_variable_equal_to_zero(b) && \
    !is_variable_equal_to_zero(c)) {
        *flag = '1'; // один корень
        *x1 = *x2 = -c/b;
    }
    else {
        discriminant = b*b - 4*a*c;
        if (discriminant >= EPS) {
            *x1 = (-b + sqrt(discriminant))/(2*a);
            *x2 = (-b - sqrt(discriminant))/(2*a);
            *flag = '2'; // два корня
        }
        else if (is_variable_equal_to_zero(discriminant)) {
            *x1 = *x2 = -b/(2*a);
            *flag = '1'; //один корень
        }
        else {
            *flag = '0'; //нет корней
        }
    }
}

void print_solutions(double x1, double x2, char flag) {
    if (flag == '0')
        printf("Нет корней");

    else if (flag == '1')
        printf("Один корень: %lf", x1);

    else if (flag == '2')
        printf("Два корня: %lf %lf", x1, x2);

    else if (flag == '3')
        printf("Бесконечное количество корней");
    else
        printf("Error");
}
