#include<stdio.h>
#include<TXLib.h>
#include<math.h>

enum number_of_solutions {no_solutions, one_solution,
two_solutions, inf_number_of_solutions};

bool is_variable_equal_to_zero(double val);
void enter_se_parameters(double *a, double *b, double *c);
void solve_square_equation(double a, double b, \
double c, double *x1, double *x2, number_of_solutions *num_of_sol);
void print_solutions(double x1, double x2,
number_of_solutions num_of_sol);

const double EPS = 0.0000001;

int main() {
    enum number_of_solutions num_of_sol;
    double a = NAN, b = NAN, c = NAN; // коэффициенты кв. ур.
    double x1 = NAN, x2 = NAN; // корни

    enter_se_parameters(&a, &b, &c);
    solve_square_equation(a, b, c, &x1, &x2, &num_of_sol);
    print_solutions(x1, x2, num_of_sol);

    return 0;
}

bool is_variable_equal_to_zero(double val) {
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
double *x1, double *x2, number_of_solutions *num_of_sol) {
    double discriminant = NAN;

    if (is_variable_equal_to_zero(a) &&
    is_variable_equal_to_zero(b) &&
    is_variable_equal_to_zero(c)) {
        *num_of_sol = inf_number_of_solutions; // бесконечное количество корней
    }
    else if (is_variable_equal_to_zero(a) &&
    is_variable_equal_to_zero(b) &&
    !is_variable_equal_to_zero(c)) {
        *num_of_sol = no_solutions; // нет корней
    }
    else if (is_variable_equal_to_zero(a) &&
    !is_variable_equal_to_zero(b) &&
    !is_variable_equal_to_zero(c)) {
        *num_of_sol = one_solution; // один корень
        *x1 = *x2 = -c/b;
    }
    else {
        discriminant = b*b - 4*a*c;
        if (discriminant >= EPS) {
            *x1 = (-b + sqrt(discriminant))/(2*a);
            *x2 = (-b - sqrt(discriminant))/(2*a);
            *num_of_sol = two_solutions; // два корня
        }
        else if (is_variable_equal_to_zero(discriminant)) {
            *x1 = *x2 = -b/(2*a);
            *num_of_sol = one_solution; //один корень
        }
        else {
            *num_of_sol = no_solutions; //нет корней
        }
    }
}

void print_solutions(double x1, double x2,
number_of_solutions num_of_sol) {
    if (num_of_sol == no_solutions)
        printf("Нет корней");

    else if (num_of_sol == one_solution)
        printf("Один корень: %lf", x1);

    else if (num_of_sol == two_solutions)
        printf("Два корня: %lf %lf", x1, x2);

    else if (num_of_sol == inf_number_of_solutions)
        printf("Бесконечное количество корней");
    else
        printf("Error");
}
