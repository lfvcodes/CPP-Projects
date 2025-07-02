/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Realice un programa que simule el juego de adivinar un número.
Create a program that simulates the guessing game.
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void jugarAdivinanza() {
    srand(time(0));
    int numeroSecreto = rand() % 100 + 1;
    int intento, intentos = 0;

    cout << "Adivina el numero (1-100):\n";

    do {
        cin >> intento;
        intentos++;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no valida. Intenta de nuevo.\n";
            continue;
        }

        if (intento < numeroSecreto) {
            cout << "Mas alto!\n";
        } else if (intento > numeroSecreto) {
            cout << "Mas bajo!\n";
        }
    } while (intento != numeroSecreto);

    cout << "Correcto! Lo adivinaste en " << intentos << " intentos.\n";
}

int main() {
    jugarAdivinanza();
    return 0;
}