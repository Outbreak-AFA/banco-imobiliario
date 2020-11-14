// Aqui haverá a strcuct e funções voltadas para players

// struct genérica para teste

typedef struct player
{
    int id;
    char nome[20];
    int resultado_dados;
    long double carteira;
    char *posicao;
    bool habeas; //sorte ou reves
    bool falencia;
} PLAYER;

PLAYER criar_player(int id, char *nome, long double carteira) {
    PLAYER p;
    p.id = id;
    strcpy(p.nome, nome);
    p.carteira = carteira;
    p.falencia = false;
    return p;
}