#include <stdlib.h>
#include <stdio.h>
#include "./src/estruturas/filaencadeada.h"


void simple_sort(int vetor[], int player_count) {
    vetor[player_count];
    int ordenado = 0;
    while(ordenado == 0) { 
     
    ordenado = 1;
     
    for(int i=1; i < player_count; i++) { 
        if(vetor[i] < vetor[i+1]) {
            int tmp = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = tmp;
            ordenado = 0;
            }
        }
    }
}