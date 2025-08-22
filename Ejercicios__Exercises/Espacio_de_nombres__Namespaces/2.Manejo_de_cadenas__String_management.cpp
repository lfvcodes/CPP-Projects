/*
# Author: @lfvcodes
GitHub: https://github.com/lfvcodes/CPP-Projects

Define un namespace llamado StringUtils que contenga funciones para convertir una cadena a
mayúsculas y contar cuántas vocales tiene. Usa funciones de la librería <cctype> para manipular caracteres.

Define a namespace called StringUtils that contains functions for converting a
string to uppercase and counting its vowels. Use functions from the <cctype> library to manipulate characters.

*/

#include <iostream>
#include <string>
#include <cctype>

namespace StringUtils
{

  std::string toUpper(const std::string &input)
  {
    std::string resultado = input;
    for (std::size_t i = 0; i < resultado.length(); ++i)
    {
      resultado[i] = std::toupper(resultado[i]);
    }
    return resultado;
  }

  int contarVocales(const std::string &input)
  {
    int contador = 0;
    for (std::size_t i = 0; i < input.length(); ++i)
    {
      char c = std::tolower(input[i]);
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      {
        ++contador;
      }
    }
    return contador;
  }

}

int main()
{
  std::string texto = "Hola Mundo";

  std::cout << "Texto original: " << texto << std::endl;
  std::cout << "Mayúsculas: " << StringUtils::toUpper(texto) << std::endl;
  std::cout << "Cantidad de vocales: " << StringUtils::contarVocales(texto) << std::endl;

  return 0;
}
