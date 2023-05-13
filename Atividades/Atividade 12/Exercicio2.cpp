/*
    Laboratório de Técnicas de Programação II - Aula 12/05/2023
    Incluir alunos no arquivo criado no Exercicio 1, considerando que não podem existir dois alunos com o mesmo número.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool existeAluno(int numeroDeMatricula, string arquivos);

int main() {

    const string ARQUIVO_DE_ALUNOS = "ALUNOS.dat";
    ofstream outAlunos(ARQUIVO_DE_ALUNOS, ios::app);
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
        if (!existeAluno(numeroDeMatricula, ARQUIVO_DE_ALUNOS)) {
            outAlunos << numeroDeMatricula << ' ' << nome << ' ' << curso << ' ' << nota1 << ' ' << nota2 << endl;
            cout << "?  ";
        } else {
            cout << "Este numero de matricula ja esta cadastrado. Escrita nao realizada. Por favor, tente novamente.\n?  ";
        }
    }

    // Fecha o arquivo de escrita
    outAlunos.close();
    cout << endl << endl << "Escrita finalizada..." << endl << endl;

    return 0;
}

bool existeAluno(int numeroDeMatricula, string arquivo) {
    ifstream inAlunos(arquivo, ios::in);
    bool retorno = true;
    unsigned int numeroDeVerificacao;
    
    // Variaveis temporarias com informacoes que serao descartadas
    string nomeTemp = "";
    string cursoTemp = "";
    float nota1Temp;
    float nota2Temp;
    
    // Se encontrar algum aluno retorna true
    while(inAlunos >> numeroDeVerificacao >> nomeTemp >> cursoTemp >> nota1Temp >> nota2Temp) {
        if (numeroDeMatricula == numeroDeVerificacao) {
            inAlunos.close();
            return true;
        }
    }
    
    // Se nao encontrar nenhum retorna false
    inAlunos.close();
    return false;
}