#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::ofstream fw("saida.txt");    // O modo file-open padrao e 'out'
    fw << "Guardando alguma coisa no arquivo\n";
    fw.close();

    // E boa pratica fechar a leitura antes de iniciar a escrita
    std::ifstream fr("saida.txt", std::ios::in);
    std::string buf;
    char c;

    getline(fr, buf);
    std::cout<<buf<<std::endl;
    
    fr.seekg(4, std::ios::beg);
    fr.get(c);
    std::cout << c << std::endl;

    fr.seekg(-7, std::ios::end); // Deve-se saber o que existe no final do arquivo (caracteres nao "visiveis"), pois a contagem para o posicionamento é feito a partir deles. (eof, \n)
    fr.get(c);
    std::cout << c << std::endl;

    fr.seekg(10, std::ios::beg);
    getline(fr, buf);
    std::cout << buf << std::endl;

    fr.close();
    return 0;
}