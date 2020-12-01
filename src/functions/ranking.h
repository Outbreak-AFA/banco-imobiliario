/*
    Cria ou Lê um arquivo registrando a pontuação (dinheiro) dos players vencedores das partidas jogadas. Possui um limite de até 10 players sendo ordenado do maior para o menor.
*/

using namespace std;
void resetRanking();

// Retorna uma lista de todos os players registrados
void getRanking(vector<PLAYER> &players) {
    FILE *pArq;
    PLAYER p;
    int total;
    players.clear();
    pArq = fopen("ranking.bin", "r+b");
    if (pArq == NULL) {
        printf("Erro ao acessar ranking.bin\nResetando...\n");
        resetRanking();
        getRanking(players);
    }

    fread(&total, sizeof(total), 1, pArq);

    for (int i = 0; i < total; i++) {
        printf("Peguei alguém??? %d\n", total);
        fseek(pArq, sizeof(total), SEEK_SET);
        fseek(pArq, i * sizeof(p), SEEK_CUR);
        fread(&p, sizeof(p), 1, pArq);
        players.push_back(p);
    }
    fclose(pArq);
}

void resetRanking() {
    FILE *pArq;
    int total = 0;
    pArq = fopen("ranking.bin", "wb");
    fwrite(&total, sizeof(total), 1, pArq);
    fclose(pArq);
}

void addRanking(vector<PLAYER> &players, PLAYER *new_player) {
    FILE *pArq;
    int size = players.size(), i;
    PLAYER p;
    vector<PLAYER> aux;

    pArq = fopen("ranking.bin", "wb");

    players.push_back(*new_player);
    if (players.size() > 10) {
        quickSort(players, 0, size);
        for(i = size; i >= 0; i--) {
            aux.push_back(players.at(i));
        }
        players = aux;
    }
    while(players.size() > 10) players.pop_back();

    size = players.size();

    fwrite(&size, sizeof(size), 1, pArq);
    fseek(pArq, sizeof(size), SEEK_SET);

    for (i = 0; i < players.size(); i++) {
        fseek(pArq, i*sizeof(players.at(i)), SEEK_CUR);
        p = players.at(i);
        fwrite(&p,sizeof(p),1, pArq );
    }
    fclose(pArq);
}

// TODO: Melhorar formatação
void mostraRanking(vector<PLAYER> &players) {
    cout << endl;
    cout << "========== \033[33mRanking Atual\033[0m ==========" << endl;
    cout << "Quantidade de players: " << players.size() << endl;
    for (int i = 0; i < players.size(); i++)
        cout << "NOME: " << players.at(i).nome << " | CARTEIRA: R$ " << players.at(i).carteira << endl;
    cout << "===================================" << endl;
    cout << endl;
}