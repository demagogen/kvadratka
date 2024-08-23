#ifndef COLOR_SCHEME_CHANGING_H_
#define COLOR_SCHEME_CHANGING_H_
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

enum STYLE {
    RESET         = 0,
    BOLD          = 1,
    UNDERLINE     = 2,
    INVERSE       = 3,
    BOLD_OFF      = 4,
    UNDERLINE_OFF = 5,
    INVERSE_OFF   = 6,
};

void change_color(COLOR color, STYLE style);
void graphic_printf(const char *st, COLOR color, STYLE style, ...);
#endif
