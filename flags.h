#ifndef FLAGS_H_
#define FLAGS_H_
typedef void (*FlagCallback)(void);

struct FLAG {
    const char *flag_short[2] = {};
    const char *flag_long[10] = {};
    void (*callback)(void) = 0;
};

//void initialize_function();
void solve_flag();
void help_flag();
void test_flag();
void version_flag();
void parse_flags(int argc, char *argv[]);
bool register_flag(const char *flag_short, const char *flag_long, FlagCallback);
//int flag_input(int argc, char *argv[]);
#endif
