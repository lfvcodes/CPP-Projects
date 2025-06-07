/* 
#author: @lfvcodes 
https://github.com/lfvcodes/CPP-Projects

Aritmética de punteros Escribe un programa que declare un array de números enteros y use aritmética de punteros para recorrerlo y mostrar su contenido.

Pointer Arithmetic Write a program that declares an array of integers and uses pointer arithmetic to traverse and display its content. 
*/

#include <iostream>

using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr; // Apunta al primer elemento

    // Recorrer y mostrar el array usando punteros
    for (int i = 0; i < 5; i++) {
        cout << "Elemento " << i + 1 << ": " << *(ptr + i) << endl;
    }

    return 0;
}
