
// Ordena com base na carteira, é usanda no Ranking (ANTIGO)
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

//////////////////////////////////////////////////////////////////////

void printVet(vector<PLAYER> &v){

	int i;
    int len = v.size();
	for(i = 0; i<len; i++) {
		cout << v.at(i).nome << " ";
	}
	cout << endl;
}

// Bubble Sort
void ordenarResultados(vector<PLAYER> &v) {
	int i, j, trocou=1;
    PLAYER aux;

    int vet_len = v.size();
	for (i=0; i<vet_len-1 && trocou; i++) {
		trocou=0; /* inicialmente nenhuma troca foi feita */
		for (j=0; j<vet_len-1-i; j++){
		   if (v.at(j).resultado_dados > v.at(j+1).resultado_dados) {
			trocou=1; /* houve troca */
			aux = v.at(j);
			v.at(j) = v.at(j+1);
			v.at(j+1) = aux;
		   }
		}
	}
}

// Bubble Sort
void sortResults(vector<int> &v) {
	int i, j, trocou=1;
    int aux;

    int vet_len = v.size();
	for (i=0; i<vet_len-1 && trocou; i++) {
		trocou=0; /* inicialmente nenhuma troca foi feita */
		for (j=0; j<vet_len-1-i; j++){
		   if (v.at(j) < v.at(j+1)) {
			trocou=1; /* houve troca */
			aux = v.at(j);
			v.at(j) = v.at(j+1);
			v.at(j+1) = aux;
		   }
		}
	}
}