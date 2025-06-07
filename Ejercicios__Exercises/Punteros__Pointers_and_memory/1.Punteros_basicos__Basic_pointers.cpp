/* 
#author: @lfvcodes 
https://github.com/lfvcodes/CPP-Projects

Uso básico de punteros Escribe un programa que declare un puntero a un número entero,
 asigne un valor a ese número y muestre su dirección y contenido usando el puntero.

Basic Pointer Usage Write a program that declares a pointer to an integer,
 assigns a value to that number, and displays its address and content using the pointer. 
*/

#include <iostream>

using namespace std;

int main() {
    int num = 42;
    int* ptr = &num;

    // Mostrar contenido y dirección usando el puntero
    cout << "Valor de num: " << *ptr << endl;
    cout << "Direccion de num: " << ptr << endl;

    return 0;
}
