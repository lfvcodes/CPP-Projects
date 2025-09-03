#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Mazo
{
private:
  vector<string> cartas;

public:
  Mazo()
  {
    inicializar();
  }

  void inicializar()
  {
    cartas.clear();
    string palos[] = {"♠", "♥", "♦", "♣"};
    // string palos[] = {"Espadas", "Corazones", "Diamantes", "Tréboles"};
    string valores[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 13; j++)
      {
        cartas.push_back(valores[j] + palos[i]);
      }
    }
  }

  void barajar()
  {
    srand(time(0));
    for (int i = 0; i < cartas.size(); i++)
    {
      int j = rand() % cartas.size();
      string temp = cartas[i];
      cartas[i] = cartas[j];
      cartas[j] = temp;
    }
    cout << "Mazo barajado.\n";
  }

  void sacarCarta()
  {
    if (cartas.empty())
    {
      cout << "No quedan cartas en el mazo.\n";
      return;
    }
    string carta = cartas.back();
    cartas.pop_back();
    cout << "Carta sacada: " << carta << "\n";
  }

  bool estaVacio()
  {
    return cartas.empty();
  }
};