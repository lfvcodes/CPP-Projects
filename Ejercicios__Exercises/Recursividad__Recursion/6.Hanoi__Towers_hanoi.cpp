/* 
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Torres de Hanoi Escribe una función recursiva que resuelva el problema
 de las torres de Hanoi para N discos. Luego, desarrolla un programa principal
  que solicite el número de discos al usuario y muestre los pasos necesarios para resolverlo.

Towers of Hanoi Write a recursive function that solves the Tower of Hanoi problem for N disks. 
Then, develop a main program that prompts the user for the number of disks and displays the necessary steps to solve it.
*/

#include <iostream>

using namespace std;

// Funcion recursiva para resolver el problema de las Torres de Hanoi
void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        cout << "Mover disco 1 de " << origen << " a " << destino << endl;
        return;
    }
    hanoi(n - 1, origen, auxiliar, destino);
    cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;
    hanoi(n - 1, auxiliar, destino, origen);
}

int main() {
    int numDiscos;

    // Solicitar numero de discos al usuario
    cout << "Digite el numero de discos: ";
    cin >> numDiscos;

    // Resolver y mostrar pasos
    hanoi(numDiscos, 'A', 'C', 'B');

    return 0;
}
