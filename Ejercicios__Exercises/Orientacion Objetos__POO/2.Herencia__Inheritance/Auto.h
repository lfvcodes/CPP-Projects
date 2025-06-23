// Clase derivada Auto que hereda de Vehiculo
class Auto : public Vehiculo
{
public:
   int numeroPuertas;

   Auto(string _marca, int _anio, int _numeroPuertas) : Vehiculo(_marca, _anio), numeroPuertas(_numeroPuertas) {}

   void mostrarInformacionAuto()
   {
      mostrarInformacionVehiculo(); // Llama al metodo de la clase base
      cout << "Numero de Puertas: " << numeroPuertas << endl;
   }
};
