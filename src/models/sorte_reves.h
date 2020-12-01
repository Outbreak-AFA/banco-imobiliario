using namespace std;
/*
Caso seu peão pare na casa Sorte ou Revés, você deve pegar a primeira carta do monte, 
cumprir o que ela indica e a devolver para o final do monte após concluir a tarefa.

Se a carta sorteada informar Habeas Corpus ou Compra Livre, você deve guardá-la para usar depois. 
Ela pode ser utilizada em qualquer momento que você deseja. Após utilizada, 
deve ser retornada ao final do monte.

A carta Habeas Corpus te dá o direito de saída livre da prisão sem a necessidade de tirar 
uma dupla nos dados ou pagar fiança.
*/

typedef struct {
    int tipo; // tipo sorte ou tipo revés 0 -> Perde $, 1 -> Ganha $, 2 -> Habeas Corpus
    
} SORTE_REVES;

SORTE_REVES criar_card_sr(int tipo) {
    SORTE_REVES sr;
    sr.tipo = tipo;
    return sr;
}

/*
LOGO das cartas de Sorte & Revés
*/
void mostrar_card_sorte_reves(vector<SORTE_REVES> &cartas) {
    char card_sr[5][9] = {
        {219, 219, 219, 219, 219, 219, 219, 219, 219},
        {219, 219, 'S', 'O', 'R', 'T', 'E', 219, 219},
        {219, 219, ' ', ' ', '&', ' ', ' ', 219, 219},
        {219, 219, 'R', 'E', 'V', 'E', 'S', 219, 219},
        {219, 219, 219, 219, 219, 219, 219, 219, 219}
    };

    for (int i=0; i<5; i++) {
        cout << endl;
        for (int j=0; j<9; j++) {
            cout << card_sr[i][j];
        }
    }
}

/*
Gera um número inteiro randômico de 0 até (int max)
*/
int randint(int max) {
    int r = rand() % max;
    return r;
}

/*
Embaralha as cartas do baralho de Sorte & Revés
*/
int embaralhaCartas(vector<SORTE_REVES> &cartas) {
    vector<SORTE_REVES> embaralhado;
    int pos;

    while (!cartas.empty()) {
        pos = randint(cartas.size());
        embaralhado.push_back(cartas.at(pos));
        cartas.erase(cartas.begin() + pos);
    }
    while (!embaralhado.empty()) {
        pos = randint(embaralhado.size());
        cartas.push_back(embaralhado.at(pos));
        embaralhado.erase(embaralhado.begin() + pos);
    }
    
    return 1; // Success
}

/*
É chamada para realizar a ação de uma carta Sorte & Revés baseada no seu tipo (0 a 2)
Sendo:

0 - O player vai perder uma quantia randômica de dinheiro
1 - O player vai ganhar uma quantia randômica de dinheiro
2 - O player vai receber um passe Habeas Corpus
*/
void acao_sorteReves(vector<SORTE_REVES> &cartas, vector<PLAYER> &players) {

    mostrar_card_sorte_reves(cartas);

    if (cartas.front().tipo == 0) {
        int valor_perde = randint(100000);
        players.front().carteira -= valor_perde;
        cout << "\nPlayer " << players.front().nome << " perdeu R$ " << valor_perde << endl;
        cout << "Saldo de " << players.front().nome << ": R$ " << players.front().carteira << endl;
    } else if (cartas.front().tipo == 1) {
        int valor_ganha = randint(100000);
        players.front().carteira += valor_ganha;
        cout << "\nPlayer " << players.front().nome << " recebeu R$ " << valor_ganha << endl;
        cout << "Saldo de " << players.front().nome << ": R$ " << players.front().carteira << endl;
    } else if (cartas.front().tipo == 2) {
        players.front().habeas = true;
        cout << "\nPlayer " << players.front().nome << " foi concedido com saida livre da prisao sem a necessidade de pagar dividas!" << endl;
    }
    embaralhaCartas(cartas);
    verificarFalenciaPlayer(players);
}

/*
Gera uma pilha de cartas Sorte & Revés (não embaralhada)
*/
void loadSorteReves(vector<SORTE_REVES> &cartas, int quant)  {
	for (int i=0; i<quant; i++) {
		SORTE_REVES card;
        card.tipo = randint(3);
		card = criar_card_sr(card.tipo);
		cartas.push_back(card);
	}
}

/*
Essa função não será utilizada ao longo do jogo.
Serve apenas para verificar se as cartas estão sendo geradas de forma aleatória com tipos entre 0 e 2
*/
void mostrarBaralho(vector<SORTE_REVES> &cartas) {
    for (int i=0; i<cartas.size(); i++) {
        cout << "Tipo carta " << (i+1) << ": " << cartas.at(i).tipo << endl;
    }
    cout << endl;
}