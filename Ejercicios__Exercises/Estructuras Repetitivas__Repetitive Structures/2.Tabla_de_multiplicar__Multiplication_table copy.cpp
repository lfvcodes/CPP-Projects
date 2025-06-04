/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Pide al usuario un número entero y muestra su tabla de multiplicar del 1 al 10 usando un ciclo for.

Ask the user for an integer and display its multiplication table from 1 to 10 using a for loop.

*/

#include <iostream>
using namespace std;

int main()
{
    int numero;

    cout << "Digite un numero entero positivo: ";
    cin >> numero;

    for (int i = 1; i <= 10; i++)
    {
        cout << numero << " * " << i << " = " << (numero * i);
        cout << endl;
    }

    return 0;
}
