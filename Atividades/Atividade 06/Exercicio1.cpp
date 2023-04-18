/*
    Laboratório de Técnicas de Programação II - Aula 24/03/2023
    Trocar todas ocorrencias da palavra ALUNO por ESTUDANTE e a palavra ESCOLA por UNIVERSIDADE, 
    assumindo que essas palavras aparecam no maximo uma vez.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    string frase;
    cout << "\nDigite uma frase que contenha as palavras ALUNO ou ESTUDANTE: ";
    getline(cin, frase); 

    size_t alunoEncontrado = frase.find("ALUNO");
    size_t escolaEncontrada = frase.find("ESCOLA");
    
    if (alunoEncontrado == string::npos && escolaEncontrada == string::npos) {
        cout << "Nao ha palavras a serem modificadas.\n\n";
        return 0;
    }    
    
    
    if(alunoEncontrado != string::npos)
        frase.replace(alunoEncontrado, 5, "ESTUDANTE");
        escolaEncontrada += 4; // Apos o replace, o indice da palavra escola, se houver, sera deslocado para frente, sendo necessario ajustar este indice

    if(escolaEncontrada != string::npos)
        frase.replace(escolaEncontrada, 6, "UNIVERSIDADE");

    cout << endl << "Resultado: " << frase << endl << endl;
    return 0;
}