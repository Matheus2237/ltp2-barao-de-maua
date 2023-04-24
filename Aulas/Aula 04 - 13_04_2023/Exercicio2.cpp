/*
    Laboratório de Técnicas de Programação II - Aula 22/04/2023
    Calcular o fatorial de um numero utilizando ponteiros.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

void fatorial(int *numero);

int main() {
    int numero = 5;
    int *ponteiro = &numero;
    cout << "Fatorial de " << *ponteiro << ": ";
    fatorial(ponteiro);
    cout << *ponteiro << endl;
    return 0;
}

void fatorial(int *numero) {
    if(*numero == 0)
        *numero = 1; 
    int size = *numero;
    for(int i = 1; i < size; i++) {
        *numero *= i;
    }
}