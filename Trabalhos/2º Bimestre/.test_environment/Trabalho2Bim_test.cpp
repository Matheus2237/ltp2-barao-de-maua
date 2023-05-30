/**
 * @file Trabalho2Bim.cpp
 * @date 2023-05-24
 * @brief Organizar dados do arquivo iris_petalas.csv, onde flores similares serão agrupadas
 *      em k grupos definidos pelo usuario.
 * @author Carlos Sérgio Fernandes Júnior - 2157633 <carlos_fernandes.1@hotmail.com>
 * @author Matheus Paulino Ribeiro - 2143432 <mathpaulinor@gmail.com>
 * @author Nicolas Fagundes Scarpa - 2093087 <bkscarpa@gmail.com>
 * @copyright Copyright (c) 2023
 */

#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

// ! Logger
#include "Logger.hpp"

using namespace std;

typedef struct {
    long double comprimento;
    long double largura;
    string variedade;
} Flor;

typedef struct {
    string numero;
    long double comprimento;
    long double largura;
    Flor *flores;
    int tamanhoVetor;
} Grupo;

int calculaTamanhoArquivo(const string nomeArquivo);
void imprimeCabecalho();
int leNaturalNaoNulo(string mensagem); // Realiza a leitura de um numero natural diferente de zero.
Grupo* inicializaGruposComRepresentantes(const int numeroDeGrupos, const string nomeArquivo, const int tamanhoArquivo);
Flor* buscaRepresentantes(const int numeroRepresentantes, const string nomeArquivo, const int tamanhoArquivo);
int* sorteiaIndicesRepresentantes(const int numeroRepresentantes, const int tamanhoArquivo);
bool elementoEstaEmLista(int elemento, int* lista, const int tamanho);
void classificaFlores(Grupo* grupos, const int numeroDeGrupos, const string nomeArquivo, const int numeroDeExecucoes);
long double calculaDistanciaEuclidiana(long double comprimentoRepresentante, long double comprimentoFlor, long double larguraRepresentante, long double larguraFlor);
int encontraGrupoIdeal(Grupo* grupos, const int numeroDeGrupos, const long double comprimentoFlor, const long double larguraFlor);
int encontraIndiceComMenorValor(long double* vetor, const int tamanho);
void alocaFlorNoGrupoIdeal(Flor flor, Grupo* grupos, const int indiceIdeal);
Flor* realocaVetor(Flor* vet, int* t);
void atualizaRepresentantes(Grupo* grupos, const int numeroDeGrupos);
void desalocaVetorDeFlores(Grupo* grupos, const int numeroDeGrupos);
void persisteResultado(Grupo *grupos, const int numeroDeGrupos, const string nomeArquivo, const int tamanhoArquivo);
string formataLinhaDeFlores(Flor flor, string numeroGrupo);
void desalocaVetorDeGrupos(Grupo* grupos, const int numeroDeGrupos);
template <typename T> void checaAlocacao(T* aloc);

int main(int argc, char *argv[]) {

    // Nome do arquivo recuperado atraves da lista de parametros da funcao main
    const string NOME_ARQUIVO = argv[1];
    const int TAMANHO_ARQUIVO = calculaTamanhoArquivo(NOME_ARQUIVO);

    // Imprimindo cabeçalho inicial
    imprimeCabecalho();

    // Lendo informacoes do usuario
    const int NUMERO_DE_GRUPOS = leNaturalNaoNulo("Digite a quantidade de grupos que deseja organizar: ");
    const int NUMERO_DE_EXECUCOES = leNaturalNaoNulo("Digite a quantidade de vezes que a organizacao se repetira: ");
    
    // Inicializando os grupos com seus representantes
    Grupo *grupos = inicializaGruposComRepresentantes(NUMERO_DE_GRUPOS, NOME_ARQUIVO, TAMANHO_ARQUIVO);

    // Chamando a funcao de classficacao das flores
    cout << "\nClassificando as flores...\n";
    classificaFlores(grupos, NUMERO_DE_GRUPOS, NOME_ARQUIVO, NUMERO_DE_EXECUCOES);
    cout << "Classificacao concluida.\n"; 

    // ! Logger
    Logger::report("\n--------------\nTamanho final dos grupos:\n");
    stringstream gruposDebug;
    for (int i = 0; i < NUMERO_DE_GRUPOS; i++) {
        gruposDebug << "\t Grupo de alocacao " << grupos[i].numero 
                    << ": " << grupos[i].tamanhoVetor;
    }
    Logger::report(gruposDebug.str());
    
    // Armazenando resultados em um outro arquivo
    cout << "Armazenando resultado em no arquivo classificacao_" << NOME_ARQUIVO << "...\n";
    persisteResultado(grupos, NUMERO_DE_GRUPOS,NOME_ARQUIVO, TAMANHO_ARQUIVO);

    // Desalocando vetor de grupos
    desalocaVetorDeGrupos(grupos, NUMERO_DE_GRUPOS);
    cout << "\nEncerrando o programa...\n\n";

    return 0;
}

int calculaTamanhoArquivo(const string nomeArquivo) {
    ifstream arquivo(nomeArquivo, ios::in);
    int tamanho = 0;
    string linha = "";
    while(getline(arquivo, linha))
        tamanho++;
    arquivo.close();

    // ! Logger
    string debug = "Tamanho do arquivo: ";
    Logger::report(debug.append(to_string(tamanho)).append("\n"));

    return tamanho;
}

void imprimeCabecalho() {
    cout << "\nInicializando o programa...\n";
    cout << endl <<
        "=======================================" << endl <<
        "   Organizacao de Especies de Flores" << endl <<
        "=======================================" << endl << endl;
}

/**
 * @brief Realiza a leitura de um numero natural diferente de zero.
 * 
 * @param message Mensagem de a ser exibida na solicitacao de entrada de.
 * @return O numero natural nao nulo.
 */
int leNaturalNaoNulo(string mensagem) {
    int numero;
    string mensagemDeErro = "Entrada invalida. Tente novamente.\n";
    bool numeroValidado = false;
    cout << mensagem;
    while(!numeroValidado) {
        cin >> numero;
        
        if(cin.fail()) { // Verifica se houve erro na leitura da acao
            cout << mensagemDeErro << mensagem;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do comeco ate o limite da sua capacidade
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(cin.gcount() > 1) { // Verifica se ha caracteres nao numericos na leitura
            cout << mensagemDeErro << mensagem;
            continue;
        }

        if(numero <= 0) {
            cout << mensagemDeErro << mensagem;
            continue;
        }

        numeroValidado = true;
    }
    return numero;
}

Grupo* inicializaGruposComRepresentantes(const int numeroDeGrupos, const string nomeArquivo, const int tamanhoArquivo) {
    Grupo *grupos = new Grupo[numeroDeGrupos];
    checaAlocacao(grupos);
    Flor *flores = buscaRepresentantes(numeroDeGrupos, nomeArquivo, tamanhoArquivo);
    for (int i = 0; i < numeroDeGrupos; i++) {
        grupos[i].numero = to_string(i+1);
        grupos[i].comprimento = flores[i].comprimento;
        grupos[i].largura = flores[i].largura;
    }
    delete[] flores;

    // ! Logger
    Logger::report("\n------------\nGrupos com representantes:\n");
    for (int i = 0; i < numeroDeGrupos; i++) {
        stringstream grupoDebug;
        grupoDebug << "\n------------\n" <<
            grupos[i].numero << endl <<
            grupos[i].comprimento << endl <<
            grupos[i].largura << endl;
        Logger::report(grupoDebug.str());
    }

    return grupos;
}

Flor *buscaRepresentantes(const int numeroRepresentantes, const string nomeArquivo, const int tamanhoArquivo) {
    ifstream arquivo(nomeArquivo, ios::in);
    
    if(!arquivo)
        throw ifstream::failure("Erro ao abrir o arquivo.");

    // ? É de fato boa prática fazer desta forma? Por que não destrutor?
    // Descartando o cabecalho do arquivo e garantindo que esta string nao pode mais ser utilizada
    {
        string cabecalho = "";
        getline(arquivo, cabecalho, '\n');
    }

    // Encontrando as flores representantes
    Flor *flores = new Flor[numeroRepresentantes];
    checaAlocacao(flores);
    int *indicesRepresentantes = sorteiaIndicesRepresentantes(numeroRepresentantes, tamanhoArquivo);
    int indiceLeitura = 0;
    int indiceFlor = 0;
    string linha = "";
    
    // Adiciona ao vetor as flores representantes
    while(getline(arquivo, linha)) {
        if(elementoEstaEmLista(++indiceLeitura, indicesRepresentantes, numeroRepresentantes)) {
            replace(linha.begin(), linha.end(), ',', ' ');
            stringstream linhaStream(linha); 
            Flor flor;
            linhaStream >> flor.comprimento >> flor.largura >> flor.variedade;
            flores[indiceFlor] = flor;
            indiceFlor++;
        }
    }

    arquivo.close();
    free(indicesRepresentantes);
    
    return flores;
}

int* sorteiaIndicesRepresentantes(const int numeroRepresentantes, const int tamanhoArquivo) {
    srand(time(0));
    int quantidadeMaxima = tamanhoArquivo - 1; // Desconsiderando linha de cabecalho
    int *indices = (int*) calloc(numeroRepresentantes, sizeof(int));
    checaAlocacao(indices);
    int contador = 0;
    while (contador < numeroRepresentantes) {
        int indice = rand() % quantidadeMaxima + 1;
        if(!elementoEstaEmLista(indice, indices, numeroRepresentantes)) {
            indices[contador] = indice;
            contador++;
        }
    }

    // ! Logger
    Logger::report("------------\n");
    string indicesDebug = "";
    for (int i = 0; i < numeroRepresentantes; i++)
        indicesDebug.append(to_string(indices[i])).append(" ");
    Logger::report(indicesDebug);

    return indices;
}

bool elementoEstaEmLista(int elemento, int* lista, const int tamanho) {
    for (int i = 0; i < tamanho; i++)
        if(elemento == lista[i])
            return true;
    return false;
}

void classificaFlores(Grupo* grupos, const int numeroDeGrupos, const string nomeArquivo, const int numeroDeExecucoes) {
    // Realiza a classicacao tantas vezes quanto foram solicitadas pelo usuario
    for (int execucao = 0; execucao < numeroDeExecucoes; execucao++) {
        ifstream arquivo(nomeArquivo, ios::in);
        if(!arquivo)
            throw ifstream::failure("Falha na leitura do arquivo.");

        // Descartar o cabeçalho do arquivo
        {
            string linhaTemp = "";
            getline(arquivo, linhaTemp);
        }

        // "Zerar" informacoes do vetor de flores
        for (int indice = 0; indice < numeroDeGrupos; indice++) {
            grupos[indice].flores = new Flor[1];
            checaAlocacao(grupos[indice].flores);
            grupos[indice].tamanhoVetor = 0;
        }
        
        int indiceDebug = 0; // ! Logger
        string linha = "";
        while (getline(arquivo, linha)) {
            
            // Atribuindo os valores da linha a flor
            replace(linha.begin(), linha.end(), ',', ' '); // Substituir as vírgulas por espaços para separar os valores da linha
            stringstream linhaStream(linha);
            Flor flor;
            linhaStream >> flor.comprimento >> flor.largura >> flor.variedade;

            // ! Logger
            stringstream linhaDebug;
            linhaDebug << "\n------------\n" << "Flor na linha " << ++indiceDebug << ":\n";
            Logger::report(linhaDebug.str());

            int indiceIdeal = encontraGrupoIdeal(grupos, numeroDeGrupos, flor.comprimento, flor.largura);
            alocaFlorNoGrupoIdeal(flor, grupos, indiceIdeal);

            // ! Logger
            stringstream indiceDebug;
            indiceDebug << "\nMelhor indice: " << indiceIdeal;
            Logger::report(indiceDebug.str());
        }
        arquivo.close();

        // ! Logger
        stringstream numExecDebug;
        numExecDebug << "\n-------------------" << "\nAtualizando representantes após " << 
        execucao + 1 << "a execucao.";
        Logger::report(numExecDebug.str());

        atualizaRepresentantes(grupos, numeroDeGrupos);
        if(execucao < numeroDeExecucoes - 1) // Desaloca vetores de flores para todas as execucoes com excecao da ultima
            desalocaVetorDeFlores(grupos, numeroDeGrupos);
    }
}

/**
 * @brief Encontra o grupo ideal para alocar a flor.
 * 
 * @param grupos 
 * @param numeroDeGrupos 
 * @param comprimentoFlor 
 * @param larguraFlor 
 * @return int 
 */
int encontraGrupoIdeal(Grupo* grupos, const int numeroDeGrupos, const long double comprimentoFlor, const long double larguraFlor) {
    Logger::report("Distancia Euclidiana:"); // ! Logger
    
    long double *distanciasEuclidianas = new long double[numeroDeGrupos];
    checaAlocacao(distanciasEuclidianas);
    for (int i = 0; i < numeroDeGrupos; i++) { // Calcular a distância euclidiana para cada grupo
        distanciasEuclidianas[i] = calculaDistanciaEuclidiana(grupos[i].comprimento, comprimentoFlor, grupos[i].largura, larguraFlor);

        // ! Logger
        stringstream linhaDebug;
        linhaDebug << "\tGrupo [" << i << "]: " << distanciasEuclidianas[i];
        Logger::report(linhaDebug.str());
    }
    int indiceIdeal = encontraIndiceComMenorValor(distanciasEuclidianas, numeroDeGrupos);
    delete[] distanciasEuclidianas;
    return indiceIdeal;
}

/**
 * @brief Calcula a distância euclidiana entre os representantes dos grupos e as flores do arquivo.
 * 
 * @param comprimentoRepresentante Comprimento do representante.
 * @param comprimentoFlor Comprimento da flor.
 * @param larguraRepresentante Largura do representante.
 * @param larguraFlor Largura da flor.
 * @return float Distancia Euclidiana.
 */
long double calculaDistanciaEuclidiana(long double comprimentoRepresentante, long double comprimentoFlor, long double larguraRepresentante, long double larguraFlor) {
    return sqrt(pow(comprimentoRepresentante - comprimentoFlor, 2) + pow(larguraRepresentante - larguraFlor, 2));
}

int encontraIndiceComMenorValor(long double* vetor, const int tamanho) {
    int indiceRetorno = 0;
    long double menorValor = vetor[0];
    for (int i = 0; i < tamanho; i++) {
        if(vetor[i] < menorValor) {
            menorValor = vetor[i];
            indiceRetorno = i;
        }
    }
    return indiceRetorno;
}

void alocaFlorNoGrupoIdeal(Flor flor, Grupo* grupos, const int indiceIdeal) {
    grupos[indiceIdeal].flores = realocaVetor(grupos[indiceIdeal].flores, &grupos[indiceIdeal].tamanhoVetor);
    int ultimoIndiceDeFlores = grupos[indiceIdeal].tamanhoVetor - 1;
    grupos[indiceIdeal].flores[ultimoIndiceDeFlores] = flor;

    // ! Logger
    stringstream alocacaoDebug;
    alocacaoDebug << "\nGrupo de alocacao: " << grupos[indiceIdeal].numero;
    alocacaoDebug << "\nTamanho do vetor alocado para este grupo: " << grupos[indiceIdeal].tamanhoVetor;
    Logger::report(alocacaoDebug.str());
}

Flor* realocaVetor(Flor* vet, int* t) {
    Flor* newvet = new Flor[*t+1];
    checaAlocacao(newvet);
    for(int i = 0; i < *t; i++)
        newvet[i] = vet[i];
    (*t)++;
    delete[] vet;
    return newvet;
}

void atualizaRepresentantes(Grupo* grupos, const int numeroDeGrupos) {
    for (int i = 0; i < numeroDeGrupos; i++) {
        int quantidadeDeFlores = grupos[i].tamanhoVetor;
        long double somaComprimentos = 0;
        long double somaLarguras = 0;
        for (int j = 0; j < quantidadeDeFlores; j++) {
            somaComprimentos += grupos[i].flores[j].comprimento;
            somaLarguras += grupos[i].flores[j].largura;
        }
        grupos[i].comprimento = somaComprimentos / quantidadeDeFlores;
        grupos[i].largura = somaLarguras / quantidadeDeFlores;

        // ! Logger
        stringstream representantesDebug;
        representantesDebug << "\n---------------\nGrupo " << grupos[i].numero <<
                            "\nComprimento: " << grupos[i].comprimento <<
                            "\nLargura: " << grupos[i].largura;
        Logger::report(representantesDebug.str());
    }
}

void desalocaVetorDeFlores(Grupo* grupos, const int numeroDeGrupos) {
    for(int i = 0; i < numeroDeGrupos; i++)
        delete[] grupos[i].flores;
}

void persisteResultado(Grupo *grupos, const int numeroDeGrupos, const string nomeArquivo, const int tamanhoArquivo) {
    string nomeArquivoClassificacao = "classificacao_";
    nomeArquivoClassificacao.append(nomeArquivo);
    
    ofstream novoArquivo(nomeArquivoClassificacao, ios::out);
    novoArquivo << "comprimento,largura,variedade,grupo" << endl;

    for(int i = 0; i < numeroDeGrupos; i++){
        string numeroGrupo = grupos[i].numero;
            for(int j = 0; j < grupos[i].tamanhoVetor; j++)
                novoArquivo << formataLinhaDeFlores(grupos[i].flores[j], numeroGrupo);
    }

    novoArquivo.close();
}

string formataLinhaDeFlores(Flor flor, string numeroGrupo){
    stringstream linha;
    linha << fixed << setprecision(1) << flor.comprimento << "," << 
            flor.largura << "," << flor.variedade << "," << numeroGrupo << endl;
    return linha.str();
}

void desalocaVetorDeGrupos(Grupo* grupos, const int numeroDeGrupos) {
    for(int i = 0; i < numeroDeGrupos; i++)
        delete[] grupos[i].flores;
    delete[] grupos;
}

template <typename T>
void checaAlocacao(T* aloc) {
    if(aloc == NULL) {
        cout << "\nFalha de alocacao!\nPrograma encerrado.\n\n";
        exit(0);
    }
}