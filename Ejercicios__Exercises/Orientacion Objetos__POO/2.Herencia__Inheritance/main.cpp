/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Herencia - Clase "Vehiculo" y "Auto"
Crea una clase base `Vehiculo` con atributos para la marca y el año.
Luego, crea una clase derivada `Auto` que herede de `Vehiculo` y agregue
un atributo para el numero de puertas. Implementa constructores
y metodos para mostrar la informacion de ambos.

Inheritance - "Vehicle" and "Car" Classes
Create a base class `Vehicle` with attributes for the make and year.
Then, create a derived class `Car` that inherits from `Vehicle` and adds an attribute for the number of doors.
Implement constructors and methods to display information for both.

*/

#include <iostream>
#include <string>
#include "Vehiculo.h"
#include "Auto.h"

using namespace std;

int main()
{
   // Crear un objeto de la clase Vehiculo
   Vehiculo miVehiculo("Toyota", 2020);
   cout << "--- Informacion del Vehiculo ---" << endl;
   miVehiculo.mostrarInformacionVehiculo();
   cout << endl;

   // Crear un objeto de la clase Auto
   Auto miAuto("Ford", 2023, 4);
   cout << "--- Informacion del Auto ---" << endl;
   miAuto.mostrarInformacionAuto();

   return 0;
}
