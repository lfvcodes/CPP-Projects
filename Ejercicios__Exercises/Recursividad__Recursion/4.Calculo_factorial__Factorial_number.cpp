/* 
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Cálculo del factorial de un número Escribe una función recursiva que calcule el
 factorial de un número entero dado.
  Luego, desarrolla un programa principal que solicite el número al usuario y muestre el resultado.

Factorial Calculation Write a recursive function that calculates the factorial
 of a given integer. Then, develop a main program that prompts the user
  for a number and displays the result. 
  */

#include <iostream>
using namespace std;

// Funcion recursiva para calcular el factorial
int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int numero;

    // Solicitar numero al usuario
    cout << "Digite un numero entero: ";
    cin >> numero;

    // Calcular y mostrar el factorial
    cout << "El factorial de " << numero << " es: " << factorial(numero) << endl;

    return 0;
}
