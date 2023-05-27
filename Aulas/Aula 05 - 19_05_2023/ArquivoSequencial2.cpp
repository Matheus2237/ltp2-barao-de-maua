#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::ofstream fw("saida.txt");    // O modo file-open padrao e 'out'
    fw<<"Guardando alguma coisa no arquivo\n";
    fw.close();

    // O ponteiro de put e get, apesar de terem nomes diferentes, sao o mesmo ponteiro
    std::string buf;
    std::fstream f("saida.txt", std::ios::in | std::ios::out);
    f.seekp(10, std::ios::beg);
    f.put('A');
    f.seekp(6, std::ios::cur);
    f.put('C');
    f.seekp(5, std::ios::cur);
    f.put('N');
    f.seekp(2, std::ios::cur);
    f.put('A');
    // f.clear(); // zera variaveis de estado da classe fstream, como por exemplo, o atributo eof
    f.seekg(0);
    getline(f, buf);
    std::cout << buf << std::endl;

    f.close();
    return 0;
}