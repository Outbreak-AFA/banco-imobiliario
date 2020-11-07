#include "dados.h"
#include <iostream>
#include <windows.h>
#include "./src/estruturas/filaencadeada.h"
#include "simple_sort.h"

/*
Isso é só um esboço para eu ter ideia de como será a lógica do sorteio. Não é nada oficial.
Depois irei fazer as alterações associando com o struct do jogador.
*/

using namespace std;
FILA *f;

int sortearJogadores(int *player_count) {
    int *resultados[player_count];
    /*
    Essa função recebe a quantidade de jogadores como argumento.
    Por meio de um loop for, serão feitas a jogada de dados de cada jogador.
    Cada valor tirado por jogador, será armazenado em uma pilha.
    */

    if (player_count < 2 || player_count > 4) {
        cout << "Quantidade de jogadores deve ser no mínimo 2 e no máximo 4!" << endl;
        return 0;
    } else {

        f = cria_fila();

        for (int i=0; i<player_count; i++) {
            cout << "Jogador " << i+1 << " vai lançar os dados!" << endl;
            Sleep(1000); // esperar 1 segundo
            cout << mostrarDados() << endl;
            cout << "Jogador " << i+1 << " tirou " << mostrarValorDados() << endl;
            resultados[i] = mostrarValorDados();
            if (i > 0) simple_sort(resultados, player_count); // ordena de forma decrescente
            enfileira(f, resultados[i]); // guarda na fila
            system("pause");
        }
    }

}