/*
# Author: @lfvcodes
GitHub: https://github.com/lfvcodes/CPP-Projects

Program Description / Descripción del Programa:

Este programa realiza una búsqueda secuencial en un arreglo de 10 números.
El usuario ingresa los números y luego busca un valor específico.

This program performs a sequential search in an array of 10 numbers.
The user enters the numbers and then searches for a specific value.
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int arreglo[10];
	int i, dato;
	char bandera = 'F'; // F = No encontrado, V = Encontrado

	// Ingreso de datos al arreglo
	for (i = 0; i <= 9; i++)
	{
		cout << "Digite el numero " << (i + 1) << ": ";
		cin >> arreglo[i];
	}

	// Búsqueda secuencial
	cout << "Digite el dato a buscar: ";
	cin >> dato;

	i = 0;
	while ((bandera == 'F') && (i < 10))
	{
		if (arreglo[i] == dato)
		{
			bandera = 'V';
		}
		i++;
	}

	// Mostrar resultados
	if (bandera == 'F')
	{
		cout << "El numero no existe en el arreglo" << endl;
	}
	else if (bandera == 'V')
	{
		cout << "El numero fue encontrado en la posicion: " << i - 1 << endl;
	}

	getch();
	return 0;
}