
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