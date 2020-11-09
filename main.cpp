#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <string.h>
#include "./src/models/players.h"
#include "./src/functions/dados.h"
#include "./src/functions/ranking.h"


int main () {
    srand(time(NULL));
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
    p.carteira = 1.31;
    addRanking(players, &p);
    
    mostraRanking(players);
    system("pause");
    return 0;
}