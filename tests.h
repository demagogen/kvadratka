#ifndef TESTS_H_
#define TESTS_H_

#include "utils.h"
#include "solve_square_equation.h"

/// @brief Хранит тестовые данные
struct TEST_DATA {
    int number_of_test;
    double a, b, c, x1_ex, x2_ex;
    NUMBER_OF_SOLUTIONS num_of_sol_ex;
};

/// @brief Возвращает название enum NUMBER_OF_SOLUTIONS
/// @param num_of_sol количество решений
/// @return Строку, которая является значением
const char* number_of_solutions_enum(NUMBER_OF_SOLUTIONS num_of_sol);

/// @brief Проверяет результаты теста
/// @param test_data структура с правильными тестовыми данными
/// @return true -- если тест прошел успешно,
///         false -- если была обнаружена ошибка
bool check_test_result    (TEST_DATA *test_data);

/// @brief Выводит результат теста
/// @param check_test_result функция, которая проверяет программу на тесте
/// @param test_data структура с правильными тестовыми данными
/// @param solutions_test структура с данными, возвращаемыми программой
void print_test_result    (bool check_test_result, const TEST_DATA *test_data, SE_SOLUTIONS *solutions_test);

/// @brief Запускает тесты
void test_functions_runner();
#endif
