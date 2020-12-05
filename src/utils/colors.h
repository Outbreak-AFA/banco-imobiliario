#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define LIGHT_GREEN_1 "\x1b[47m"
#define LIGHT_GREEN_2 "\x1b[46m"
#define LIGHT_GREEN_3 "\x1b[83m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define ORANGE_1 "\033[166m"
#define ORANGE_2 "\033[202m"
#define CYAN "\033[36m"
#define PINK_1 "\033[164m"
#define PINK_2 "\033[201m"
#define PINK_3 "\033[198m"
#define WHITE "\033[37m"
#define GREY_1 "\033[238m"
#define GREY_2 "\033[245m"
#define GREY_3 "\033[250m"
#define GREY_4 "\033[239m"
#define RESET_COLORS "\033[0m"

/*          FORMAS DE USAR

cout << GREEN << "texto" << endl;

                OU

cout "\033[0;33mtexto" << endl;

                OU

printf("\033[0;33m texto");
printf(BLUE "text" BLUE);
printf(BLUE "text");
printf(BLUE "%d" BLUE, numero);
printf(BLUE "%d" RESET_COLORS, numero);


*/