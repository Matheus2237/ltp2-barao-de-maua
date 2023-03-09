/*
    Laboratório de Técnicas de Programação II - Aula 07/03/2023
    Criar uma estrutura do tipo DadosALuno e armazenar os valores lidos em uma variável deste tipo.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

struct DadosAluno {
    float media;
    int idade;
};
typedef struct DadosAluno DadosAluno; 

int main() {
    DadosAluno aluno;

    // Solicita a media do aluno 
    cout << endl << "Digite a media do aluno: ";
    cin >> aluno.media;

    // Solicita a idade do aluno
    cout << endl << "Digite a idade do aluno: ";
    cin >> aluno.idade;

    // Imprime as informacoes do aluno 
    cout << endl << "O aluno possui a media " << aluno.media << " e a idade " <<  aluno.idade << "." << endl << endl;

    return 0;
}
