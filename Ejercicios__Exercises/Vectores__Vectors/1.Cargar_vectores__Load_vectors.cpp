/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Crea un programa en C++ que permita ingresar 20 valores numéricos.
Una vez ingresados, el usuario proporcionará un número específico para buscar. 
El programa deberá determinar cuántas veces se repite este número específico
dentro de los 20 valores iniciales.
Finalmente, debe mostrar todos los valores ingresados (el "vector") y 
el resultado de la búsqueda (la cantidad de veces que se repitió el número).
El programa debe utilizar dos funciones que devuelvan parámetros.

Create a C++ program that takes 20 numerical inputs. 
After these values are entered, the user will provide a specific number to search for.
The program should then count how many times this specific number appears within
the initial 20 values. Finally, 
it should display all the entered values (the "vector") and
the total count of the searched number.
The program must use two functions that return parameters.
*/

#include <iostream>
#include <vector>
using namespace std;

void cargarVector(vector<int>& vec);
int contarRepeticiones(const vector<int>& vec, int valor);
void mostrarVector(const vector<int>& vec);

int main() {
    vector<int> valores(20);
    
    cargarVector(valores);
    mostrarVector(valores);
    
    int valorBuscar;
    cout << "\nValor a buscar: ";
    cin >> valorBuscar;
    
    int repeticiones = contarRepeticiones(valores, valorBuscar);
    cout << "El valor aparece " << repeticiones << " veces.\n";
    
    return 0;
}

void cargarVector(vector<int>& vec) {
    for(int i = 0; i < 20; i++) {
        cout << "Digite valor " << i+1 << ": ";
        cin >> vec[i];
    }
}

int contarRepeticiones(const vector<int>& vec, int valor) {
    int contador = 0;
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] == valor) {
            contador++;
        }
    }
    return contador;
}

void mostrarVector(const vector<int>& vec) {
    cout << "\nVector: [";
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if(i < vec.size()-1) {
            cout << ", ";
        }
    }
    cout << "]\n";
}