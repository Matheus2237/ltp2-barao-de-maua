/*
    Laboratório de Técnicas de Programação II - Aula 10/02/2023
    Jogo Cara ou Coroa
    @author: Matheus Paulino <mathpaulinor@gmail.com>
*/

#include <iostream>
#include <string>

using namespace std;

bool game = true;

const bool CARA = false;
const bool COROA = true;

int contadorCara;
int contadorCoroa;
int totalAcertos;

string entradaUsuario;
bool apostaUsuario;
bool resultadoMomentaneo;

void printHeader() { /* Prints the header of the game */
    cout << endl << "===============" << endl;
    cout << "CARA OU COROA" << endl;
    cout << "===============" << endl << endl;
}

void printChallenge() { /* Prints the challenge to the user */
    cout << "Cara ou Coroa? ";
}

string toUpperCase(string input) { /* Returns all string in upper case*/
    string output;
    for (int iterator = 0; iterator < input.length(); iterator++) {
        if(input[iterator] == ' ') { break; } /* Trims the string after it's first word*/
        output.push_back(toupper(input[iterator]));
    }
    return output;
}

bool parseBet(string bet) { /* Transforms the bet as a string to a boolean value */
    if(bet == "COROA") { return COROA; } 
    else { return CARA; }
}

bool getUserBet() { /* Reads the user input and returns it as a valid bet */
    string stringBet;
    bool validInput = false;
    printChallenge();
    while (!validInput) {    
        cin >> entradaUsuario;
        stringBet = toUpperCase(entradaUsuario);
        if(stringBet == "CARA" || stringBet == "COROA") { return parseBet(stringBet);} /* Stops method to ask for a valid user input */
        cout << "Nao entendi. ";
        printChallenge();
    } 
    return parseBet(stringBet);
}

bool flip() {  /* Flips the coin, updates the counter and returns the result */
    srand(time(0));
    int numResultado = rand() % 2;
    if (numResultado == 0) {
        contadorCoroa++;
        return COROA;
    } else {
        contadorCara++;
        return CARA;
    }
}

string resultAsString() {   /* Converts the momentary result to a string */
    if (resultadoMomentaneo == CARA) { return "cara"; }
    else { return "coroa"; }
}

void printResultMessage() { /* Prints the result message about the user guess */
    cout << endl;
    cout << "Deu " << resultAsString() << endl;
    if (resultadoMomentaneo == apostaUsuario) {
        totalAcertos++;
        cout << "Voce acertou!" << endl;
    }
    else {
        cout << "Voce errou!" << endl;
    }
}

void printTotalScore() { /* Prints the total score of the game at that moment of invocation */
    cout << endl << "Total de lancamentos:" << endl;
    cout << "   Cara: " << contadorCara << endl;
    cout << "   Coroa: " << contadorCoroa << endl;
    cout << "   Total de acertos: " << totalAcertos << endl;
}

void playAgain() { /* Checks if the user wants to play more */
    string wantsMore;
    bool tryAskingMore = true;
    cout << endl;
    while(tryAskingMore) {
        cout << "Quer jogar mais?[S/N] ";
        cin >> wantsMore;
        if (toUpperCase(wantsMore) == "S") {
            game = true;
            tryAskingMore = false;
        }
        else if (toUpperCase(wantsMore) == "N") {
            game = false;
            tryAskingMore = false;
        }
        else {
            cout << "Nao entendi. ";
        }
    }
    cout << endl;
}

void printFooter() { /* Prints the footer at the end of the game */
    cout << "===============" << endl;
    cout << "FIM DE JOGO" << endl;
    cout << "===============" << endl << endl;
}

int main() {
    printHeader();
    while(game) {
        apostaUsuario = getUserBet();
        resultadoMomentaneo = flip();
        printResultMessage();
        printTotalScore();
        playAgain();
    }
    printFooter();
}