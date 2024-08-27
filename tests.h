#ifndef TESTS_H_
#define TESTS_H_

#include "utils.h"
#include "solve_square_equation.h"

/// @brief Хранит тестовые данные
/// @details Хранит тестовые данные для проверки функции решения квадратных
///          уравнений.

struct TEST_DATA {
    int number_of_test;                               ///<количество тестов
    double a = 0, b = 0, c = 0;                       ///<правильные коэффициенты
    double x1_ex = 0, x2_ex = 0;                      ///<правильные корни
    NUMBER_OF_SOLUTIONS num_of_sol_ex = ERROR_NUMBER; ///<правильное количество решений
};

/// @brief Возвращает название имя значения переменной
/// @details Возвращает имя значения переменной num_of_sol в виде
///          строки.
/// @param num_of_sol количество решений
/// @return Строку, которая является значением

const char* number_of_solutions_enum(NUMBER_OF_SOLUTIONS num_of_sol);

/// @brief Проверяет результаты теста
/// @details Проверяет результат теста на тестовых данных в структуре test_data.
/// @param test_data структура с правильными тестовыми данными
/// @return true -- если тест прошел успешно,
///         false -- если была обнаружена ошибка

bool check_test_result(TEST_DATA *test_data);

/// @brief Выводит результат теста
/// @details Выводит результат теста функции решения квадратного уравнения
///          в поток вывода.
/// @param check_test_result функция, которая проверяет программу на тесте
/// @param test_data структура с правильными тестовыми данными
/// @param solutions_test структура с данными, возвращаемыми программой

void print_test_result(bool check_test_result, const TEST_DATA *test_data, SE_SOLUTIONS *solutions_test);

/// @brief Запускает тесты
/// @details Запускает функции для проверки тестовых данных и для вывода их
///          в поток вывода.

void test_functions_runner();
#endif
