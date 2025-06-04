/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Crea un programa en C++ para proyectar el salario anual de un empleado durante varios años, aplicando aumentos basados en el salario actual: 10% (< $500), 5% (>= $500 y <= $1000), o 2% (> $1000).

El programa debe solicitar el salario inicial y la cantidad de años a simular, mostrando el aumento y el salario actualizado para cada año.

Create a C++ program to project an employee's annual salary over several years, applying increases based on the current salary: 10% (< $500), 5% (>= $500 and <= $1,000), or 2% (> $1,000).

The program should request the starting salary and the number of years to simulate, displaying the increase and updated salary for each year.
*/

#include <iostream>
using namespace std;

int main()
{
   float salario = 0;
   int anios = 0;

   cout << "Ingrese el salario inicial del empleado: $";
   cin >> salario;

   cout << "Ingrese el número de anios a simular: ";
   cin >> anios;

   for (int i = 1; i <= anios; i++)
   {
      float aumento = 0;

      if (salario < 500)
      {
         aumento = salario * 0.10;
      }
      else if (salario <= 1000)
      {
         aumento = salario * 0.05;
      }
      else
      {
         aumento = salario * 0.02;
      }

      salario += aumento;

      cout << "Anio " << i << ": aumento = $" << aumento << ", salario actualizado = $" << salario << endl;
   }

   return 0;
}
