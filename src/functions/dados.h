#define MAX 6
#define MIN 1

using namespace std;

int girarDado() {
    int random;
    random = rand() % (MAX + MIN);

    if (random != 0)
        return random;
    else
        return girarDado();
}


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
                dados[i][j] == 'a' ? cout << ' ' << d1 << ' ' : cout << ' ' << d2 << ' ';
            }
        }
        cout << endl;
    }

    return (d1 + d2);
}