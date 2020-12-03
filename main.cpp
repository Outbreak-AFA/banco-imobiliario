#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include "./src/utils/utils.h"
#include "./src/models/players.h"
#include "./src/functions/sorts.h"
#include "./src/functions/ranking.h"
#include "./src/functions/menu.h"
#include "./src/functions/tabuleiro.h"
#include "./src/functions/dados.h"
#include "./src/models/sorte_reves.h"
#include "./src/functions/sortear_jogadores.h"
#include "./src/models/propriedade.h"
#include "./src/utils/colors.h"

using namespace std;

/*
Verifica se todos os players do jogo atingiram a falência.
*/
int falenciaGeral(vector<PLAYER> &players) {
	if (players.size() == 1) return 1;
	else return 0;
}

int main () {
    srand(time(NULL));
    vector<PLAYER> players; // fila de players
    vector<SORTE_REVES> cartas; // pilha de cartas
    vector<PROPRIEDADE> propriedades;
    cout << "\033[32mINICIANDO\033[0m\n";
    clear();
   while(1) {
       if (escolhas() == 0) break;
   }

    Sleep(1000);
    
    /*
    Geração dos players e realização do sorteio para verificar a ordem de cada.
    */
    loadPlayers(players);
    sortearJogadores(players);
    verificarOrdemPlayers(players);

    /*
    Geração das cartas do baralho de Sorte & Revés e embaralhando-as logo em seguida.
    */
    cout << "\033[31m[!] \033[0;34mGerando cartas do jogo e embaralhando...\033[0m\n\n";
    loadSorteReves(cartas, 50);
    embaralhaCartas(cartas);
    Sleep(1000);

    cout << "\033[31m[!] \033[0;34mGerando propriedades...\033[0m\n\n";
    loadPropriedades(propriedades);
    Sleep(1000);

    printarmapa();
    Sleep(1000);
    pause();
    clear();

    while (falenciaGeral(players)) {

    }

    /*
    ** Após o while **

    -> Mostrar o ranking
    -> Mensagens finais
    */
    return 0;
}
