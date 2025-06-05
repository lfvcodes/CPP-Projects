/*
# Author: @lfvcodes
GitHub: https://github.com/lfvcodes/CPP-Projects

Program Description / Descripción del Programa:

Este programa implementa una búsqueda binaria en un arreglo ordenado de 10 números.
El usuario ingresa los números y luego busca un valor específico.

This program implements binary search on a sorted array of 10 numbers.
The user enters the numbers and then searches for a specific value.
*/

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	int numeros[10]; // Arreglo para almacenar los números
	int inf, sup, mitad, dato, i;
	char bandera = 'F'; // F = No encontrado, V = Encontrado

	// Ingreso de datos (debe ser un arreglo ordenado)
	cout << "DIGITE 10 NUMEROS EN ORDEN ASCENDENTE:" << endl;
	for (i = 0; i < 10; i++)
	{
		cout << "Digite el numero " << (i + 1) << ": ";
		cin >> numeros[i];
	}

	// Solicitar dato a buscar
	cout << endl
		  << "Digite el numero a buscar: ";
	cin >> dato;

	// Algoritmo de Búsqueda Binaria
	inf = 0; // Límite inferior
	sup = 9; // Límite superior (corregido de 10 a 9 para 10 elementos)
	i = 0;

	while ((inf <= sup) && (i < 10))
	{
		mitad = (inf + sup) / 2;

		if (numeros[mitad] == dato)
		{
			bandera = 'V';
			break;
		}

		if (numeros[mitad] > dato)
		{
			sup = mitad - 1; // Corregido para mejor eficiencia
		}
		else
		{
			inf = mitad + 1; // Corregido para mejor eficiencia
		}

		i++;
	}

	// Mostrar resultados
	if (bandera == 'V')
	{
		cout << "El numero fue encontrado en la posicion: " << mitad << endl;
	}
	else
	{
		cout << "El numero NO fue encontrado en el arreglo" << endl;
	}

	getch();
	return 0;
}