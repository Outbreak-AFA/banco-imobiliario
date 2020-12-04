/*
    Cria ou Lê um arquivo registrando a pontuação (dinheiro) dos players vencedores das partidas jogadas. Possui um limite de até 10 players sendo ordenado do maior para o menor.
*/

using namespace std;

void resetaRanking() {
    FILE *pArq;
    pArq = fopen("ranking.txt", "w");
    fclose(pArq);
}

int adicionarRanking(PLAYER p) {
    FILE * pArq;
    pArq = fopen("ranking.txt", "a");
    string linha;

    std::ostringstream sstream;
    sstream << p.carteira;
    std::string carteira = sstream.str();

    if (pArq == NULL) {
        printf("Erro ao acessar ranking.txt\nResetando...\n");
        resetaRanking();
        return adicionarRanking(p);
    }

    linha += p.nome + "..................." + carteira + "\n";

    for (int num = 0; num < linha.length(); num++){
        fputc(linha.at(num), pArq);
    }

    fclose(pArq);
    return 1;
}

string consomeRanking() {
    FILE *pDados;
    string dados;
    pDados = fopen("ranking.txt", "r");

    if (pDados == NULL) {
        printf("Erro ao acessar ranking.txt\nResetando...\n");
        resetaRanking();
        return "nao ha dados para mostrar ainda!";
    }
    int i = 0;
    while (!feof(pDados)) {
        dados += fgetc(pDados);
        i++;
    }
    dados.at(i-1) = '\0';
    fclose(pDados);
    return dados;
}