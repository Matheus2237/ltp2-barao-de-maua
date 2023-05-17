/*
    Laboratório de Técnicas de Programação II - Aula 16/05/2023
    Repetindo o exercicio 1, porem utilizando a estrutura Vector.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

typedef struct {
    int numero;
    string nome;
    string nomeCurso;
    float n1;
    float n2;
    float media;
} Aluno;

void imprimeAluno(Aluno aluno);

int main() {
    
    cout << endl <<"Registros de Notas dos Alunos" << endl;
    ifstream arquivoAlunos("ALUNOS.dat", ios::in);
    vector<Aluno> alunos; 

    // a) Imprimir todos os alunos na tela
    cout << endl << "Imprimindo todos os alunos..." << endl;
    Aluno aluno;
    while(arquivoAlunos >> aluno.numero >> aluno.nome >> aluno.nomeCurso >> aluno.n1 >> aluno.n2) {
        aluno.media = (aluno.n1 + aluno.n2) / 2;
        alunos.push_back(aluno);
        imprimeAluno(aluno);
    }

    // b) Imprimir apenas alunos aprovados
    cout << endl << "Imprimindo os alunos aprovados..." << endl;
    for (Aluno aluno : alunos) {
        if (aluno.media >= 7) {
            imprimeAluno(aluno);
        }
    }

    // c) Imprimir apenas alunos reprovados
    cout << endl << "Imprimindo os alunos reprovados..." << endl;
    for (Aluno aluno : alunos) {
        if (aluno.media < 3) {
            imprimeAluno(aluno);
        }
    }

    // d) Imprimir apenas alunos de recuperacao
    cout << endl << "Imprimindo os alunos em recuperacao..." << endl;
    for (Aluno aluno : alunos) {
        if (aluno.media >=3 && aluno.media < 7) {
            imprimeAluno(aluno);
        }
    }

    arquivoAlunos.close();
    return 0;
}

void imprimeAluno(Aluno aluno) {
    cout << right << setw(3) << aluno.numero << ' ' << 
            left << setw(10) << aluno.nome << ' ' << 
            left << setw(3) << aluno.nomeCurso << ' ' << 
            left << setprecision(2) << aluno.media << '\n';
}