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

#include "letters.h"

map<char, vector<string>> asciiArt; // Nota el espacio entre > >

int main()
{

    initAsciiArt(asciiArt);

    string texto;
    cout << "Digite un texto: ";
    getline(cin, texto);

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

    return 0;
}
