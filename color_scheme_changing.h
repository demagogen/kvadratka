#ifndef COLOR_SCHEME_CHANGING_H_
#define COLOR_SCHEME_CHANGING_H_

/// @brief Перечислимый тип цветов
enum COLOR {
    BLACK   = 0,
    RED     = 1,
    GREEN   = 2,
    YELLOW  = 3,
    BLUE    = 4,
    MAGENTA = 5,
    CYAN    = 6,
    WHITE   = 7,
};

/// @brief Перечислимый тип стилей
enum STYLE {
    RESET         = 0,
    BOLD          = 1,
    UNDERLINE     = 2,
    INVERSE       = 3,
    BOLD_OFF      = 4,
    UNDERLINE_OFF = 5,
    INVERSE_OFF   = 6,
};

/// @brief Меняет цвет и стиль выводящей строки
/// @param color цвет
/// @param style стиль
void change_color(COLOR color, STYLE style);

/// @brief Выводит строку с цветом и стилем
/// @param st строка
/// @param color цвет
/// @param style стиль
/// @param  Строка с цветом color и стилем style
void graphic_printf(const char *st, COLOR color, STYLE style, ...);
#endif
