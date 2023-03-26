/*
    Laboratório de Técnicas de Programação II - Aula 14/03/2023
    Contar quantas vezes um determinado algarismo existe em um numero natural utilizando recursao.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

int ocorrencia(int numero, int algarismo);
int ocorrenciaOtimizada(int numero, int algarismo);

int main() {

    int n = 2102;
    int k = 2;

    cout << "O numero " << k << " aparece " << ocorrencia(n, k) << " vezes no numero " << n << "." << endl;
    cout << "O numero " << k << " aparece " << ocorrenciaOtimizada(n, k) << " vezes no numero " << n << "." << endl;

    return 0;
}

/* Conta quantas vezes um algarismo ocorre em um numero */
int ocorrencia(int numero, int algarismo) {
    if(numero == 0) {
        return 0;
    }
    if(numero % 10 == algarismo) {
        return 1 + ocorrencia(numero / 10, algarismo);
    }
    else {
        return ocorrencia(numero / 10, algarismo);
    }
}

/* Neste exemplo, vale lembrar que c++ considera true or false também como 1 e 0, respectivamente */
/* Para que esta operação de comparação retorne um booleano, basta que o tipo de retorno desta função seja bool  */
int ocorrenciaOtimizada(int numero, int algarismo) {
    if (numero / 10 == 0) return 0;
    return (numero % 10) + ocorrenciaOtimizada(numero/10, algarismo);
}