#include <iostream>
#include <fstream>
#include <string>

typedef struct {
    int x;
    double d;
} Registro;

int main() {
    const int tam = 3;

    std::fstream f; // Abre apenas para entrada e saida em modo texto e nao e possivel sobrescrever os modulos depois de utilizar o construtor
    f.open("registro.dat", std::ios::in | std::ios::out | std::ios::binary);
    f.seekp(1 * sizeof(Registro), std::ios::beg);

    Registro temp{4, 4.2};
    f.write(reinterpret_cast<char *>(&temp), sizeof(Registro));

    f.seekg(0, std::ios::beg);
    
    Registro registros_l[3];
    f.read(reinterpret_cast<char *>(&registros_l), 3 * sizeof(Registro));
    
    for (int i = 0; i < 3; i++)
        std::cout << registros_l[i].x << ", " << registros_l[i].d << std::endl;
    f.close();

    return 0;
}