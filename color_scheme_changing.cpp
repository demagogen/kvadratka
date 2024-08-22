#include <stdarg.h>
#include <stdio.h>

#include "color_scheme_changing.h"

void graphic_printf(const char *st, COLOR color, STYLE style, ...) {
    va_list argument_pointer;
    char *pointer;

    va_start(argument_pointer, style);
    printf("\033[");

    esc_sequence_start(color, style);

    vprintf(st, argument_pointer);

    printf("\033[0m");
    va_end(argument_pointer);
}

void esc_sequence_start(COLOR color, STYLE style) {
        switch(style) {
        case RESET:
            printf("0;");
            break;
        case BOLD:
            printf("1;");
            break;
    }

    switch(color) {
        case BLACK:
            printf("30m");
            break;
        case RED:
            printf("31m");
            break;
        case GREEN:
            printf("32m");
            break;
    }
}
