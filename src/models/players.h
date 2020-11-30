// Aqui haverá a strcuct e funções voltadas para players

// struct genérica para teste
#define MAX 4
tabuleiro casas[32];
typedef struct{         
    int id;
    char nome[4][20];      
    int resultado_dados;
    long double carteira;
    char *posicao1, *posicao2, *posicao3, *posicao4;
    bool habeas; //sorte ou reves
    bool falencia;
} PLAYER;

PLAYER criar_player(int id, char *nome, long double carteira) {
    PLAYER p;
    p.id = id;
    strcpy(p.nome, nome);
    p.carteira = carteira;
    p.habeas = false;
    p.falencia = false;
    return p;
}



int nome_jogador(vector<PLAYER> &players){ //vector==fila
	int x, i;
	cout << "Quantos pessoas?/n";
	cin >> i;
	
		if(i>=2 && i<=4){
			for(x=0;x<=i;x++){
				PLAYER p;
				cout<<"nome:";
				cin>>p.nome;
				p=criar_player(x+1, p.nome);
				players.push_back(p);
			}
		}else{
			cout<<"A quantidade permitida de players e de 2 a 4! "<<endl;
		}


}


 // jogadas de cada jogador       
int jogadas(int sortearJogadores){

	
}

int MAPA(){
//player1
	casas[0].posicao1 = &TABULEIRO[55][112]; //start        
	casas[1].posicao1 = &TABULEIRO[55][95];
	casas[2].posicao1 = &TABULEIRO[55][82];      
	casas[3].posicao1 = &TABULEIRO[55][69];
	casas[4].posicao1 = &TABULEIRO[55][56];
	casas[5].posicao1 = &TABULEIRO[55][43];
	casas[6].posicao1 = &TABULEIRO[55][30];
	casas[7].posicao1 = &TABULEIRO[55][17];//detencao
	casas[8].posicao1 = &TABULEIRO[46][17];
	casas[9].posicao1 = &TABULEIRO[40][17];
	casas[10].posicao1 = &TABULEIRO[34][17];
	casas[11].posicao1 = &TABULEIRO[27][17];
	casas[12].posicao1 = &TABULEIRO[21][17];
	casas[13].posicao1 = &TABULEIRO[15][17];
	casas[14].posicao1 = &TABULEIRO[9][17];//ferias
	casas[15].posicao1 = &TABULEIRO[9][30];
	casas[16].posicao1 = &TABULEIRO[9][43]; 
	casas[17].posicao1 = &TABULEIRO[9][56];
	casas[18].posicao1 = &TABULEIRO[9][69];
	casas[19].posicao1 = &TABULEIRO[9][82];
	casas[20].posicao1 = &TABULEIRO[9][95];
	casas[21].posicao1 = &TABULEIRO[9][112];  //va para cadeia
	casas[22].posicao1 = &TABULEIRO[15][112];
	casas[23].posicao1 = &TABULEIRO[21][112];
	casas[24].posicao1 = &TABULEIRO[27][112];
	casas[25].posicao1 = &TABULEIRO[34][112];
	casas[26].posicao1 = &TABULEIRO[40][112];
	casas[27].posicao1 = &TABULEIRO[46][112];
	
//player 2
	casas[0].posicao2 = &TABULEIRO[55][97]; //start       
	casas[1].posicao2 = &TABULEIRO[55][84];
	casas[2].posicao2 = &TABULEIRO[55][71];
	casas[3].posicao2 = &TABULEIRO[55][58];
	casas[4].posicao2 = &TABULEIRO[55][45];
	casas[5].posicao2 = &TABULEIRO[55][32];
	casas[6].posicao2 = &TABULEIRO[55][19];
	casas[7].posicao2 = &TABULEIRO[55][2];//detencao
	casas[8].posicao2 = &TABULEIRO[46][2];
	casas[9].posicao2 = &TABULEIRO[40][2];
	casas[10].posicao2 = &TABULEIRO[34][2];
	casas[11].posicao2 = &TABULEIRO[27][2];
	casas[12].posicao2 = &TABULEIRO[21][2];
	casas[13].posicao2 = &TABULEIRO[15][2];
	casas[14].posicao2 = &TABULEIRO[9][2];//ferias
	casas[15].posicao2 = &TABULEIRO[9][19];	
	casas[16].posicao2 = &TABULEIRO[9][32];
	casas[17].posicao2 = &TABULEIRO[9][45];
	casas[18].posicao2 = &TABULEIRO[9][58];
	casas[19].posicao2 = &TABULEIRO[9][71];
	casas[20].posicao2 = &TABULEIRO[9][84];
	casas[21].posicao2 = &TABULEIRO[9][97];// va para cadeia
	casas[22].posicao2 = &TABULEIRO[15][97];
	casas[23].posicao2 = &TABULEIRO[21][97];
	casas[24].posicao2 = &TABULEIRO[27][97];
	casas[25].posicao2 = &TABULEIRO[34][97];
	casas[26].posicao2 = &TABULEIRO[40][97];
	casas[27].posicao2 = &TABULEIRO[46][97];	
	
	//player 3
	casas[0].posicao3 = &TABULEIRO[48][97]; //start        
	casas[1].posicao3 = &TABULEIRO[48][84];
	casas[2].posicao3 = &TABULEIRO[48][71];
	casas[3].posicao3 = &TABULEIRO[48][58];
	casas[4].posicao3 = &TABULEIRO[48][45];
	casas[5].posicao3 = &TABULEIRO[48][32];
	casas[6].posicao3 = &TABULEIRO[48][19];
	casas[7].posicao3 = &TABULEIRO[48][2];//detencao
	casas[8].posicao3 = &TABULEIRO[42][2];
	casas[9].posicao3 = &TABULEIRO[36][2];
	casas[10].posicao3 = &TABULEIRO[29][2];
	casas[11].posicao3 = &TABULEIRO[23][2];
	casas[12].posicao3 = &TABULEIRO[17][2];
	casas[13].posicao3 = &TABULEIRO[11][2];
	casas[14].posicao3 = &TABULEIRO[2][2];//ferias
	casas[15].posicao3 = &TABULEIRO[2][19];
	casas[16].posicao3 = &TABULEIRO[2][32];  
	casas[17].posicao3 = &TABULEIRO[2][45];
	casas[18].posicao3 = &TABULEIRO[2][58];
	casas[19].posicao3 = &TABULEIRO[2][71];
	casas[20].posicao3 = &TABULEIRO[2][84];
	casas[21].posicao3 = &TABULEIRO[2][97];// va para cadeia
	casas[22].posicao3 = &TABULEIRO[11][97];
	casas[23].posicao3 = &TABULEIRO[17][97];
	casas[24].posicao3 = &TABULEIRO[23][97];
	casas[25].posicao3 = &TABULEIRO[29][97];
	casas[26].posicao3 = &TABULEIRO[36][97];
	casas[27].posicao3 = &TABULEIRO[42][97];	
	
	//player4	
	casas[0].posicao4 = &TABULEIRO[48][112]; //start        
	casas[1].posicao4 = &TABULEIRO[48][95];
	casas[2].posicao4 = &TABULEIRO[48][82];
	casas[3].posicao4 = &TABULEIRO[48][69];
	casas[4].posicao4 = &TABULEIRO[48][56];   
	casas[5].posicao4 = &TABULEIRO[48][43];
	casas[6].posicao4 = &TABULEIRO[48][30];
	casas[7].posicao4 = &TABULEIRO[48][17];//detencao
	casas[8].posicao4 = &TABULEIRO[42][17];
	casas[9].posicao4 = &TABULEIRO[36][17];
	casas[10].posicao4 = &TABULEIRO[29][17];
	casas[11].posicao4 = &TABULEIRO[23][17];
	casas[12].posicao4 = &TABULEIRO[17][17];
	casas[13].posicao4 = &TABULEIRO[11][17];
	casas[14].posicao4 = &TABULEIRO[2][17]; //ferias
	casas[15].posicao4 = &TABULEIRO[2][30];	
	casas[16].posicao4 = &TABULEIRO[2][43];  
	casas[17].posicao4 = &TABULEIRO[2][56];
	casas[18].posicao4 = &TABULEIRO[2][59];
	casas[19].posicao4 = &TABULEIRO[2][82];
	casas[20].posicao4 = &TABULEIRO[2][95];
	casas[21].posicao4 = &TABULEIRO[2][112];// va para cadeia
	casas[22].posicao4 = &TABULEIRO[11][112];
	casas[23].posicao4 = &TABULEIRO[17][112];
	casas[24].posicao4 = &TABULEIRO[23][112];
	casas[25].posicao4 = &TABULEIRO[29][112];
	casas[26].posicao4 = &TABULEIRO[36][112];
	casas[27].posicao4 = &TABULEIRO[42][112];
}
	



int start(vector<PLAYER> &players){
	MAPA();
	int carteira;
	char nome;
	nome->casas[0];
	while(nome->casas[0]){
		carteira=carteira+200.000;
	}
	
}

int CARTEIRA (vector<PLAYER> &players){
	int carteira; 
	int i;
	for(i>0;i<=4;i++){
		nome[i].carteira=200.000;
	}
	if(carteira<=0){
		printf("o player faliu\n");	  
	}
}


int MOVIMENTACAO(int start){
	mostrarDados();
	int cont1, cont2=0;
	cont1=mostrarDados;
	cont2= cont2+cont1;
	for(cont2=0;cont2<=27;cont2++){
		nome->casas[cont2];
		
		
	}
}