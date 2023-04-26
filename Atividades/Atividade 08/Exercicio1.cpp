/*
    Laboratório de Técnicas de Programação II - Aula 25/04/2023
    Definir uma estrutura de nos e realizar operacoes com eles.
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

    No *primeiro;
    No n1;
    No n2;
    No n3;

    n1.valor = 1;
    n2.valor = 2;
    n3.valor = 3;

    primeiro = &n1;
    n1.proximoNo = &n2;
    n2.proximoNo = &n3;
    n3.proximoNo = &n1;

    // letras a) e b)
    
    // Escrita a partir de cada no
    cout << "Endereco de n1: " << &n1 << endl;
    cout << "Valor guardado em n1: " << n1.valor << endl;
    cout << "Endereco do proximo no guardado em n1: " << n1.proximoNo << endl;

    cout << "Endereco de n2: " << &n2 << endl;
    cout << "Valor guardado em n2: " << n2.valor << endl;
    cout << "Endereco do proximo no guardado em n2: " << n2.proximoNo << endl;
    
    cout << "Endereco de n3: " << &n3 << endl;
    cout << "Valor guardado em n3: " << n3.valor << endl;
    cout << "Endereco do proximo no guardado em n3: " << n3.proximoNo << endl;

    // // Escrita a partir do primeiro no
    // cout << "Endereco de n1: " << primeiro << endl;
    // cout << "Valor guardado em n1: " << primeiro->valor << endl;
    // cout << "Endereco do proximo no guardado em n1: " << primeiro -> proximoNo << endl;

    // cout << "Endereco de n2: " << primeiro -> proximoNo << endl;
    // cout << "Valor guardado em n2: " << primeiro -> proximoNo -> valor << endl;
    // cout << "Endereco do proximo no guardado em n2: " << primeiro -> proximoNo -> proximoNo << endl;

    // cout << "Endereco de n3: " << primeiro -> proximoNo -> proximoNo << endl;
    // cout << "Valor guardado em n3: " << primeiro -> proximoNo -> proximoNo -> valor << endl;
    // cout << "Endereco do proximo no guardado em n3: " << primeiro -> proximoNo -> proximoNo -> proximoNo << endl;

    // letra c)
    No n4;
    n4.valor = 4;
    n4.proximoNo = &n1;
    n3.proximoNo = &n4;

    cout << "Endereco de n4: " << &n4 << endl;
    cout << "Valor guardado em n4: " << n4.valor << endl;
    cout << "Endereco do proximo no guardado em n4: " << n4.proximoNo << endl;

    // letra d)
    primeiro = &n2;
    n4.proximoNo = &n2;

    cout << "Endereco de n4: " << &n4 << endl;
    cout << "Valor guardado em n4: " << n4.valor << endl;
    cout << "Endereco do proximo no guardado em n4: " << n4.proximoNo << endl;
}
