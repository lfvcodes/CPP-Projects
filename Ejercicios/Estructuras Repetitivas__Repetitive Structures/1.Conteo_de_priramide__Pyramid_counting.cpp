/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Desarrolla un programa en C++ que solicite al usuario un número entero positivo. Luego, el programa debe imprimir una secuencia de números en orden descendente, formando un patrón similar a una pirámide invertida.

El patrón debe comenzar con el número ingresado por el usuario en la primera línea. Cada línea subsiguiente debe comenzar con el número de la línea anterior menos uno, continuando el conteo descendente hasta 1.

Si el usuario ingresa un número que no es positivo (menor o igual a cero), el programa debe mostrar un mensaje de error y finalizar.
Ejemplo de salida:

5 4 3 2 1
4 3 2 1
3 2 1
2 1
1

Develop a C++ program that prompts the user for a positive integer. The program should then print a sequence of numbers in descending order, forming a pattern similar to an inverted pyramid.

The pattern should begin with the number entered by the user on the first line. Each subsequent line should begin with the number from the previous line minus one, continuing to count down to 1.

If the user enters a non-positive number (less than or equal to zero), the program should display an error message and exit.
Example output:

5 4 3 2 1
4 3 2 1
3 2 1
2 1
1

*/

#include <iostream>
using namespace std;

int main()
{
   int numero;

   cout << "Digite un numero entero positivo: ";
   cin >> numero;

   if (numero <= 0)
   {
      cout << "Debe digitar un numero mayor que cero" << endl;
      return 1;
   }

   for (int i = numero; i >= 1; i--)
   {
      for (int j = i; j >= 1; j--)
      {
         cout << j << " ";
      }
      cout << endl;
   }

   return 0;
}
