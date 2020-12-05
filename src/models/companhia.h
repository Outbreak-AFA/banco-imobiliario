typedef struct {
    double cobranca;
    int posicao;
    string nome;
} COMPANHIA;

COMPANHIA criar_companhia(string nome, int posicao) {
    COMPANHIA c;
    c.nome = nome;
    c.posicao = posicao;
    c.cobranca = 200000.0;
    return c;
}

void buildCompanhias(vector<COMPANHIA> &companhias) {
    COMPANHIA c;
    c = criar_companhia("COMPANHIA DE TELEFONE", 6);
    companhias.push_back(c);
    c = criar_companhia("COMPANHIA DE AGUA", 11);
    companhias.push_back(c);
    c = criar_companhia("COMPANHIA DE LUZ", 20);
    companhias.push_back(c);
    c = criar_companhia("COMPANHIA DE MINERACAO", 27);
    companhias.push_back(c);
}

COMPANHIA getCompanhia(vector<PLAYER> &players, vector<COMPANHIA> &companhias) {
    for (int i = 0; i < companhias.size(); i++) {
        if (companhias.at(i).posicao == players.front().celula){
            return companhias.at(i);
        }
    }
}

void pagar_companhia(vector<PLAYER> &players, COMPANHIA companhia) {

    cout << players.front().nome << " esta na "<< companhia.nome << endl;
    Sleep(1000);

    players.front().carteira -= companhia.cobranca;
    cout << "Player " << players.front().nome << " pagou $ " << companhia.cobranca << " por ter passado nessa companhia"<< endl;
    
    cout << endl;
}