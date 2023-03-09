/*
    Laboratório de Técnicas de Programação II - Aula 07/03/2023
    Cria um vetor do tipo DadosAluno, recebe 10 itens deste tipo e exibe ao usuario.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct DadosAluno {
    double media;
    int idade;
};
typedef struct DadosAluno DadosAluno; 

void populateAlunosIn(DadosAluno *vetor);
string getDataFrom(DadosAluno aluno, int posicao    );

int main() {
    DadosAluno alunos[10];

    // Popula o vetor com dados digitados pelo usuario
    cout << endl << "Por favor, cadastre 10 alunos." << endl;
    populateAlunosIn(alunos);

    // Imprime na tela os dados obtidos.
    cout.precision(2);
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << getDataFrom(alunos[i], i);
    }
    
    return 0;
}

void populateAlunosIn(DadosAluno vector[]) {
    for (int i = 0; i < 10; i++) {
        DadosAluno aluno;
        
        cout << endl << "Aluno " << i + 1 << endl; // Indica ao usuario sobre qual aluno as informacoes estao sendo cadastradas
        cout << endl << "Digite a media do aluno: "; // Solicita a media do aluno 
        cin >> aluno.media;
        cout << endl << "Digite a idade do aluno: "; // Solicita a idade do aluno
        cin >> aluno.idade;
 
        vector[i] = aluno; // atribui o aluno ao vetor na posicao da iteracao do for
    }
}

string getDataFrom(DadosAluno aluno, int posicao) {
    return "O aluno " + to_string(posicao) + " possui a media " + to_string(aluno.media) + " e a idade " + to_string(aluno.idade) + ".\n";
}