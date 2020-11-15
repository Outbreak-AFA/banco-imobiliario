#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include "players.h"
#include <windows.h>

using namespace std;

// PROPRIEDADES

// Para comprar alguma propriedade, que seja um terreno, praça, bairro ou empresa, 
// é necessário que seu peão caia em uma das casas, caso já não seja o dono.

// Caso a propriedade seja de outro jogador, se o seu peão parar na casa, 
// você deverá pagar ao dono desta propriedade o valor do aluguel indicado no título da propriedade.

// Dica: Diversificar seus investimentos é palavra de ordem no mundo dos negócios. 
// Lembre-se que quanto mais propriedades tiver, maior a probabilidade de ganhar dinheiro, 
// porque sempre que caírem na sua propriedade você receberá aluguel.



typedef struct {
    int tipo;
    char nome_avenida[30];
    char *posicao;
    int casas, hoteis;
    bool tem_dono; // verificar se a propriedade tem dono
    char nome_comprador[10];
    long double valor_aluguel; // valor do aluguel da propriedade
} PROPRIEDADE;

PROPRIEDADE criar_propriedade(int tipo, char *nome_avenida, bool tem_dono, 
char *nome_comprador, double valor_aluguel, int casas, int hoteis) {
    PROPRIEDADE p;
    p.tipo = tipo;
    strcpy(p.nome_avenida, nome_avenida);
    strcpy(p.nome_comprador, nome_comprador);
    p.tem_dono = tem_dono;
    p.valor_aluguel = valor_aluguel;
    p.casas = casas;
    p.hoteis = hoteis;
    return p;
}

// Função que mostra o card de uma propriedade
void consultar_propriedade(PROPRIEDADE *p) {

   // card genérico de propriedade
   cout << endl;
   cout << "==========================================================" << endl;
   cout << "| Tipo de propriedade: " << p->tipo << endl;
   cout << "| " << p->nome_avenida << endl; 
   cout << "| Aluguel: " << "R$ " << p->valor_aluguel << endl;
   if (p->tem_dono == true) {
       cout << "| " << "Proprietario(a): " << p->nome_comprador << endl;
   } 
   cout << "| " << "Casas: " << p->casas << " Hoteis: " << p->hoteis << endl;
   cout << "==========================================================" << endl;

}

void comprar_propriedade(vector<PLAYER> *players, PLAYER *pl, PROPRIEDADE *p) {
    if (p->tem_dono) {
        cout << "Essa propriedade ja tem dono(a). Voce nao pode comprar ela!" << endl;
    } else {
        p->tem_dono = true;
        pl->carteira -= p->valor_aluguel;
        cout << "\nPlayer " << pl->nome << " comprou a propriedade " << endl;
        cout << "Saldo " << pl->nome << ": R$ " << pl->carteira << endl;
        strcpy(p->nome_comprador, pl->nome);
        consultar_propriedade(p);
    }
    for (int i=0; i<players->size(); i++) {
        if (strcmp(players->at(i).nome, pl->nome) == 0) {
            players->at(i).carteira = pl->carteira;
        }
    }
} // refatorar

// void comprarPropriedade(vector<PLAYER> *players, PROPRIEDADE *p) {
    
// }

// Função que é ativada quando um player cai em uma propriedade que já tem dono(a)
// void receber_aluguel(PLAYER *pl_caiu, PLAYER *pl_dono, PROPRIEDADE *p) {
//     consultar_propriedade(p);
//     if (p->tem_dono && (strcmp(p->nome_comprador, pl_dono->nome) == 0)) {
//             cout << "Player " << pl_caiu->nome << " caiu na propriedade do(a) player " << pl_dono->nome << endl;
//             pl_caiu->carteira -= p->valor_aluguel;
//             cout << endl;
//             cout << pl_caiu->nome << " pagou R$ " << p->valor_aluguel << " a " << pl_dono->nome << endl;
//             cout << "\nSaldo " << pl_caiu->nome << ": R$ " << pl_caiu->carteira << endl;
//             cout << "Saldo " << pl_dono->nome << ": R$ " << pl_dono->carteira << endl;
//     }
// }

// Refazer o método acima só que adaptando ao vetor de players
// O método acima não atualiza o resultado quando chamado num vetor com ...at(x)....
void pagar_aluguel_propriedade(vector<PLAYER> *players, PROPRIEDADE *p) {
    int pl_len = players->size();
    consultar_propriedade(p);
    for (int i=0; i<pl_len; i++) {
        if (p->tem_dono && (strcmp(players->at(i).nome, p->nome_comprador) == 0)) {
            cout << "Essa e a propriedade dx player " << players->at(i).nome << endl;
            players->at(i).carteira += p->valor_aluguel;
            Sleep(1000);
        }
    }
    for (int j=0; j<players->size(); j++) { // TESTE comparando ID com tipo (fazer depois com posição)
        if (players->at(j).id == p->tipo) {
            players->at(j).carteira -= p->valor_aluguel;
            cout << endl << "Player " << players->at(j).nome << " pagou R$ " << p->valor_aluguel << " por ter passado na propriedade.\n";
        }
        /*
        Refatorar depois para -> quando a posição do player for igual à posição da propriedade e,
        caso essa propriedade tenha um dono, esse player que parou na propriedade irá pagar o valor
        do aluguel. Esse valor já vai estar sendo adicionado à carteira do dono.
        */
    }
    for (int k=0; k<players->size(); k++) {
        cout << "Saldo de " << players->at(k).nome << ": " << players->at(k).carteira << endl;
    }
}

int main() {
    PROPRIEDADE p;
    PLAYER pl, pl2;
    vector <PLAYER> players;

    pl = criar_player(1, "Felipe", 30000);
    pl2 = criar_player(2, "Amanda", 70000);
    players.push_back(pl);
    players.push_back(pl2);

    p = criar_propriedade(1, "Avenida Teste", false, "", 20000, 0, 0);
    comprar_propriedade(&players, &pl2, &p);
    pagar_aluguel_propriedade(&players, &p);

    return 0;
}