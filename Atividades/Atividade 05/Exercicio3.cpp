/*
    Laboratório de Técnicas de Programação II - Aula 17/03/2023
    Calcular o resto da divisao de dois numeros inteiros utilizando recursao.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

int calculaModulo(int divisor, int dividendo);

int main() {

    int divisor;
    int dividendo;
    cout << "Calculadora de modulo da divisao entre dois inteiros" << endl <<
            "Digite o divisor: ";
    cin >> divisor;
    cout << "Digite o dividendo: ";
    cin >> dividendo;


    cout << "O modulo da divisao entre " << divisor << " e " << dividendo << " eh " << calculaModulo(divisor, dividendo) << "." << endl;
    return 0;
}

/* Calcula o modulo da divisao entre dois numeros inteiros */
int calculaModulo(int divisor, int dividendo) {
    if (divisor == dividendo) return 0;
    if (divisor > dividendo) {
        return calculaModulo(divisor - dividendo, dividendo);
    } else {
        return divisor;
    }
}