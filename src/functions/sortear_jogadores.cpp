#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include "dados.h"
#include "./../models/players.h"
#include "sorts.h"

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

    PLAYER p, *ptr_p;
    ptr_p = &p;

    vector<PLAYER> *players;

    if (player_count < 2 || player_count > 4) {
        cout << "Quantidade de jogadores deve ser no mínimo 2 e no maximo 4!" << endl;
        return 0;
    } else {

        for (int i=0; i < player_count; i++) {
            ptr_p->id = i+1;
            cout << "Jogador(a) " << ptr_p->id << " vai lançar os dados!" << endl;
            Sleep(1000); // esperar 1 segundo

            int valor_dados = mostrarDados();
            cout << "Jogador(a) " << ptr_p->id << " tirou " << valor_dados << endl;
            ptr_p->resultado_dados = valor_dados;

            p = criar_player(ptr_p->id, ptr_p->nome, ptr_p->resultado_dados, ptr_p->carteira);
            players->push_back(p);

            system("pause");
        }
        ordenarResultados(players, player_count);

    }

}

int main() {
    int quantidade;
    cin >> quantidade;

    sortearJogadores(quantidade);

    return 0;
}
