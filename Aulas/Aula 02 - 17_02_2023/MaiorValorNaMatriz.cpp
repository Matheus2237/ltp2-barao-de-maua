/*
    Laboratório de Técnicas de Programação II - Aula 17/02/2023
    Encontrar a posição do maior valor na matriz 5x5.
    @author: Matheus Paulino <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));    
    int matriz[5][5]; /* Declaração da matriz */

    cout << endl;
    for(int i = 0; i < 5; i++) { /* Popular matriz */
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = rand() % 100; /* Gera e atribui um número aleatório */
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    int maiorValor = 0;
    int maiorI = 0;
    int maiorJ = 0;
    for(int i = 0; i < 5; i++) { /* Encontra o maior valor da matriz */
        for (int j = 0; j < 5; j++) {
            if(matriz[i][j] > maiorValor) { /* Atribui o maior valor somente quando encontrado */
                maiorValor = matriz[i][j];
                maiorI = i + 1;
                maiorJ = j + 1;
            }
        }
    }

    cout << endl << "O maior valor encontrado nesta matriz (" << maiorValor << ") se encontra na posicao " << maiorI << "x" << maiorJ << "." << endl << endl;
    return 0;
}