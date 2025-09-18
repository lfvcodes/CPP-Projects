
/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Simula un sistema de punto de venta. Incluye gestión de inventario,
procesamiento de ventas con facturación detallada y control de existencias.
La interfaz basada en terminal muestra los productos en formato de caja, similar a los sistemas reales.

simulates a point-of-sale system. Includes inventory management, sales processing with detailed billing,
and stock control. The terminal-based interface displays products in box format similar to real POS systems.
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "struct.h"

using namespace std;

vector<Producto> inventario;

void dibujarLinea(int longitud, char caracter)
{
  for (int i = 0; i < longitud; i++)
  {
    cout << caracter;
  }
  cout << endl;
}

void mostrarEncabezado(const string &titulo)
{
  cout << endl;
  dibujarLinea(50, '=');
  cout << setw((50 + titulo.length()) / 2) << titulo << endl;
  dibujarLinea(50, '=');
  cout << endl;
}

void agregarProducto()
{
  mostrarEncabezado("AGREGAR PRODUCTO");

  Producto nuevo;
  cout << "Codigo: ";
  cin >> nuevo.codigo;
  cin.ignore();

  cout << "Nombre: ";
  getline(cin, nuevo.nombre);

  cout << "Precio: ";
  cin >> nuevo.precio;

  cout << "Stock: ";
  cin >> nuevo.stock;

  inventario.push_back(nuevo);
  cout << "\nProducto agregado exitosamente!" << endl;
}

void mostrarInventario()
{
  mostrarEncabezado("INVENTARIO DISPONIBLE");

  if (inventario.empty())
  {
    cout << "No hay productos en el inventario." << endl;
    return;
  }

  dibujarLinea(60, '-');
  cout << setw(6) << "COD"
       << setw(20) << "NOMBRE"
       << setw(15) << "PRECIO"
       << setw(10) << "STOCK" << endl;
  dibujarLinea(60, '-');

  for (size_t i = 0; i < inventario.size(); i++)
  {
    cout << setw(6) << inventario[i].codigo
         << setw(20) << inventario[i].nombre.substr(0, 17)
         << setw(15) << fixed << setprecision(2) << inventario[i].precio
         << setw(10) << inventario[i].stock << endl;
  }
  dibujarLinea(60, '-');
}

void realizarVenta()
{
  mostrarEncabezado("MODULO DE VENTAS");

  if (inventario.empty())
  {
    cout << "No hay productos disponibles para vender." << endl;
    return;
  }

  vector<Producto> carrito;
  vector<int> cantidades;
  double total = 0.0;
  char continuar = 's';

  while (continuar == 's' || continuar == 'S')
  {
    mostrarInventario();

    int codigo, cantidad;
    cout << "\nDigite codigo del producto: ";
    cin >> codigo;

    cout << "Digite cantidad: ";
    cin >> cantidad;

    bool encontrado = false;
    for (size_t i = 0; i < inventario.size(); i++)
    {
      if (inventario[i].codigo == codigo)
      {
        if (inventario[i].stock >= cantidad)
        {
          carrito.push_back(inventario[i]);
          cantidades.push_back(cantidad);
          total += inventario[i].precio * cantidad;
          inventario[i].stock -= cantidad;
          encontrado = true;
          cout << "Producto agregado al carrito." << endl;
        }
        else
        {
          cout << "Stock insuficiente." << endl;
        }
        break;
      }
    }

    if (!encontrado)
    {
      cout << "Producto no encontrado." << endl;
    }

    cout << "\nDesea agregar otro producto? (s/n): ";
    cin >> continuar;
  }

  mostrarEncabezado("FACTURA DE VENTA");

  dibujarLinea(70, '-');
  cout << setw(6) << "CANT"
       << setw(20) << "DESCRIPCION"
       << setw(15) << "PRECIO UNIT"
       << setw(15) << "SUBTOTAL" << endl;
  dibujarLinea(70, '-');

  for (size_t i = 0; i < carrito.size(); i++)
  {
    double subtotal = carrito[i].precio * cantidades[i];
    cout << setw(6) << cantidades[i]
         << setw(20) << carrito[i].nombre.substr(0, 17)
         << setw(15) << fixed << setprecision(2) << carrito[i].precio
         << setw(15) << subtotal << endl;
  }

  dibujarLinea(70, '-');
  cout << setw(46) << "TOTAL: $" << setw(15) << total << endl;
  dibujarLinea(70, '=');

  cout << "\nVenta realizada exitosamente!" << endl;
}

int main()
{

  Producto p1 = {1001, "Arroz 1kg", 2.50, 50};
  Producto p2 = {1002, "Azucar 1kg", 1.80, 40};
  Producto p3 = {1003, "Aceite 1L", 4.20, 30};
  Producto p4 = {1004, "Leche 1L", 1.50, 60};
  Producto p5 = {1005, "Pan integral", 0.80, 100};

  inventario.push_back(p1);
  inventario.push_back(p2);
  inventario.push_back(p3);
  inventario.push_back(p4);
  inventario.push_back(p5);

  int opcion;

  do
  {
    system("CLS");
    mostrarEncabezado("SISTEMA DE FACTURA");
    cout << "1. Mostrar Inventario" << endl;
    cout << "2. Agregar Producto" << endl;
    cout << "3. Realizar Venta" << endl;
    cout << "4. Salir" << endl;
    dibujarLinea(30, '-');
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    system("CLS");
    switch (opcion)
    {
    case 1:
      mostrarInventario();
      break;
    case 2:
      agregarProducto();
      break;
    case 3:
      realizarVenta();
      break;
    case 4:
      cout << "Saliendo del sistema..." << endl;
      break;
    default:
      cout << "Opcion no valida." << endl;
    }

    if (opcion != 4)
    {
      cout << "\nPresione Enter para continuar...";
      cin.ignore();
      cin.get();
    }

  } while (opcion != 4);

  return 0;
}
