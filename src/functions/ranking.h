// #include <stdio.h>
// #include <vector>
/*
    Cria ou Lê um arquivo registrando a pontuação (dinheiro) dos players vencedores das partidas jogadas. Possui um limite de até 10 players sendo ordenado do maior para o menor.
*/

// struct genérica para teste
typedef struct player
{
    char nome[30];
    double carteira;
} PLAYER;


// Retorna uma lista de todos os players registrados
vector<PLAYER> getRanking() {
    FILE *pArq;
    PLAYER p;
    int total;
    std::vector<PLAYER> players;

    pArq = fopen("ranking.bin", "a+b");
    if (pArq == NULL) {
        printf("Erro ao acessar ranking.bin\n");
        exit(1);
    }

    fread(&total, sizeof(total), 1, pArq);
    

    for(int i = 0; i < total; i++)
    {
        fseek(pArq, sizeof(total), SEEK_SET);
        fseek(pArq, i*sizeof(p), SEEK_CUR);
        fread(&p, sizeof(p), 1, pArq);
        players.push_back(p);
    }

    fclose(pArq);
    return players;
}

// void resetRanking() {
//     FILE *pArq;
//     PLAYER p[3] = {"Felipe", 100.40, "Amanda", 75.60, "Antonio", 10.30};
//     int *total;
//     *total = 3;
//     pArq = fopen("ranking.bin", "wb");
//     fwrite(total, sizeof(total), 1, pArq);
//     fwrite(p, sizeof(p), 3, pArq);
//     fclose(pArq);
// }