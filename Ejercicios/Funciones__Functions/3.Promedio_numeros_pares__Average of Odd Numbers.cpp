/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Promedio de Números Impares
Desarrolla una función `void` que calcule y muestre el promedio de todos los números impares entre 1 y 51 (inclusive).

Average of Odd Numbers
Develop a `void` function that calculates and displays the average of all odd numbers between 1 and 51 (inclusive).
*/

#include <iostream>

using namespace std;

// Funcion que calcula y muestra el promedio de los numeros impares entre 1 y 51
void calcularPromedioImpares() {
    int suma = 0, cantidad = 0;

    for (int i = 1; i <= 51; i += 2) {
        suma += i;
        cantidad++;
    }

    double promedio = suma / (double) cantidad;
    cout << "El promedio de los numeros impares entre 1 y 51 es: " << promedio << endl;
}

int main() {
    calcularPromedioImpares();
    return 0;
}
