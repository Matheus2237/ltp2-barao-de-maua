/*
    Laboratório de Técnicas de Programação II - Aula 25/04/2023
    Realizar as mesmas operações para a mesma estrutura do exercicio 1 da ativadae 8, porem utilizando alocacao dinamica.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

struct No {
    int valor;
    No *proximoNo;
};

typedef struct No No;

int main() {

    No *primeiro = new No;
    
    // No 1
    primeiro -> valor = 1;
    primeiro -> proximoNo = new No; 

    // No 2
    primeiro -> proximoNo -> valor = 2;
    primeiro -> proximoNo -> proximoNo = new No;

    // No 3
    primeiro -> proximoNo -> proximoNo -> valor = 3;
    primeiro -> proximoNo -> proximoNo -> proximoNo = primeiro;

    // letras a) e b)
    cout << endl << "-----------------------------------------------------" << endl;
    cout << endl << "Estrutura inicial com os nos 1, 2 e 3:" << endl << endl;
    
    cout << "Endereco de n1: " << primeiro << endl;
    cout << "Valor guardado em n1: " << primeiro -> valor << endl;
    cout << "Endereco do proximo no guardado em n1: " << primeiro -> proximoNo << endl;

    cout << "Endereco de n2: " << primeiro -> proximoNo << endl;
    cout << "Valor guardado em n2: " << primeiro -> proximoNo -> valor << endl;
    cout << "Endereco do proximo no guardado em n2: " << primeiro -> proximoNo -> proximoNo << endl;

    cout << "Endereco de n3: " << primeiro -> proximoNo -> proximoNo << endl;
    cout << "Valor guardado em n3: " << primeiro -> proximoNo -> proximoNo -> valor << endl;
    cout << "Endereco do proximo no guardado em n3: " << primeiro -> proximoNo -> proximoNo -> proximoNo << endl;
    
    // letra c)
    // No 4
    primeiro -> proximoNo -> proximoNo -> proximoNo = new No;
    primeiro -> proximoNo -> proximoNo -> proximoNo -> valor = 4;
    primeiro -> proximoNo -> proximoNo -> proximoNo -> proximoNo = primeiro;

    cout << endl << "-----------------------------------------------------" << endl;
    cout << endl << "Adicionando o no 4. Estrutura com os nos 1, 2, 3 e 4:" << endl << endl;

    cout << "Endereco de n1: " << primeiro << endl;
    cout << "Valor guardado em n1: " << primeiro -> valor << endl;
    cout << "Endereco do proximo no guardado em n1: " << primeiro -> proximoNo << endl;

    cout << "Endereco de n2: " << primeiro -> proximoNo << endl;
    cout << "Valor guardado em n2: " << primeiro -> proximoNo -> valor << endl;
    cout << "Endereco do proximo no guardado em n2: " << primeiro -> proximoNo -> proximoNo << endl;

    cout << "Endereco de n3: " << primeiro -> proximoNo -> proximoNo << endl;
    cout << "Valor guardado em n3: " << primeiro -> proximoNo -> proximoNo -> valor << endl;
    cout << "Endereco do proximo no guardado em n3: " << primeiro -> proximoNo -> proximoNo -> proximoNo << endl;

    cout << "Endereco de n4: " << primeiro -> proximoNo -> proximoNo -> proximoNo << endl;
    cout << "Valor guardado em n4: " << primeiro -> proximoNo -> proximoNo -> proximoNo -> valor << endl;
    cout << "Endereco do proximo no guardado em n4: " << primeiro -> proximoNo -> proximoNo -> proximoNo -> proximoNo << endl;

    // letra d)
    primeiro = primeiro -> proximoNo;
    delete primeiro -> proximoNo -> proximoNo -> proximoNo;
    primeiro -> proximoNo -> proximoNo -> proximoNo = primeiro;

    cout << endl << "-----------------------------------------------------" << endl;
    cout << endl << "Removendo o no 1. Estrutura com os nos 2, 3 e 4:" << endl << endl;

    cout << "Endereco de n2: " << primeiro << endl;
    cout << "Valor guardado em n2: " << primeiro -> valor << endl;
    cout << "Endereco do proximo no guardado em n2: " << primeiro -> proximoNo << endl;

    cout << "Endereco de n3: " << primeiro -> proximoNo << endl;
    cout << "Valor guardado em n3: " << primeiro -> proximoNo -> valor << endl;
    cout << "Endereco do proximo no guardado em n3: " << primeiro -> proximoNo -> proximoNo << endl;

    cout << "Endereco de n4: " << primeiro -> proximoNo -> proximoNo << endl;
    cout << "Valor guardado em n4: " << primeiro -> proximoNo -> proximoNo -> valor << endl;
    cout << "Endereco do proximo no guardado em n4: " << primeiro -> proximoNo -> proximoNo -> proximoNo << endl;

    cout << endl << "-----------------------------------------------------" << endl << endl;
    return 0;
}