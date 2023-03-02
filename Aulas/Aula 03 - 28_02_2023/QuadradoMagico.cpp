/*
    Laboratório de Técnicas de Programação II - Aula 28/02/2023
    Gerar uma matriz 4x4 e verificar se é um quadrado mágico.
    @author: Matheus Paulino <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

bool isQuadradoMagico(int matriz[4][4]);
bool checaLinhas(int matriz[4][4], int checkValue);
bool checaColunas(int matriz[4][4], int checkValue);
bool checaDiagPrincipal(int matriz[4][4], int checkValue);
bool checaDiagSecundaria(int matriz[4][4], int checkValue);
string formataResposta(bool resposta);

int main() {

    /* Gerando uma matriz com valores aleatórios e imprimindo-os */
    srand(time(0));
    int matriz[4][4];

    cout << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matriz[i][j] = rand() % 100;
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    /* Verificando se e um quadrado magico */
    string resposta = formataResposta(isQuadradoMagico(matriz));
    cout << endl << "A matriz " << resposta << "e um quadrado magico." << endl;
}

/* Verifica se a matriz é um quadrado mágico */
bool isQuadradoMagico(int matriz[4][4]) {
    int valorChecagem;
    for (int j = 0; j < 4; j++) { valorChecagem += matriz[0][j]; }

    bool somaLinha = checaLinhas(matriz, valorChecagem);
    bool somaColuna = checaColunas(matriz, valorChecagem);
    bool somaDiagPrincipal = checaDiagPrincipal(matriz, valorChecagem);
    bool somaDiagSecundaria = checaDiagSecundaria(matriz, valorChecagem);

    if (somaLinha && somaColuna && somaDiagPrincipal && somaDiagSecundaria) { return true; }
    return false;
}

/* Checa a soma das linhas */
bool checaLinhas(int matriz[4][4], int checkValue) {
    for (int i = 0; i < 4; i++) {
        int soma = 0;
        for (int j = 0; j < 4; j++) {
            soma += matriz[i][j];
        }
        if (soma != checkValue) return false;
    }
    return true;
}

/* Checa a soma das colunas */
bool checaColunas(int matriz[4][4], int checkValue) {
    for (int j = 0; j < 4; j++) {    
        int soma = 0;
        for (int i = 0; i < 4; i++) {    
            soma += matriz[i][j];
        }
        if(soma != checkValue) return false;
    }
    return true;  
}

/* Checa a soma dos elementos da diagonal principal */
bool checaDiagPrincipal(int matriz[4][4], int checkValue) {
    int soma = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if(i == j) {
                soma += matriz[i][j];
            }
        }
    }
    if (soma != checkValue) return false;
    return true;
}

/* Checa a soma dos elementos da diagonal secundária */
bool checaDiagSecundaria(int matriz[4][4], int checkValue) {
    int soma = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if(i + j == 3) {
                soma += matriz[i][j];
            }
        }
    }
    if (soma != checkValue) return false;
    return true;
}

/* Recebe a validação se é um quadrado mágico ou não e formata essa resposta para string */ 
string formataResposta(bool validacao) {
    if (validacao == false) return "nao ";
    else return "";
}