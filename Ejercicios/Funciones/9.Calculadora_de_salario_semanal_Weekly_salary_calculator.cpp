/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Calculadora de Salario Semanal
Programa que calcule:
- Sueldo bruto (horas normales y extras al 50%)
- Impuestos (20% si ≤300 $, 30% si >300 $, solo aplica si bruto >2500 $)
- Sueldo neto
Usa funciones para cada cálculo.

Weekly Salary Calculator
Program that calculates:
- Gross salary (regular hours and overtime at 50%)
- Taxes (20% if less than 300 Bs, 30% if more than 300 $, only applies if gross salary is greater than 2500 $)
- Net salary
Use functions for each calculation.
*/

#include <iostream>
using namespace std;

// Función para calcular el sueldo bruto
double calcularSueldoBruto(double horasNormales, double horasExtras, double tarifaPorHora)
{
	return (horasNormales * tarifaPorHora) + (horasExtras * tarifaPorHora * 1.5);
}

// Función para calcular los impuestos
double calcularImpuestos(double sueldoBruto)
{
	if (sueldoBruto > 2500)
	{
		if (sueldoBruto <= 300)
		{
			return sueldoBruto * 0.20; // Impuesto del 20%
		}
		else
		{
			return sueldoBruto * 0.30; // Impuesto del 30%
		}
	}
	return 0; // Sin impuestos si sueldo <= 2500
}

// Función para calcular el sueldo neto
double calcularSueldoNeto(double sueldoBruto, double impuestos)
{
	return sueldoBruto - impuestos;
}

int main()
{
	double horasNormales, horasExtras, tarifaPorHora;

	cout << "Digite horas normales trabajadas: ";
	cin >> horasNormales;
	cout << "Digite horas extras trabajadas: ";
	cin >> horasExtras;
	cout << "Digite tarifa por hora: ";
	cin >> tarifaPorHora;

	// Cálculos
	double sueldoBruto = calcularSueldoBruto(horasNormales, horasExtras, tarifaPorHora);
	double impuestos = calcularImpuestos(sueldoBruto);
	double sueldoNeto = calcularSueldoNeto(sueldoBruto, impuestos);

	// Mostrar resultados
	cout << "Sueldo Bruto: " << sueldoBruto << " $" << endl;
	cout << "Impuestos: " << impuestos << " $" << endl;
	cout << "Sueldo Neto: " << sueldoNeto << " $" << endl;

	return 0;
}