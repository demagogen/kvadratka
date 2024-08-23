#ifndef ENTER_PRINT_H_
#define ENTER_PRINT_H_

#include "solve_square_equation.h"

/// @brief Сохраняет ответ пользователя на выбор действий
/// @details Сохраняет и передает ответ пользователя на выбор действий
///          в начале программы.
/// @return целочисленное число, означающее выбор пользователя
int programm_options_input();

/// @brief Сохраняет коэффициенты введенные пользователем
/// @details Сохраняет коэффициенты, введенные пользователем,
///          для решения квадратного уравнения.
/// @param a первый коэффициент
/// @param b второй коэффициент
/// @param c третий коэффициент
void enter_se_parameters(double *a, double *b, double *c);

/// @brief Выводит ответы решения квадратного уравнения
/// @details Выводит в поток вывода ответы решения квадратного уравнения
///          в виде структуры.
/// @param solutions структура с данными о решении квадратного уравнения
void print_solutions(const SE_SOLUTIONS *solutions);
#endif
