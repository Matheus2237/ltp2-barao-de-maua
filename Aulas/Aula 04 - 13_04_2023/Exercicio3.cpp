/*
    Laboratório de Técnicas de Programação II - Aula 22/04/2023
    Calcular a media entre os elementos de mesma posicao de dois vetores e armazenar em um terceiro vetor.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

void imprimeVetor(string nome, int *vetor, int tamanho);
void calculaMediaEntreVetores(int *vetorResultado, int *vetorA, int *vetorB, int tamanho);

int main() {
    
    int tempA[4] = {1, 4, 6, 8};
    int *vetA = tempA;
    imprimeVetor("Vetor A: ", vetA, 4);

    int tempB[4] = {3, 5, 6, 1};
    int *vetB = tempB;
    imprimeVetor("Vetor B: ", vetB, 4);

    int tempC[4];
    int *vetC = tempC;
    calculaMediaEntreVetores(vetC, vetA, vetB, 4);
    imprimeVetor("Vetor C: ", vetC, 4);

    return 0;
}

void imprimeVetor(string nome, int *vetor, int tamanho) {
    cout << nome << *vetor;
    for (int i = 1; i < tamanho; i++) {
        *vetor++;
        cout  << ", " << *vetor;
    }
    cout << endl;
}

void calculaMediaEntreVetores(int *vetorResultado, int *vetorA, int *vetorB, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        *vetorResultado = (*vetorA + *vetorB) / 2;
        *vetorResultado++;
        *vetorA++;
        *vetorB++;
    }
}