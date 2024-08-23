#ifndef ENTER_PRINT_H_
#define ENTER_PRINT_H_
/// @brief Возвращает ответ пользователя на выбор действий
/// @return целочисленное число, означающее выбор пользователя
int programm_options_input();

/// @brief Вводит коэффициенты пользователя
/// @param a первый коэффициент
/// @param b второй коэффициент
/// @param c третий коэффициент
void enter_se_parameters  (double *a, double *b, double *c);

/// @brief Выводит ответы решения квадратного уравнения
/// @param solutions структура с данными о решении квадратного уравнения
void print_solutions      (const SE_SOLUTIONS *solutions);
#endif
