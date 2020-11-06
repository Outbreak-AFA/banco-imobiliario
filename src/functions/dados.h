#define MAX 6
#define MIN 1

int girarDado() {
    int random1, random2;
    random1 = rand() % (MAX + MIN);
    return random1;
}

using namespace std;
int mostrarDados() {
    // permite visualizar os dados jogados

    int d1, d2;

    cout << "> Girando dados..." << endl;
    Sleep(1000); // milisegundos
    d1 = girarDado();
    d2 = girarDado();

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
                dados[i][j] == 'a' ? cout << ' ' << d1 << ' ': cout << ' ' << d2 << ' ';
            }
        }
        cout << endl;
    }

    return d1 + d2;
}
