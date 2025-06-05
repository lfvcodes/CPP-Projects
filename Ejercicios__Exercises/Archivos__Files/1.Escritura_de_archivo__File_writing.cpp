/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Realice un programa que pida al usuario el nombre de un fichero
de texto y, a continuación permita almacenar al usuario tantas frases como el
usuario desee.

Create a program that asks the user for the name of a text file and
then allows the user to store as many phrases as they want.
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void escribirFrases();

int main()
{
   escribirFrases();

   system("pause");
   return 0;
}

void escribirFrases()
{
   ofstream archivo;
   string nombreArchivo, frase;
   char rpt;

   cout << "Digite el nombre del archivo: ";
   getline(cin, nombreArchivo);

   archivo.open(nombreArchivo.c_str(), ios::out); // Creamos el archivo

   if (archivo.fail())
   { // Si a ocurrido algun error
      cout << "No se pudo abrir el archivo";
      exit(1);
   }

   do
   {
      fflush(stdin);
      cout << "Digite una frase: ";
      getline(cin, frase);
      archivo << frase << endl;

      cout << "\nDesea agregar otra frase(S/N): ";
      cin >> rpt;
   } while ((rpt == 'S') || (rpt == 's'));

   archivo.close(); // Cerramos el archivo
}