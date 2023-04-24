/*
    Laboratório de Técnicas de Programação II - Aula 22/04/2023
    Realizar a troca de valores de tres variaveis utilizando ponteiros.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

void trocaValores(int *a, int *b, int *c);

int main() {

    int a = 5;
    int b = 7;
    int c = 9;

    cout << "Antes da troca:\n" <<
            "a: " << a << endl <<
            "b: " << b << endl <<
            "c: " << c << endl;

    trocaValores(&a, &b, &c);

    cout << "Depois da troca:\n" <<
            "a: " << a << endl <<
            "b: " << b << endl <<
            "c: " << c << endl;

    return 0;
}

void trocaValores(int *a, int *b, int *c) {
    int temp = *a;
    *a = *c;
    *c = *b;
    *b = temp;
}