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

void esc_sequence_start(COLOR color, STYLE style);
void graphic_printf(const char *st, COLOR color, STYLE style, ...);
#endif
