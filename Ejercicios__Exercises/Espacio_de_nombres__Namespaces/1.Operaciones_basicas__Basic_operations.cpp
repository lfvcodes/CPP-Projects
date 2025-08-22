/*
# Author: @lfvcodes
GitHub: https://github.com/lfvcodes/CPP-Projects


Crea un namespace llamado MathOps que contenga funciones para sumar, restar, multiplicar y dividir dos números enteros.
Luego, en la función main, utiliza estas funciones para operar con los valores a = 12 y b = 4

Create a namespace called MathOps that contains functions for adding, subtracting, multiplying, and dividing two integers.
Then, in the main function, use these functions to operate on the values a = 12 and b = 4.
*/

#include <iostream>

namespace MathOps
{
  int sumar(int a, int b)
  {
    return a + b;
  }

  int restar(int a, int b)
  {
    return a - b;
  }

  int multiplicar(int a, int b)
  {
    return a * b;
  }

  int dividir(int a, int b)
  {
    if (b == 0)
    {
      std::cout << "Error: division por cero." << std::endl;
      return 0;
    }
    return a / b;
  }
}

int main()
{
  int a = 12;
  int b = 4;

  std::cout << "Operaciones con a = " << a << " y b = " << b << std::endl;
  std::cout << "Suma: " << MathOps::sumar(a, b) << std::endl;
  std::cout << "Resta: " << MathOps::restar(a, b) << std::endl;
  std::cout << "Multiplicacion: " << MathOps::multiplicar(a, b) << std::endl;
  std::cout << "Division: " << MathOps::dividir(a, b) << std::endl;

  return 0;
}
