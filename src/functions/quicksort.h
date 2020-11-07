#include<stdio.h>
#include "lista.h"

/*
int main(){   
   int vetor[13] = {7, 1, 4, 3, 18, 6, 9, 2, 10, 5, 0, 21, 16};
         
   Quick(vetor, 0, 12);
   printVetor(vetor, 13);
}
*/

void Quick(LISTA *l, int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = l->dados[meio];
   
   do{
      while (l->dados[i] < pivo) i = i + 1;
      while (l->dados[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = l->dados[i];
         l->dados[i] = l->dados[j];
         l->dados[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quick(l, inicio, j);
   if(i < fim) Quick(l, i, fim);   
}
