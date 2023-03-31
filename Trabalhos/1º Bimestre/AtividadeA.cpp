/**
 * @file AtividadeA.cpp
 * @date 2023-03-08
 * @brief Laboratório de Técnicas de Programação II - Trabalho 1° Bimestre - Atividade A
 *      Calcula o seno e cosseno de um ângulo digitado pelo usuário, tanto por funções criadas 
 *      neste código, quanto pelas próprias funções do cmath, e calcula o erro entre essas funções.
 * @author Carlos Sérgio Fernandes Júnior - 2157633 <carlos_fernandes.1@hotmail.com>
 * @author Matheus Paulino Ribeiro - 2143432 <mathpaulinor@gmail.com>
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <cmath>

using namespace std;

double grauParaRadiano(double grau); /// Transforma de grau para Radiano
double fatorial(int n); /// Calcula o fatorial
double modulo(double n); /// Calcula o modulo
double seno(double angulo, int termos); /// Calcula o seno
double cosseno(double angulo, int termos); /// Calcula o cosseno
double erroAbsoluto(double r1,double r2); /// Calcula o erro absoluto
double erroPercentual(double r1, double r2); /// Calcula o erro percentual

const double PI = 3.141592653589793;

int main() {
    /* Imprime o cabecalho */
    cout << endl <<
            "===================================" << endl <<
            "   Calculadora de Seno e Cosseno" << endl <<
            "===================================" << endl;

    /* Solicita um angulo ao usuario */
    double angulo;
    cout << endl << "Digite o valor do angulo em graus: ";
    cin >> angulo;

    /* Imprime o resultado para uma serie de 3 termos */
    double sen3Termos = seno(grauParaRadiano(angulo), 3);
    double cos3Termos = cosseno(grauParaRadiano(angulo), 3);
    cout << endl << "1. Para uma serie de 3 termos, temos:" <<
            endl << "\tsen" << angulo << " = " << sen3Termos <<
            endl << "\tcos" << angulo << " = " << cos3Termos << endl;

    /* Imprime o resultado para uma serie de 40 termos */
    double sen40Termos = seno(grauParaRadiano(angulo), 40);
    double cos40Termos = cosseno(grauParaRadiano(angulo), 40);
    cout << endl << "2. Para uma serie de 40 termos, temos:" <<
            endl << "\tsen" << angulo << " = " << sen40Termos <<
            endl << "\tcos" << angulo << " = " << cos40Termos << endl;

    /* Imprime o resultado obtido atraves das funcoes da biblioteca cmath */
    double senCmath = sin(grauParaRadiano(angulo));
    double cosCmath = cos(grauParaRadiano(angulo));
    cout << endl << "3. Ao utilizar as funcoes de seno e cosseno da biblioteca cmath, temos:" <<
            endl << "\tsen" << angulo << " = " << senCmath <<
            endl << "\tcos" << angulo << " = " << cosCmath << endl;

    /* Imprime os erros absolutos e percentuais entre os valores obtidos anteriormente */
    cout << endl << "4. Calculo de erro entre as funcoes criadas e as funcoes da biblioteca cmath:" << 
            endl << "\tEntre a serie de 3 termos e as funcoes do cmath, temos: " <<
            endl << "\t\tPara a funcao Seno    ->   Erro absoluto: " << erroAbsoluto(sen3Termos, senCmath) << " | Erro percentual: " << erroPercentual(sen3Termos, senCmath) << "%" << 
            endl << "\t\tPara a funcao Cosseno ->  Erro absoluto: " << erroAbsoluto(cos3Termos, cosCmath) << " | Erro percentual: " << erroPercentual(cos3Termos, cosCmath) << "%" <<
            endl << "\tEntre a serie de 40 termos e as funcoes do cmath, temos: " <<
            endl << "\t\tPara a funcao Seno    ->   Erro absoluto: " << erroAbsoluto(sen40Termos, senCmath) << " | Erro percentual: " << erroPercentual(sen40Termos, senCmath) << "%" <<
            endl << "\t\tPara a funcao Cosseno ->  Erro absoluto: " << erroAbsoluto(cos40Termos, cosCmath) << " | Erro percentual: " << erroPercentual(cos40Termos, cosCmath) << "%" << endl << endl;

    return 0;
}

/**
 * @brief Transforma um valor em graus em um valor em radiano.
 *      O valor radiano de um número em graus corresponde a este mesmo 
 *      número multiplicado por Pi dividido por 180.
 * 
 * @param grau Angulo em graus
 * @return Valor do angulo em radianos
 */
double grauParaRadiano(double grau){
    return grau * PI /180;
}

/**
 * @brief Calcula o fatorial de um número.
 *      O fatorial é o número multiplicado por todos os inteiros 
 *      menores que este número e maiores que 0.
 * 
 * @param n Numero a ter o valor fatorial calculado
 * @return o valor fatorial do número
 */
double fatorial(int n){
    if(n==0) return 1;
    double fat = n;
    for(int i = n-1; i > 0; i--){
        fat *= i;
    }
    return fat;
}

/**
 * @brief Calcula o valor positivo de um número real.
 *      O módulo se define como a distância de um número real até 0.
 * 
 * @param n Número a ter o módulo calculado. Pode ser tanto positivo quanto negativo e até mesmo nulo.
 * @return O valor positivo do número.
 */
double modulo(double n){
    if(n<0){
        n *= -1;
    }
    return n;
}

/**
 * @brief Calcula o valor do seno de um ângulo.
 *      O seno é uma função trigonométrica definida como sendo a razão 
 *      entre o cateto oposto e a hipotenusa de um triângulo retângulo.
 * 
 * @param angulo Valor do ângulo em radianos
 * @param termos Quantidade de termos utilizados para fazer o cálculo
 * @return O valor do seno do ângulo informado
 */
double seno(double angulo, int termos){
    double sen = 0;
    for(int i = 0; i < termos; i++){
        int n = 2*i + 1;
        sen += pow((-1), i) * pow(angulo, n) / fatorial(n);
    }
    return sen;
}

/**
 * @brief Calcula o valor do cosseno de um ângulo.
 *      O cosseno é uma função trigonométrica definida como sendo a razão 
 *      entre o cateto adjacente e a hipotenusa de um triângulo retângulo.
 * 
 * @param angulo Valor do ângulo em radianos
 * @param termos Quantidade de termos utilizados para fazer o cálculo
 * @return O valor do cosseno do ângulo informado
 */
double cosseno(double angulo, int termos){
    double cos = 0;
    for(int i = 0; i < termos; i++){
        int n = 2*i;
        cos += pow((-1), i) * pow(angulo, n) / fatorial(n);
    }
    return cos;
}

/**
 * @brief Calcula o erro absoluto entre dos valores.
 *      O erro absoluto se define como a diferença entre o valor medido 
 *      e o valor real.
 * 
 * @param va Valor aproximado
 * @param vr Valor real
 * @return retorna o erro absoluto entre os valores.
 */
double erroAbsoluto(double va,double vr){
    return modulo(va - vr);
}

/**
 * @brief Calcula o erro percentual entre dos valores.
 *      O erro percentual se define como o erro relativo multiplicado por 100.
 *      Por sua vez, o erro relativo se define como o quociente entre o erro 
 *      absoluto e o valor real.
 * 
 * @param va Valor aproximado
 * @param vr Valor real
 * @return retorna o erro percentual entre os valores.
 */
double erroPercentual(double va, double vr){
    return modulo(erroAbsoluto(va, vr) / vr * 100);
}