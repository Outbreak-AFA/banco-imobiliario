#include <iostream>
#include <string.h>
#include <windows.h>
#include "./src/styles/colors.h"
#include <stdio.h>
#include <vector>


using namespace std;
/*
Caso seu peão pare na casa Sorte ou Revés, você deve pegar a primeira carta do monte, 
cumprir o que ela indica e a devolver para o final do monte após concluir a tarefa.

Se a carta sorteada informar Habeas Corpus ou Compra Livre, você deve guardá-la para usar depois. 
Ela pode ser utilizada em qualquer momento que você deseja. Após utilizada, 
deve ser retornada ao final do monte.

A carta Habeas Corpus te dá o direito de saída livre da prisão sem a necessidade de tirar 
uma dupla nos dados ou pagar fiança.
*/

typedef struct {
    int tipo; // tipo sorte ou tipo revés 1-> Ganha $, 2 -> Perde $, 3 -> Habeas Corpus
    char mensagem[100];
    
} SORTE_REVES;

SORTE_REVES criar_card_sr(int tipo, char *mensagem) {
    SORTE_REVES sr;
    sr.tipo = tipo;
    strcpy(sr.mensagem, mensagem);
    return sr;
}

void mostrar_card_sorte_reves() {
    system("clear");
    char card_sr[5][9] = {
        {219, 219, 219, 219, 219, 219, 219, 219, 219},
        {219, 219, 'S', 'O', 'R', 'T', 'E', 219, 219},
        {219, 219, ' ', ' ', '&', ' ', ' ', 219, 219},
        {219, 219, 'R', 'E', 'V', 'E', 'S', 219, 219},
        {219, 219, 219, 219, 219, 219, 219, 219, 219}
    };

    for (int i=0; i<5; i++) {
        cout << endl;
        for (int j=0; j<9; j++) {
            cout << card_sr[i][j];
        }
    }

}

int randint(int max) {
    int r = rand() % max;
    return r;
}

int embaralhaCartas(vector<SORTE_REVES> &cartas) {
    vector<SORTE_REVES> embaralhado;
    int pos;

    while (!cartas.empty()) {
        pos = randint(cartas.size());
        embaralhado.push_back(cartas.at(pos));
        cartas.erase(cartas.begin() + pos);
    }
    while (!embaralhado.empty()) {
        pos = randint(embaralhado.size());
        cartas.push_back(embaralhado.at(pos));
        embaralhado.erase(embaralhado.begin() + pos);
    }
    
    return 1; // Success
}

/*
int main() {
    mostrar_card_sorte_reves();
    cout << ANSI_RESET_COLORS << "\nDeu certo" << endl;
    cout << ANSI_COLOR_RED << "teste " << ANSI_COLOR_BLUE << "teste2" << ANSI_RESET_COLORS;
    return 0;
}
*/