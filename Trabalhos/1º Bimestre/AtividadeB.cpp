/**
 * @file AtividadeB.cpp
 * @date 2023-03-28
 * @brief Laboratório de Técnicas de Programação II - Trabalho 1° Bimestre - Atividade B
 *      Sistema para uma empresa financeira. Possibilita o gerenciamento de seus clientes e 
 *      dos empréstimos feitos por cada um.    
 * @author Carlos Sérgio Fernandes Júnior - 2157633 <carlos_fernandes.1@hotmail.com>
 * @author Matheus Paulino Ribeiro - 2143432 <mathpaulinor@gmail.com>
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <optional>

using namespace std;

struct Endereco {
    string logradouro;
    int numero;
    string complemento;
    string bairro;
    string cidade;
    string estado;
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Parcela {
    Data dataDeVencimento;
    Data dataDePagamento;
    bool parcelaPaga = false; // Inicializado como false pois as parcelas incialmente nao sao pagas
};

struct Emprestimo {
    float valor = 0; // Inicializado como zero pois e utilizado para checar se o cliente possui emprestimo ou nao
    int numeroDeParcelas;
    float ValorDasParcelas;
    Data dataDeEmprestimo;
    Parcela *parcelas;
};

struct Cliente {
    string nome;
    string cpf;
    Endereco endereco;
    Data data;
    Emprestimo emprestimo;
};  

typedef struct Endereco Endereco;
typedef struct Data Data;
typedef struct Emprestimo Emprestimo;
typedef struct Parcela Parcela;
typedef struct Cliente Cliente;

void cadastraNovoCliente(Cliente clientes[], int tamanho); /// Cadastra um novo cliente no vetor.
Endereco cadastraEndereco(); /// Cadastra o enedereco do cliente.
Data cadastraData(string tipoData); /// Cadastra uma data valida.
bool validarData(Data data); /// Valida datas.
bool anoBissexto(int ano); /// Verifica se o ano e bissexto ou  nao.
void mostrarInformacoesCliente(Cliente clientes[], int tamanho); /// Exibe os dados do cliente na tela.
int buscaIndiceCliente(Cliente clientes[], string cpf, int tamanho); /// Busca pelo indice de um cliente no vetor.
Cliente buscarCliente(Cliente clientes[], string cpf, int tamanho); /// Busca pelo cliente no vetor a partir de seu CPF.
int leNaturalNaoNulo(string errorMessage); /// Realiza a leitura de um numero natural diferente de zero.
int leAcao(); /// Realiza a leitura um numero inteiro que represente uma acao valida.
int leParcela(string message); /// Realiza a leitura do numero de parcelas do emprestimo.
float leRealMaiorQueZero(string errorMessage); /// Realiza a leitura de um numero real maior que 0.
string leCpf(); /// Realiza a leitura de um CPF valido.
string enderecoToString(Endereco endereco); /// Formata o endereco para exibicao.
string dataToString(Data data); /// Formata a data para exibicao.
void cadastrarEmpestimo(Cliente clientes[], int tamanho); /// Cadastra um emprestimo a um cliente, calcula o valor das parcelas e suas datas de vencimento.
int getMaiorDiaVencimento(int dia, int mes, int ano); /// Corrige as datas de vencimento de acordo com o maior dia existente em cada mes.
void cadastrarParcelaPaga(Cliente clientes[], int tamanho); /// Realiza o cadastro do pagamento de uma parcela do emprestimo de um cliente.
void mostrarEmprestimo(Cliente cliente); /// Exibe as informacoes sobre o emprestimo de um cliente.
void mostrarParcelas(Cliente cliente); /// Exibe as informacoes sobre as parcelas de um cliente.
void excluirCliente(Cliente clientes[], int tamanho); /// Exclui um cliente do vetor de clientes.
void editarInformacoesCliente(Cliente clientes[], int tamanho); // Realiza a edicao das informacoes do cliente.
Endereco editarEndereco(Cliente clientes[], int indice); /// Realiza a edicao do endereco de um cliente cadastrado no vetor de clientes.
Data editarData(Cliente clientes[], int indice); /// Realiza a edicao da data de um cliente cadastrado no vetor de clientes.
bool clienteExistente(string cpf, Cliente clientes[], int tamanho); /// Checa se um determinado CPF esta cadastrado no vetor de clientes.
int buscarIndiceVago(Cliente clientes[], int tamanho); /// Busca em um vetor de clientes o primeiro cliente disponivel para cadastro.
bool confirmarAcao(); /// Recebe do usuario a confirmacao de que deseja prosseguir ou nao com uma acao.
optional<string> leStringEdicao(); /// Le uma entrada do usuario para ser utilizada na edicao de dados que pode ser vazia ou nao.
optional<int> leNumeroEdicaoNaturalNaoNulo(string errorMessage); /// Le a entrada do usuario que pode ser vazia ou nao e verifica se e um numero valido ou nao.
bool ehNumeroValido(string num); /// Verifica se a entrada contem somente digitos numericos.

/// Acoes realizadas pelo menu.
const int CADASTRAR_CLIENTE = 1;
const int VISUALIZAR_CLIENTE = 2;
const int ATUALIZAR_CLIENTE = 3;
const int PAGAR_PARCELA = 4;
const int CADASTRAR_EMPRESTIMO = 5;
const int EXCLUIR_CLIENTE = 6;
const int SAIR = 7;

int main() {
    
    cout << endl << "Inicializando o programa..." << endl;

    cout << endl << "Digite a quantidade de clientes: ";
    int tamanho = leNaturalNaoNulo("Entrada invalida. Tente novamente.\nDigite a quantidade de clientes: ");
    Cliente *clientes = new Cliente[tamanho]; 
    
    bool system = true;
    while(system) {
        cout << endl <<
            "========================" << endl <<
            "   Sistema Financeiro" << endl <<
            "========================" << endl << endl <<
            "   [1] Cadastrar cliente" << endl <<
            "   [2] Visualizar as informacoes de um cliente" << endl <<
            "   [3] Editar as informacoes de um cliente" << endl <<
            "   [4] Cadastrar parcela paga" << endl <<
            "   [5] Cadastrar emprestimo" << endl <<
            "   [6] Excluir cliente" << endl <<
            "   [7] Sair" << endl; 

        cout << endl << "Escolha qual acao deseja realizar: ";
        int acao = leAcao();
        switch (acao) {
        case CADASTRAR_CLIENTE:
            cadastraNovoCliente(clientes, tamanho);
            break;
        case VISUALIZAR_CLIENTE:
            mostrarInformacoesCliente(clientes, tamanho);
            break;
        case ATUALIZAR_CLIENTE:
            editarInformacoesCliente(clientes, tamanho);
            break;
        case PAGAR_PARCELA:
            cadastrarParcelaPaga(clientes, tamanho);
            break;
        case CADASTRAR_EMPRESTIMO:
            cadastrarEmpestimo(clientes, tamanho);
            break;
        case EXCLUIR_CLIENTE:
            excluirCliente(clientes, tamanho);
            break;
        case SAIR:
            if(!confirmarAcao())
                continue;
            system = false;
            cout << endl << "Programa encerrado..." << endl << endl;
            break;
        default:
            break;
        }
    }
    
    delete [] clientes;
    return 0;
}

/**
 * @brief Cadastra um novo cliente no vetor caso este possua um espaco vazio para tal.
 * 
 * @param clientes Vetor que guarda as informacoes de todos os clientes cadastrados.
 * @param tamanho Tamanho do vetor.
 */
void cadastraNovoCliente(Cliente clientes[], int tamanho) {
    try {            
        int indice = buscarIndiceVago(clientes, tamanho);

        Cliente cliente;
        cout << endl << "Cadastrando novo cliente..." << endl; 
        
        cout << "Digite o CPF do cliente: ";
        cliente.cpf = leCpf();
        if(clienteExistente(cliente.cpf, clientes, tamanho)) {
            cout << endl << "Cliente ja cadastrado." << endl;
            return;
        }

        cout << "\tNome: ";
        getline(cin, cliente.nome);
        
        cliente.endereco = cadastraEndereco();
        cliente.data = cadastraData("\tData de nascimento: ");

        clientes[indice] = cliente;
        cout << endl << "Cliente cadastrado com sucesso!" << endl;
    } catch(out_of_range& ooa) {
        cerr << endl << ooa.what() << endl;
    }
}


/**
 * @brief Cadastra o enedereco do cliente.
 * 
 * @return A struct do tipo Endereco preenchida com as informaces validas.
 */
Endereco cadastraEndereco() {
    Endereco endereco;
    cout << "\tEndereco:" << endl;
    
    cout << "\t\tLogradouro: ";
    getline(cin, endereco.logradouro);
    
    cout << "\t\tNumero: ";
    endereco.numero = leNaturalNaoNulo("\t\tEntrada invalida. Tente novamente.\n\t\tNumero: ");

    cout << "\t\tComplemento: ";
    getline(cin, endereco.complemento);
    
    cout << "\t\tBairro: ";
    getline(cin, endereco.bairro);
    
    cout << "\t\tCidade: ";
    getline(cin, endereco.cidade);
    
    cout << "\t\tEstado (UF): ";
    getline(cin, endereco.estado);
    
    return endereco;
}

/**
 * @brief Cadastra uma data valida.
 * 
 * @param tipoData O tipo de data que esta sendo cadastrada.
 * @return Uma struct do tipo Data com valores validos.
 */
Data cadastraData(string tipoData) {
    Data data;
    bool dataValida = false;
    while(!dataValida) {
        cout << tipoData << endl;
        
        cout << "\t\tDia: ";
        data.dia = leNaturalNaoNulo("\tEntrada invalida.\n\t\tDia: ");
        
        cout << "\t\tMes: ";
        data.mes = leNaturalNaoNulo("\tEntrada invalida.\n\t\tMes: ");
        
        cout << "\t\tAno: ";
        data.ano = leNaturalNaoNulo("\tEntrada invalida.\n\t\tAno: ");

        if (!validarData(data)) {
            cout << endl << "\tData invalida.Tente novamente: " << endl << endl;
            continue;
        }

        dataValida = true;
    }
    return data;
}

/**
 * @brief Verifica se a data recebida possui um valor condizente com a realidade.
 * 
 * @param data Data a ser verificada.
 * @return True se for uma data valida.
 * @return False se nao for uma data valida.
 */
bool validarData(Data data) {
    if(data.mes > 12 || data.ano > 9999) return false;
    switch (data.mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(data.dia > 31) return false;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(data.dia > 30) return false;
            break;
        case 2:
            if(anoBissexto(data.ano) && data.dia == 29) return true;
            if(data.dia > 28) return false;
            break;
        default:
            return false;
            break;
    }
    return true;
}

/**
 * @brief Verifica se o ano recebido corresponde a um ano bissexto ou  nao.
 * 
 * @param ano Ano que sera verificado
 * @return True caso este ano for bissexto.
 * @return False caso este ano nao for bissexto.
 */
bool anoBissexto(int ano) {
    if (ano % 400 == 0) return true;
    if (ano % 100 != 0 && ano % 4 == 0) return true;
    return false;
}

/**
 * @brief Exibe os dados do cliente na tela, inclusive suas informacoes sobre o emprestimo e cada parcela;
 * 
 * @param clientes Vetor que guarda as informacoes de todos os clientes cadastrados.
 * @param tamanho Tamanho do vetor.
 */
void mostrarInformacoesCliente(Cliente clientes[], int tamanho){
    try {
        cout << endl << "Digite o CPF do cliente: ";
        string cpf = leCpf();
        Cliente cliente = buscarCliente(clientes, cpf, tamanho);
        cout << endl << "Exibindo informacoes do cliente..." << endl << endl 
            << "\tNome: " << cliente.nome << endl
            << "\tCPF: " << cliente.cpf << endl
            << "\tData de nascimento: " << dataToString(cliente.data) << endl
            << "\tEndereco: "  << enderecoToString(cliente.endereco) << endl; 
        if(cliente.emprestimo.valor != 0){
            mostrarEmprestimo(cliente);
            mostrarParcelas(cliente);
        }
        else
            cout << endl << "\tEsse cliente nao possui um emprestimo cadastrado." << endl;
    } catch(out_of_range &ooa) {
        cout << endl << ooa.what() << endl; 
    }
}

/**
 * @brief Busca pelo indice de um cliente no vetor a partir de seu CPF.
 * 
 * @param clientes Vetor que contem os clientes.
 * @param cpf CPF do cliente a ser procurado.
 * @param tamanho Tamanho do vetor.
 * @return O indice do elemento procurado no vetor.
 * @throws std::out_of_range Lanca uma excessao caso nao encontre o cliente no vetor.
 */
int buscaIndiceCliente(Cliente clientes[], string cpf, int tamanho) {
    for (int i = 0; i < tamanho; i++)
    {
        if (cpf == clientes[i].cpf)
        {
            return i;
        }
    }
    throw out_of_range("Cliente nao encontrado.");
}

/**
 * @brief Busca pelo cliente no vetor a partir de seu CPF.
 * 
 * @param clientes Vetor que contem os clientes.
 * @param cpf CPF do cliente a ser procurado.
 * @param tamanho Tamanho do vetor.
 * @return O cliente encontrado.
 */
Cliente buscarCliente(Cliente clientes[], string cpf, int tamanho) {
    int indice = buscaIndiceCliente(clientes, cpf, tamanho);    
    return clientes[indice];
}

/**
 * @brief Realiza a leitura de um numero natural diferente de zero.
 * 
 * @param errorMessage Mensagem de erro exibida caso a entrada seja invalida.
 * @return O numero natural nao nulo.
 */
int leNaturalNaoNulo(string errorMessage) {
    int numero;
    bool numeroValidado = false;
    while(!numeroValidado) {
        cin >> numero;
        
        if(cin.fail()) { // Verifica se houve erro na leitura da acao
            cout << errorMessage;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do comeco ate o limite da sua capacidade
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(cin.gcount() > 1) { // Verifica se ha caracteres nao numericos na leitura
            cout << errorMessage;
            continue;
        }

        if(numero <= 0) {
            cout << errorMessage;
            continue;
        }

        numeroValidado = true;
    }
    return numero;
}

/**
 * @brief Realiza a leitura um numero inteiro que represente uma acao valida.
 * 
 * @return O numero da acao valida.
 */
int leAcao() {
    int acao;
    bool acaoValida = false;
    while(!acaoValida) {
        acao = leNaturalNaoNulo("Acao invalida. Tente novamente.\nEscolha qual acao deseja realizar: ");
        if(acao <= 7)
            acaoValida = true;
        else
            cout << "Acao invalida. Tente novamente.\nEscolha qual acao deseja realizar: ";
    }
    return acao;
}

/**
 * @brief Realiza a leitura do numero de parcelas do emprestimo.
 * 
 * @param message Mensagem que sera exibida na leitura. 
 * @return Numero valido de parcelas.
 */
int leParcela(string message) {
    int parcelas;
    bool parcelasValidas = false;
    while(!parcelasValidas) {
        parcelas = leNaturalNaoNulo("\tEntrada invalida. " + message);
        if(parcelas <= 12)
            parcelasValidas = true;
        else
            cout << "\tNumero maximo de parcelas excedido. " << message;
    }
   return parcelas;
}

/**
 * @brief Realiza a leitura de um numero real maior que 0.
 * 
 * @param errorMessage Mensagem de erro exibida caso a entrada seja invalida.
 * @return O numero real valido.
 */
float leRealMaiorQueZero(string errorMessage) {
    float numero;
    bool numeroValidado = false;
    while(!numeroValidado) {
        cin >> numero;
        
        if(cin.fail()) { // Verifica se houve erro na leitura da acao
            cout << errorMessage;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do comeco ate o limite da sua capacidade
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(cin.gcount() > 1) { // Verifica se ha caracteres nao numericos na leitura
            cout << errorMessage;
            continue;
        }

        if(numero <= 0) {
            cout << errorMessage;
            continue;
        }

        numeroValidado = true;
    }
    return numero;

}

/**
 * @brief Realiza a leitura de um CPF valido.
 * 
 * @return O CPF valido.
 */
string leCpf() {
    string cpf;
    bool cpfValidado = false;
    while(!cpfValidado) {
        getline(cin, cpf);

        bool temDigito = false;
        for (int i = 0; i < cpf.length(); i++) // Verifica se ha caracteres nao numericos na leitura
            if(!isdigit(cpf[i]))
                temDigito = true;
        if(temDigito) {
            cout << "CPF invalido. Tente novamente.\nDigite o CPF do cliente: ";
            continue;
        }

        if(cpf.length() != 11) { // Verifica se o cpf tem mais de 11 digitos;
            cout << "CPF invalido. Tente novamente.\nDigite o CPF do cliente: ";
            continue;
        }
        
        cpfValidado = true;
    }
    return cpf;
}

/**
 * @brief Formata o endereco para exibicao.
 * 
 * @param endereco Struct de endereco que sera formatada.
 * @return O endereco formatado em string.
 */
string enderecoToString(Endereco endereco) {
    return string()
            .append(endereco.logradouro).append(", ")
            .append(to_string(endereco.numero)).append(", ")
            .append(empty(endereco.complemento) ? "" : endereco.complemento.append(", "))
            .append(endereco.bairro).append(", ")
            .append(endereco.cidade).append(", ")
            .append(endereco.estado);
}

/**
 * @brief Formata a data para exibicao.
 * 
 * @param data Struct de data que sera formatada.
 * @return A data formatada em string.
 */
string dataToString(Data data) {
    string dia = string().insert(0, 2 - to_string(data.dia).length(), '0').append(to_string(data.dia)); 
    string mes = string().insert(0, 2 - to_string(data.mes).length(), '0').append(to_string(data.mes));
    string ano = string().insert(0, 4 - to_string(data.ano).length(), '0').append(to_string(data.ano));
    return string().append(dia).append("/").append(mes).append("/").append(ano);
}

/**
 * @brief Cadastra um emprestimo a um cliente, calcula o valor das parcelas e suas datas de vencimento.
 * 
 * @param clientes Vetor de clientes.
 * @param tamanho Tamanho do vetor de clientes.
 */
void cadastrarEmpestimo(Cliente clientes[], int tamanho){
    try {
        cout << endl << "Digite o CPF do cliente: ";
        string cpf = leCpf();
        Cliente cliente = buscarCliente(clientes, cpf, tamanho);
        
        if(cliente.emprestimo.valor != 0) {
            cout << endl << "Este cpf ja possui um emprestimo cadastrado. Deseja sobrescreve-lo?";
            if(!confirmarAcao())
                return;
        }

        cout << endl << "Cadastrando emprestimo ao cliente..." << endl; 
        cout << endl << "\tDigite o valor do emprestimo: ";
        cliente.emprestimo.valor = leRealMaiorQueZero("\tEntrada inválida.Digite o valor do emprestimo: ");
        
        cout << "\tDigite o numero de parcelas: ";
        cliente.emprestimo.numeroDeParcelas = leParcela("Digite o numero de parcelas: ");
        
        cliente.emprestimo.ValorDasParcelas = cliente.emprestimo.valor / cliente.emprestimo.numeroDeParcelas;
        cout << setprecision(2) << fixed;
        cout << endl << "\tO valor das parcelas sera de: R$" << cliente.emprestimo.ValorDasParcelas << endl;
        
        cout << endl << "\tDigite a data do emprestimo: " << endl;
        cliente.emprestimo.dataDeEmprestimo = cadastraData("\tData do emprestimo: ");

        cliente.emprestimo.parcelas = new Parcela[cliente.emprestimo.numeroDeParcelas];
        for(int i = 0; i < cliente.emprestimo.numeroDeParcelas; i++){
            
            cliente.emprestimo.parcelas[i].parcelaPaga = false;
            cliente.emprestimo.parcelas[i].dataDeVencimento = cliente.emprestimo.dataDeEmprestimo;
            
            if(cliente.emprestimo.parcelas[i].dataDeVencimento.mes + i + 1 <= 12) {
                cliente.emprestimo.parcelas[i].dataDeVencimento.mes += i+1;
                cliente.emprestimo.parcelas[i].dataDeVencimento.dia = getMaiorDiaVencimento(cliente.emprestimo.parcelas[i].dataDeVencimento.dia,
                                                                                                cliente.emprestimo.parcelas[i].dataDeVencimento.mes,
                                                                                                cliente.emprestimo.parcelas[i].dataDeVencimento.ano);
            }
            else{
                cliente.emprestimo.parcelas[i].dataDeVencimento.mes += i + 1 - 12;
                cliente.emprestimo.parcelas[i].dataDeVencimento.ano += 1;
                cliente.emprestimo.parcelas[i].dataDeVencimento.dia = getMaiorDiaVencimento(cliente.emprestimo.parcelas[i].dataDeVencimento.dia,
                                                                                                cliente.emprestimo.parcelas[i].dataDeVencimento.mes,
                                                                                                cliente.emprestimo.parcelas[i].dataDeVencimento.ano);
            }
        }
        clientes[buscaIndiceCliente(clientes, cpf, tamanho)] = cliente;
        cout << endl << "Emprestimo cadastrado..." << endl;
    } catch(out_of_range &ooa) {
        cout << endl << ooa.what() << endl; 
    }
}

/**
 * @brief Corrige as datas de vencimento de acordo com o maior dia existente em cada mes.
 * 
 * @param dia Dia da data que sera corrigida se necessario.
 * @param ano Ano da data que sera corrigida.
 * @param mes Mês da data que sera corrigida.
 * @return Retorna o dia corrigido se necessario.
 */
int getMaiorDiaVencimento(int dia, int mes, int ano) {
    if(dia > 28) {
        switch (mes) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return (dia > 31) ? 31 : dia;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                return (dia > 30) ? 30 : dia;
                break;
            case 2:
                if(anoBissexto(ano) && dia >= 29)
                    return 29;
                else
                    return 28;    
                return (dia > 28) ? 28 : dia;
                break;
            default:
                break;
        }
    }
    return dia;
}

/**
 * @brief Realiza o cadastro do pagamento de uma parcela do emprestimo de um cliente.
 * 
 * @param clientes Vetor de clientes.
 * @param tamanho Tamanho do vetor de clientes.
 */
void cadastrarParcelaPaga(Cliente clientes[], int tamanho){
    try{
        cout << endl << "Digite o CPF do cliente: ";
        string cpf = leCpf();
        Cliente cliente = buscarCliente(clientes, cpf, tamanho);
        
        if(cliente.emprestimo.valor == 0){
            cout << endl << "O cliente nao possui emprestimo cadastrado."  << endl;
            return;
        }

        mostrarParcelas(cliente);
        cout << endl << "\tDigite o numero da parcela a ser paga: ";
        
        int parcela = leParcela("Digite o numero da parcela a ser paga: ") - 1;
        if(cliente.emprestimo.parcelas[parcela].parcelaPaga) {
            cout << endl << "A parcela "<< parcela + 1 << " ja esta paga." << endl;
            return;
        }

        cout << endl;
        Data dataPagamento = cadastraData("\tData de pagamento da parcela");

        cout << endl << "Confirma o pagamento da parcela?" << endl;
        if(confirmarAcao()) {
            cliente.emprestimo.parcelas[parcela].dataDePagamento = dataPagamento;
            cliente.emprestimo.parcelas[parcela].parcelaPaga = true;
            clientes[buscaIndiceCliente(clientes, cpf, tamanho)] = cliente;
            cout << endl << "Pagamento da parcela registrado..." << endl;
        }
    } catch(out_of_range &ooa) {
        cout << endl << ooa.what() << endl; 
    }
}

/**
 * @brief Exibe as informacoes sobre o emprestimo de um cliente.
 * 
 * @param cliente Cliente que tera as informacoes exibidas.
 */
void mostrarEmprestimo(Cliente cliente){
    cout << endl << "Informacoes do emprestimo do cliente " << cliente.nome << ":" << endl
         << endl << "\tValor do emprestimo: " << cliente.emprestimo.valor
         << endl << "\tNumero de parcelas: " << cliente.emprestimo.numeroDeParcelas
         << endl << "\tValor das parcelas: " << cliente.emprestimo.ValorDasParcelas
         << endl << "\tData do emprestimo: " << dataToString(cliente.emprestimo.dataDeEmprestimo) << endl;
}

/**
 * @brief Exibe as informacoes sobre as parcelas de um cliente.
 * 
 * @param cliente Cliente que tera as informacoes exibidas.
 */
void mostrarParcelas(Cliente cliente){
    cout << endl << "Parcelas do cliente " << cliente.nome << ":" << endl;
    for(int i = 0; i < cliente.emprestimo.numeroDeParcelas; i++){
        cout << endl << "\tParcela: " << i + 1;
        cout << endl << "\tData de vencimento: " << dataToString(cliente.emprestimo.parcelas[i].dataDeVencimento);
        if(!cliente.emprestimo.parcelas[i].parcelaPaga) {
            cout << endl << "\tStatus da parcela: Parcela nao paga" << endl;
            continue;
        }
        cout << endl << "\tStatus da parcela: Parcela Paga";
        cout << endl << "\tData de pagamento: " << dataToString(cliente.emprestimo.parcelas[i].dataDePagamento) << endl;
    }
}

/**
 * @brief Exclui um cliente do vetor de clientes.
 * 
 * @param clientes Vetor de clientes.
 * @param tamanho Tamanho do vetor de clientes. 
 */
void excluirCliente(Cliente clientes[], int tamanho){
    try {
        cout << endl << "Digite o CPF do cliente: ";
        string cpf = leCpf();
        int indice = buscaIndiceCliente(clientes, cpf, tamanho);
        if(confirmarAcao()) {
            clientes[indice].cpf = "";
            cout << endl << "Cliente excluido com sucesso." << endl;
        }
    } catch(out_of_range &ooa) {
        cout << endl << ooa.what() << endl; 
    }
}

/**
 * @brief Realiza a edicao das informacoes do cliente.
 * 
 * @param clientes Vetor de clientes.
 * @param tamanho Tamanho do vetor de clientes.
 */
void editarInformacoesCliente(Cliente clientes[], int tamanho){
    try {
        cout << endl << "Digite o CPF do cliente: ";
        string cpf = leCpf();
        int indice = buscaIndiceCliente(clientes, cpf, tamanho);

        Cliente modelo;
        cout << endl<< "Editando as informacoes do cliente..." << endl <<
                "Para as informacoes que nao serao alteradas, basta pressionar a tecla enter." << endl << endl;        

        cout << "\tNome: ";
        modelo.nome = leStringEdicao().value_or(clientes[indice].nome);

        modelo.endereco = editarEndereco(clientes, indice);
        modelo.data = editarData(clientes, indice);

        modelo.cpf = cpf;
        modelo.emprestimo = clientes[indice].emprestimo;
        clientes[indice] = modelo;

        cout << endl << "Edicao realizada com sucesso." << endl;
    }
    catch(out_of_range& ooa) {
        cerr << endl << "Cliente nao encontrado." << endl;
    }
}

/**
 * @brief Realiza a edicao do endereco de um cliente cadastrado no vetor de clientes.
 * 
 * @param clientes Vetor de clientes. 
 * @param indice Posicao do cliente que tera o endereco alterado no vetor de clientes.
 * @return O endereco editado.
 */
Endereco editarEndereco(Cliente clientes[], int indice) {
    Endereco modelo;
    cout << "\tEndereco:" << endl;
    
    cout << "\t\tLogradouro: ";
    modelo.logradouro = leStringEdicao().value_or(clientes[indice].endereco.logradouro);
    
    cout << "\t\tNumero: ";
    modelo.numero = leNumeroEdicaoNaturalNaoNulo("\t\tEntrada invalida. Tente novamente.\n\t\tNumero: ").value_or(clientes[indice].endereco.numero);

    cout << "\t\tComplemento: ";
    getline(cin, modelo.complemento);

    cout << "\t\tBairro: ";
    modelo.bairro = leStringEdicao().value_or(clientes[indice].endereco.bairro);
    
    cout << "\t\tCidade: ";
    modelo.cidade = leStringEdicao().value_or(clientes[indice].endereco.cidade);
    
    cout << "\t\tEstado (UF): ";
    modelo.estado = leStringEdicao().value_or(clientes[indice].endereco.estado);
    
    return modelo;
}

/**
 * @brief Realiza a edicao da data de um cliente cadastrado no vetor de clientes.
 * 
 * @param clientes Vetor de clientes.
 * @param indice Posicao do cliente que tera a data alterada no vetor.
 * @return A data editada.
 */
Data editarData(Cliente clientes[], int indice) {
    Data modelo;
    bool dataValida = false;
    while(!dataValida) {
        cout << "\tData de nascimento:" << endl;
        
        cout << "\t\tDia: ";
        modelo.dia = leNumeroEdicaoNaturalNaoNulo("\tEntrada invalida.\n\t\tDia: ")
                        .value_or(clientes[indice].data.dia);
        
        cout << "\t\tMes: ";
        modelo.mes = leNumeroEdicaoNaturalNaoNulo("\tEntrada invalida.\n\t\tMes: ")
                        .value_or(clientes[indice].data.mes);
        
        cout << "\t\tAno: ";
        modelo.ano = leNumeroEdicaoNaturalNaoNulo("\tEntrada invalida.\n\t\tAno: ")
                        .value_or(clientes[indice].data.ano);

        if (!validarData(modelo)) {
            cout << endl << "\tData invalida.Tente novamente: " << endl << endl;
            continue;
        }

        dataValida = true;
    }
    return modelo;
}

/**
 * @brief Checa se um determinado CPF esta cadastrado no vetor de clientes.
 * 
 * @param cpf CPF do cliente a ser buscado.
 * @param clientes Vetor de clientes.
 * @param tamanho Tamanho do vetor de clientes.
 * @return True caso o cliente exista no vetor.
 * @return False caso o cliente nao exista no vetor.
 */
bool clienteExistente(string cpf, Cliente clientes[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        if(cpf == clientes[i].cpf) return true;
    }
    return false;
}

/**
 * @brief Busca em um vetor de clientes o primeiro cliente disponivel para cadastro.
 * 
 * @param clientes Vetor de clientes.
 * @param tamanho Tamanho do vetor de clientes.
 * @return A posição do primeiro cliente vago encontrado.
 * @throw std::out_of_range caso o vetor de clientes esteja cheio. 
 */
int buscarIndiceVago(Cliente clientes[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        if(clientes[i].cpf == "")
            return i;
    }
    throw out_of_range("A lista de clientes esta cheia.");
}

/**
 * @brief Recebe do usuario a confirmacao de que deseja prosseguir ou nao com uma acao.
 * 
 * @return True caso a entrada seja "S" ou  "s".
 * @return False caso a entrada seja "N" ou "n".
 */
bool confirmarAcao() {
    bool retorno = false;    
    cout << endl << "Deseja continuar esta acao? [S/n]: ";
    while(true) {
        string entrada;
        getline(cin, entrada);

        if(entrada == "S" || entrada == "s") {
            retorno = true;
            break;
        }
        else if(entrada == "N" || entrada == "n") {
            cout << endl << "Operacao abortada..." << endl;
            retorno = false;
            break;
        }

        cout << endl << "Entrada invalida. Deseja continuar esta acao? [S/n]: ";
    }
    return retorno;   
}

/**
 * @brief Le uma entrada do usuario para ser utilizada na edicao de dados que pode ser vazia ou nao.
 * 
 * @return A entrada do usuario caso exista.
 * @return nullopt caso a entrada do usuario seja um "enter".
 */
optional<string> leStringEdicao() {
    string entrada;
    getline(cin, entrada);
    if(entrada.empty())
        return nullopt;
    return entrada;
}

/**
 * @brief Le a entrada do usuario que pode ser vazia ou nao e verifica se e um numero valido ou nao.
 * 
 * @param errorMessage Mensagem de erro que deve ser exibida a usuario caso digite um numero nao valido.
 * @return Um numero inteiro valido caso a entrada do usuario nao seja vazia e seja um numero valido.
 * @return nullopt caso a entrada do usuário seja um "enter".  
 */
optional<int> leNumeroEdicaoNaturalNaoNulo(string errorMessage) {
    int num;
    bool numValido = false;
    while(!numValido) {
        string sNum;
        getline(cin, sNum);
        
        /* Verifica se o usuario apenas digitou enter */
        if(sNum.empty())
            return nullopt;
        
        /* Verifica se a string contem apenas digitos numericos para poder ser convertida em int */
        if (!ehNumeroValido(sNum)) {
            cout << errorMessage;
            continue;
        }
        
        /* Verifica se este inteiro e menor ou igual as zero */
        num = stoi(sNum);
        if(num <= 0) {
            cout << errorMessage;
            continue;
        }

        numValido = true;    
    }
    return num;
}

/**
 * @brief Verifica se a entrada contem somente digitos numericos.
 * 
 * @param num String a ser verificada.
 * @returns True caso a entrada for um numero valido.
 * @returns False caso a entrada nao for um numero valido.
 */
bool ehNumeroValido(string num) {
    for (int i = 0; i < num.length(); i++) {
        if(!isdigit(num[i])) {
            return false;
        }
    }
    return true;
}