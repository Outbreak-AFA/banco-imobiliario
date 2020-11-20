#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h>
#include <iostream>
#include <vector>
#include <string>
#include "./src/models/players.h"
#include "./src/functions/dados.h"
#include "./src/functions/sorts.h"
#include "./src/functions/sortear_jogadores.h"
#include "./src/functions/menu.h"
#include "./src/functions/tabuleiro.h"
// #include "./src/models/propriedade.h"
// #include "./src/styles/colors.h"
//#include "./src/functions/ranking.h"

using namespace std;

int main () {
    srand(time(NULL));

    instrucoes();

    printarmapa();

    PLAYER p, p2, p3, p4;
    vector<PLAYER> vet;
    p = criar_player(1, "Antonio", 2000);
    p2 = criar_player(2, "Felipe", 4000);
    p3 = criar_player(3, "Amanda", 6000);
    p4 = criar_player(4, "Lapa", 8000);
    vet.push_back(p);
    vet.push_back(p2);
    vet.push_back(p3);
    vet.push_back(p4);

    // sortearJogadores(vet);

    // cout << endl << "Ordem: ";
    // printVet(vet);

    // PROPRIEDADE p, *ptr_p;
    // ptr_p = &p;
    // PLAYER pl, *ptr_pl, pl2, *ptr_pl2;
    // ptr_pl = &pl;
    // ptr_pl2 = &pl2;

    // pl = criar_player(1, "Felipe", 2, 3000);
    // pl2 = criar_player(1, "Amanda", 1, 7000);

    // p = criar_propriedade(1, "Avenida Teste", true, ptr_pl2->nome, 2000, 0, 0);
    // receber_aluguel(ptr_pl, ptr_pl2, ptr_p);

/*
    PLAYER p;
    std::vector<PLAYER> players;
    resetRanking();
    getRanking(players);

    strcpy(p.nome, "Antonio");
    p.carteira = 1341.31;
    addRanking(players, &p);
    strcpy(p.nome, "Antonia");
    p.carteira = 1241.31;
    addRanking(players, &p);
    strcpy(p.nome, "Felipe");
    p.carteira = 1041.31;
    addRanking(players, &p);
    strcpy(p.nome, "Amanda");
    p.carteira = 9341.31;
    addRanking(players, &p);
    strcpy(p.nome, "Lapa");
    p.carteira = 13410.31;
    addRanking(players, &p);
    strcpy(p.nome, "Madoka");
    p.carteira = 1342.31;
    addRanking(players, &p);
    strcpy(p.nome, "Homura");
    p.carteira = 1361.31;
    addRanking(players, &p);
    strcpy(p.nome, "Mami");
    p.carteira = 131.31;
    addRanking(players, &p);
    strcpy(p.nome, "Sayaka");
    p.carteira = 1141.31;
    addRanking(players, &p);
    strcpy(p.nome, "Kyoko");
    p.carteira = 341.31;
    addRanking(players, &p);
    strcpy(p.nome, "Sakura");
    p.carteira = 112314.31;
    addRanking(players, &p);
    
    mostraRanking(players);

    system("pause");
*/
    return 0;
}