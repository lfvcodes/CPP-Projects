/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Crea un programa en C++ que muestre un menú con 3 opciones:
Saludar → Muestra un mensaje de bienvenida.
Contar hasta 5 → Imprime los números del 1 al 5.
Salir → Termina el programa.
El programa debe usar switch para manejar las opciones y repetirse hasta que el usuario elija salir.

Create a C++ program that displays a menu with three options:
Greet → Display a welcome message.
Count to 5 → Print the numbers from 1 to 5.
Exit → Terminate the program.
The program should use switches to manage the options and loop until the user chooses to exit.
*/

#include <iostream>
using namespace std;

int main()
{
   int opcion;

   do
   {
      cout << "\n--- Menu Basico ---" << endl;
      cout << "1. Saludar" << endl;
      cout << "2. Contar hasta 5" << endl;
      cout << "3. Salir" << endl;
      cout << "Digite una opcion: ";
      cin >> opcion;

      switch (opcion)
      {
      case 1:
         cout << "Hola,Bienvenido al programa." << endl;
         break;

      case 2:
         cout << "Contando hasta 5:" << endl;
         for (int i = 1; i <= 5; i++)
         {
            cout << i << endl;
         }
         break;

      case 3:
         cout << "Saliendo del programa. Hasta luego!" << endl;
         break;

      default:
         cout << "Opcion no valida. Intente de nuevo." << endl;
      }
   } while (opcion != 3);

   return 0;
}