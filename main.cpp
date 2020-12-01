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
#include "./src/utils/colors.h"
//#include "./src/models/propriedade.h"

using namespace std;

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
    
    loadPlayers(players);
    sortearJogadores(players);
    verificarOrdemPlayers(players);

    mostraRanking(players);
    
    cout << "\x1b[31m[!] \033[0;34mGerando cartas do jogo e embaralhando...\033[0m\n\n";
    loadSorteReves(cartas);
    embaralhaCartas(cartas);
    Sleep(1000);

    printarmapa();
    Sleep(1000);
    pause();
    clear();

    return 0;
}
