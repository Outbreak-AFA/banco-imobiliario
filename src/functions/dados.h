#define MAX 6
#define MIN 1

int girarDado() {
    int random;
    random = rand() % (MAX + MIN);
    return random;
}

struct Dado {
    int valor;

    Dado(int valor) {
        this->valor = valor;
    }

    void setValor(int valor) {
        this->valor = valor;
    }

    int getValor() {
        return valor;
    }
};

int var;

using namespace std;
int mostrarDados() {
    // permite visualizar os dados jogados

    cout << "> Girando dados..." << endl;
    Sleep(1000); // milisegundos
    int d1 = girarDado();
    int d2 = girarDado();

    char dados[5][11] = {
        {219, 219, 219, 219, 219, ' ', 219, 219, 219, 219, 219 },
        {219, ' ', ' ', ' ', 219, ' ', 219, ' ', ' ', ' ', 219 },
        {219, ' ', 'a', ' ', 219, ' ', 219, ' ', 'b', ' ', 219 },
        {219, ' ', ' ', ' ', 219, ' ', 219, ' ', ' ', ' ', 219 },
        {219, 219, 219, 219, 219, ' ', 219, 219, 219, 219, 219 }
    };

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 11; j++){

            if (dados[i][j] != 'a' && dados[i][j] != 'b') {
                cout << ' ' << dados[i][j] << ' ';
            }
            else {
                if (d1 == 0) {
                    d1++;
                } else if (d2 == 0) {
                    d2++;
                } else if (d1 == 0 && d2 == 0) {
                    d1++;
                    d2++;
                }
                dados[i][j] == 'a' ? cout << ' ' << d1 << ' ' : cout << ' ' << d2 << ' ';
            }
        }
        cout << endl;
    }

    int casas = (d1+d2);
    Dado d(casas);
    
    var = d.getValor();
    return d.getValor();
}

int mostrarValorDados() {
    return var;
}
