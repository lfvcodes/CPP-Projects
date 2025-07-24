/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Debes crear un programa en C++ para gestionar las calificaciones de los estudiantes
de una clase. 
El programa deberá almacenar el nombre de cada estudiante y un vector de sus notas 
(números decimales). Además, 
se necesita una función que calcule el promedio de notas para un estudiante dado.

create a C++ program to manage student grades for a class. 
The program should store each student's name and a vector of their grades 
(decimal numbers). Additionally, 
you'll need a function to calculate the average grade for a given student.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Estudiante {
    string nombre;
    vector<double> notas;
};

double calcularPromedio(const Estudiante& est);

int main() {
    Estudiante estudiantes[100];
    int cantidad = 0;
    int continuar = 1;

    do {
        cout << "Digite el nombre del estudiante: ";
        getline(cin,estudiantes[cantidad].nombre);
        
        cout << "Digite las 4 notas:\n";
        for(int i = 0; i < 4; i++) {
            double nota;
            cout << "Nota " << (i+1) << ": ";
            cin >> nota;
            estudiantes[cantidad].notas.push_back(nota);
        }
        
        cantidad++;
        
        cout << "Desea agregar otro estudiante? (1.Si/ 0.No): ";
        cin >> continuar;
    } while(continuar == 1);

    cout << "\nListado de estudiantes y promedios:\n";
    for(int i = 0; i < cantidad; i++) {
        cout << "Estudiante: " << estudiantes[i].nombre 
             << ", Promedio: " << calcularPromedio(estudiantes[i]) << endl;
    }

    return 0;
}

double calcularPromedio(const Estudiante& est) {
    if(est.notas.empty()) return 0.0;
    
    double suma = 0;
    for(int i = 0; i < est.notas.size(); i++) {
        suma += est.notas[i];
    }
    return suma / est.notas.size();
}