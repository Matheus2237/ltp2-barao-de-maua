/*
    Laboratório de Técnicas de Programação II - Aula 10/03/2023
    Calcular a soma de todos os valores de um array de numeros reais.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

float recursiveSum(float vetor[], int tamanho, int parcela);

int main() {
    
    float valores[4] = {45.6, 32.5, 12.6, 34.2};

    cout << "A soma de todos os valores e: " << recursiveSum(valores, 4, 0) << endl;
    
    return 0;
}

/* Soma um valor do array com a soma dos proximos valores do array */
float recursiveSum(float vetor[], int tamanho, int parcela) {
    if (parcela == tamanho - 1) {
        return vetor[tamanho - 1];
    }
    return vetor[parcela] + recursiveSum(vetor, tamanho, parcela + 1);
}