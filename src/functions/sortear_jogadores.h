#include "dados.h"
#include <iostream>
#include <windows.h>
#include "./src/models/players.h"
#include <list>
#include <vector>
#include "sorts.h"

/*
Isso é só um esboço para eu ter ideia de como será a lógica do sorteio. Não é nada oficial.
Depois irei fazer as alterações associando com o struct do jogador.
*/

using namespace std;

/*
Essa função recebe a quantidade de jogadores como argumento.
Por meio de um loop for, serão feitas a jogada de dados de cada jogador.
Cada valor tirado por jogador, será armazenado em uma list<>.
*/
int sortearJogadores(vector<PLAYER> players, int player_count) {

    if (player_count < 2 || player_count > 4) {
        cout << "Quantidade de jogadores deve ser no mínimo 2 e no maximo 4!" << endl;
        return 0;
    } else {

        PLAYER p;
        list<int> resultado;

        for (int i=0; i < player_count; i++) {
            p.id = i+1;
            cout << "Jogador " << p.id << " vai lançar os dados!" << endl;
            Sleep(1000); // esperar 1 segundo
            int valor_dados = mostrarDados();
            cout << "Jogador " << p.id << " tirou " << valor_dados << endl;
            resultado.push_back(valor_dados);
            p.resultado_dados = valor_dados;
            p = criar_player(p.id, p.nome, p.resultado_dados, p.carteira);
            players.push_back(p);
            system("pause");
        }
        quickSortSorteioInicial(players, 0, player_count);

    }

}

/*
int main() {
    int quantidade = 2;
    int *ptr_quantidade = &quantidade;
    PLAYER p, *ptr_p;
    ptr_p = &p;
    vector<PLAYER> players;
    sortearJogadores(ptr_quantidade);
    return 0;
}
*/