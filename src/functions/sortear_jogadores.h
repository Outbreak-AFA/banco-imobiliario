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

    if (players.size() < 2 || players.size() > 4) {
        cout << "Quantidade de jogadores deve ser no mínimo 2 e no maximo 4!" << endl;
        return 0;
    } else {

        for (int i=0; i < players.size(); i++) {
            cout << "Jogador(a) " << players.at(i).nome << " vai lancar os dados!" << endl;
            Sleep(1000); // esperar 1 segundo

            int valor_dados = mostrarDados();
            cout << "Jogador(a) " << players.at(i).nome << " tirou " << valor_dados << "! :D" << endl;
            players.at(i).resultado_dados = valor_dados;
            system("pause");
        }

        ordenarResultados(players);
        aux_vet = players;
        players.clear();
        for (int i=aux_vet.size()-1; i>=0; i--) {
            players.push_back(aux_vet.at(i));
        }
        printVet(players);
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