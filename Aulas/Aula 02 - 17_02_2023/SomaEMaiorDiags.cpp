/*
    Laboratório de Técnicas de Programação II - Aula 17/02/2023
    Encontrar a soma dos elementos da diagonal principal e encontrar o maior elemento da diagonal secundária.
    @author: Matheus Paulino <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int somaDiagonalPrincipal(int matriz[3][3]);
int maiorElementoDiagSecundaria(int matriz[3][3]);

int main() {
    srand(time(0));    
    int matriz[3][3]; /* Declaração da matriz */

    cout << endl;
    for(int i = 0; i < 3; i++) { /* Popular matriz */
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = rand() % 100; /* Gera e atribui um número aleatório */
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "A soma dos elementos da diagonal principal resulta em " << somaDiagonalPrincipal(matriz) << "." << endl;
    cout << "O maior elemento da diagonal secundaria e " << maiorElementoDiagSecundaria(matriz) << "." << endl << endl;
    return 0;
}

int somaDiagonalPrincipal(int matriz[3][3]) { /* Soma os valores apenas da diagonal principal */
    int soma = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == j) { /* A diagonal principal é composta por elementos na posição em que i e j possuem mesmo valor */
                soma += matriz[i][j];
            }
        }
    }
    return soma;
}

int maiorElementoDiagSecundaria(int matriz[3][3]) { /* Encontra o maior valor na diagonal secundária */
    int maiorElemento = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i + j == 2 && matriz[i][j] > maiorElemento) { /* A diagonal secundária de uma matriz 3x3 é composta por elementos na posição em que o i e j somados resultam no valor 4, porém a iteração segue de 0 a 2, então a soma deve ser 2 */
                maiorElemento = matriz[i][j];
            }
        }
    }
    return maiorElemento;
}