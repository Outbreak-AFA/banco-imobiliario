#include "dados.h"
#include <iostream>
#include <windows.h>
#include "./src/estruturas/filaencadeada.h"
#include "simple_sort.h"
#include <list>

/*
Isso é só um esboço para eu ter ideia de como será a lógica do sorteio. Não é nada oficial.
Depois irei fazer as alterações associando com o struct do jogador.
*/

using namespace std;

int sortearJogadores(int player_count) {
    /*
    Essa função recebe a quantidade de jogadores como argumento.
    Por meio de um loop for, serão feitas a jogada de dados de cada jogador.
    Cada valor tirado por jogador, será armazenado em uma list<>.
    */

    if (player_count < 2 || player_count > 4) {
        cout << "Quantidade de jogadores deve ser no mínimo 2 e no maximo 4!" << endl;
        return 0;
    } else {

        list<int> resultado;
        // list<player> resultado;

        for (int i=0; i<player_count; i++) {
            cout << "Jogador " << i+1 << " vai lançar os dados!" << endl;
            Sleep(1000); // esperar 1 segundo
            int valor_dados = mostrarDados();
            cout << "Jogador " << i+1 << " tirou " << valor_dados << endl;
            resultado.push_back(valor_dados);
            // player->resultado = valor_dados
            // resultado.push_back(player->resultado);
            system("pause");
        }
        if (!resultado.empty()) {
            resultado.sort(); // ordena a lista em ordem crescente
            resultado.reverse(); // inverte a lista, deixando-a em ordem decrescente
        }

    }

}