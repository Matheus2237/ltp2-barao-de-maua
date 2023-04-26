/*
    Laboratório de Técnicas de Programação II - Aula 21/04/2023
    Somar dois vetores armazenando a soma no primeiro vetor.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

void imprimeVetor(string texto, int *vetor, int tamanho);
void somaVetoresSalvandoNoPrimeiro(int *vetor1, int *vetor2, int tamanho);

int main() {
    
    int vetTemp1[4] = {3, 6, 7, 9};
    int vetTemp2[4] = {4, 5, 7, 1};
    int *vetor1 = vetTemp1;
    int *vetor2 = vetTemp2;
    
    cout << "Antes da soma...\n";
    imprimeVetor("Vetor 1", vetor1, 4);
    imprimeVetor("Vetor 2", vetor2, 4);

    somaVetoresSalvandoNoPrimeiro(vetor1, vetor2, 4);

    cout << "\nDepois da soma...\n";
    imprimeVetor("Vetor 1", vetor1, 4);
    imprimeVetor("Vetor 2", vetor2, 4);

    return 0;
}

void imprimeVetor(string texto, int *vetor, int tamanho) {
    cout << texto << ": " << *vetor;
    for (int i = 1; i < tamanho; i++) {
        cout << ", " << *(++vetor);
    }
    cout << endl;
}

void somaVetoresSalvandoNoPrimeiro(int *vetor1, int *vetor2, int tamanho) {
    for(int i = 0; i < 4; i++) {
        *vetor1 += *vetor2;
        *vetor1++;
        *vetor2++;
    }
}