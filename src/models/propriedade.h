#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <vector>
#include "players.h"
#include <windows.h>
#include "./src/utils/utils.h"

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

   clear();
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

// Função que pode ser ativada por um player que queira comprar a propriedade em que caiu.
void comprar_propriedade(vector<PLAYER> &players, PROPRIEDADE *p) {
    if (p->tem_dono) {
        cout << "Essa propriedade ja tem dono(a). Voce nao pode comprar ela!" << endl;
    } else if (strcmp(players.front().posicao, p->posicao) == 0){
        p->tem_dono = true;
        players.front().carteira -= p->valor_aluguel;
        cout << "\nPlayer " << players.front().nome << " comprou a propriedade " << endl;
        cout << "Saldo " << players.front().nome << ": R$ " << players.front().carteira << endl;
        strcpy(p->nome_comprador, players.front().nome);
        pause();
        consultar_propriedade(p);
    }
}

// Função para que um player que cair em uma propriedade que já tenha sido comprada, pague o valor
// do aluguel dessa propriedade ao dono.
void pagar_aluguel_propriedade(vector<PLAYER> &players, PROPRIEDADE *p) {
    int pl_len = players.size();
    int cont = 0;
    consultar_propriedade(p);
    for (int i=0; i<pl_len; i++) {
        if (p->tem_dono && (strcmp(players.at(i).nome, p->nome_comprador) == 0)) {
            cout << "Essa e a propriedade dx player " << players.at(i).nome << endl;
            Sleep(1000);
        }
    }
    // ISSO É UM TESTE ////////////
    players.front().posicao = " ";      // Posição Felipe
    players.at(1).posicao = "aa";    // Posição Amanda
    p->posicao = " ";               //  Posição propriedade
    ///////////////////////////////
    if (p->tem_dono && (strcmp(players.front().posicao, p->posicao) == 0)) {
        for (int k=0; k<pl_len; k++) {
            if (strcmp(players.at(k).nome, p->nome_comprador) == 0) {
                players.at(k).carteira += (p->valor_aluguel);
            }
        }

        players.front().carteira -= p->valor_aluguel;
        cout << "Player " << players.front().nome << " pagou R$ " << p->valor_aluguel << " por ter passado na propriedade de " << p->nome_comprador << endl;
        
        cout << endl;
    }
  
    // Saldo de todos os players
    for (int k=0; k<players.size(); k++) {
        cout << endl << "Saldo de " << players.at(k).nome << ": " << players.at(k).carteira;
    }
    cout << endl;
}

// int main() {
//     PROPRIEDADE p;
//     PLAYER pl, pl2, pl3;
//     vector <PLAYER> players;

//     pl = criar_player(1, "Felipe", 30000);
//     pl2 = criar_player(2, "Amanda", 70000);
//     pl3 = criar_player(3, "Antonio", 40000);
//     players.push_back(pl);
//     players.push_back(pl2);
//     players.push_back(pl3);

//     p = criar_propriedade(1, "Avenida Teste", false, "", 20000, 0, 0);
//     comprar_propriedade(&players, &pl2, &p);
//     pagar_aluguel_propriedade(&players, &p);

//     return 0;
// }