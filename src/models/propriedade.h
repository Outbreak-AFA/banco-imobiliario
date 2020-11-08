#include <stdlib.h>
#include <iostream>
#include <string.h>

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
    string nome_avenida;
    int casas, hoteis;
    bool tem_dono = false; // verificar se a propriedade tem dono
    string nome_dono;
    double valor_aluguel; // valor do aluguel da propriedade
} PROPRIEDADE;

PROPRIEDADE criar_propriedade(int tipo_propriedade, string nome_avenida, bool tem_dono, 
string nome_dono, double valor_aluguel, int casas, int hoteis) {
    PROPRIEDADE p;
    p.tipo_propriedade = tipo_propriedade;
    p.nome_avenida = nome_avenida;
    p.nome_dono = nome_dono;
    p.tem_dono = tem_dono;
    p.valor_aluguel = valor_aluguel;
    p.casas = casas;
    p.hoteis = hoteis;
    return p;
}

void mostrar_propriedade(PROPRIEDADE *p) {

   // card teste de propriedade
   cout << endl;
   cout << "Tipo de propriedade: " << p->tipo_propriedade << endl;
   cout << p->nome_avenida << endl; 
   cout << "R$ " << p->valor_aluguel << ".00" << endl;
   if (p->tem_dono) {
       cout << "Proprietario: " << p->nome_dono << endl;
   }
   cout << "Casas: " << p->casas << " Hoteis: " << p->hoteis << endl;

}

void comprar_propriedade(PROPRIEDADE *p) {
    if (p->tem_dono) {
        cout << "Essa propriedade ja tem um dono. Voce nao pode comprar ela!" << endl;
    } else {
        p->tem_dono = true;
        // atualizar depois utilizando a struct do jogador
        cout << "Jogador ... comprou a propriedade " << endl;
        mostrar_propriedade(p);
    }
}