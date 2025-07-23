/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Desarrolla un conjunto de funciones que permitan: leer una fracción, 
mostrarla en pantalla, simplificarla utilizando el máximo común divisor (MCD),
el cual se calculará usando el algoritmo de Euclides.

Develop a set of functions that allow: reading a fraction, displaying it,
simplifying it using the greatest common divisor (GCD), 
calculated with Euclid's algorithm.
*/ 

#include <iostream>
#include <cmath>
#include <numeric> 

using namespace std;

// --- Estructura para representar una fraccion ---
struct Fraccion {
    int numerador;
    int denominador;
};

// --- Funcion para calcular el Maximo Comun Divisor (MCD) usando el algoritmo de Euclides ---
int calcularMCD(int a, int b) {
    // Aseguramos que los numeros sean positivos para el algoritmo de Euclides
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// --- Funcion para leer una fraccion desde el usuario ---
Fraccion leerFraccion() {
    Fraccion f;
    cout << "Ingrese el numerador: ";
    cin >> f.numerador;
    cout << "Ingrese el denominador: ";
    cin >> f.denominador;

    // Asegurarse de que el denominador no sea cero
    while (f.denominador == 0) {
        cout << "El denominador no puede ser cero. Ingrese un denominador valido: ";
        cin >> f.denominador;
    }
    return f;
}

// --- Funcion para mostrar una fraccion en pantalla ---
void mostrarFraccion(const Fraccion& f) {
    cout << f.numerador << "/" << f.denominador;
}

// --- Funcion para simplificar una fraccion ---
Fraccion simplificarFraccion(Fraccion f) {
    int mcd = calcularMCD(f.numerador, f.denominador);
    f.numerador /= mcd;
    f.denominador /= mcd;

    // Ajustar el signo si el denominador es negativo (convencion es que el signo va en el numerador)
    if (f.denominador < 0) {
        f.numerador *= -1;
        f.denominador *= -1;
    }
    return f;
}

// --- Funcion principal del programa ---
int main() {
    cout << "--- Programa de Fracciones ---" << endl;

    // 1. Leer una fraccion
    cout << "\nVamos a leer una fraccion:" << endl;
    Fraccion miFraccion = leerFraccion();

    // 2. Mostrar la fraccion leida
    cout << "La fraccion ingresada es: ";
    mostrarFraccion(miFraccion);
    cout << endl;

    // 3. Simplificar la fraccion
    Fraccion fraccionSimplificada = simplificarFraccion(miFraccion);

    // 4. Mostrar la fraccion simplificada
    cout << "La fraccion simplificada es: ";
    mostrarFraccion(fraccionSimplificada);
    cout << endl;

    return 0;
}