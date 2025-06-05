/*
# Author: @lfvcodes
GitHub: https://github.com/lfvcodes/CPP-Projects

Program Description / Descripción del Programa:

Este programa implementa el algoritmo QuickSort para ordenar un arreglo de números reales.
El usuario especifica el tamaño del arreglo e ingresa sus elementos, luego el programa muestra
tanto el arreglo original como el ordenado.

This program implements the QuickSort algorithm to sort an array of real numbers.
The user specifies the array size and enters its elements, then the program displays
both the original and sorted arrays.
*/

#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

// Prototipos de funciones / Function prototypes
void quicksort(double[20], int, int);
void escribir(double[20], int);

int main()
{
    int i, nro = 10;
    double B[20];

    // Entrada de datos / Data input
    cout << "Digite la longitud del arreglo (max 20): " << endl
         << endl;
    cin >> nro;

    cout << "Digite los elementos del arreglo:" << endl
         << endl;
    for (i = 0; i < nro; i++)
    {
        cout << "B[" << i << "]= ";
        cin >> B[i];
    }

    // Mostrar arreglo original / Show original array
    cout << endl
         << "ARREGLO ORIGINAL" << endl
         << endl;
    for (i = 0; i < nro; i++)
    {
        cout << B[i] << setw(5);
    }

    // Ordenar y mostrar resultados / Sort and show results
    quicksort(B, 0, nro - 1);
    escribir(B, nro);

    getch();
    return 0;
}

// Implementación de QuickSort / QuickSort implementation
void quicksort(double A[20], int primero, int ultimo)
{
    int central, i, j;
    double pivote;

    central = (primero + ultimo) / 2;
    pivote = A[central];
    i = primero;
    j = ultimo;

    do
    {
        while (A[i] < pivote)
            i++;
        while (A[j] > pivote)
            j--;

        if (i <= j)
        {
            // Intercambiar elementos / Swap elements
            double temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    // Llamadas recursivas / Recursive calls
    if (primero < j)
        quicksort(A, primero, j); // Sublista izquierda / Left sublist
    if (i < ultimo)
        quicksort(A, i, ultimo); // Sublista derecha / Right sublist
}

// Función para mostrar el arreglo / Function to display array
void escribir(double A[20], int n)
{
    int i;
    cout << endl
         << "ARREGLO ORDENADO CON QUICKSORT" << endl
         << endl;
    for (i = 0; i < n; i++)
    {
        cout << A[i] << setw(5);
    }
    cout << endl
         << endl;
}