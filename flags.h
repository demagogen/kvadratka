#ifndef FLAGS_H_
#define FLAGS_H_
typedef void (*FlagCallback)(void);


/// @brief Структура флагов
///@details Структура флагов с данными о вызове флагов

struct FLAG {
    const char *flag_short = NULL;
    const char *flag_long = NULL;
    void (*callback)(void) = 0;
    const char *description = NULL;
};

/// @brief Вывод информации по использованию программы
/// @details Вывод информации по использованию программы, после ввода флагов -h или --help

void print_help();

/// @brief Парсер флагов
/// @details Парсер флагов, который вызывает нужные флаги
/// @param argc количество аргументов командой строки
/// @param argv массив элементов командной строки

void parse_flags(int argc, char *argv[]);

/// @brief Регистрация флага
/// @details Регистрация флагов, которые будут вызываться при вводе flag_short или flag_long
///          и которые будут выводить сообщение description
/// @param flag_short короткий флаг
/// @param flag_long длинный флаг
/// @param указатель на функцию, которая должна будет вызвана при нахождении флагов
/// @param description описание к флагам
/// @return true -- если функция завершилась успешно
///         false -- если при вызове функции была ошибка

bool register_flag(const char *flag_short, const char *flag_long, FlagCallback, const char *description);
#endif
