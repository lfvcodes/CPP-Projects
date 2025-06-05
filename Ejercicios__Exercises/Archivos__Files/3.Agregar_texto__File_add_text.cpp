/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

 Realice un programa que pida al usuario el nombre o ubicacion
de un fichero de texto y, a continuación añada texto en el hasta que el
usuario lo decida.

Create a program that prompts the user for the name or location of a text file and then adds text
 to it until the user decides what to do.
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

void agregarTexto();

int main()
{
   agregarTexto();

   system("pause");
   return 0;
}

void agregarTexto()
{
   ofstream archivo;
   string nombreArchivo, texto;
   char rpt;

   cout << "Digite el nombre o ubicacion del archivo: ";
   getline(cin, nombreArchivo);

   archivo.open(nombreArchivo.c_str(), ios::app); // Abrimos el archivo en modo añadir

   if (archivo.fail())
   {
      cout << "No se pudo abrir el archivo";
      exit(1);
   }

   do
   {
      fflush(stdin);
      cout << "Digite una frase: ";
      getline(cin, texto);
      archivo << texto << endl;

      cout << "Desea agregar otra frase? (s/n): ";
      cin >> rpt;
   } while ((rpt == 'S') || (rpt == 's'));

   archivo.close();
}