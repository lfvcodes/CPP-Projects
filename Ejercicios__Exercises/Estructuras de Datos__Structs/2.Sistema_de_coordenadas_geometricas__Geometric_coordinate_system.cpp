/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Usa estructuras Punto y Rectangulo para calcular el área de un rectángulo definido por dos puntos.

Use Point and Rectangle structures to calculate the area of ​​a rectangle defined by two points.
*/

#include <iostream>
using namespace std;

struct Punto
{
   float x, y;
};

struct Rectangulo
{
   Punto superiorIzq;
   Punto inferiorDer;
};

float calcularArea(const Rectangulo &rect)
{
   float base = rect.inferiorDer.x - rect.superiorIzq.x;
   float altura = rect.superiorIzq.y - rect.inferiorDer.y;
   return base * altura;
}

int main()
{
   Rectangulo rect;
   cout << "Digite coordenadas (x y) de la esquina superior izquierda: ";
   cin >> rect.superiorIzq.x >> rect.superiorIzq.y;
   cout << "Digite coordenadas (x y) de la esquina inferior derecha: ";
   cin >> rect.inferiorDer.x >> rect.inferiorDer.y;

   cout << "Area del rectangulo: " << calcularArea(rect) << endl;
   return 0;
}