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


// permite visualizar os dados jogados
int mostrarDados() {

    cout << "> Girando dados..." << endl;
    Sleep(1000); // milisegundos
    int d1 = girarDado();
    int d2 = girarDado();

    char dados[5][23] = {
        {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, ' ', 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219 },
        {219, 219, 219, ' ', ' ', ' ', ' ', ' ', 219, 219, 219, ' ', 219, 219, 219, ' ', ' ', ' ', ' ', ' ', 219, 219, 219 },
        {219, 219, 219, ' ', ' ', 'a', ' ', ' ', 219, 219, 219, ' ', 219, 219, 219, ' ', ' ', 'b', ' ', ' ', 219, 219, 219 },
        {219, 219, 219, ' ', ' ', ' ', ' ', ' ', 219, 219, 219, ' ', 219, 219, 219, ' ', ' ', ' ', ' ', ' ', 219, 219, 219 },
        {219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, ' ', 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219 }
    };

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 23; j++){
            if (dados[i][j] == 'a') cout << d1;
            else if (dados[i][j] == 'b') cout << d2;
            else cout << dados[i][j];
        }
        cout << endl;
    }

    return (d1 + d2);
}