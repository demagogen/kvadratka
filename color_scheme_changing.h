#ifndef COLOR_SCHEME_CHANGING_H_
#define COLOR_SCHEME_CHANGING_H_
enum COLOR {
    BLACK = 0,
    RED   = 1,
    GREEN = 2,
};

enum STYLE {
    RESET = 0,
    BOLD  = 1,
};

void change_color(COLOR color, STYLE style);
void graphic_printf(const char *st, COLOR color, STYLE style, ...);
#endif
