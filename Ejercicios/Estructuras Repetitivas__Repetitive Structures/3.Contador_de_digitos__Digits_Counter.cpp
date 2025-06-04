/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Crea un programa que lea un número entero y cuente cuántos dígitos tiene (ejemplo: 1234 tiene 4 dígitos). Usa un ciclo while.

Create a program that reads an integer and counts how many digits it has (example: 1234 has 4 digits). Use a while loop.
*/

#include <iostream>
#include <cmath> // Para usar abs()

using namespace std;

int main()
{
    int numero;
    int contador = 0; // Inicializamos el contador de dígitos

    cout << "Digite un numero entero: ";
    cin >> numero;

    // Caso especial para el numero 0, que tiene 1 digito
    if (numero == 0)
    {
        contador = 1;
    }
    else
    {
        // Trabajamos con el valor absoluto para manejar numeros negativos
        int temp_numero = abs(numero);

        // Usamos un ciclo while para dividir el numero por 10 repetidamente
        // hasta que sea 0. En cada division contamos un digito.
        while (temp_numero > 0)
        {
            temp_numero = temp_numero / 10; // Quitamos el ultimo digito
            contador++;
        }
    }

    cout << "El numero " << numero << " tiene " << contador << " digitos." << endl;

    return 0;
}