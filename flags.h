#ifndef FLAGS_H_
#define FLAGS_H_
typedef void (*FlagCallback)(void);

struct FLAG {
    const char *flag_short = NULL;
    const char *flag_long = NULL;
    void (*callback)(void) = 0;
    const char *description = NULL;
};

//void initialize_function();
void print_help();
void parse_flags(int argc, char *argv[]);
bool register_flag(const char *flag_short, const char *flag_long, FlagCallback, const char *description);
//int flag_input(int argc, char *argv[]);
#endif
