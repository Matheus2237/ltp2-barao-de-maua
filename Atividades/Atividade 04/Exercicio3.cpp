/*
    Laboratório de Técnicas de Programação II - Aula 14/03/2023
    Calcular o MDC de dois numeros inteiros utilizando recursão.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

int calculaMDC(int x, int y);

int main() {

    int n1;
    int n2;
    cout << "Calculadora de MDC" << endl <<
            "Digite o primeiro numero: ";
    cin >> n1;
    cout << "Digite o segundo numero: ";
    cin >> n2;

    cout << "O MDC entre " << n1 << " e " << n2 << " eh " << calculaMDC(n1, n2) << "." << endl; 
    return 0;
}

/* Calcula o MDC entre dois numeros inteiros */
int calculaMDC(int x, int y) {
    if (x == y) return x;
    if (x > y) {
        return calculaMDC(x - y, y);
    } else {
        return calculaMDC(y, x);
    }
}