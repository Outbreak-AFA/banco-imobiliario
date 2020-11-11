// #include <iostream>
// #include <stdlib.h>
// #include <windows.h>
// #include <vector>
// #include "dados.h"
// #include "./../models/players.h"
// #include "sorts.h"

/*
                                FASE DE TESTES + MANUTENÇÃO DA FUNÇÃO
*/

using namespace std;

/*
Essa função recebe a quantidade de jogadores como argumento.
Por meio de um loop for, serão feitas a jogada de dados de cada jogador.
Cada valor tirado por jogador, será armazenado em uma list<>.
*/
int sortearJogadores(vector<PLAYER> &players) {

    vector<PLAYER> aux_vet;

    int vet_len = players.size();

    if (vet_len > 2 && vet_len < 4) {    
        for (int i=0; i < vet_len; i++) {
            cout << "Jogador(a) " << players.at(i).nome << " vai lancar os dados!" << endl;
            Sleep(1000); // esperar 1 segundo

            int valor_dados = mostrarDados();
            cout << "Jogador(a) " << players.at(i).nome << " tirou " << valor_dados << "! :D" << endl;
            players.at(i).resultado_dados = valor_dados;
            system("pause");

            if (i>0 && (players.at(i).resultado_dados == players.at(i-1).resultado_dados)) {
                cout << "\nResultados repetidos. Sorteando novamente..." << endl;
                sortearJogadores(players);
            }
            if (i>1 && (players.at(i).resultado_dados == players.at(i-1).resultado_dados || (players.at(i).resultado_dados == players.at(i-2).resultado_dados))) {
                cout << "\nResultados repetidos. Sorteando novamente..." << endl;
                sortearJogadores(players);
            }
        }

        ordenarResultados(players);
        aux_vet = players;
        players.clear();
        for (int i=aux_vet.size()-1; i>=0; i--) {
            players.push_back(aux_vet.at(i));
        }
        printVet(players);

    } else {
        cout << "Quantidade de jogadores deve ser no minimo 2 e no maximo 4!" << endl;
        return 0;
    }
}

/*
int main() {

    PLAYER p, p2, p3;
    vector<PLAYER> vet;
    p = criar_player(1, "Antonio", 2000);
    p2 = criar_player(2, "Felipe", 4000);
    p3 = criar_player(3, "Amanda", 6000);
    vet.push_back(p);
    vet.push_back(p2);
    vet.push_back(p3);

    sortearJogadores(vet);

    return 0;
}
*/