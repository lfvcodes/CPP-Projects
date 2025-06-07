/* 
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Serie de Fibonacci Escribe una función recursiva que calcule el enésimo término de la serie de Fibonacci. 
Luego, desarrolla un programa principal que solicite el término al usuario y muestre el resultado.

Fibonacci Series Write a recursive function that calculates the nth term in the Fibonacci sequence. 
Then, develop a main program that prompts the user for the term and displays the result
*/

#include <iostream>

using namespace std;

// Funcion recursiva para calcular el enesimo termino de Fibonacci
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int termino;

    // Solicitar termino al usuario
    cout << "Digite el termino de Fibonacci: ";
    cin >> termino;

    // Calcular y mostrar el resultado
    cout << "El termino " << termino << " de Fibonacci es: " << fibonacci(termino) << endl;

    return 0;
}
