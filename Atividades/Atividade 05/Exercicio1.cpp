/*
    Laboratório de Técnicas de Programação II - Aula 17/03/2023
    Transformar um número decimal para sua forma binaria utilizando recursao.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

# include <iostream>

using namespace std;

long decimalParaBinario(int numero);

int main() {

    int decimal;
    cout << "Digite um numero natural na base decimal: ";
    cin >> decimal;

    cout << "Convertendo numero..." << endl << "Decimal: " << decimal << " - Binario: " << decimalParaBinario(decimal) << endl; 
    return 0;
}

/* Converte um numero de decimal para binario mantendo o tipo inteiro */
long decimalParaBinario(int numero) {
    if (numero < 2) return numero;
    return decimalParaBinario(numero / 2) * 10 + numero % 2;
}

/* Converte um numero de decimal para binario imprimindo o resultado na tela */
/* Desta maneira nao existe a limitacao do tamanho maximo do numero que o int suporta */
void imprimeBinario(int nro) {
    if(nro < 2) cout << nro;
    imprimeBinario(nro / 2);
    cout << nro % 2;
}