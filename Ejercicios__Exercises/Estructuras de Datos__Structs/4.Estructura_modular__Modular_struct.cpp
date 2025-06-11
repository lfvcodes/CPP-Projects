/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Programa para ingresar nombres y calificaciones de estudiantes, listar en orden alfabético, utilizar estructuras y funciones
Program to enter student names and grades, list in alphabetical order, use structure and functions
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Alumno
{
   string nombre;
   float nota;
};

void ingresarDatos(Alumno alumnos[], int cantidad);
void ordenarPorNombre(Alumno alumnos[], int cantidad);
void mostrarReporte(const Alumno alumnos[], int cantidad);

int main()
{
   Alumno alumnos[100];
   int cantidad;

   cout << "Digite el numero de alumnos: ";
   cin >> cantidad;
   cin.ignore(); // Limpiar el buffer

   ingresarDatos(alumnos, cantidad);
   ordenarPorNombre(alumnos, cantidad);
   mostrarReporte(alumnos, cantidad);

   return 0;
}

void ingresarDatos(Alumno alumnos[], int cantidad)
{
   for (int i = 0; i < cantidad; ++i)
   {
      cout << "\nAlumno #" << i + 1 << endl;
      cout << "Nombre: ";
      getline(cin, alumnos[i].nombre);
      cout << "Nota: ";
      cin >> alumnos[i].nota;
      cin.ignore(); // Limpiar el buffer para el siguiente getline
   }
}

void ordenarPorNombre(Alumno alumnos[], int cantidad)
{
   sort(alumnos, alumnos + cantidad, {
      return a.nombre < b.nombre;
   });
}

void mostrarReporte(const Alumno alumnos[], int cantidad)
{
   cout << "\n--- Reporte de Alumnos ---\n";
   for (int i = 0; i < cantidad; ++i)
   {
      cout << "Nombre: " << alumnos[i].nombre << " | Nota: " << alumnos[i].nota << endl;
   }
}
