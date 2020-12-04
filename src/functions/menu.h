int instrucoes() {

// Menu do jogo 
    printf("\n");
	printf("Objetivo do jogo: Tornar-se o mais rico jogador, atraves de compra, aluguel ou venda de propriedades.\n");
		printf("\n\n");
	printf("\033[32mRegras do Jogo Banco Imobiliario\n\033[0m");
    printf(" - Podem jogar de 2 a 4 pessoas. \n");
    printf(" - Todos os jogadores devem comecar o jogo com uma quantia de R$ 200000.\n");
        printf("\n\n\n");
    printf("\033[32mCOMO JOGAR?\n\033[0m");  // Instrucoes
    printf("1-Todos os jogadores devem jogar os dados para saber a ordem de jogada, devera ser organizado em ordem decrescente.\n");
    printf("2-O jogador que cair nas companhias tera que pagar ao banco.");
    printf("3-Caso caia em um terreno sem proprietario, podera comprar pagando o valor indicado ao banco.\n");
    printf("4-Se a propriedade possuir dono, devera pagar o aluguel ao proprietario.\n");
    printf("5-Ao cair em uma casa de Sorte & Reves, o jogador tera que receber uma carta e executar a ordem que nela contem .\n");
    printf("6-O jogador que cair na casa 'Va para detencao', precisara se dirigir a 'detencao'. \n");
    printf("6- Para sair da detencao, o jogador necessita tirar numeros iguais nos dados, esperar 3 rodadas ou caso possua o cartao 'Saida livre da detencao'.\n");
    printf("7-Ao alcancar o 'start', todas as vezes os jogadores deverao receber o valor de R$ 200000.\n");
	printf("8-Cada terreno pode-se construir mais de uma casa .\n");
    printf("9-Apos declarar falencia, o jogador sera retirado do jogo.\n");
    printf("10-Durante o jogo, nenhum jogador podera dar ou emprestar dinheiro para outro jogador.\n");
    printf("11-O jogo termina quando sobra somente um jogador que nao foi a falencia.  \n");
        printf("\n\n");
}

void creditos() {
    printf("\033[32mCREDITOS\n\033[0m");
        printf("\n");
    printf("Disciplina: Algoritmo e Estrutura de Dados\n\n");

    printf("\033[35mEstudantes:\n\033[0m");
	printf("Amanda Rigaud\n");
    printf("Antonio Cesar\n");
    printf("Felipe Ribeiro\n");
    	printf("\n\n");
    printf("\033[35mDocente: \033[0mMarcos Lapa\n");
        printf("\n\n\n");
}



int escolhas() {
    vector<PLAYER> players_ranking;
    int OPC;
    printf("Escolha uma das opcoes abaixo!\n");
    printf("[1] Iniciar Jogo\n");
    printf("[2] Como Jogar\n");
    printf("[3] Ranking de Vencedores\n");
    printf("[4] Creditos\n");
    printf("[5] Sair do Jogo\n");

    scanf("%d", &OPC);

    // Essa opcao e para a pessoa sair do jogo
	switch(OPC){
		case 1:
            printf("Certo! Tenham um bom jogo! :D\n");
            return 0;
		case 2:
            instrucoes();
            pause();
			break; 
		case 3:
            getRanking(players_ranking);
            mostraRanking(players_ranking);
            pause();
			break; 
		case 4:
            creditos();
            pause();
			break; 
		case 5:
			printf("O programa foi fechado! Tchau!\n");
            pause();
			clear();	// Essa funcao e para limpar tela
            exit(0); // Finalizou com sucesso!
        default:
            escolhas();
    }
    clear();
    escolhas();
}