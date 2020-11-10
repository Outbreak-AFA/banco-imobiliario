#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\033[0;33m"
#define ANSI_COLOR_BLUE "\033[0;34m"
#define ANSI_COLOR_PURPLE "\033[0;35m"
#define ANSI_COLOR_CYAN "\033[0;36m"
#define ANSI_COLOR_WHITE "\033[0;37m"
#define ANSI_RESET_COLORS "\033[0m"

/*          FORMAS DE USAR

cout << ANSI_COLOR_GREEN << "texto" << endl;

                OU

cout "\033[0;33mtexto" << endl;

                OU

printf(ANSI_COLOR_BLUE "text" ANSI_COLOR_BLUE);
printf(ANSI_COLOR_BLUE "%d" ANSI_COLOR_BLUE, numero);


*/