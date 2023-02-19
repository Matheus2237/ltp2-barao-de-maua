/*
    Laboratório de Técnicas de Programação II - Aula 17/02/2023
    Gerar duas matrizes 3x3 e copiar os maiores valores para uma terceira matriz.
    @author: Matheus Paulino <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int primeiraMatriz[3][3];
int segundaMatriz[3][3];
int terceiraMatriz[3][3];

int posicaoVetor = 0;

void popularMatriz(int matriz[][3]);
void extrairValores(int vetor[18], int matriz[][3]);
void ordenarMaiorParaMenor(int vetor[]);
void copiarMaioresValoresParaMatriz(int matriz[][3], int vetor[18]);

int main() {
    srand(time(0));

    cout << endl << "Primeira Matriz" << endl; /* Geração da primeira matriz */
    popularMatriz(primeiraMatriz);

    cout << endl << "Segunda Matriz" << endl; /* Geração da segunda matriz */
    popularMatriz(segundaMatriz);

    int vetorAuxiliar[18]; /* Extraindo os números das matrizes para um vetor */
    extrairValores(vetorAuxiliar, primeiraMatriz);
    extrairValores(vetorAuxiliar, segundaMatriz);
    ordenarMaiorParaMenor(vetorAuxiliar); /* Ordena o vetor de modo a organizar seus elementos do maior para o menor */

    cout << endl << "Terceira Matriz" << endl; /* Cópia dos maiores valores das duas matrizes anteriores para a terceira matriz */
    copiarMaioresValoresParaMatriz(terceiraMatriz, vetorAuxiliar);

    cout << endl;
    return 0;
}

/* Recebe uma matriz vazia e a popula com números gerados aleatoriamente. */
void popularMatriz(int matriz[][3]) { 
    int numeroMomentaneo = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            numeroMomentaneo = rand() % 100;
            matriz[i][j] = numeroMomentaneo;
            cout << numeroMomentaneo << " ";
        }
        cout << endl;
    }
}

/* 
  Lê a matriz e extrai todos os seus elementos para um vetor.
  Este vetor será utilizado para atribuir os maiores valores para a terceira matriz.
 */
void extrairValores(int vetor[18], int matriz[][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            vetor[posicaoVetor] = matriz[i][j];
            posicaoVetor++;
        }
    }
}

/*
  A ordenação é feita comparando o primeiro número com o segundo, e assim sucessivamente, 
  e no momento em que o primeiro for menor que o segundo, eles trocam de lugar. Esse processo
  segue até percorrer todos os elementos da lista e comparar todos com todos.
    -> Posição x: O primeiro elemento da comparação varia entre a primeira e a penúltima posição do vetor.
    -> Posição y: O segundo elemento da comparação varia entre o próximo elemento a partir do primeiro e a última posição do vetor.
*/
void ordenarMaiorParaMenor(int vetor[]) { 
    int aux;
    for(int x = 0; x < 17; x++) {
        for(int y = x + 1; y < 18; y++) {
            if(vetor[x] < vetor[y]) {
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = aux;
            }
        }
    }
}

/* Recebe como parâmetro o vetor ordenado e copia seus maiores valores para a matriz */
void copiarMaioresValoresParaMatriz(int matriz[][3], int vetorOrdenado[18]) {
    int iteradorVetor = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            matriz[i][j] = vetorOrdenado[iteradorVetor];
            cout << vetorOrdenado[iteradorVetor] << " ";
            iteradorVetor++;
        }
        cout << endl;
    } 
}