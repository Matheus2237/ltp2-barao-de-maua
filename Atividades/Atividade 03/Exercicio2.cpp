/*
    Laboratório de Técnicas de Programação II - Aula 10/03/2023
    Inverte a posicao dos elementos de um array de inteiros.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

void inverteLista(int vetor[], int primeiroIndice, int ultimoIndice);
void trocaValores(int vetor[], int valorEsquerda, int valorDireita);

int main() {

    int valores[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    inverteLista(valores, 0, 8);

    cout << "{ ";
    for (int i = 0; i < 9; i++) {
        if (i == 8) cout << valores[i] << " ";
        else cout << valores[i] << ", ";
    }
    cout << "}" << endl;

    return 0;   
}

/* Inverte os valores de uma lista */
void inverteLista(int vetor[], int primeiroIndice, int ultimoIndice) {
    if (primeiroIndice < ultimoIndice) {
        trocaValores(vetor, primeiroIndice, ultimoIndice);
        inverteLista(vetor, primeiroIndice + 1, ultimoIndice - 1);
    }    
}

/* Troca o valor de duas variaveis entre si */
void trocaValores(int vetor[], int valorEsquerda, int valorDireita) {
    int temporario = vetor[valorEsquerda];
    vetor[valorEsquerda] = vetor[valorDireita];
    vetor[valorDireita] = temporario;
}