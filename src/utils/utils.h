/*
Gera um número inteiro randômico de 1 até (int max)
*/
int randint(int max) {
    int r = rand() % max;
        if (r == 0) randint(max);
    return r;
}


void clear() {
    system("cls");
}

void pause() {
    system("pause");
}