/*
    Laboratório de Técnicas de Programação II - Aula 17/02/2023
    Gerar uma matriz 5x5, preencher a diagonal principal com o valor 1 e os demais elementos com o valor 0 (Matriz Identidade).
    @author: Matheus Paulino <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    cout << endl << "Gerando matriz identidade 5x5..." << endl << endl;

    int matriz[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if(i == j) cout << "1 "; /* A matriz identidade é composta por elementos de valor 1 nas posições em que i = j */
            else cout << "0 ";       /* e o por elementos de valor 0 nas demais posições */
        }
        cout << endl;
    }
    
    cout << endl;
    return 0;
}