
// struct com todos os atributos de um player 
using namespace std;
typedef struct players{         
    int id;
	char pino;
    string nome;
    int resultado_dados;
	char *posicao;
	int celula; // unidade do tabuleiro
    long double carteira;
    bool habeas; //sorte ou reves
	int detencao; //quantidade de partidas sem jogas
    bool falencia;
} PLAYER;

void loadPlayers(vector<PLAYER> &players) {
	int quant = 0;
	while ((quant < 2) || (quant > 4)) {
		cout << "Quantos jogadores teremos na partida?" << endl;
		cout << "\x1b[31m[!] \033[34mMinimo permitido: 2 jogadores. Maximo permitido: 4 jogadores.\033[0m" << endl;
		cin >> quant;
		if (quant >= 2 && quant <=4) {
			break;
		}
	}

	// criando os players
	for (int i=0; i<quant; i++) {
		PLAYER p;
		cout << "Nome player " << (i+1) << ": "; cin >> p.nome;
		cout << "Character do player " << (i+1) << ": "; cin >> p.pino;
		p.carteira = 400000.0;
		p.id = i+1;
		p.celula = 0;
		p.detencao = 0;
		p.habeas = false;
		p.falencia = false;
		if (p.id == 1) p.posicao = casas_player1[0].posicao;
		else if (p.id == 2) p.posicao = casas_player2[0].posicao;
		else if (p.id == 3) p.posicao = casas_player3[0].posicao;
		else if (p.id == 4) p.posicao = casas_player4[0].posicao;
		*(p.posicao) = p.pino;
		players.push_back(p);
	}
}

void verificarFalenciaPlayer(vector<PLAYER> &players) {
	if (players.front().carteira <= 0) {
		players.front().falencia = true;
		cout << "\x1b[31mPlayer " << players.front().nome << " atingiu um valor menor ou igual a zero em sua carteira!" << endl;
		cout << "\x1b[31mE declarada a falencia de player " << players.front().nome << "!" << endl;
		cout << "\x1b[31m[!] \033[34mPlayer \033[0m" << players.front().nome << " \033[34mfoi removide do jogo :(\033[0m" << endl;
		*players.front().posicao = ' ';
		players.erase(players.begin());

	}
}


void start(vector<PLAYER> &players){
	long double valor = 200000.00;
	cout << "Player " << players.front().nome << " recebeu $ " << valor << "!" << endl;
	players.front().carteira += valor;
}


void atualizaMapa(vector<PLAYER> &players, char *antigo, char *atual) {
	*antigo = ' ';
	*atual = players.front().pino;
	players.front().posicao = atual;
}

void mudaMapa(vector<PLAYER> &players) {
	if (players.front().id == 1) {
		// muda o mapa de acordo com as posições do jogador 1
		for (int pos = 0; pos < 28; pos++) {
			if (players.front().celula == pos) {
				atualizaMapa(players, players.front().posicao, casas_player1[pos].posicao);
				break;
			}
		}
	}
	else if (players.front().id == 2) {
		// muda o mapa de acordo com as posições do jogador 2
		for (int pos = 0; pos < 28; pos++) {
			if (players.front().celula == pos) {
				atualizaMapa(players, players.front().posicao, casas_player2[pos].posicao);
				break;
			}
		}
	}
	else if (players.front().id == 3) {
		// muda o mapa de acordo com as posições do jogador 3
		for (int pos = 0; pos < 28; pos++) {
			if (players.front().celula == pos) {
				atualizaMapa(players, players.front().posicao, casas_player3[pos].posicao);
				break;
			}
		}
	}
	else if (players.front().id == 4) {
		// muda o mapa de acordo com as posições do jogador 4
		for (int pos = 0; pos < 28; pos++) {
			if (players.front().celula == pos) {
				atualizaMapa(players, players.front().posicao, casas_player4[pos].posicao);
				break;
			}
		}
	}
}



void movePlayer(vector<PLAYER> &players) {
	cout << players.front().nome << " ira jogar os dados!" << endl;
	int dados = mostrarDados();
	players.front().celula += dados;
	if (players.front().celula > 27) {
		players.front().celula %= 28;
		if (players.front().celula > 0) start(players); // passou pelo start
	}
	mudaMapa(players);
}

void nextPlayer(vector<PLAYER> &players) {
	vector<PLAYER> aux;
	for (int i = 1; i < players.size(); i++) {
		aux.push_back(players.at(i));
	}
	aux.push_back(players.at(0));
	players = aux;
}

/*
Verifica se todos os players do jogo atingiram a falência.
*/
int falenciaGeral(vector<PLAYER> &players) {
	if (players.size() == 1) return 1;
	else return 0;
}
