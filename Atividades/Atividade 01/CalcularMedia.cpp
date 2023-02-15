/*
    Laboratório de Técnicas de Programação II - Aula 15/02/2023
    Calcular a média inteira de números inteiros
    @author: Matheus Paulino <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

void printManual() {
    cout << "Calculadora de Media Inteira" << endl << endl;
    cout << "Digite no teclado os valores que voce deseja calcular a media." << endl;
    cout << "   * Digite um valor por vez e aperte enter para confirmar." << endl;
    cout << "   * Para encerrar a entrada de dados, digite o valor 9999." << endl << endl;
}

int calculaMedia() { 
    int entrada = 0;
    int dividendoAcumulado = 0;
    int divisor = 0;

    cout << "Digite o primeiro valor: ";
    cin >> entrada;
    if (entrada == 9999) return 0;

    while(entrada != 9999) {
        dividendoAcumulado += entrada;
        divisor++;
        cout << "Digite o proximo valor: ";
        cin >> entrada;
    }   

    return dividendoAcumulado / divisor;
}

void printResultado(int resultado) {
    cout << endl << "Calculando a media..." << endl;
    cout << "A media inteira dos valores digitados e " << resultado << endl << endl;
}

int main() {
    printManual();
    int media = calculaMedia();
    printResultado(media);
}