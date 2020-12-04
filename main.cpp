#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h>
#include <sstream>
#include "./src/functions/dados.h"
#include "./src/utils/utils.h"
#include "./src/functions/tabuleiro.h"
#include "./src/models/players.h"
#include "./src/functions/detencao.h"
#include "./src/functions/sorts.h"
#include "./src/functions/ranking.h"
#include "./src/functions/menu.h"
#include "./src/models/sorte_reves.h"
#include "./src/functions/sortear_jogadores.h"
#include "./src/models/propriedade.h"
#include "./src/models/companhia.h"
#include "./src/utils/colors.h"

using namespace std;

int main () {
    srand(time(NULL));
    vector<PLAYER> players; // fila de players
    vector<SORTE_REVES> cartas; // pilha de cartas
    vector<PROPRIEDADE> propriedades; // lista de propriedades
    vector<COMPANHIA> companhias; // lista de propriedades
    PROPRIEDADE propriedade;
    COMPANHIA companhia;
    int decisao;
    cout << "\033[32mINICIANDO\033[0m\n";
    clear();
    while(1) {
       if (escolhas() == 0) break;
    }

    Sleep(1000);
    
    /*
    Geração dos players e realização do sorteio para verificar a ordem de cada.
    */
    setPlayersMapa();
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

    cout << "\033[31m[!] \033[0;34mGerando companhias...\033[0m\n\n";
    buildCompanhias(companhias);
    Sleep(1000);

    printarmapa(players.front().pino);
    Sleep(1000);
    pause();
    clear();

    while (!falenciaGeral(players)) {
        clear();
        if (players.front().detencao <= 0) {
            movePlayer(players);
            printarmapa(players.front().pino);
            cout << players.front().nome << " POSSUI NA CARTEIRA: \x1b[32m$ " << players.front().carteira << "\033[0m" << endl;
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
                        ferias(players);
                    }
                    else if (lapa == 21) {
                        cout << "Poxa, quanto azar voce tem! Volte para a casa 'DETENCAO' e sofra as punicoes." << endl;
                        vaParaDetencao(players);
                    }
                    else if (lapa == 2 || lapa == 5 || lapa == 10 || lapa == 15 || lapa == 19 || lapa == 23 || lapa == 25) {
                        mainSorteReves(players, cartas);
                    }
                    else if(lapa == 6 || lapa == 11 || lapa == 20 || lapa == 27) {
                        companhia = getCompanhia(players, companhias);
                        pagar_companhia(players, companhia);
                    }
                    else {
                        narrador(players.front().nome, "pisou em uma PROPRIEDADE!");
                        propriedade = getPropriedade(players, propriedades);
                        cout << propriedade.nome_avenida << endl;
                        menuPropriedade(players, propriedades, propriedade);
                    }
                }
            }
                verificarFalenciaPlayer(players);
                pause();
                // Movimetar o player
                nextPlayer(players);
        } else {
            cout << players.front().nome << " esta na detencao!" << endl;
            players.front().detencao--;
            if (players.front().habeas == true) {
                int choicePrison;
                cout << players.front().nome <<" possui uma carta de Habeas Corpus! Deseja utiliza-la?\n";
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
            pause();
        }
    }

    cout << "FIM DE JOGO! :D" << endl;
    cout << "PARABENS " << players.front().nome <<"!!!"<< endl;
    cout << "Gostaria de participar do nosso ranking de vencedores?" << endl;
    cout << "[1] SIM" << endl;
    cout << "[2] NAO" << endl;
    cin >> decisao;
    if (decisao ==  1) {
        cout << "Certo! adicionando ao ranking! Obrigado por jogar! Volte sempre ;)" << endl;
        adicionarRanking(players.front());
    }
    else cout << "Tudo bem, Obrigado por jogar! Volte sempre ;)" << endl;

    return 0;
}
