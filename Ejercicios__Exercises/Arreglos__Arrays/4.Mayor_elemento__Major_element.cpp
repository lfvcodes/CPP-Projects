/*
# Author: @lfvcodes
GitHub: https://github.com/lfvcodes/CPP-Projects

Program Description / Descripción del Programa:

Este programa lee un arreglo de números enteros desde la entrada estándar
y determina el elemento mayor del arreglo.

This program reads an array of integers from standard input
and determines the largest element in the array.
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int numeros[100], n, mayor = 0;

	cout << "Digite la cantidad de elementos a procesar: ";
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Digite el numero " << (i + 1) << ": ";
		cin >> numeros[i]; // Almacenamos los elementos en el arreglo

		if (numeros[i] > mayor)
		{							  // Determinamos el mayor elemento en cada
			mayor = numeros[i]; // iteración del bucle
		}
	}

	cout << "\nEl mayor elemento del arreglo es: " << mayor << endl;

	getch();
	return 0;
}