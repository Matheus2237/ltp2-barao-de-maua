/*
    Laboratório de Técnicas de Programação II - Aula 24/03/2023
    Para toda ocorrencia da palavra TECLADO em uma frase, deve ser concatenado logo apos o texto OU MOUSE.
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string frase;
    getline(cin, frase);

    size_t pos;
    while ((pos = frase.find("TECLADO", pos)) != string::npos) {
        frase.insert(pos + 8, " OU MOUSE");
        pos += 16;
    }
    
    cout << frase << endl;
    return 0;
}