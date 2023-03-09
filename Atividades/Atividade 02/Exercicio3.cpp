/*
    Laboratório de Técnicas de Programação II - Aula 07/03/2023
    Criar a estrutura de um livro, atribuir 5 livros a um vetor e calcular a media do numero de paginas dos livros.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>

using namespace std;

struct Livro {
    string titulo;
    int ano;
    int paginas;
    double preco;
};
typedef struct Livro Livro;

void populate(Livro vector[5]);

int main() {
    Livro livros[5];

    // Recebe informacoes de 5 livros do usuario
    cout << endl << "Por favor, cadastre 5 livros." << endl;
    populate(livros);

    //Calcula a media de paginas dos 5 livros e exibe ao usuario
    int somaPaginas = 0;
    for (int i = 0; i < 5; i++) {
        somaPaginas += livros[i].paginas;
    }
    int media = somaPaginas / 5;
    cout << "A media do numero de paginas cadastradas e " << media << "." << endl;
}

void populate(Livro vector[5]) {
    for (int i = 0; i < 5; i++) {
        Livro livro;
        
        cout << endl << "Livro " << i + 1 << endl; // Indica ao usuario sobre qual livro as informacoes estao sendo cadastradas
        cout << endl << "Digite o titulo: "; // Solicita o titulo do livro 
        cin >> livro.titulo;
        cout << endl << "Digite o ano de publicacao: "; // Solicita o ano de publicacao do livro
        cin >> livro.ano;
        cout << endl << "Digite o numero de paginas do livro: "; // Solicita o numero de paginas do livro
        cin >> livro.paginas;
        cout << endl << "Digite o preco: "; // Solicita o preco do livro
        cin >> livro.preco;
 
        vector[i] = livro; // atribui o livro ao vetor na posicao da iteracao do for
    }
}
