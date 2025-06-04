/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Calculadora de Circunferencia
Desarrolla una función que calcule el área y perímetro de una circunferencia dado su radio.
El programa principal debe leer el radio y mostrar ambos valores.

Circumference Calculator
Develop a function that calculates the area and perimeter of a circle given its radius.
The main program should read the radius and display both values.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Definición de M_PI si no está ya definido
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Función para calcular el área y el perímetro de una circunferencia
void calcularCircunferencia(float radio, float &area, float &perimetro)
{
	// Cálculo del área
	area = M_PI * radio * radio; // Utilizando la constante M_PI para el cálculo
	// Cálculo del perímetro
	perimetro = 2 * M_PI * radio;
}

int main()
{
	float radio;
	float area, perimetro;

	// Solicitar al usuario que ingrese el radio
	cout << "Digite el radio de la circunferencia: ";
	cin >> radio;

	// Llamar a la función para calcular el área y el perímetro
	calcularCircunferencia(radio, area, perimetro);

	// Mostrar resultados
	cout << fixed << setprecision(2);
	cout << "area de la circunferencia: " << area << " unidades cuadradas" << endl;
	cout << "Perimetro de la circunferencia: " << perimetro << " unidades" << endl;

	return 0;
}