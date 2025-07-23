/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects


Crea una función que reciba un número entero y retorne
el mismo número con los dígitos invertidos. Por ejemplo: 356 se convierte en 653.

Create a function that receives an integer and returns the number with its digits
reversed. For example: 356 becomes 653.
*/

#include <iostream>

// Funcion para invertir los digitos de un numero entero
int invertirNumero(int num) {
    int numeroInvertido = 0;
    while (num > 0) {
        int digito = num % 10; // Obtenemos el ultimo digito
        numeroInvertido = numeroInvertido * 10 + digito; // Anadimos el digito al numero invertido
        num /= 10; // Eliminamos el ultimo digito del numero original
    }
    return numeroInvertido;
}

int main() {
    using namespace std; // Usamos namespace std para cout y cin

    int numeroOriginal;

    cout << "Ingresa un numero entero para invertirlo: ";
    cin >> numeroOriginal;

    int numeroInvertido = invertirNumero(numeroOriginal);

    cout << "El numero original es: " << numeroOriginal << endl;
    cout << "El numero invertido es: " << numeroInvertido << endl;

    return 0;
}