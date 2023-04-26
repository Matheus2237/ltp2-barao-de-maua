/*
    Laboratório de Técnicas de Programação II - Aula 21/04/2023
    Construir um vetor de 10 pontos (x, y) aleatorios.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <ctime>

using namespace std;

struct Ponto {
    int x;
    int y;
};

typedef struct Ponto Ponto;

int sorteiaInteiro();

int main() {

    srand(time(0));
    Ponto pontosTemp[10];
    Ponto *pontos = pontosTemp;
    int qtdPontos = 10;

    for (int i = 0; i < qtdPontos; i++) {
        pontos -> x = sorteiaInteiro();
        pontos -> y = sorteiaInteiro();
        cout << "Ponto " << i+1 << ": (" << pontos -> x << "; " << pontos -> y << ")" << endl;
        pontos++;
    }

    return 0;
}

int sorteiaInteiro() {
    return rand() % 50;
}