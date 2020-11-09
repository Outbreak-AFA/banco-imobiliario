#include <iostream>

/*
Caso seu peão pare na casa Sorte ou Revés, você deve pegar a primeira carta do monte, 
cumprir o que ela indica e a devolver para o final do monte após concluir a tarefa.

Se a carta sorteada informar Habeas Corpus ou Compra Livre, você deve guardá-la para usar depois. 
Ela pode ser utilizada em qualquer momento que você deseja. Após utilizada, 
deve ser retornada ao final do monte.

A carta Habeas Corpus te dá o direito de saída livre da prisão sem a necessidade de tirar 
uma dupla nos dados ou pagar fiança.
*/

typedef struct {
    char tipo_sr[15]; // tipo sorte ou tipo revés
    
} SORTE_REVES;