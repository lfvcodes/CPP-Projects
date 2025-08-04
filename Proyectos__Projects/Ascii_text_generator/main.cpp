/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype> // Para toupper()

using namespace std;

#include "digits.h"

map<char, vector<string> > asciiArt;

bool esValido(char c);

int main()
{   
    initAsciiArt(asciiArt);
    int op = -1;
    do{
        system("CLS");

        string texto = "";
        cout << "Digite un texto: ";

        getline(cin, texto);

        bool textoValido = true;
        for (size_t i = 0; i < texto.length(); ++i) {
            char c = texto[i];
            if (!esValido(c)) {
                textoValido = false;
                break;
            }
        }
        
        if (!textoValido) {
            cout << "\nERROR: El texto contiene caracteres no permitidos. ";
            cout << "Solo se aceptan letras, numeros y espacios.\n\n";
            system("pause");
            continue;  // Volver al inicio del bucle
        }
		
        // Imprimir cada linea del arte ASCII
        for (int i = 0; i < 5; ++i)
        { // Cada letra tiene 5 lineas de altura
            for (size_t j = 0; j < texto.length(); ++j)
            { // Usamos indice en lugar de range-based for
                char c = texto[j];
                char upperC = toupper(c);
                if (asciiArt.find(upperC) != asciiArt.end())
                {
                    // Para letras minusculas que tienen diferente disenio
                    if (islower(c))
                    {
                        if (asciiArt.find(c) != asciiArt.end() && i < asciiArt[c].size())
                        {
                            cout << asciiArt[c][i] << " ";
                        }
                        else
                        {
                            cout << string(6, ' ') << " ";
                        }
                    }
                    else
                    {
                        if (i < asciiArt[upperC].size())
                        {
                            cout << asciiArt[upperC][i] << " ";
                        }
                        else
                        {
                            cout << string(6, ' ') << " ";
                        }
                    }
                }
                else
                {
                    // Si el caracter no esta definido, imprimir espacios
                    cout << string(6, ' ') << " ";
                }
            }
            cout << endl;
        }

        cout << endl <<"Desea Generar otro texto? (1.SI / 0.NO)"<<endl;
        cin >> op;
         cin.ignore(100, '\n');
    }while(op != 0);

    return 0;
}

// Función para verificar si un carácter es válido (letra, número o espacio)
bool esValido(char c) {
    return isalnum(c) || c == ' ';  // isalnum verifica si es letra o número
}
