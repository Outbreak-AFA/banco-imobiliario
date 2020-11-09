#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct no{
    int dados;
    struct no *prox;
} NO;
typedef struct{
    NO *ini;
    NO *fim;
}FILA;

FILA* cria_fila(){
    FILA *fi = (FILA*) malloc(sizeof(FILA));
    if(fi != NULL){ // Deu certo a alocação
        fi->fim = NULL;
        fi->ini = NULL;
    }
    return fi;
}


int fila_vazia(FILA *f){
    if(f==NULL || f->ini==NULL) return 1;
    return 0;
}

int enfileira(FILA *f, int num){
    if(f==NULL) return 0;
    NO *novo_no = (NO*)malloc(sizeof(NO));
    if(novo_no == NULL) return 0;
        novo_no->dados = num;
        novo_no->prox = NULL;
    if(f->ini == NULL){ // Fila vazia, inserir no início
        f->ini = novo_no;
        f->fim = novo_no;
    }else{
        f->fim->prox = novo_no;
        f->fim = novo_no;
    }
    return 1;
}

int desenfileira(FILA *f, int num){
    if(fila_vazia(f)) return 0;
    NO *aux = f->ini;
    if (aux > f->ini->prox) {
        //f->ini = aux->prox;
        free(aux);
    }
    return 1;
}

// mesclar com a struct do jogador ???
void imprimeJogador(int player_count, FILA*f) {
    NO *aux = f->ini;
    cout << endl;
    for (int i=0; i<player_count; i++) {
        cout << "===== Jogador " << i+1 << " =====" << endl;
    }
}