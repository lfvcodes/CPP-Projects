/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Calculadora de Cuotas de Seguros
Crea un programa que calcule la cuota de un seguro basado en el monto:
- 4% para montos < 600 Bs
- 2% para montos ? 600 Bs
Implementa una función que reciba el monto y devuelva la cuota, mostrando el resultado en el programa principal.

Insurance Premium Calculator
Create a program that calculates an insurance premium based on the amount:
- 4% for amounts < 600 Bs
- 2% for amounts = 600 Bs
Implement a function that receives the amount and returns the premium, displaying the result in the main program.
*/


#include <iostream>

using namespace std;

// Funcion que calcula la cuota del seguro
double calcularCuota(double monto) {
    if (monto < 600) {
        return monto * 0.04;
    } else {
        return monto * 0.02;
    }
}

int main() {
    double monto;
    
    // Solicitar el monto al usuario
    cout << "Digite el monto del seguro: ";
    cin >> monto;

    // Calcular y mostrar la cuota
    double cuota = calcularCuota(monto);
    cout << "La cuota del seguro es: " << cuota << " Bs" << endl;

    return 0;
}

