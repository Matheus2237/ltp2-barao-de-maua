/*
    Laboratório de Técnicas de Programação II - 09/05/2023
    Abrir o arquivo "Alunos_CC" criado no exercicio 1 e imprimir todo o conteudo contido nele.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Abrindo o arquivo para leitura
    cout << endl << "Lendo os registros..." << endl << endl;
    ifstream alunos("Alunos_CC", ios::in);

    // Imprimindo os registros
    string registro = "";
    while(!alunos.eof()) {
        getline(alunos, registro, '\n');
        cout << registro << endl;
    }

    // Fechando o arquivo
    alunos.close();
    cout << "Fim da leitura..." << endl << endl;

    return 0;
}