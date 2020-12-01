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
    char *posicao1, *posicao2, *posicao3, *posicao4;
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

void comprar_propriedade(vector<PLAYER> &players, PROPRIEDADE *p) {
    if (p->tem_dono) {
        cout << "Essa propriedade ja tem dono(a). Voce nao pode comprar ela!" << endl;
    } else {
        p->tem_dono = true;
        players.front().carteira -= p->valor_aluguel;
        cout << "\nPlayer " << players.front().nome << " comprou a propriedade " << endl;
        cout << "Saldo " << players.front().nome << ": R$ " << players.front().carteira << endl;
        strcpy(p->nome_comprador, players.front().nome);
        pause();
        consultar_propriedade(p);
    }
    verificarFalenciaPlayer(players);
}

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

    if (p->tem_dono) {
        if ((strcmp(players.front().posicao1, p->posicao1) == 0) || (strcmp(players.front().posicao2, p->posicao2) == 0) || (strcmp(players.front().posicao3, p->posicao3) == 0) || (strcmp(players.front().posicao4, p->posicao4) == 0))
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
    verificarFalenciaPlayer(players);
}