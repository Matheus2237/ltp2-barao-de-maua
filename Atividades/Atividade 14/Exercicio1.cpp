/*
    Laboratório de Técnicas de Programação II - Aula 25/05/2023
    Escrever um arquivo binario, em que cada registro e composto por um vendedor,
    e permitir realizar operacoes de consulta e edicao no arquivo. 
    @author: Matheus Paulino Ribeiro <mathpaulinor@gmail.com>
*/

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

typedef struct {
    int codigoVendedor;
    char nome[30];
    double valorVenda;
    int mes;
} Vendedor;

void inicializaArquivoDeVendedores(std::fstream& arquivo);
void exibeLista(std::fstream& arquivo);
int lerOpcao(std::fstream& arquivo);
void exibirOpcoes(std::fstream& arquivo);
void registraNovoVendedor(std::fstream& arquivo);
template <typename T> T le_valor(std::string texto);
int controlaSeExiste(std::fstream& arquivo, int comparable, std::string type);
void imprimeVendedor(Vendedor vendedor);
bool vendedorValido(Vendedor vendedor);
void excluiVendedor(std::fstream& arquivo);
int controlaCodigo(int codigo);
int controlaMes(int mes);
bool existeCodigo(std::fstream& arquivo, int codigo);
bool existeMes(std::fstream& arquivo, int mes);
void consultarTotalVendas(std::fstream& arquivo);
void alterarValorDaVenda(std::fstream& arquivo);

const std::string ARQUIVO = "vendas.dat";

int main(void) {
    //Inicializando o programa
    std::cout << "\nRegistro de Vendedores\n\nLista de Vendedores:\n";
    std::fstream vendas;
    
    // Inicializando arquivo com informacoes pre cadastradas
    inicializaArquivoDeVendedores(vendas);

    bool keepRunning = true;
    int opcao;
    while (keepRunning) {
        opcao = lerOpcao(vendas);    
        switch (opcao) {
        case 1:
            try { registraNovoVendedor(vendas); }
            catch(std::exception& e) { std::cout << std::endl << e.what(); };
            break;
        case 2:
            consultarTotalVendas(vendas);
            break;
        case 3:
            alterarValorDaVenda(vendas);
            break;
        case 4:
            excluiVendedor(vendas);
            break;
        case 0:
            keepRunning = false;
            break;
        default:
            break;
        }
    }

    // Encerrando o programa
    std::cout << "\nEncerrando o programa...\n"; 
    return 0;
}

void inicializaArquivoDeVendedores(std::fstream& arquivo) {
    arquivo.open(ARQUIVO, std::ios::out | std::ios::binary);
    std::vector<Vendedor> vendedores; 
    vendedores.push_back({1, "Matheus", 5000, 1});
    vendedores.push_back({2, "Ana", 4000, 2});
    vendedores.push_back({3, "Lucas", 2500, 4});
    for (const Vendedor& vendedor : vendedores)
        arquivo.write(reinterpret_cast<const char*>(&vendedor), sizeof(Vendedor));
    arquivo.close();
}

void exibeLista(std::fstream& arquivo) {
    std::cout << std::endl;
    arquivo.open(ARQUIVO, std::ios::in | std::ios::binary);
    Vendedor vl;;
    while (arquivo.read(reinterpret_cast<char*>(&vl), sizeof(Vendedor)))
        if(vendedorValido(vl))
            imprimeVendedor(vl);
    arquivo.close();
}

int lerOpcao(std::fstream& arquivo) {
    exibirOpcoes(arquivo);
    int opcao;
    std::cin >> opcao;
    return opcao;
}

void exibirOpcoes(std::fstream& arquivo) {
    exibeLista(arquivo);
    std::cout << "\n[1] Cadastrar vendedor do mes"
              << "\n[2] Consultar valor total de vendas de um vendedor"
              << "\n[3] Alterar valor de uma venda" 
              << "\n[4] Excluir vendedor"
              << "\n[0] Sair\n"
              << "\n ? ";
}

void registraNovoVendedor(std::fstream& arquivo) {
    std::cout << std::endl;
    
    Vendedor vendedor;
    vendedor.codigoVendedor = controlaSeExiste(arquivo, controlaCodigo(le_valor<int>("Codigo do vendedor")), "codigo");
    std::strncpy(vendedor.nome, le_valor<std::string>("Nome").c_str(), sizeof(vendedor.nome) - 1);
    vendedor.nome[sizeof(vendedor.nome) - 1] = '\0';
    vendedor.valorVenda = le_valor<double>("Venda");
    vendedor.mes = controlaSeExiste(arquivo, controlaMes(le_valor<int>("Mes")), "mes");
    
    arquivo.open(ARQUIVO, std::ios::app | std::ios::binary);
    arquivo.write(reinterpret_cast<char*>(&vendedor), sizeof(Vendedor));
    arquivo.close();
}

template <typename T>
T le_valor(std::string texto) {
    T valor;
    std::cout << texto << ": ";
    std::cin >> valor;
    return valor;
}

int controlaSeExiste(std::fstream& arquivo, int comparable, std::string type) {
    arquivo.open("vendas.dat", std::ios::in | std::ios::binary);
    Vendedor vl;
    while (arquivo.read(reinterpret_cast<char*>(&vl), sizeof(Vendedor))) {
        if(type == "codigo" && vl.codigoVendedor == comparable ||
            type == "mes" && vl.mes == comparable) {
            arquivo.close();
            std::stringstream erro;
            erro << "O valor informado para " << type << " ja existe no arquivo.\n";
            throw std::out_of_range(erro.str());
        }
    }
    arquivo.close();
    return comparable;
}

void imprimeVendedor(Vendedor vendedor) {
    std::cout << vendedor.codigoVendedor << ' ' << vendedor.nome << ' ' << vendedor.valorVenda << ' ' << vendedor.mes << std::endl;
}

bool vendedorValido(Vendedor vendedor) {
    return vendedor.codigoVendedor != 0;
}

void excluiVendedor(std::fstream& arquivo) {
    std::cout << std::endl;
    try {
        int codigo = controlaCodigo(le_valor<int>("Codigo"));
        if (!existeCodigo(arquivo, codigo)) {
            std::cout << "\nVendedor nao registrado.\n";
            return;
        }

        // Extraindo os vendedores que sao diferentes do codigo lido
        arquivo.open(ARQUIVO, std::ios::in | std::ios::binary);
        std::vector<Vendedor> vendedores;
        Vendedor vTemp;
        while (arquivo.read(reinterpret_cast<char*>(&vTemp), sizeof(Vendedor)))
            if (vTemp.codigoVendedor != codigo)
                vendedores.push_back(vTemp);
        arquivo.close();

        // Reescrevendo o arquivo com os vendedores remanescentes
        arquivo.open(ARQUIVO, std::ios::out | std::ios::binary);
        for (Vendedor vendedor : vendedores)
            arquivo.write(reinterpret_cast<const char*>(&vendedor), sizeof(Vendedor));
        arquivo.close();
    } catch(std::exception& e) {
        std::cout << std::endl << e.what();
    }
}

int controlaCodigo(int codigo) {
    if (codigo <= 0)
        throw std::invalid_argument("Codigo de vendedor invalido\n");
    return codigo;
}

int controlaMes(int mes) {
    if (mes <= 0 || mes > 12)
        throw std::invalid_argument("Mes invalido\n");
    return mes;
}

bool existeCodigo(std::fstream& arquivo, int codigo) {
    arquivo.open(ARQUIVO, std::ios::in | std::ios::binary);
    Vendedor vTemp;
    while (arquivo.read(reinterpret_cast<char*>(&vTemp), sizeof(Vendedor))) {
        if (vTemp.codigoVendedor == codigo) {
            arquivo.close();
            return true;
        }
    }
    arquivo.close();
    return false;
}

bool existeMes(std::fstream& arquivo, int mes) {
    arquivo.open(ARQUIVO, std::ios::in | std::ios::binary);
    Vendedor vTemp;
    while (arquivo.read(reinterpret_cast<char*>(&vTemp), sizeof(Vendedor))) {
        if (vTemp.mes == mes) {
            arquivo.close();
            return true;
        }
    }
    arquivo.close();
    return false;
}

void consultarTotalVendas(std::fstream& arquivo) {
    std::cout << std::endl;
    try {
        int codigo = controlaCodigo(le_valor<int>("Codigo"));
        if (!existeCodigo(arquivo, codigo)) {
            std::cout << "\nVendedor nao registrado.\n";
            return;
        }

        arquivo.open(ARQUIVO, std::ios::in | std::ios::binary);
        double valorVenda = 0;
        std::string nome = "";
        Vendedor vendedor;
        while (arquivo.read(reinterpret_cast<char*>(&vendedor), sizeof(Vendedor))) {
            if (vendedor.codigoVendedor == codigo) {
                valorVenda = vendedor.valorVenda;
                nome = vendedor.nome;
            }
        }
        arquivo.close();
        
        std::cout << "\nValor total de vendas do(a) vendedor(a) " << nome << " [" << codigo << "]: " << valorVenda << std::endl;
    } catch(std::exception& e) {
        std::cout << std::endl << e.what();
    }
}

void alterarValorDaVenda(std::fstream& arquivo) {
    std::cout << std::endl;
    try {
        int mes = controlaMes(le_valor<int>("Mes"));
        if (!existeMes(arquivo, mes)) {
            std::cout << "\nMes sem venda registrada.\n";
            return;
        }

        arquivo.open(ARQUIVO, std::ios::in | std::ios::binary);        
        std::vector<Vendedor> vendedores;
        Vendedor vTemp;
        while(arquivo.read(reinterpret_cast<char*>(&vTemp), sizeof(Vendedor))) {
            if (vTemp.mes == mes) {
                vTemp.valorVenda = le_valor<double>("Valor da venda");
                vendedores.push_back(vTemp);
            }
            else { vendedores.push_back(vTemp); }
        }
        arquivo.close();

        arquivo.open(ARQUIVO, std::ios::out | std::ios::binary);
        for (Vendedor vendedor : vendedores)
          arquivo.write(reinterpret_cast<const char*>(&vendedor), sizeof(Vendedor));
        arquivo.close();
    } catch(std::exception& e) {
        std::cout << std::endl << e.what();
    }
}