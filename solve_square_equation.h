#ifndef SOLVE_SQUARE_EQUATION_H_
#define SOLVE_SQUARE_EQUATION_H_

/// @brief Перечисляемый тип данных о решениях уравнения
/// @details Перечислимый тип данных о решениях уравнения,
///          содержащий информацию о количестве корней.

enum NUMBER_OF_SOLUTIONS {
    ERROR_NUMBER            = 0, ///<ошибочное значение
    NO_SOLUTIONS            = 1, ///<нет решений
    ONE_SOLUTION            = 2, ///<одно решение
    TWO_SOLUTIONS           = 3, ///<два решения
    INF_NUMBER_OF_SOLUTIONS = 4, ///<бесконечное количество решений
};

/// @brief Структура с данными о решении уравнения
/// @details Структура с данными о решении уравнения, в
///          в которую сохраняется информация о решении
///          квадратного уравнения.

struct SE_SOLUTIONS{
    double x1 = 0, x2 = 0;
    NUMBER_OF_SOLUTIONS num_of_sol = ERROR_NUMBER;
};

/// @brief Решает линейное уравнение (частный случай)
/// @details Решает линейное уравнения (частный случай квадратного уравнения)
///          и сохраняет данные в структуру solutions.
/// @param b второй коэффициент
/// @param c третий коэффициент
/// @param solutions структура с данными о решении уравнения\

void linear_equation(double b, double c, SE_SOLUTIONS *solutions);

/// @brief Решает квадратное уравнение (общий случай)
/// @details Решает квадратное уравнение (общий случай) и сохраняет
///          данные в структуру solutions.
/// @param a первый коэффициент
/// @param b второй коэффициент
/// @param c третий коэффициент
/// @param solutions структура с данными о решении уравнения

void quadratic_equation(double a, double b, double c, SE_SOLUTIONS *solutions);

/// @brief Решает квадратное уравнение
/// @details Решает квадратное уравнение. Рассматривает частные случаи и
///          запускает функции для решения конкретных случаев квадратного
///          уравнения.
/// @param a первый коэффициент
/// @param b второй коэффициент
/// @param c третий коэффициент
/// @param solutions структура с данными о решении уравнения

void solve_square_equation(double a, double b, double c, SE_SOLUTIONS *solutions);
#endif
