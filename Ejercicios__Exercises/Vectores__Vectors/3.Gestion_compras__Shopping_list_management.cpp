/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Crea un programa para gestionar una lista de compras del supermercado.
El programa debe permitir agregar productos, mostrar la lista completa
y calcular el costo total basado en los precios de cada producto.

Create a program to manage a supermarket shopping list.
The program should allow you to add products, display the complete list,
and calculate the total cost based on the prices of each product.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> productos;
    vector<double> precios;
    int opcion;

    do {
    	system("CLS");
        cout << "\n1. Agregar producto\n2. Mostrar lista\n3. Calcular total\n4. Salir\nOpcion: ";
        cin >> opcion;

        if(opcion == 1) {
            string producto;
            double precio;
            cout << "Nombre del producto: ";
            cin.ignore();
            getline(cin, producto);
            cout << "Precio: ";
            cin >> precio;
            productos.push_back(producto);
            precios.push_back(precio);
            system("PAUSE");
        }
        else if(opcion == 2) {
            cout << "\nLista de compras:\n";
            for(int i = 0; i < productos.size(); i++) {
                cout << productos[i] << " - $" << precios[i] << endl;
            }
            system("PAUSE");
        }
        else if(opcion == 3) {
            double total = 0;
            for(int i = 0; i < precios.size(); i++) {
                total += precios[i];
            }
            cout << "Total a pagar: $" << total << endl;
            system("PAUSE");
        }
    } while(opcion != 4);

    return 0;
}