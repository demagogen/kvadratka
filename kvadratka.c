#include<stdio.h>
#include<TXLib.h>
#include<math.h>

int main() {
    const double ZERO = 0.0000001;
    double a, b, c; //коэффициенты
    double x1, x2; //корни
    double discriminant;
    a = b = c = x1 = x2 = discriminant = NAN;

    printf("Введите коэффициенты квадратного уравнения\n");
    printf("Первый: ");
    scanf("%lf", &a);

    printf("Второй: ");
    scanf("%lf", &b);

    printf("Третий: ");
    scanf("%lf", &c);

    if (fabs(a) < ZERO) {

        if (fabs(b) < ZERO) {

            if (fabs(c) < ZERO) {
                printf("Решение уравнения -- множество ");
                printf("действительных чисел");
            }

            else {
                printf("Нет корней");
            }
        }

        else {
            x1 = x2 = -(c/b);
            printf("Один корень: %lf", x1);
        }
    }

    else {
        discriminant = b*b - 4*a*c;

        if (discriminant >= ZERO) {
            x1 = (-b + sqrt(discriminant))/(2*a);
            x2 = (-b - sqrt(discriminant))/(2*a);
            printf("Два корня: %lf %lf", x1, x2);
        }

        else if (fabs(discriminant) < ZERO) {
            x1 = x2 = -b/(2*a);
            printf("Один корень: %lf", x1);
        }

        else {
            printf("Нет корней");
        }
    }

    return 0;
}
