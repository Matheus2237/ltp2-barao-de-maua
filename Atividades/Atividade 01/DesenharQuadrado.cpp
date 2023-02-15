/*
    Laboratório de Técnicas de Programação II - Aula 15/02/2023
    Imprimir um quadrado de asteriscos com lados de tamanho definido pelo usuário
    @author: Matheus Paulino <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

void desenhaQuadrado(int lado) {
    for (int v = 0; v < lado; v++) {
        if (v == 0 || v == lado - 1) {
            for (int h = 0; h < lado; h++) {
                cout << "*";
            }
        }
        else {    
            for (int h = 0; h < lado; h++) {
                if (h == 0 || h == lado -1) cout << "*";
                else cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int ladoQuadrado;
    cout << "Digite o tamanho que deseja para o lado do quadrado entre 1 e 20: ";
    cin >> ladoQuadrado;
    cout << endl;

    if (ladoQuadrado < 1 || ladoQuadrado > 20) {
        cout << "Este tamanho e invalido";
        return 0;
    }

    desenhaQuadrado(ladoQuadrado);
    cout << endl;
}