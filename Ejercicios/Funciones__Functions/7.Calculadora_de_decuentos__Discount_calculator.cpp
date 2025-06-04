/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Calculadora de Descuentos (Versión 1)
Implementa una función `void` que calcule descuentos según el precio:
- < 6 $: 0%
- ≥6 y <60 $: 5%
- ≥60 $: 10%
Mostrar precio inicial, descuento y precio final.


Discount Calculator (Version 1)
Implements a `void` function that calculates discounts based on price:
- <6 $: 0%
- ≥6 and <60 $: 5%
- ≥60 $: 10%
Displays initial price, discount, and final price.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Función para calcular el descuento
void calcularDescuento(float precioInicial)
{
	float descuento = 0.0;
	float precioFinal;

	// Determinar el porcentaje de descuento según el precio
	if (precioInicial < 6)
	{
		descuento = 0; // 0%
	}
	else if (precioInicial >= 6 && precioInicial < 60)
	{
		descuento = precioInicial * 0.05; // 5%
	}
	else
	{
		descuento = precioInicial * 0.10; // 10%
	}

	// Calcular el precio final
	precioFinal = precioInicial - descuento;

	// Mostrar resultados
	cout << fixed << setprecision(2); // Configurar formato de salida
	cout << "Precio inicial: Dolar: " << precioInicial << endl;
	cout << "Descuento: Dolar: " << descuento << endl;
	cout << "Precio final Dolar: " << precioFinal << endl;
}

int main()
{
	float precioInicial;

	// Solicitar al usuario que ingrese el precio inicial
	cout << "Digite el precio inicial: ";
	cin >> precioInicial;

	// Llamar a la función para calcular el descuento
	calcularDescuento(precioInicial);

	return 0;
}