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
    long double custo_de_compra; // valor do aluguel da propriedade
} PROPRIEDADE;

PROPRIEDADE criar_propriedade(string nome_avenida,long double custo_de_compra, bool tem_dono, int posicao) {
    PROPRIEDADE p;
    p.nome_avenida = nome_avenida;
    p.custo_de_compra = custo_de_compra;
    p.tem_dono = tem_dono;
    p.posicao = posicao;
    p.casas = 0;
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
   cout << "| Custo de compra: " << "$ " << propriedade.custo_de_compra << endl;
   cout << "| Aluguel: " << "$ " << (propriedade.custo_de_compra * 0.1) << endl;
   if (propriedade.tem_dono == true) {
       cout << "| " << "Proprietario(a): " << propriedade.nome_comprador << endl;
   } else {
       cout << "| " << "Proprietario(a): Ninguem!" << endl;
   }
   cout << "| " << "Qnt. de Casas: " << propriedade.casas << endl;
   cout << "==========================================================" << endl;
   pause();

}

PROPRIEDADE getPropriedade(vector<PLAYER> &players, vector<PROPRIEDADE> &propriedades) {
    for (int i = 0; i < propriedades.size(); i++) {
        // cout << propriedades.at(i).nome_avenida << ": " << propriedades.at(i).posicao << endl;
        if (propriedades.at(i).posicao == players.front().celula){
            return propriedades.at(i);
        }
    }
}

void comprar_propriedade(vector<PLAYER> &players, vector<PROPRIEDADE> &propriedades, PROPRIEDADE propriedade) {
    int local;
    for (int i = 0; i < propriedades.size(); i++) {
        if (propriedades.at(i).posicao == players.front().celula){
            local = i;
            break;
        }
    }
    propriedades.at(local).tem_dono = true;
    propriedades.at(local).id_comprador = players.front().id; // relacionamento
    players.front().carteira -= propriedades.at(local).custo_de_compra;
    cout << "\nPlayer " << players.front().nome << " comprou a propriedade " << endl;
    cout << "Saldo " << players.front().nome << ": $ " << players.front().carteira << endl;
    propriedades.at(local).nome_comprador = players.front().nome;
    pause();
    consultar_propriedade(propriedades.at(local));
}

void pagar_aluguel_propriedade(vector<PLAYER> &players, PROPRIEDADE propriedade) {

        cout << "Essa e' a propriedade de player " << propriedade.nome_comprador << endl;
        Sleep(1000);

        players.front().carteira -= (propriedade.custo_de_compra * 0.1) + ((propriedade.custo_de_compra * 0.1) * propriedade.casas);
        cout << "Player " << players.front().nome << " pagou $ " << ((propriedade.custo_de_compra * 0.1) + ((propriedade.custo_de_compra * 0.1) * propriedade.casas)) << " por ter passado na propriedade de " << propriedade.nome_comprador << endl;

        for(int i = 0; i < players.size(); i++) {
            if (propriedade.id_comprador == players.at(i).id) {
                players.at(i).carteira += ((propriedade.custo_de_compra * 0.1) + ((propriedade.custo_de_compra * 0.1) * propriedade.casas));
                cout << players.at(i).nome << " recebeu $ " << ((propriedade.custo_de_compra * 0.1) + ((propriedade.custo_de_compra * 0.1) * propriedade.casas)) << "!\n";
            }
        }
        
        cout << endl;
}

void construirCasa(vector<PLAYER> &players, vector<PROPRIEDADE> &propriedades, PROPRIEDADE propriedade) {
    int local;
    for (int i = 0; i < propriedades.size(); i++) {
        if (propriedades.at(i).posicao == players.front().celula){
            local = i;
            break;
        }
    }
    propriedades.at(local).casas += 1;
    players.front().carteira -= propriedades.at(local).custo_de_compra/2.0;
    cout << players.front().nome << "contruiu +1 casa!, agora a propriedade possui " << propriedades.at(local).casas << " casas e gastou $ " << (propriedades.at(local).custo_de_compra/2.0) << " para contrui-la!" << endl;

}

int menuPropriedade(vector<PLAYER> &players, vector<PROPRIEDADE> &propriedades, PROPRIEDADE propriedade) {
    int res;
    if (!propriedade.tem_dono) {
        cout << "O que deseja fazer?" << endl;
        cout << "[1] - Consultar " << propriedade.nome_avenida << endl;
        cout << "[2] - Comprar " << propriedade.nome_avenida << endl;
        cin >> res;
        switch(res) {
            case 1:
                consultar_propriedade(propriedade);
                return menuPropriedade(players, propriedades, propriedade);
            case 2:
                comprar_propriedade(players, propriedades, propriedade);
                return 1;
            default:
                cout << "Opcao invalida!" << endl;
                return menuPropriedade(players, propriedades, propriedade);
        }
    }
    else {
        // relacionamento de 1 pra 1
        if (players.front().id == propriedade.id_comprador) {
            cout << "Seja bem-vinde a sua propriedade! O que deseja fazer?" << endl;
            cout << "[1] - Consultar " << propriedade.nome_avenida << endl;
            cout << "[2] - Construir uma casa" << endl;
            cout << "[3] - Fazer nada" << endl;
            cin >> res;

            switch(res) {
            case 1:
                consultar_propriedade(propriedade);
                return menuPropriedade(players, propriedades, propriedade);
            case 2:
                construirCasa(players, propriedades, propriedade);
                return 1;
            case 3:
                return 1;
            default:
                cout << "Opcao invalida!" << endl;
                return menuPropriedade(players, propriedades, propriedade);
            }

        }
        else {
            pagar_aluguel_propriedade(players, propriedade);
        }
    }

}