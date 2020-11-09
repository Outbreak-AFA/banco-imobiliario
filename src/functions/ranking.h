#include <stdio.h>
#include <vector>
#include "sorts.h"
/*
    Cria ou Lê um arquivo registrando a pontuação (dinheiro) dos players vencedores das partidas jogadas. Possui um limite de até 10 players sendo ordenado do maior para o menor.
*/

// Retorna uma lista de todos os players registrados
void getRanking(std::vector<PLAYER> &players)
{
    FILE *pArq;
    PLAYER p;
    int total;
    players.clear();
    pArq = fopen("ranking.bin", "r+b");
    if (pArq == NULL)
    {
        printf("Erro ao acessar ranking.bin\n");
        exit(1);
    }

    fread(&total, sizeof(total), 1, pArq);

    for (int i = 0; i < total; i++)
    {
        printf("Peguei alguém???%d\n", total);
        fseek(pArq, sizeof(total), SEEK_SET);
        fseek(pArq, i * sizeof(p), SEEK_CUR);
        fread(&p, sizeof(p), 1, pArq);
        players.push_back(p);
    }

    fclose(pArq);
}

void resetRanking()
{
    FILE *pArq;
    int total = 0;
    pArq = fopen("ranking.bin", "wb");
    fwrite(&total, sizeof(total), 1, pArq);
    fclose(pArq);
}

void addRanking(vector<PLAYER> &players, PLAYER *new_player)
{
    FILE *pArq;
    int size = players.size();
    PLAYER p;

    pArq = fopen("ranking.bin", "wb");

    players.push_back(*new_player);
    if (players.size() > 10) {
        quickSort(players, 0, size);
    }
    while(players.size() > 10) players.pop_back();

    size = players.size();

    fwrite(&size, sizeof(size), 1, pArq);
    fseek(pArq, sizeof(size), SEEK_SET);

    for(int i = 0; i < players.size(); i++){
        fseek(pArq, i*sizeof(players.at(i)), SEEK_CUR);
        p = players.at(i);
        fwrite(&p,sizeof(p),1, pArq );
    }
    fclose(pArq);
}

void mostraRanking(vector<PLAYER> players) {
    for (int i = 0; i < players.size(); i++)
        printf("NOME: %s | CARTEIRA: %.2f\n", players.at(i).nome, players.at(i).carteira);
}