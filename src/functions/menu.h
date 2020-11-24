
// #include <stdio.h>
// #include <time.h>      
// #include <conio.h>
// #include <stdlib.h>
// #include <ctype.h>
int instrucoes() {
	int OPC;

// Menu do jogo 
	printf("Objetivo do jogo:Tornar-se o mais rico jogador, atraves de compra, aluguel ou venda de propriedades.\n");
	printf("\n");
	printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
	printf("Regras do Jogo Banco Imobiliario\n");
    printf("Podem jogar de 2 a 4 pessoas, as quais escolheram a cor de seus pinos. \n");
    printf("Todos os jogadores devem comecar o jogo com uma quantia de $200.000.\n");
        printf("\n");
        printf("\n");
	printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
    printf("COMO JOGAR?\n");  // Instrucoes
    printf("1-Todos os jogadores devem jogar os dados para saber a ordem de jogada, devera ser organizado em ordem decrescente.\n");
    printf("2-O jogador que cair nas companhias tera que pagar ao banco.");
    printf("3-Caso caia em um terreno sem proprietario, podera comprar pagando o valor indicado ao banco.\n");
    printf("4-Se a propriedade possuir dono, devera pagar o aluguel ao proprietario.\n");
    printf("5-Ao cair em uma casa de sorte / reves, o jogador tera que receber uma carta e executar a ordem que nela contem .\n");
    printf("6-O jogador que cair na casa 'Va para detencao', precisara se dirigir a 'detencao'. \n");
    printf("6- Para sair da detencao, o jogador necessita tirar numeros iguais nos dados, esperar 3 rodadas ou caso possua o cartao 'Saida livre da detencao'.\n");
    printf("7-Ao alcancar o 'start', todas as vezes os jogadores deverao recero valor de $200.000.\n");
    printf("8-So conseguira construir uma casa, quando tiver o comjunto de cores completo.\n");
    printf("9-Cada terreno pode-se construir ate 4 casas ou 1 hotel.\n");
    printf("10-O jogador devera colocar uma casa em cada terreno do grupo de mesma cor antes do colocar a segunda.\n");
    printf("11-Se mesmo apos vender suas casa e hoteis, hipotecar suas propriedades o jogador nao conseguir pagar sua divida, o mesmo ira se retirar do jogo.\n");
    printf("12-Durante o jogo, nenhum jogador podera dar ou emprestar dinheiro para outro jogador.\n");
    printf("13-O jogo termina quando sobra somente um jogador que nao foi a falencia.  \n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
    printf("CREDITOS\n");
        printf("\n");
        printf("\n");
        printf("\n");
    printf("Disciplina: Algoritmo e Estrutura de Dados\n");
        printf("\n");
        printf("\n");
    printf("Estudantes:\n");
    printf("Amanda Rigaud\n");
    printf("Antonio Cesar\n");
    printf("Felipe Ribeiro\n");
    	printf("\n");
	printf("\n");
    printf("Docente: Marcos Lapa\n");
        printf("\n");
        printf("\n");
        printf("\n");   
        
// Momento da decisao(se ira jogar ou nao)
    printf("Digite 1 para continuar o jogo...\n");
	printf("Digite 2 para sair...\n");
	scanf("%d", &OPC);
	
// Essa opcao e para a pessoa sair do jogo
	switch(OPC){
	
		case 2:
			printf("O programa foi fechado!\n");
			system("cls");	// Essa funcao e para limpar tela
            system("pause");
			return 0;
		case 1:		// chamando as funcoes que fazem o jogo acontecer 
			break; 
    }
}

/*int main(){
    instrucoes();
    return 0;
}*/

