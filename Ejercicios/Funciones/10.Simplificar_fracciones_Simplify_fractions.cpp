/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Operaciones con Fracciones
Crea un sistema para trabajar con fracciones con estas funciones:
- Leer_fracción: Lee y simplifica
- Escribir_fracción: Muestra formateada
- Calcular_mcd: Usando algoritmo de Euclides
- Simplificar_fracción: Reduce la fracción

Operations with Fractions
Create a system for working with fractions with these functions:
- Read_fraction: Reads and simplifies
- Write_fraction: Formats the fraction
- Calculate_gcd: Uses Euclidean algorithm
- Simplify_fraction: Reduces the fraction
*/

#include <iostream>
using namespace std;

// Función para calcular el Maximo Comun Divisor (MCD)
int calcular_mcd(int a, int b)
{
	while (b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return (a < 0) ? -a : a; // Asegurarse de que el MCD sea positivo
}

// Función para simplificar la fracción
void simplificar_fraccion(int &numerador, int &denominador)
{
	int mcd = calcular_mcd(numerador, denominador);
	numerador /= mcd;
	denominador /= mcd;

	// Asegurarse de que el denominador sea positivo
	if (denominador < 0)
	{
		numerador = -numerador;
		denominador = -denominador;
	}
}

// Función para leer y simplificar la fracción
void leer_fraccion(int &numerador, int &denominador)
{
	cout << "Ingrese el numerador: ";
	cin >> numerador;
	cout << "Ingrese el denominador: ";
	cin >> denominador;

	// Comprobar que el denominador no sea cero
	while (denominador == 0)
	{
		cout << "Error: El denominador no puede ser cero. Ingrese nuevamente: ";
		cin >> denominador;
	}

	simplificar_fraccion(numerador, denominador); // Simplificamos la fracción al leer
}

// Función para escribir la fracción de forma formateada
void escribir_fraccion(int numerador, int denominador)
{
	cout << "Fraccion: " << numerador << "/" << denominador << endl;
}

int main()
{
	int numerador, denominador;

	leer_fraccion(numerador, denominador);

	// Mostrar fracción simplificada
	escribir_fraccion(numerador, denominador);

	return 0;
}