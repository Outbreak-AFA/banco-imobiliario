#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 30


typedef struct lista{
int cont;
int dados[MAX];

} LISTA;

LISTA* criarLista(){

LISTA *l;
l = (LISTA*)malloc(sizeof(LISTA));
if(l != 0){
l->cont = 0;

}
return l;

}

void destruirLista(LISTA* l){

free(l);

}

int listaVazia(LISTA* l){

if(l == 0) return -1;
else return l->cont == 0;

}

int listaCheia(LISTA* l){

if(l == 0) return -1;
else return l->cont == MAX;

}

int inserirNoFinal(LISTA* l, int num){

if(l==0) return 0;
if(listaCheia(l)) return 0;
l->dados[l->cont] = num;
l->cont++;
return 1;

}

int inserirNoInicio(LISTA* l, int num){

int i;
if(l==0) return 0;
if(listaCheia(l)) return 0;
for(i=l->cont-1; i>=0; i--){

l->dados[i+1] = l->dados[i];

}
l->dados[0] = num;
l->cont++;
return 1;

}

int inserirNoMeio(LISTA* l, int num, int posicao){
	int i;
	if(l==0) return 0;
	if(listaCheia(l)) return 0;
	for(i=l->cont-1; i>=posicao; i--){
		l->dados[i+1] = l->dados[i];

	}
	l->dados[posicao] = num;
	l->cont++;
	return 1;
