using namespace std;

void sortearJogadores(vector<PLAYER> &players) {

    vector<PLAYER> aux_vet, temp;

    int vet_len = players.size();
    int temp_len = temp.size();
 
    for (int i=0; i < vet_len; i++) {
        cout << "Jogador(a) " << players.at(i).nome << " vai lancar os dados!" << endl;
        Sleep(1000); // esperar 1 segundo

        int valor_dados = mostrarDados();
        cout << "Jogador(a) " << players.at(i).nome << " tirou " << valor_dados << "! :D" << endl;
        players.at(i).resultado_dados = valor_dados;
        cout << endl << players.at(i).resultado_dados << endl;
        system("pause");

        if (i==1 && (players.at(i).resultado_dados == players.at(i-1).resultado_dados)) {
            cout << "\nResultados repetidos. Sorteando novamente..." << endl;
            i = 0;
        }
        if (i==2 && (players.at(i).resultado_dados == players.at(i-1).resultado_dados || (players.at(i).resultado_dados == players.at(i-2).resultado_dados))) {
            cout << "\nResultados repetidos. Sorteando novamente..." << endl;
            i = 1;
        }
        if (i==3 && (players.at(i).resultado_dados == players.at(i-1).resultado_dados || (players.at(i).resultado_dados == players.at(i-2).resultado_dados) || (players.at(i).resultado_dados == players.at(i-3).resultado_dados))) {
            cout << "\nResultados repetidos. Sorteando novamente..." << endl;
            i = 2;
        }
        if (i==4 && (players.at(i).resultado_dados == players.at(i-1).resultado_dados || (players.at(i).resultado_dados == players.at(i-2).resultado_dados) || (players.at(i).resultado_dados == players.at(i-3).resultado_dados) || (players.at(i).resultado_dados == players.at(i-4).resultado_dados))) {
            cout << "\nResultados repetidos. Sorteando novamente..." << endl;
            i = 3;
        }

    }

    /*
    Manipulando a fila de Players.

    1 - Os players são ordenados baseado nos seus resultados tirados nos dados lançados
    2 - Os players são enfileirados em uma fila auxiliar
    3 - A fila anterior é limpa
    4 - Os players são enfileirados de forma contrária na fila original
    */
    ordenarResultados(players);
    aux_vet = players;
    players.clear();
    for (int i=aux_vet.size()-1; i>=0; i--) {
        players.push_back(aux_vet.at(i));
    }
}

void verificarOrdemPlayers(vector<PLAYER> &players) {
    cout << endl << "Ordem: ";
    printVet(players);
}