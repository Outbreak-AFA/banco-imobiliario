#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "./src/functions/dados.h"

int main () {
    srand(time(NULL));
    mostrarDados();
    system("pause");

    return 0;
}