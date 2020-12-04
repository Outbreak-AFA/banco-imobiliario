using namespace std;

void sortearJogadores(vector<PLAYER> &players) {
    vector<PLAYER> aux;
    vector<int> resultados;
    int tamanho = players.size();

    while(1) {
        tamanho = players.size();
        if (players.empty()) break;

        for (int i=0; i < tamanho && tamanho > 1; i++) {
            cout << "Jogador(a) " << players.at(i).nome << " vai lancar os dados!" << endl;
            Sleep(1000); // esperar 1 segundo

            int valor_dados = mostrarDados();
            cout << "Jogador(a) " << players.at(i).nome << " tirou " << valor_dados << "! :D" << endl;
            players.at(i).resultado_dados = valor_dados;
            resultados.push_back(valor_dados);
            cout << endl << players.at(i).resultado_dados << endl;
            Sleep(1000);
        }

        // Ordena resultados
        sortResults(resultados);

        if (resultados.at(0) == resultados.at(1)) {
            clear();
            cout << "\nOpa! Pessoas tiraram o mesmo valor!. Sorteando novamente..." << endl;
            Sleep(1000);
        }
        else {
            ordenarResultados(players);
            cout << players.back().nome << " entrou na fila!" << endl;
            aux.push_back(players.back());
                    
            // Remove da lista o jogador com maior resultado
            players.pop_back();
        }
    }

    players = aux;

}

void verificarOrdemPlayers(vector<PLAYER> &players) {
    cout << endl << "Ordem: ";
    printVet(players);
}