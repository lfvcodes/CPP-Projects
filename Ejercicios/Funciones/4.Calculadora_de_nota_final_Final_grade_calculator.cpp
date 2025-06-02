/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Calculadora de Nota Final
Crea una función que calcule la nota final de un estudiante con estos componentes:
- 55% promedio de 3 parciales
- 30% examen final
- 15% trabajo especial
La función debe devolver el resultado al `main` para mostrarlo.

Final Grade Calculator
Create a function that calculates a student's final grade with these components:
- 55% average of 3 midterms
- 30% final exam
- 15% special assignment
The function should return the result to `main` for display.
*/

#include <iostream>
using namespace std;

// Función para calcular la nota final
float calcularNotaFinal(float parcial1, float parcial2, float parcial3, float examenFinal, float trabajoEspecial)
{
	float promedioParciales = (parcial1 + parcial2 + parcial3) / 3.0;
	float notaFinal = (promedioParciales * 0.55) + (examenFinal * 0.30) + (trabajoEspecial * 0.15);
	return notaFinal;
}

int main()
{
	float parcial1, parcial2, parcial3, examenFinal, trabajoEspecial;

	// Solicitar al usuario las calificaciones
	cout << "Digite la nota del primer parcial: ";
	cin >> parcial1;
	cout << "Digite la nota del segundo parcial: ";
	cin >> parcial2;
	cout << "Digite la nota del tercer parcial: ";
	cin >> parcial3;
	cout << "Digite la nota del examen final: ";
	cin >> examenFinal;
	cout << "Digite la nota del trabajo especial: ";
	cin >> trabajoEspecial;

	// Calcular la nota final
	float notaFinal = calcularNotaFinal(parcial1, parcial2, parcial3, examenFinal, trabajoEspecial);

	// Mostrar la nota final
	cout << "La nota final es: " << notaFinal << endl;

	return 0;
}