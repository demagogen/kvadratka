#ifndef SOLVE_SQUARE_EQUATION_H_
#define SOLVE_SQUARE_EQUATION_H_

/// @brief Перечисляемый тип данных о решениях уравнения
enum NUMBER_OF_SOLUTIONS {
    ERROR_NUMBER            = 0,
    NO_SOLUTIONS            = 1,
    ONE_SOLUTION            = 2,
    TWO_SOLUTIONS           = 3,
    INF_NUMBER_OF_SOLUTIONS = 4,
};

/// @brief Структура с данными о решении уравнения
struct SE_SOLUTIONS{
    double x1, x2;
    NUMBER_OF_SOLUTIONS num_of_sol;
};

/// @brief Решает линейное уравнение (частный случай)
/// @param b второй коэффициент
/// @param c третий коэффициент
/// @param solutions структура с данными о решении уравнения
void linear_equation      (double b, double c, SE_SOLUTIONS *solutions);

/// @brief Решает квадратное уравнение (частный случай)
/// @param a первый коэффициент
/// @param b второй коэффициент
/// @param c третий коэффициент
/// @param solutions структура с данными о решении уравнения
void quadratic_equation   (double a, double b, double c, SE_SOLUTIONS *solutions);

/// @brief Решает квадратное уравнение
/// @param a первый коэффициент
/// @param b второй коэффициент
/// @param c третий коэффициент
/// @param solutions структура с данными о решении уравнения
void solve_square_equation(double a, double b, double c, SE_SOLUTIONS *solutions);
#endif
