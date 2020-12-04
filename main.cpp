#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h>
#include "./src/functions/dados.h"
#include "./src/utils/utils.h"
#include "./src/functions/detencao.h"
#include "./src/models/players.h"
#include "./src/functions/sorts.h"
#include "./src/functions/ranking.h"
#include "./src/functions/menu.h"
#include "./src/functions/tabuleiro.h"
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
    vector<PROPRIEDADE> propriedades; // lista de propriedades
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
    buildPropriedades(propriedades);
    Sleep(1000);

    printarmapa();
    Sleep(1000);
    pause();
    clear();

    while (!falenciaGeral(players)) {

        if (players.front().detencao <= 0) {

            // JOGA OS DADOS
            for(int lapa = 0; lapa < 28; lapa++) {

                //Verifica posição do jogador atual e possíveis ações no jogo
                if (players.front().celula == lapa) {
                    if (lapa == 0) {
                        narrador(players.front().nome, "passou pelo INICIO!");
                        start(players); // um unico jogador
                    }
                    else if (lapa == 7) {
                        cout << "Que pena! :( Voce caiu justamente na detencao..." << endl;
                        detencao(players);
                    }
                    else if (lapa == 14) {
                        // TODO
                        // chamar funções de férias
                    }
                    else if (lapa == 21) {
                        cout << "Poxa, quanto azar voce tem! Volte para a casa 'DETENCAO' e sofra as punicoes." << endl;
                        vaParaDetencao(players);
                        detencao(players);
                    }
                    else if (lapa == 2 || lapa == 5 || lapa == 10 || lapa == 15 || lapa == 19 || lapa == 23 || lapa == 25) {
                        cout << "Pegue uma carta do baralho de Sorte & Reves!" << endl;
                        cout << "Boa sorte......... (ou nao) hahaha!" << endl;
                        Sleep(1000);
                        acao_sorteReves(cartas, players);
                        cout << endl << "\033[31m[!] \033[0;34mEmbaralhando Sorte & Reves!\033[0m\n\n";
                        embaralhaCartas(cartas);
                    }
                    else if(lapa == 6 || lapa == 11 || lapa == 20 || lapa == 27) {
                        //chamar funções de Companhia
                    }
                    else {
                        // chamar funções de propriedades
                    }
                }
                
                verificarFalenciaPlayer(players);
                // Movimetar o player
                nextPlayer(players);
            }
        } else {
            cout << "Esta na detencao!" << endl;
            players.front().detencao--;
            if (players.front().habeas == true) {
                int choicePrison;
                cout << "Voce possui uma carta de Habeas Corpus! Deseja utiliza-la?\n";
                cout << "[1] SIM" << endl;
                cout << "[2] NAO" << endl;
                cin >> choicePrison;
                if (choicePrison == 1) {
                    sairDaDetencao(players);
                } else if (choicePrison == 2) {
                    cout << "Tudo bem :( Passando para proximo player!" << endl;
                }
            }
            verificaDetencao(players);
            nextPlayer(players);
        }
    }
    /*
    ** Após o while **

    -> Mostrar o ranking
    -> Mensagens finais
    */
    return 0;
}
