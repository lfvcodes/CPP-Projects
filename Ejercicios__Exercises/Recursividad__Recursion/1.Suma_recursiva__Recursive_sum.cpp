/* 
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Suma de los dígitos de un número Escribe una función recursiva que calcule 
la suma de los dígitos de un número entero dado.
 Luego, 
 desarrolla un programa principal que solicite al usuario un número y muestre
  el resultado de la función.

Sum of Digits Write a recursive function that calculates the sum of the digits of
 a given integer. 
 Then, develop a main program that prompts the user for a number and displays
  the result of the function. 
  */
#include <iostream>

using namespace std;

// Funcion recursiva para sumar los digitos de un numero
int sumaDigitos(int num) {
    if (num == 0)
        return 0;
    return (num % 10) + sumaDigitos(num / 10);
}

int main() {
    int numero;

    // Solicitar numero al usuario
    cout << "Digite un numero entero: ";
    cin >> numero;

    // Calcular y mostrar la suma de los digitos
    cout << "La suma de los digitos es: " << sumaDigitos(numero) << endl;

    return 0;
}
