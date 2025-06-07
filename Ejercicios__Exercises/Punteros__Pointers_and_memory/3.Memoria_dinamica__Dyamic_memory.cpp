/* 
#author: @lfvcodes 
https://github.com/lfvcodes/CPP-Projects

Memoria dinámica y arrays dinámicos Escribe un programa que solicite al usuario un tamaño de array, lo reserve dinámicamente con new, almacene números en él y luego lo libere con delete.

Dynamic Memory and Dynamic Arrays Write a program that asks the user for an array size, allocates memory dynamically with new, stores numbers in it, and then frees it with delete. 
*/

#include <iostream>

using namespace std;

int main() {
    int tamanio;

    // Solicitar tamaño del array
    cout << "Digite el tamaño del array: ";
    cin >> tamanio;

    // Reservar memoria dinámicamente
    int* arr = new int[tamanio];

    // Almacenar valores en el array
    for (int i = 0; i < tamanio; i++) {
        cout << "Digite el valor del elemento " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Mostrar contenido del array
    cout << "Contenido del array: ";
    for (int i = 0; i < tamanio; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Liberar memoria dinámica
    delete[] arr;

    return 0;
}
