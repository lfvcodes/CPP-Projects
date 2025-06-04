/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Crea un programa en C++ que simule un cajero automático básico. El programa debe ofrecer las siguientes opciones:

Retirar: Permitir al usuario retirar dinero, verificando saldo suficiente y cantidad válida.
Consultar Saldo: Mostrar un mensaje indicando la seguridad de la información.
Salir: Finalizar el programa.
El programa debe manejar opciones no válidas y considerar un saldo inicial de $50,000.

Instrucciones:

Implementa el programa utilizando estructuras condicionales en C++.

Create a C++ program that simulates a basic ATM. The program should offer the following options:

Withdraw: Allow the user to withdraw money, verifying a sufficient balance and a valid amount.
Check Balance: Display a message indicating the security of the information.
Exit: End the program.
The program should handle invalid options and consider an initial balance of $50,000.

Instructions:

Implement the program using conditional structures in C++.*/

#include <iostream>
using namespace std;

int main()
{
   float saldo = 50000;
   float saldoNuevo = 0;
   int opcion = 0;
   float cantidad = 0;

   cout << "Bienvenido, desea realizar una operacion?" << endl;
   cout << "1. Retirar " << endl;
   cout << "2. Consultar Saldo" << endl;
   cout << "3. Salir " << endl;
   cout << "opcion: ";
   cin >> opcion;
   cout << endl;

   switch (opcion)
   {
   case 1:
      cout << "Digite la cantidad a retirar: ";
      cin >> cantidad;
      if (cantidad > 0 && cantidad <= saldo)
      {
         saldoNuevo = saldo - cantidad;
         cout << "Retiro Realizado su saldo actual es: " << saldoNuevo << endl;
      }
      else if (cantidad > saldo)
      {
         cout << "Codigo 51, Fondo Insuficiente" << endl;
      }
      else
      {
         cout << "Error al realizar Retiro" << endl;
      }
      break;
   case 2:
      cout << "Su informacion financiera esta segura en el universo cuantico";
      break;
   case 3:
      cout << "Adios, lo esperamos pronto" << endl;
      break;
   default:
      cout << "Estimado Usuario la opcion digitada no existe" << endl;
      break;
   }
   return 0;
}