/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Verificador de Paridad
Crea una función llamada `par` que reciba un entero y devuelva:
- 1 si es par
- 0 si es impar
El programa principal debe mostrar el resultado.

Parity Checker
Create a function called `par` that receives an integer and returns:
- 1 if even
- 0 if odd
The main program should display the result.
*/

#include <iostream>
using namespace std;

// Función para verificar la paridad
int par(int numero)
{
	if (numero % 2 == 0)
	{
		return 1; // Es par
	}
	else
	{
		return 0; // Es impar
	}
}

int main()
{
	int numero;

	// Solicitar al usuario que ingrese un número
	cout << "Digite un numero entero: ";
	cin >> numero;

	// Llamar a la función y mostrar el resultado
	int resultado = par(numero);
	if (resultado == 1)
	{
		cout << "El numero " << numero << " es par." << endl;
	}
	else
	{
		cout << "El numero " << numero << " es impar." << endl;
	}

	return 0;
}