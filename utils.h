#ifndef UTILS_H_
#define UTILS_H_
const double EPS = 1e-7;

enum COMPARE_RESULT{
    MORE  = 1,
    LESS  = -1,
    EQUAL = 0,
};

/// @brief Очищает буфер
void clear_buffer                ();
/// @brief Проверяет коэффициенты на допустимые значения
/// @param a первый коэффициент
/// @param b второй коэффициент
/// @param c третий коэффициент
/// @return true -- если все параметры имеют допустимые значения,
///         false -- если хотя бы один из параметров не имеет допустимого значения
bool is_parameters_valid         (double a, double b, double c);

/// @brief Сравнивает числа
/// @param var1 первое число
/// @param var2 второе число
/// @return Имя значения проверки типа COMPARE_RESULT
COMPARE_RESULT comparing_function(double var1, double var2);
#endif
