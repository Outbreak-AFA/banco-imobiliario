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
#include "./src/models/players.h"
#include "./src/functions/ranking.h"
#include "./src/functions/sorts.h"
#include "./src/functions/menu.h"
#include "./src/functions/tabuleiro.h"
#include "./src/functions/dados.h"
#include "./src/functions/sortear_jogadores.h"
#include "./src/models/sorte_reves.h"
#include "./src/utils/utils.h"
#include "./src/models/propriedade.h"
#include "./src/utils/colors.h"

using namespace std;

/*
Verifica se todos os players do jogo atingiram a falência.
*/
int falenciaGeral(vector<PLAYER> &players) {
	for (int i=0; i<players.size(); i++) {
		if (players.front().falencia) {
			players.pop_back();
		}
	}
	if (players.empty()) return 1;
	else return 0;
}

// void acaoJogador(vector<PLAYER> &players) {
// 	cout << players.front().nome << ", o que deseja fazer?" << endl;
//     int actions;
//     cout << "1 - Jogar dados" << endl;
//     cout << "2 - Checar status de jogador" << endl;
//     cin >> actions;
//     if (actions == 1) {
//     	int resultadoDados = mostrarDados();
//     	cout << "Player " << players.front().nome << " jogou os dados e tirou " << resultadoDados << endl;
// 	} else if (actions == 2) {
// 		cout << "========== STATUS " << players.front().nome << " ==========" << endl;
// 		cout << "ID: " << players.front().id << endl;
// 		cout << "Carteira: R$ " << players.front().carteira << endl;
// 		cout << "Habeas? " players.front().habeas == true ? cout << "Possui" << endl : cout << "Nao possui" << endl; 
// 	}
// }

int main () {
    srand(time(NULL));

    resetRanking();

	vector<SORTE_REVES> cartas;
    vector<PLAYER> players;

    instrucoes();
    Sleep(1000);
    
    /*
    Geração dos players e realização do sorteio para verificar a ordem de cada.
    */
    loadPlayers(players);
    sortearJogadores(players);
    verificarOrdemPlayers(players);

    mostraRanking(players);
    
    /*
    Geração das cartas do baralho de Sorte & Revés e embaralhando-as logo em seguida.
    */
    cout << "\x1b[31m[!] \033[0;34mGerando cartas do jogo e embaralhando...\033[0m\n\n";
    loadSorteReves(cartas, 50);
    embaralhaCartas(cartas);
    Sleep(1000);

    printarmapa();
    Sleep(1000);
    pause();
    clear();

    return 0;
}
