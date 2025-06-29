/*
 * Lista.h
 *
 *  Created on: 19 mar. 2024
 *      Author: koala
 */

#ifndef LISTA_H_
#define LISTA_H_
using namespace std;
struct NodoMesa {
    ColaVotantes votantes;
    NodoMesa* siguiente;
};


// Definición de la clase ListaMesas
class ListaMesas {
private:
    NodoMesa* inicio;

public:
    ListaMesas() : inicio(nullptr) {}

    void agregarMesa() {
		NodoMesa* nuevaMesa = new NodoMesa;
		nuevaMesa->siguiente = inicio;
		inicio = nuevaMesa;
	}

    void mostrarMesasRegistradas() {
        NodoMesa* actual = inicio;
        int numMesa = 1;
        while (actual != nullptr) {
            cout << "Mesa " << numMesa << endl;
            actual->votantes.mostrarVotantesEnCola(); // Aquí se muestra la cola de votantes
            actual = actual->siguiente;
            numMesa++;
        }
    }

    NodoMesa* obtenerMesa(int numeroMesa) {
	   NodoMesa* actual = inicio;
	   int i = 1;
	   while (actual != nullptr) {
		   // Verifica si el número de la mesa coincide
		   if (numeroMesa == i) {
			   return actual;
		   }
		   actual = actual->siguiente;
		   i++;
	   }
	   return nullptr; // Devuelve nullptr si la mesa no se encuentra
   }

};



#endif /* LISTA_H_ */
