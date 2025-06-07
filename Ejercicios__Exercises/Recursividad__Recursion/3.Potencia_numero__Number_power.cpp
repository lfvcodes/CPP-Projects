/* 
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Potencia de un número Escribe una función recursiva que calcule la potencia
de un número dado base^exponente. Luego, desarrolla un programa principal que
solicite la base y el exponente al usuario y muestre el resultado.

Power of a Number Write a recursive function that calculates the power of a 
given number base^exponent. Then, develop a main program that prompts the user
for the base and exponent and displays the result.
 */

#include <iostream>

using namespace std;

// Funcion recursiva para calcular la potencia
double potencia(int base, int exponente) {
    if (exponente == 0)
        return 1;
    return base * potencia(base, exponente - 1);
}

int main() {
    int base, exponente;

    // Solicitar base y exponente al usuario
    cout << "Digite la base: ";
    cin >> base;
    cout << "Digite el exponente: ";
    cin >> exponente;

    // Calcular y mostrar la potencia
    cout << "El resultado de " << base << "^" << exponente << " es: " << potencia(base, exponente) << endl;

    return 0;
}
