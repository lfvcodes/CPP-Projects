/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Crea un inventario de productos usando un arreglo estático (máximo 100 productos). Implementa:
-Añadir productos.
-Buscar por id.
-Calcular el valor total del inventario.

Create a product inventory using a static array (maximum 100 products). Implements:

-Add products.
-Search by ID.
-Calculate the total inventory value.
*/

#include <iostream>
#include <string>
using namespace std;

struct Producto
{
   int id;
   string nombre;
   float precio;
   int stock;
};

void agregarProducto(Producto inventario[], int &n)
{
   if (n >= 100)
   {
      cout << "Inventario lleno (máx 100 productos).\n";
      return;
   }
   cout << "ID: ";
   cin >> inventario[n].id;
   cout << "Nombre: ";
   cin >> inventario[n].nombre;
   cout << "Precio: ";
   cin >> inventario[n].precio;
   cout << "Stock: ";
   cin >> inventario[n].stock;
   n++;
}

void buscarProducto(const Producto inventario[], int n, int id)
{
   for (int i = 0; i < n; ++i)
   {
      if (inventario[i].id == id)
      {
         cout << "Producto encontrado:\n";
         cout << "Nombre: " << inventario[i].nombre << "\nPrecio: " << inventario[i].precio
              << "\nStock: " << inventario[i].stock << endl;
         return;
      }
   }
   cout << "Producto no encontrado.\n";
}

float valorTotalInventario(const Producto inventario[], int n)
{
   float total = 0;
   for (int i = 0; i < n; ++i)
   {
      total += inventario[i].precio * inventario[i].stock;
   }
   return total;
}

int main()
{
   Producto inventario[100];
   int n = 0; // Numero actual de productos
   int opcion, id;

   do
   {
      cout << "\n1. Agregar producto\n2. Buscar producto\n3. Valor total\n0. Salir\nOpcion: ";
      cin >> opcion;

      switch (opcion)
      {
      case 1:
         agregarProducto(inventario, n);
         break;
      case 2:
         cout << "ID a buscar: ";
         cin >> id;
         buscarProducto(inventario, n, id);
         break;
      case 3:
         cout << "Valor total del inventario: $" << valorTotalInventario(inventario, n) << endl;
         break;
      }
   } while (opcion != 0);

   return 0;
}