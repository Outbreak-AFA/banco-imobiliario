#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "players.h"

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
    char nome_avenida[30];
    int casas, hoteis;
    bool tem_dono; // verificar se a propriedade tem dono
    char nome_comprador[10];
    double valor_aluguel; // valor do aluguel da propriedade
} PROPRIEDADE;

PROPRIEDADE criar_propriedade(int tipo_propriedade, char *nome_avenida, bool tem_dono, 
char *nome_comprador, double valor_aluguel, int casas, int hoteis) {
    PROPRIEDADE p;
    p.tipo_propriedade = tipo_propriedade;
    strcpy(p.nome_avenida, nome_avenida);
    strcpy(p.nome_comprador, nome_comprador);
    p.tem_dono = tem_dono;
    p.valor_aluguel = valor_aluguel;
    p.casas = casas;
    p.hoteis = hoteis;
    return p;
}

// Função que mostra o card de uma propriedade
void mostrar_propriedade(PROPRIEDADE *p) {

   // card genérico de propriedade
   cout << endl;
   cout << "==========================================================" << endl;
   cout << "| Tipo de propriedade: " << p->tipo_propriedade << endl;
   cout << "| " << p->nome_avenida << endl; 
   cout << "| Aluguel: " << "R$ " << p->valor_aluguel << endl;
   if (p->tem_dono == true) {
       cout << "| " << "Proprietario(a): " << p->nome_comprador << endl;
   } 
   cout << "| " << "Casas: " << p->casas << " Hoteis: " << p->hoteis << endl;
   cout << "==========================================================" << endl;

}

void comprar_propriedade(PLAYER *pl, PROPRIEDADE *p) {
    if (p->tem_dono) {
        cout << "Essa propriedade ja tem dono(a). Voce nao pode comprar ela!" << endl;
    } else {
        p->tem_dono = true;
        pl->carteira -= p->valor_aluguel;
        cout << "\nPlayer " << pl->nome << " comprou a propriedade " << endl;
        cout << "Saldo " << pl->nome << ": R$ " << pl->carteira << endl;
        strcpy(p->nome_comprador, pl->nome);
        mostrar_propriedade(p);
    }
}

// Função que é ativada quando um player cai em uma propriedade que já tem dono(a)
void receber_aluguel(PLAYER *pl_caiu, PLAYER *pl_dono, PROPRIEDADE *p) {
    mostrar_propriedade(p);
    if (p->tem_dono && (strcmp(p->nome_comprador, pl_dono->nome) == 0)) {
        cout << "Player " << pl_caiu->nome << " caiu na propriedade do player " << pl_dono->nome << endl;
        pl_caiu->carteira -= p->valor_aluguel;
        pl_dono->carteira += p->valor_aluguel;
        cout << endl;
        cout << pl_caiu->nome << " pagou R$ " << p->valor_aluguel << " a " << pl_dono->nome << endl;
        cout << "\nSaldo " << pl_caiu->nome << ": R$ " << pl_caiu->carteira << endl;
        cout << "Saldo " << pl_dono->nome << ": R$ " << pl_dono->carteira << endl;
    }
}

/*
int main() {
    PROPRIEDADE p, *ptr_p;
    ptr_p = &p;
    PLAYER pl, *ptr_pl, pl2, *ptr_pl2;
    ptr_pl = &pl;
    ptr_pl2 = &pl2;

    pl = criar_player(1, "Felipe", 2, 3000);
    pl2 = criar_player(1, "Amanda", 1, 7000);

    p = criar_propriedade(1, "Avenida Teste", true, ptr_pl2->nome, 2000, 0, 0);
    receber_aluguel(ptr_pl, ptr_pl2, ptr_p);

    return 0;
}
*/