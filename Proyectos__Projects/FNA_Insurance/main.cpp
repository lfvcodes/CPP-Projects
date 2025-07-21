/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Desarrollar un programa que calcule el monto adecuado de una póliza de seguro de vida,
utilizando el método de Análisis de Necesidades Financieras (FNA).
Este método considera factores como ingresos,
deudas, gastos futuros y ahorros existentes para determinar la cobertura necesaria.


Develop a program that calculates the appropriate amount for a life insurance policy,
using the Financial Needs Analysis (FNA) method. This method considers factors such as
income, debt, future expenses, and existing savings to determine the necessary coverage.

*/

#include <iostream>
#include <iomanip>
#include "FNA.h"
using namespace std;

int main() {
    SeguroFNA seguro;
    char opcion;

    do {
        double ingreso, deudas, gastos, ahorros;
        int edadActual, edadJubilacion;

        cout << "\n=== Calculadora de Poliza de Seguro (FNA) ===" << endl;

        // Validar ingreso anual
        do {
            cout << "Ingreso anual: $";
            cin >> ingreso;
        } while (ingreso < 0);

        // Validar edades
        do {
            cout << "Edad actual: ";
            cin >> edadActual;
            cout << "Edad de jubilacion: ";
            cin >> edadJubilacion;
        } while (edadJubilacion <= edadActual || edadActual < 18);

        int anios = edadJubilacion - edadActual;

        // Validar deudas, gastos y ahorros
        do {
            cout << "Deudas totales: $";
            cin >> deudas;
        } while (deudas < 0);

        do {
            cout << "Gastos futuros estimados: $";
            cin >> gastos;
        } while (gastos < 0);

        do {
            cout << "Ahorros existentes: $";
            cin >> ahorros;
        } while (ahorros < 0);

        // Calcular y mostrar resultado
        seguro.setDatos(ingreso, anios, deudas, gastos, ahorros);
        double cobertura = seguro.calcularCobertura();

        cout << fixed << setprecision(2);
        cout << "\n-> Cobertura recomendada: $" << cobertura << endl;

        // Preguntar si desea continuar
        cout << "\nDesea realizar otro calculo? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    cout << "\nPrograma terminado. Gracias por usar la calculadora FNA!" << endl;
    return 0;
}