/*
# Author: @lfvcodes
GitHub: https://github.com/lfvcodes/CPP-Projects

Este programa recibe 5 números enteros como entrada del usuario,
los ordena en forma ascendente usando el algoritmo de ordenamiento de burbuja,
y luego muestra los números ordenados tanto en forma ascendente como descendente.

This program takes 5 integer numbers as input from the user,
sorts them in ascending order using the bubble sort algorithm,
and then displays the sorted numbers in both ascending and descending order.
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int arreglo[5];
	int i, j, aux;

	// Solicitar números al usuario / Request numbers from user
	for (i = 0; i < 5; i++)
	{
		cout << "Digite el número " << (i + 1) << ": ";
		cin >> arreglo[i];
	}

	// Algoritmo de ordenamiento burbuja / Bubble sort algorithm
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (arreglo[j] > arreglo[j + 1])
			{
				aux = arreglo[j];
				arreglo[j] = arreglo[j + 1];
				arreglo[j + 1] = aux;
			}
		}
	}

	// Mostrar números orden ascendente / Show ascending order
	cout << "Números ordenados de forma ascendente: ";
	for (i = 0; i < 5; i++)
	{
		cout << arreglo[i] << " ";
	}

	// Mostrar números orden descendente / Show descending order
	cout << "\nNúmeros ordenados de forma descendente: ";
	for (i = 4; i >= 0; i--)
	{
		cout << arreglo[i] << " ";
	}

	getch();
	return 0;
}