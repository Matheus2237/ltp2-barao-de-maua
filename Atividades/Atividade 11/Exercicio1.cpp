/*
    Laboratório de Técnicas de Programação II - Aula 09/05/2023
    Criar um arquivo com nome "Alunos_CC" e armazenar dentro dele 3 registros com: numero da matricula, nome e email.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    int qtdSolicitadaDeAlunos = 3; // Quantidade solicitada de registros
    ofstream alunos("Alunos_CC", ios::out); // Criando o arquivo para escrita

    cout << "\nDigite o registro de 3 alunos com as seguintes informacoes, respectivamente: numero de matricula, nome e email." << endl
         << "Para o melhor funcionamento do programa, escreva cada informacao separadas por espaco." << endl << endl;

    // Dados do resgistro do aluno
    unsigned int numeroDeMatricula;
    string nome = "";
    string email = "";

    // Espera do usuario a escrita dos 3 arquivos
    for (int i = 0; i < qtdSolicitadaDeAlunos; i++) {
        cout << "? ";
        cin >> numeroDeMatricula >> nome >> email;
        alunos << numeroDeMatricula << ' ' << nome << ' ' << email << endl;
    }
    
    // Fecha o arquivo
    alunos.close();
    cout << endl << "Escrita finalizada..." << endl << endl;

    return 0;
}