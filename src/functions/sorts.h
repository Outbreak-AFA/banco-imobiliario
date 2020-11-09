// #include <stdlib.h>
// #include <stdio.h>
// #include "./src/estruturas/filaencadeada.h"
// #include <vector>

// struct genérica para teste
// typedef struct player
// {
//     char nome[30];
//     double carteira;
// } PLAYER;

void quickSort(vector<PLAYER> &vetor, int inicio, int fim)
{
    int i, j, meio;
    double pivo;
    PLAYER aux;
    i = inicio;
    j = fim;
    meio = (int)((i + j) / 2);
    pivo = vetor.at(meio).carteira;

    do
    {
        while (vetor.at(i).carteira < pivo)
            i = i + 1;
        while (vetor.at(j).carteira > pivo)
            j = j - 1;

        if (i <= j)
        {
            aux = vetor.at(i);
            vetor.at(i) = vetor.at(j);
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    } while (j > i);

    if (inicio < j)
        quickSort(vetor, inicio, j);
    if (i < fim)
        quickSort(vetor, i, fim);
}

void quickSortSorteioInicial(vector<PLAYER> &vetor, int inicio, int fim)
{
    int i, j, meio;
    double pivo;
    PLAYER aux;
    i = inicio;
    j = fim;
    meio = (int)((i + j) / 2);
    pivo = vetor.at(meio).resultado_dados;

    do
    {
        while (vetor.at(i).carteira < pivo)
            i = i + 1;
        while (vetor.at(j).carteira > pivo)
            j = j - 1;

        if (i <= j)
        {
            aux = vetor.at(i);
            vetor.at(i) = vetor.at(j);
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    } while (j > i);

    if (inicio < j)
        quickSort(vetor, inicio, j);
    if (i < fim)
        quickSort(vetor, i, fim);
}