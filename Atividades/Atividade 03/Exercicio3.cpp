/*
    Laboratório de Técnicas de Programação II - Aula 10/03/2023
    Contar quantas vezes um determinado algarismo existe em um numero natural utilizando recursao.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

//762021192

#include <iostream>
#include <string>

using namespace std;

int contaAlgarismo(string numero, char algarismo, int posicao);
int existeAlgarismoNoIndiceDeContagem(char algarismo, char indice);

int main() {
    
    string numero;
    char numeroChecagem;

    cout << endl << "Digite um numero natural: ";
    cin >> numero;

    cout << endl << "Digite o algarismo que quer contar: ";
    cin >> numeroChecagem;

    cout << endl << "O algarismo " << numeroChecagem << " aparece " << 
            contaAlgarismo(numero, numeroChecagem, 0) << " vezes no numero " << 
            numero << "." << endl << endl;

    return 0;
}

/* Conta a quantidade de algarismos em um numero */
int contaAlgarismo(string numero, char algarismo, int indiceContagem) {
    if (indiceContagem == numero.length()) {
        return 0;
    }
    return existeAlgarismoNoIndiceDeContagem(algarismo, numero.at(indiceContagem)) + contaAlgarismo(numero, algarismo, indiceContagem + 1);
}

/* Verifica se o algarismo existe na posicao determinada */
int existeAlgarismoNoIndiceDeContagem(char algarismo, char indice) {
    if (algarismo == indice) return 1;
    else return 0;
}