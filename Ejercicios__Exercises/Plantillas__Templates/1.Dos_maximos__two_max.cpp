/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Ejercicio básico: Máximo de dos valores
Crear una función plantilla que devuelva el máximo de dos valores de cualquier tipo comparable

Basic exercise: Maximum of two values
Create a template function that returns the maximum of two values of any comparable type
*/

#include <iostream>
using namespace std;

// Plantilla para encontrar el máximo de dos valores
template <typename T> //T es un modelo genérico que puede adaptarse a diferentes tipos de datos.
T maximo(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    
    // Ejemplos de uso
    //maximo(5, 10);       T se convierte en int
    //maximo(3.14, 2.71);  T se convierte en double
    //maximo('a', 'z');    T se convierte en char

    cout << "Maximo entre 5 y 10: " << maximo(5, 10) << endl;
    cout << "Maximo entre 3.14 y 2.71: " << maximo(3.14, 2.71) << endl;
    cout << "Maximo entre 'a' y 'z': " << maximo('a', 'z') << endl;
    
    return 0;
}