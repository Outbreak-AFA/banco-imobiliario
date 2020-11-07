#include "dados.h"
#include <iostream>
#include <windows.h>
#include "quicksort.h"
#include "filaencadeada.h"

/*
Isso é só um esboço para eu ter ideia de como será a lógica do sorteio. Não é nada oficial.
Depois irei fazer as alterações associando com o struct do jogador.
*/

using namespace std;
FILA *f;
int sortearJogadores(int player_count) {
    /*
    Essa função recebe a quantidade de jogadores como argumento.
    Por meio de um loop for, serão feitas a jogada de dados de cada jogador.
    Cada valor tirado por jogador, será armazenado em uma pilha.
    */

    if (player_count < 2 || player_count > 4) {
        cout << "Quantidade de jogadores deve ser no mínimo 2 e no máximo 4!" << endl;
        return 0;
    } else {

        for (int i=1; i<=player_count; i++) {
            cout << "Jogador " << i << " vai lançar os dados!" << endl;
            system("pause");
            cout << mostrarDados() << endl;
            cout << "Jogador " << i << " tirou " << mostrarValorDados() << endl;
            enfileira(f, mostrarValorDados());
            system("pause");
            
        }
    }

}