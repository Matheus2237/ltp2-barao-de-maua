/*
    Laboratório de Técnicas de Programação II - Aula 21/04/2023
    Multiplicar um vetor por um fator k.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

void imprimeVetor(string texto, int *vetor, int tamanho);
void multiplicaElementosDoVetor(int *vetor, int tamanho, int fator);

int main() {
    int vetor [4]= {1, 2, 3, 4};
    int *ponteiro = vetor;
    imprimeVetor("Vetor original", vetor, 4);
    multiplicaElementosDoVetor(vetor, 4, 3);
    imprimeVetor("Vetor multiplicado por 3", vetor, 4);
    return 0;
}

void imprimeVetor(string texto, int *vetor, int tamanho) {
    cout << texto << ": " << *vetor;
    for (int i = 1; i < tamanho; i++) {
        cout << ", " << *(++vetor);
    }
    cout << endl;
}

void multiplicaElementosDoVetor(int *vetor, int tamanho, int fator) {
    for (int i = 0; i < tamanho; i++) {
        *vetor *= fator;
        vetor++;        
    }
}