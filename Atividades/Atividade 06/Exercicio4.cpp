/*
    Laboratório de Técnicas de Programação II - Aula 24/03/2023
    Para um nome digitado pelo usuario, o sistema deve reescreve-lo da seguinte maneira:
    Matheus Paulino Ribeiro -> Ribeiro, M. P.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    string nome;
    cout << "Digite um nome: ";
    getline(cin, nome);
        
    string citacao;
    citacao = toupper(nome[0]);
    citacao += ". ";

    size_t pos = nome.find(" ");
    while(pos != nome.find_last_of(" ")) {
        citacao += toupper(nome[pos + 1]);
        citacao += ". ";
        pos = nome.find(" ", pos + 1);
    }

    citacao.insert(0, nome.substr(pos + 1, nome.length() - 1).append(", "));
    cout << "Citacao: " << citacao << endl;
    
    return 0;
}