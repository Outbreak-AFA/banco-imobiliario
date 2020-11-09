// Aqui haverá a strcuct e funções voltadas para players

// struct genérica para teste
typedef struct player
{
    int id;
    char nome[30];
    int resultado_dados;
    double carteira;
} PLAYER;

PLAYER criar_player(int id, char *nome, int resultado_dados, double carteira) {
    PLAYER p;
    p.id = id;
    strcpy(p.nome, nome);
    p.resultado_dados = resultado_dados;
    p.carteira = carteira;
    return p;
}