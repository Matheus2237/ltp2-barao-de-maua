/*
    Laboratório de Técnicas de Programação II - Aula 02/05/2023
    Alocar uma matriz dinamicamente com dimensoes especificadas pelo usuario, realizar a soma de seus elementos e desaloca-los.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <ctime>

using namespace std;

int preencheComInteiro();
long int somaElementosDaMatriz(int **matriz, int linhas, int colunas);

int main() {
    // Definindo a seed da randomizacao de numeros
    srand(time(0));

    // Solicitando ao usuario as dimensoes da matriz
    int linhas;
    int colunas;
    cout << "\nDigite a quantidade de linhas da matriz: ";
    cin >> linhas;
    cout << "Digite a quantidade de colunas da matriz: ";
    cin >> colunas;
    cout << endl;

    // Alocando a matriz
    int **matriz = new int*[linhas];
    for (int i = 0; i < linhas; i++)
        matriz[i] = new int[colunas];
    
    // Atribuindo valores a matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = preencheComInteiro();
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Calculando a soma dos elementos da matriz
    long int soma = somaElementosDaMatriz(matriz, linhas, colunas);
    cout << "\nA soma dos elementos da matriz e: " << soma << endl << endl;

    // Desacolando os elementos da memoria
    for (int i = 0; i < linhas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}

int preencheComInteiro() {
    return rand() % 1000;
}

long int somaElementosDaMatriz(int **matriz, int linhas, int colunas) {
    int soma = 0;
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            soma += matriz[i][j];
    return soma;   
}
