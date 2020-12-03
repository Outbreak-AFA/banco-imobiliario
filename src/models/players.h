// Aqui haverá a strcuct e funções voltadas para players

// struct genérica para teste 
using namespace std;
typedef struct players{         
    int id;
    string nome;
    int resultado_dados;
	char *posicao;
    long double carteira;
    bool habeas; //sorte ou reves
    bool falencia;
} PLAYER;

PLAYER criar_player(int id, string nome, long double carteira) {
    PLAYER p;
    p.id = id;
    p.nome = nome;
    p.carteira = carteira;
    p.habeas = false;
    p.falencia = false;
    return p;
}


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
	for (int i=0; i<quant; i++) {
		PLAYER p;
		cout << "Nome player " << (i+1) << ": "; cin >> p.nome;
		p.carteira = 0.0;
		p.id = i+1;
		p = criar_player(p.id, p.nome, p.carteira);
		players.push_back(p);
	}
}

void verificarFalenciaPlayer(vector<PLAYER> &players) {
	if (players.front().carteira <= 0) {
		players.front().falencia = true;
		cout << "\x1b[31mPlayer " << players.front().nome << " atingiu um valor menor ou igual a zero em sua carteira!" << endl;
		cout << "\x1b[31mE declarada a falencia dx player " << players.front().nome << "!" << endl;
		if (players.front().falencia) {
			cout << "\x1b[31m[!] \033[34mPlayer \033[0m" << players.front().nome << " \033[34mfoi removidx do jogo :(\033[0m" << endl;
			players.pop_back();

		}
	}
}

// int MAPA(int tabuleiro){
	
// 	casas[0].posicao = &TABULEIRO[55][112]; //start        
// 	casas[1].posicao = &TABULEIRO[55][95];
// 	casas[2].posicao = &TABULEIRO[55][82];      
// 	casas[3].posicao = &TABULEIRO[55][69];
// 	casas[4].posicao = &TABULEIRO[55][56];
// 	casas[5].posicao = &TABULEIRO[55][43];
// 	casas[6].posicao = &TABULEIRO[55][30];
// 	casas[7].posicao = &TABULEIRO[55][17];//detencao
// 	casas[8].posicao = &TABULEIRO[46][17];
// 	casas[9].posicao = &TABULEIRO[40][17];
// 	casas[10].posicao = &TABULEIRO[34][17];
// 	casas[11].posicao = &TABULEIRO[27][17];
// 	casas[12].posicao = &TABULEIRO[21][17];
// 	casas[13].posicao = &TABULEIRO[15][17];
// 	casas[14].posicao = &TABULEIRO[9][17];//ferias
// 	casas[15].posicao = &TABULEIRO[9][30];
// 	casas[16].posicao = &TABULEIRO[9][43]; 
// 	casas[17].posicao = &TABULEIRO[9][56];
// 	casas[18].posicao = &TABULEIRO[9][69];
// 	casas[19].posicao = &TABULEIRO[9][82];
// 	casas[20].posicao = &TABULEIRO[9][95];
// 	casas[21].posicao = &TABULEIRO[9][112];  //va para cadeia
// 	casas[22].posicao = &TABULEIRO[15][112];
// 	casas[23].posicao = &TABULEIRO[21][112];
// 	casas[24].posicao = &TABULEIRO[27][112];
// 	casas[25].posicao = &TABULEIRO[34][112];
// 	casas[26].posicao = &TABULEIRO[40][112];
// 	casas[27].posicao = &TABULEIRO[46][112];
// }

// void start(vector<PLAYER> &players){
// 	long double valor = 200000.00;
// 	for (int i=0; i<players.size(); i++) {
// 		if (strcmp(players.at(i).posicao, casas[0].posicao) == 0) {
// 			cout << "Player " << players.at(i).nome << " recebeu R$ " << valor << "!" << endl;
// 			players.at(i).carteira += valor;
// 		}
// 	}
// }

// refatorar
// int MOVIMENTACAO(vector<PLAYER> &players, int start) {
// 	int valorDados = mostrarDados();
// 	int cont1, cont2 = 0;
// 	cout << "Player " << players.front().nome << " tirou o valor " << valorDados << "! :D" << endl;
// 	cont1 = valorDados;
// 	cont2 += cont1;
// 	for(cont2=0;cont2<=27;cont2++){
// 		players.front().nome->casas[cont2]; // modificar 
// 	}
// }