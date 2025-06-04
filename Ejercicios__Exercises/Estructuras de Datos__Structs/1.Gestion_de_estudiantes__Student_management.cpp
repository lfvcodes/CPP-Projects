/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Crea una estructura Estudiante con los campos nombre, edad y promedio. Luego, escribe un programa que permita:
Ingresar datos de N estudiantes.
Mostrar el estudiante con el mayor promedio.

Create a Student structure with the fields name, age, and GPA. Then, write a program that allows you to:
Enter data for N students.
Display the student with the highest GPA.
*/

#include <iostream>
#include <string>
using namespace std;

struct Estudiante
{
   string nombre;
   int edad;
   float promedio;
};

void mostrarMejorEstudiante(const Estudiante estudiantes[], int n)
{
   if (n == 0)
   {
      cout << "No hay estudiantes.\n";
      return;
   }

   Estudiante mejor = estudiantes[0];
   for (int i = 1; i < n; ++i)
   {
      if (estudiantes[i].promedio > mejor.promedio)
      {
         mejor = estudiantes[i];
      }
   }

   cout << "Mejor estudiante:\n";
   cout << "Nombre: " << mejor.nombre << "\nEdad: " << mejor.edad
        << "\nPromedio: " << mejor.promedio << endl;
}

int main()
{
   Estudiante estudiantes[100];
   int n;
   cout << "Digite el numero de estudiantes (max 100): ";
   cin >> n;

   for (int i = 0; i < n; ++i)
   {
      cout << "\nEstudiante " << i + 1 << ":\n";
      cout << "Nombre: ";
      cin >> estudiantes[i].nombre;
      cout << "Edad: ";
      cin >> estudiantes[i].edad;
      cout << "Promedio: ";
      cin >> estudiantes[i].promedio;
   }

   mostrarMejorEstudiante(estudiantes, n);
   return 0;
}