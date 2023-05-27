#include <iostream>
#include <fstream>
#include <string>

typedef struct {
    int x;
    double d;
} Registro;

int main() {
    const int tam = 4;
    Registro registros[tam] = {{1, 1.1}, {2, 2.2}, {3, 3.3}};

    std::fstream f("registro.dat", std::ios::out | std::ios::binary); // Informa que e um arquivo para escrita e que esta em modo binario
    // Arquivos binarios nao funcionam com operadores de fluxo, pois nao ha mais um fluxo de caracteres e sim os dados da memoria sendo escritos direto no arquivo
    f.write(reinterpret_cast<char*>(registros), tam * sizeof(Registro)); // Recebe como parametros o ponteiro que aponta para o endereco de memoria do que sera escrito e o tamanho do bloco que sera escrito (em bytes)
    f.close();

    f.open("registro.dat", std::ios::in | std::ios::binary);
    f.seekg(1 * sizeof(Registro), std::ios::beg);

    Registro temp;
    f.read(reinterpret_cast<char *>(&temp), sizeof(Registro));
    std::cout << temp.x << ", " << temp.d << std::endl;
    f.close();

    return 0;
}