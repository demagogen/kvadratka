#ifndef UTILS_H_
#define UTILS_H_

/// @brief Перечислимый тип сравнений
/// @details Содержит имена для результатов сравнения двух чисел.

enum COMPARE_RESULT{
    LESS  = -1, ///<первое значение меньше
    EQUAL = 0,  ///<значения равны
    MORE  = 1,  ///<первое значение больше
};

enum ERROR_DATA{
    PROGRAM_ERROR,   ///<ошибка программы
    ENTER_ERROR,     ///<ошибка при вводе
    VALIDATION_ERROR,///<ошибка в тестах
};

const char* error_data_enum(ERROR_DATA error_inf);
/// @brief Очищает буфер
/// @details Очищает буфер для прочтения данных, которые введет пользователь после первой попытки.

void clear_buffer();

/// @brief Проверяет коэффициенты на допустимые значения
/// @details Проверяет являются ли коэффициенты числами типа double.
///          Выводит значение false, если хотя бы одна переменная имеет
///          значение NAN или INF.
/// @param a первый коэффициент
/// @param b второй коэффициент
/// @param c третий коэффициент
/// @return true -- если все параметры имеют допустимые значения,
///         false -- если хотя бы один из параметров не имеет допустимого значения

bool is_parameters_valid(double a, double b, double c);

/// @brief Сравнивает числа
/// @details Сравнивает два числа и выводит результат сравнения.
///          LESS -- если первое число меньше второго, EQUAL -- если числа равны,
///          MORE -- если первое число больше второго.
/// @param var1 первое число
/// @param var2 второе число
/// @return Имя значения проверки типа COMPARE_RESULT

COMPARE_RESULT comparing_function(double var1, double var2);

#endif
