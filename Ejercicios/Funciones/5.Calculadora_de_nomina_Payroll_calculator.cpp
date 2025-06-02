/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Calculadora de Nómina
Desarrolla un programa que procese:
- Nombre del empleado
- Salario por hora
- Horas trabajadas
- Porcentaje de retención
Implementa una función `void` que calcule y muestre:
- Salario bruto
- Impuestos
- Salario neto

Payroll Calculator
Develop a program that processes:
- Employee name
- Hourly wage
- Hours worked
- Withholding percentage
Implement a `void` function that calculates and displays:
- Gross pay
- Taxes
- Net pay
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Función para calcular y mostrar la nómina
void calcularNomina(const string &nombre, float salarioPorHora, float horasTrabajadas, float porcentajeRetencion)
{
	// Cálculo del salario bruto
	float salarioBruto = (salarioPorHora * horasTrabajadas);

	// Cálculo de impuestos
	float impuestos = salarioBruto * (porcentajeRetencion / 100);

	// Cálculo del salario neto
	float salarioNeto = salarioBruto - impuestos;

	// Mostrar resultados
	cout << fixed << setprecision(2); // Configurar formato de salida
	cout << "Nombre del empleado: " << nombre << endl;
	cout << "Salario bruto: $" << salarioBruto << endl;
	cout << "Impuestos: $" << impuestos << endl;
	cout << "Salario neto: $" << salarioNeto << endl;
}

int main()
{
	string nombre;
	float salarioPorHora, horasTrabajadas, porcentajeRetencion;

	// Solicitar datos al usuario
	cout << "Digite el nombre del empleado: ";
	getline(cin, nombre);
	cout << "Digite el salario por hora: ";
	cin >> salarioPorHora;
	cout << "Digite las horas trabajadas: ";
	cin >> horasTrabajadas;
	cout << "Digite el porcentaje de retención: ";
	cin >> porcentajeRetencion;

	// Llamar a la función para calcular la nómina
	calcularNomina(nombre, salarioPorHora, horasTrabajadas, porcentajeRetencion);

	return 0;
}