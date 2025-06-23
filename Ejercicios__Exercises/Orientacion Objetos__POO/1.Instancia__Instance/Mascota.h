#include <iostream>
#include <string>
using namespace std;

class Mascota
{
private:
   string nombre;
   string tipo;
   int edad;

public:
   // Constructor
   Mascota(string n, string t, int e)
   {
      nombre = n;
      tipo = t;
      edad = e;
   }

   // Metodo para mostrar informacion
   void mostrarInformacion()
   {
      cout << "Nombre: " << nombre << endl;
      cout << "Tipo: " << tipo << endl;
      cout << "Edad: " << edad << " anios" << endl;
   }

   // Metodo para hacer que la mascota emita un sonido
   void hacerSonido()
   {
      if (tipo == "perro")
      {
         cout << nombre << " dice: Guau!" << endl;
      }
      else if (tipo == "gato")
      {
         cout << nombre << " dice: Miau!" << endl;
      }
      else
      {
         cout << nombre << " hace un sonido desconocido." << endl;
      }
   }
};
