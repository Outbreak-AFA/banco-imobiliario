/*
Gera um número inteiro randômico de 1 até (int max)
*/
int randint(int max) {
    int r = rand() % max;
        if (r == 0) randint(max);
    return r;
}

int randomSortReves(int max) {
    int r = rand() % max;
    return r;
}

void narrador(string nome, string texto) {
    cout << nome << " " << texto << endl;
}

void clear() {
    system("cls");
}

void pause() {
    system("pause");
}