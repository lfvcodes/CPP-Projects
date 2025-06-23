// Clase base Vehiculo
#include <iostream>
#include <string>;
using namespace std;

class Vehiculo
{
public:
   string marca;
   int anio;

   Vehiculo(string _marca, int _anio) : marca(_marca), anio(_anio) {}

   void mostrarInformacionVehiculo()
   {
      cout << "Marca: " << marca << endl;
      cout << "Anio: " << anio << endl;
   }
};
