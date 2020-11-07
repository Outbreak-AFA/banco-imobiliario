#include <stdlib.h>
#include <iostream>

using namespace std;

/* PROPRIEDADES

Para comprar alguma propriedade, que seja um terreno, praça, bairro ou empresa, 
é necessário que seu peão caia em uma das casas, caso já não seja o dono.

Caso a propriedade seja de outro jogador, se o seu peão parar na casa, 
você deverá pagar ao dono desta propriedade o valor do aluguel indicado no título da propriedade.

Dica: Diversificar seus investimentos é palavra de ordem no mundo dos negócios. 
Lembre-se que quanto mais propriedades tiver, maior a probabilidade de ganhar dinheiro, 
porque sempre que caírem na sua propriedade você receberá aluguel.

*/


typedef struct {
    int tipo_propriedade; // int ? char ? (definir depois) // atribuir valores numéricos ?
    bool tem_dono; // verificar se a propriedade tem dono
    double valor_aluguel; // valor do aluguel da propriedade
} PROPRIEDADE;

PROPRIEDADE criar_propriedade(int tipo_propriedade, bool tem_dono, double valor_aluguel) {
    PROPRIEDADE p;
    p.tipo_propriedade = tipo_propriedade;
    p.tem_dono = tem_dono;
    p.valor_aluguel = valor_aluguel;
    return p;
}

void comprar_propriedade(PROPRIEDADE *p) {
    if (p->tem_dono) {
        cout << "Essa propriedade ja tem um dono. Voce nao pode comprar ela!" << endl;
    }
}