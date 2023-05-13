/*
    Laboratório de Técnicas de Programação II - Aula 12/05/2023
    Criar um arquivo com nome "ALUNOS.DAT" e armazenar dentro dele registros de alunos com as seguintes informações: numero, nome, curso, nota1, nota2.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ofstream alunos("ALUNOS.dat", ios::out);
    cout << "\nDigite os registros de alunos com as seguintes informacoes, respectivamente: numero de matricula, nome, curso, nota 1 e nota 2." << endl
         << "Para o melhor funcionamento do programa, escreva cada informacao separadas por espaco. Para encerrar o cadastro dos alunos, entre com o valor \"eof\"." << endl << endl;

    // Dados do resgistro do aluno
    unsigned int numeroDeMatricula;
    string nome = "";
    string curso = "";
    float nota1;
    float nota2;

    // Lendo dados 
    cout << "?  ";
    while(cin >> numeroDeMatricula >> nome >> curso >> nota1 >> nota2) {
        alunos << numeroDeMatricula << ' ' << nome << ' ' << curso << ' ' << nota1 << ' ' << nota2 << endl;
        cout << "?  ";
    }

    // Fecha o arquivo
    alunos.close();
    cout << endl << endl << "Escrita finalizada..." << endl << endl;

    return 0;
}