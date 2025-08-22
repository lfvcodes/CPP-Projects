/*
# Author: @lfvcodes
GitHub: https://github.com/lfvcodes/CPP-Projects

Crea un namespace Sistema que contenga otro namespace llamado Configuracion.
Dentro de Configuracion, define una función mostrarInfo() que imprima en pantalla el nombre del sistema y su versión.

Create a System namespace containing another namespace called Configuration.
Within Configuration, define a displayInfo() function that prints the system name and version to the screen.

*/

#include <iostream>

namespace Sistema
{
  namespace Configuracion
  {

    void mostrarInfo()
    {
      std::cout << "Nombre del sistema: velfsoftware" << std::endl;
      std::cout << "Version: 1.0.0" << std::endl;
      std::cout << "Estado: Operativo" << std::endl;
    }

  }
}

int main()
{
  Sistema::Configuracion::mostrarInfo();
  return 0;
}
