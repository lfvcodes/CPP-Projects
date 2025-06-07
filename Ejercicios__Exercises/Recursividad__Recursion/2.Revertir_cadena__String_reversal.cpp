/* 
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Inversión de una cadena de caracteres Escribe una función recursiva que 
invierta una cadena de caracteres dada. 
Luego, desarrolla un programa principal que solicite una cadena al usuario y muestre
el resultado.

String Reversal Write a recursive function that reverses a given string.
Then, develop a main program that prompts the user for a string and
displays the result. 
*/

#include <iostream>

using namespace std;

// Funcion recursiva para invertir una cadena
void invertirCadena(string &cadena, int i, int j) {
    if (i >= j)
        return;
    swap(cadena[i], cadena[j]);
    invertirCadena(cadena, i + 1, j - 1);
}

int main() {
    string texto;

    // Solicitar cadena al usuario
    cout << "Digite una cadena de texto: ";
    cin >> texto;

    // Invertir la cadena y mostrar el resultado
    invertirCadena(texto, 0, texto.length() - 1);
    cout << "La cadena invertida es: " << texto << endl;

    return 0;
}
