/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Instanciación de Clases - Clase "Mascota"
Crea una clase `Mascota` con atributos como nombre, tipo y edad.
Implementa un constructor para inicializar estos atributos y métodos
para mostrar la información de la mascota y emitir un sonido según su tipo.

Class Instantiation - "Pet" Class
Create a class `Pet` with attributes such as name, type, and age.
Implement a constructor to initialize these attributes and methods
to display the pet's information and make a sound based on its type.
*/

#include <iostream>
#include <string>
#include "Mascota.h"
using namespace std;

int main()
{
   // Crear objetos (instancias) de la clase Mascota
   Mascota mascota1("Firulais", "perro", 5);
   Mascota mascota2("Michi", "gato", 3);

   // Usar metodos de los objetos
   cout << "Informacion de la primera mascota:" << endl;
   mascota1.mostrarInformacion();
   mascota1.hacerSonido();

   cout << "\nInformacion de la segunda mascota:" << endl;
   mascota2.mostrarInformacion();
   mascota2.hacerSonido();

   return 0;
}
