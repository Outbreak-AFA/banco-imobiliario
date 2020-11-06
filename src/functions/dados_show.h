#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#define MAX 6
#define MIN 1
using namespace std;

/*
>> DOC

> MAX = Valor máximo do dado
> MIN = Valor mínimo do dado

*/

int casas;

int mostrarDados() {
    // permite visualizar os dados jogados

    int random1, random2;
    srand(time(NULL));
    for (int i=1; i<=2; i++) {
        random1 = rand() % (MAX + MIN);
        random2 = rand() % (MAX + MIN);
    }

    cout << "Girando dados..." << endl;
    Sleep(1000); // milisegundos

    cout << "==========" << " ==========\n";
    cout << "|        |" << " |        |\n";
    cout << "|  " << random1 << "     |" << " |    " << random2 << "   |\n";
    cout << "|        |" << " |        |\n";
    cout << "==========" << " ==========\n";

    casas = (random1 + random2);
}

int pegarCasas() {
    // pega a soma dos valores dos dados
    // se a função mostrarDados() não for chamada, automaticamente será retornado por essa o número 0
    return casas;
}
