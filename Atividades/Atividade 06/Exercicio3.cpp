/*
    Laboratório de Técnicas de Programação II - Aula 24/03/2023
    Para um nome digitado pelo usuario, o sistema deve gerar um login automaticamente seguindo o seguinte modelo:
    Matheus Paulino Ribeiro -> mpribeiro
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string nome;
    cout << "Digite o nome completo: ";
    getline(cin, nome);

    string login;
    size_t pos = nome.find(" ");
  
    if(pos == string::npos) {
        login = tolower(nome[0]);
        login += nome.substr(1);
        return 0;
    }

    login += tolower(nome[0]);
    size_t sobrenomes = count(nome.begin() + pos + 1, nome.end(), ' ') + 1;
    if(sobrenomes == 1) {
        login += tolower(nome[pos + 1]);
        login += nome.substr(pos + 2);
    } else if(sobrenomes >= 2) {
        while (pos != string::npos && pos <= nome.find_last_of(" ")) {
            login += tolower(nome[pos + 1]);
            pos = nome.find(" ", pos + 1);
        }
        login += nome.substr(nome.find_last_of(" ") + 2);
    }

    cout << "Nome completo: " << nome << endl;
    cout << "Login: " << login << endl;

    return 0;
}