/*
    Laboratório de Técnicas de Programação II - Aula 16/05/2023
    Para o arquivo ALUNOS.dat criado nas atividades anteriores, 
    montar um sistema que mostre as informações sobre as médias dos alunos.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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
int encontraQuantidade(const string filename);

int main() {
    
    cout << endl <<"Registros de Notas dos Alunos" << endl;
    
    const string FILENAME = "ALUNOS.dat";
    ifstream alunos(FILENAME, ios::in);
    Aluno aluno;
    
    int quantidadeAlunos = encontraQuantidade(FILENAME);
    Aluno *vetorAlunos = new Aluno[quantidadeAlunos]; 
    int indice = 0;

    // a) Imprimir todos os alunos na tela
    alunos.seekg(0);
    cout << endl << "Imprimindo todos os alunos..." << endl;
    while(alunos >> aluno.numero >> aluno.nome >> aluno.nomeCurso >> aluno.n1 >> aluno.n2) {
        aluno.media = (aluno.n1 + aluno.n2) / 2;
        vetorAlunos[indice] = aluno;
        indice++;
        imprimeAluno(aluno);
    }

    // b) Imprimir apenas alunos aprovados
    cout << endl << "Imprimindo os alunos aprovados..." << endl;
    for (int i = 0; i < indice; i++) {
        if (vetorAlunos[i].media >= 7) {
            imprimeAluno(vetorAlunos[i]);
        }
    }

    // c) Imprimir apenas alunos reprovados
    cout << endl << "Imprimindo os alunos reprovados..." << endl;
    for (int i = 0; i < indice; i++) {
        if (vetorAlunos[i].media < 3) {
            imprimeAluno(vetorAlunos[i]);
        }
    }

    // d) Imprimir apenas alunos de recuperacao
    cout << endl << "Imprimindo os alunos em recuperacao..." << endl;
    for (int i = 0; i < indice; i++) {
        if (vetorAlunos[i].media >=3 && vetorAlunos[i].media < 7) {
            imprimeAluno(vetorAlunos[i]);
        }
    }

    alunos.close();
    return 0;
}

void imprimeAluno(Aluno aluno) {
    cout << right << setw(3) << aluno.numero << ' ' << 
            left << setw(10) << aluno.nome << ' ' << 
            left << setw(3) << aluno.nomeCurso << ' ' << 
            left << setprecision(2) << aluno.media << '\n';
}

int encontraQuantidade(const string filename) {
    ifstream contagemAlunos(filename, ios::in);
    int tamanho = 0;
    string descarte = "";
    while(!contagemAlunos.eof()) {
        getline(contagemAlunos, descarte, '\n');
        tamanho++;
    }
    return tamanho;
}