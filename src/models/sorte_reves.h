#include <iostream>
#include <string.h>
#include <windows.h>
#include "./src/styles/colors.h"
#include <stdio.h>

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
    char tipo_sr[15]; // tipo sorte ou tipo revés
    char mensagem_sr[100];
    
} SORTE_REVES;

SORTE_REVES criar_card_sr(char *tipo_sr, char *mensagem_sr) {
    SORTE_REVES sr;
    strcpy(sr.tipo_sr, tipo_sr);
    strcpy(sr.mensagem_sr, mensagem_sr);
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

/*
int main() {
    mostrar_card_sorte_reves();
    cout << ANSI_RESET_COLORS << "\nDeu certo" << endl;
    cout << ANSI_COLOR_RED << "teste " << ANSI_COLOR_BLUE << "teste2" << ANSI_RESET_COLORS;
    return 0;
}
*/