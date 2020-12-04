void sairDaDetencao(vector<PLAYER> &players) {
    if (players.front().habeas == true) {
        players.front().habeas = false;
        players.front().detencao = 0;
        cout << players.front().nome << " utilizou a carta Habeas Corpus para sair da detencao!" << endl;
    }
}

void vaParaDetencao(vector<PLAYER> &players) {
    players.front().celula = 7;
    if(players.front().id == 1) atualizaMapa(players, players.front().posicao, casas_player1[7].posicao);
    else if(players.front().id == 2) atualizaMapa(players, players.front().posicao, casas_player2[7].posicao);
    else if(players.front().id == 3) atualizaMapa(players, players.front().posicao, casas_player3[7].posicao);
    else if(players.front().id == 4) atualizaMapa(players, players.front().posicao, casas_player4[7].posicao);
}

void detencao(vector<PLAYER> &players) {
    players.front().detencao = 2;
}
void ferias(vector<PLAYER> &players) {
    cout << "Sua chefa te deu ferias e um mimo da empresa! Aproveite! ;D" << endl;
    int valor = randint(30) * 1000;
    players.front().carteira += valor;
    cout << players.front().nome << "recebeu $" << valor << endl;

}

void verificaDetencao(vector<PLAYER> &players) {
    if (players.front().detencao <= 0) {
        cout << "Parabens " << players.front().nome << "! Seu tempo de detencao acabou!" << endl;
        cout << "Voce esta livre agora!" << endl;
    }
}