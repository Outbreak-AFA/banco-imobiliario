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
    char *posicao;
    int casas;
    bool tem_dono; // verificar se a propriedade tem dono
    string nome_comprador;
    long double valor_aluguel; // valor do aluguel da propriedade
} PROPRIEDADE;

PROPRIEDADE criar_propriedade(string nome_avenida, double valor_aluguel, bool tem_dono) {
    PROPRIEDADE p;
    p.nome_avenida = nome_avenida;
    p.valor_aluguel = valor_aluguel;
    p.tem_dono = tem_dono;
    return p;
}

void loadPropriedades(vector<PROPRIEDADE> &propriedades) {
    PROPRIEDADE pr;
    pr = criar_propriedade("Ondina", 290000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Vitoria", 320000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Barra", 300000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Companhia de Telefone", 200000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Av. Orlando Gomes", 140000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Rua SENAI Cimatec", 60000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Companhia de Agua", 200000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Jaguaripe", 130000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Farol da Barra", 100000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Vilas do Atlantico", 150000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Buraquinho", 70000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Abrantes", 100000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Companhia de Luz", 200000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Pituba", 150000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Rio Vermelho", 100000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Av. ACM", 200000, false);
    propriedades.push_back(pr);
    pr = criar_propriedade("Companhia de Mineracao", 200000, false);
    propriedades.push_back(pr);
}

// Função que mostra o card de uma propriedade
void consultar_propriedade(vector<PROPRIEDADE> &propriedades) {

   clear();
   // card genérico de propriedade
   cout << endl;
   cout << "==========================================================" << endl;
   cout << "| " << propriedades.front().nome_avenida << endl; 
   cout << "| Aluguel: " << "R$ " << propriedades.front().valor_aluguel << endl;
   if (propriedades.front().tem_dono == true) {
       cout << "| " << "Proprietario(a): " << propriedades.front().nome_comprador << endl;
   } 
   cout << "| " << "Casas: " << propriedades.front().casas << endl;
   cout << "==========================================================" << endl;

}

void comprar_propriedade(vector<PLAYER> &players, vector<PROPRIEDADE> &propriedades) {
    if (propriedades.front().tem_dono) {
        cout << "Essa propriedade ja tem dono(a). Voce nao pode comprar ela!" << endl;
    } else {
        propriedades.front().tem_dono = true;
        players.front().carteira -= propriedades.front().valor_aluguel;
        cout << "\nPlayer " << players.front().nome << " comprou a propriedade " << endl;
        cout << "Saldo " << players.front().nome << ": R$ " << players.front().carteira << endl;
        propriedades.front().nome_comprador = players.front().nome;
        pause();
        consultar_propriedade(propriedades);
    }
    verificarFalenciaPlayer(players);
}

void pagar_aluguel_propriedade(vector<PLAYER> &players, vector<PROPRIEDADE> &propriedades) {
    int pl_len = players.size();
    int cont = 0;
    consultar_propriedade(propriedades);
    for (int i=0; i<pl_len; i++) {
        if (propriedades.front().tem_dono && (players.at(i).nome == propriedades.front().nome_comprador)) {
            cout << "Essa e a propriedade dx player " << players.at(i).nome << endl;
            Sleep(1000);
        }
    }

    if (propriedades.front().tem_dono) {
        // if ((strcmp(players.front()., p->posicao) == 0))
            for (int k=0; k<pl_len; k++) {
                if (players.at(k).nome == propriedades.front().nome_comprador) {
                    players.at(k).carteira += propriedades.front().valor_aluguel;
                }
            }

        players.front().carteira -= propriedades.front().valor_aluguel;
        cout << "Player " << players.front().nome << " pagou R$ " << propriedades.front().valor_aluguel << " por ter passado na propriedade de " << propriedades.front().nome_comprador << endl;
        
        cout << endl;
    }
  
    // Saldo de todos os players
    for (int k=0; k<players.size(); k++) {
        cout << endl << "Saldo de " << players.at(k).nome << ": " << players.at(k).carteira;
    }
    cout << endl;
    verificarFalenciaPlayer(players);
}