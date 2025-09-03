/*
# Author: @lfvcodes
GitHub: https://github.com/lfvcodes/CPP-Projects

Crear un programa en C++ que permita simular un mazo de 52 cartas. El usuario podrá:

Barajar el mazo (mezclar aleatoriamente las cartas).
Sacar una carta del mazo (mostrarla y eliminarla de la pila).
Volver a barajar el mazo en cualquier momento.
El programa debe mostrar las cartas sacadas y permitir repetir acciones hasta que el mazo esté vacío.

Create a C++ program that simulates a 52-card deck. The user will be able to:

Shuffle the deck (randomly mix the cards).
Draw a card from the deck (reveal it and remove it from the stack).
Shuffle the deck again at any time.
The program must display the cards drawn and allow repeating actions until the deck is empty.

*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Mazo.h"

using namespace std;

int main()
{
  SetConsoleOutputCP(65001);
  Mazo mazo;
  int opcion;

  cout << "=== Simulador de Mazo de Naipes ===\n";
  mazo.barajar();

  do
  {
    cout << "\nOpciones:\n";
    cout << "1. Sacar carta\n";
    cout << "2. Barajar de nuevo\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      mazo.sacarCarta();
      break;
    case 2:
      mazo.barajar();
      break;
    case 3:
      cout << "Saliendo del programa...\n";
      break;
    default:
      cout << "Opcion invalida.\n";
    }

    if (mazo.estaVacio())
    {
      cout << "El mazo esta vacio. Reiniciando...\n";
      mazo.inicializar();
      mazo.barajar();
    }

  } while (opcion != 3);

  return 0;
}
