using namespace std;

// PROPRIEDADES

// Para comprar alguma propriedade, que seja um terreno, praça, bairro ou empresa, 
// é necessário que seu peão caia em uma das casas, caso já não seja o dono.

// Caso a propriedade seja de outro jogador, se o seu peão parar na casa, 
// você deverá pagar ao dono desta propriedade o valor do aluguel indicado no título da propriedade.

// Dica: Diversificar seus investimentos é palavra de ordem no mundo dos negócios. 
// Lembre-se que quanto mais propriedades tiver, maior a probabilidade de ganhar dinheiro, 
// porque sempre que caírem na sua propriedade você receberá aluguel.

typedef struct {
    string nome_avenida;
    int posicao;
    int id_comprador;
    int casas;
    bool tem_dono; // verificar se a propriedade tem dono
    string nome_comprador;
    long double valor_aluguel; // valor do aluguel da propriedade
} PROPRIEDADE;

PROPRIEDADE criar_propriedade(string nome_avenida, double valor_aluguel, bool tem_dono, int posicao) {
    PROPRIEDADE p;
    p.nome_avenida = nome_avenida;
    p.valor_aluguel = valor_aluguel;
    p.tem_dono = tem_dono;
    p.posicao;
    return p;
}

void buildPropriedades(vector<PROPRIEDADE> &propriedades) {
    PROPRIEDADE pr;
    pr = criar_propriedade("Ondina", 290000, false, 1);
    propriedades.push_back(pr);
    pr = criar_propriedade("Vitoria", 320000, false, 3);
    propriedades.push_back(pr);
    pr = criar_propriedade("Barra", 300000, false, 4);
    propriedades.push_back(pr);
    pr = criar_propriedade("Av. Orlando Gomes", 140000, false, 8);
    propriedades.push_back(pr);
    pr = criar_propriedade("Rua SENAI Cimatec", 60000, false, 9);
    propriedades.push_back(pr);
    pr = criar_propriedade("Jaguaripe", 130000, false, 12);
    propriedades.push_back(pr);
    pr = criar_propriedade("Farol da Barra", 100000, false, 13);
    propriedades.push_back(pr);
    pr = criar_propriedade("Vilas do Atlantico", 150000, false, 16);
    propriedades.push_back(pr);
    pr = criar_propriedade("Buraquinho", 70000, false, 17);
    propriedades.push_back(pr);
    pr = criar_propriedade("Abrantes", 100000, false, 18);
    propriedades.push_back(pr);
    pr = criar_propriedade("Pituba", 150000, false, 22);
    propriedades.push_back(pr);
    pr = criar_propriedade("Rio Vermelho", 100000, false, 24);
    propriedades.push_back(pr);
    pr = criar_propriedade("Av. ACM", 200000, false, 26);
    propriedades.push_back(pr);
}

// Função que mostra o card de uma propriedade
void consultar_propriedade(PROPRIEDADE propriedade) {

   clear();
   // card genérico de propriedade
   cout << endl;
   cout << "==========================================================" << endl;
   cout << "| " << propriedade.nome_avenida << endl; 
   cout << "| Aluguel: " << "R$ " << propriedade.valor_aluguel << endl;
   if (propriedade.tem_dono == true) {
       cout << "| " << "Proprietario(a): " << propriedade.nome_comprador << endl;
   } 
   cout << "| " << "Casas: " << propriedade.casas << endl;
   cout << "==========================================================" << endl;
   pause();

}

PROPRIEDADE getPropriedade(vector<PLAYER> &players, vector<PROPRIEDADE> &propriedades) {
    for (int i = 0; i < propriedades.size(); i++) {
        if (propriedades.at(i).posicao == players.front().celula){
            return propriedades.at(i);
        }
    }
}

void comprar_propriedade(vector<PLAYER> &players, PROPRIEDADE propriedades) {

    if (propriedades.tem_dono) {
        cout << "Essa propriedade ja tem dono(a). Voce nao pode comprar ela!" << endl;
    } else {
        propriedades.tem_dono = true;
        players.front().carteira -= propriedades.valor_aluguel;
        cout << "\nPlayer " << players.front().nome << " comprou a propriedade " << endl;
        cout << "Saldo " << players.front().nome << ": R$ " << players.front().carteira << endl;
        propriedades.nome_comprador = players.front().nome;
        pause();
        consultar_propriedade(propriedades);
    }
}

void pagar_aluguel_propriedade(vector<PLAYER> &players, PROPRIEDADE propriedade) {

    if (propriedade.tem_dono) {
        cout << "Essa e' a propriedade de player " << propriedade.nome_comprador << endl;
        Sleep(1000);

        players.front().carteira -= propriedade.valor_aluguel;
        cout << "Player " << players.front().nome << " pagou R$ " << propriedade.valor_aluguel << " por ter passado na propriedade de " << propriedade.nome_comprador << endl;

        for(int i = 0; i < players.size(); i++) {
            if (propriedade.id_comprador == players.at(i).id) {
                players.at(i).carteira += propriedade.valor_aluguel;
                cout << players.at(i).nome << " recebeu " << propriedade.valor_aluguel << "!\n";
            }
        }
        
        cout << endl;
    }
}