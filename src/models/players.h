// Aqui haverá a strcuct e funções voltadas para players

// struct genérica para teste

typedef struct player
{
    int id;
    string nome;
    int resultado_dados;
    double carteira;
    bool habeas; //sorte ou reves
} PLAYER;

PLAYER criar_player(int id, string nome, double carteira) {
    PLAYER p;
    p.id = id;
    p.nome = nome;
    p.carteira = carteira;
    return p;
}