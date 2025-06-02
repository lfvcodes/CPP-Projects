/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Cálculo de Temperatura Media
Escribe una función que calcule la temperatura media diaria usando la máxima y mínima. Desarrolla un programa principal que pida al usuario el número de días a analizar, luego solicite las temperaturas máxima y mínima de cada día, y muestre la media utilizando la función creada.

Average Temperature Calculation
Write a function that calculates the average daily temperature using the maximum and minimum temperatures. Develop a main program that prompts the user for the number of days to analyze, then requests the maximum and minimum temperatures for each day, and displays the average using the created function.
*/


#include <iostream>

using namespace std;

// Funcion para calcular la temperatura media diaria
double calcularMedia(double maxima, double minima) {
    return (maxima + minima) / 2.0;
}

int main() {
    int numDias;
    
    // Solicitar el numero de dias a analizar
    cout << "Digite el numero de dias a analizar: ";
    cin >> numDias;

    for (int i = 1; i <= numDias; i++) {
        double tempMaxima, tempMinima;
        
        // Solicitar las temperaturas maxima y minima del dia
        cout << "Dia " << i << " - Digite la temperatura maxima: ";
        cin >> tempMaxima;
        cout << "Dia " << i << " - Digite la temperatura minima: ";
        cin >> tempMinima;
        
        // Calcular y mostrar la temperatura media
        double tempMedia = calcularMedia(tempMaxima, tempMinima);
        cout << "La temperatura media del dia " << i << " es: " << tempMedia << "�C" << endl;
    }

    return 0;
}

