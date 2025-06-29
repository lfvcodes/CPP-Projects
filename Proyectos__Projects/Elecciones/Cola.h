
#ifndef COLA_H_
#define COLA_H_

#include "Pila.h"
// Definición de las estructuras Voto y Votante

struct Votante {
   int cedula;
   std::string nombre;
   Pila* votos;
};

// Definición de las estructuras NodoVotante y NodoMesa
struct NodoVotante {
    Votante datos;
    NodoVotante* siguiente;
};

// Definición de la clase ColaVotantes
class ColaVotantes {
private:
    NodoVotante* frente;
    NodoVotante* final;

public:
    ColaVotantes() : frente(nullptr), final(nullptr) {}

    // Método para agregar un votante a la cola
    void agregarVotante(int cedula, const std::string& nombre) {
        NodoVotante* nuevo = new NodoVotante;
        nuevo->datos.cedula = cedula;
        nuevo->datos.nombre = nombre;
        nuevo->datos.votos = nullptr; // Inicializamos la pila de votos como vacía
        nuevo->siguiente = nullptr;

        if (frente == nullptr) {
            frente = nuevo;
        } else {
            final->siguiente = nuevo;
        }
        final = nuevo;
    }

    NodoVotante* getFrente(){
    	return this->frente;
    }

    NodoVotante* getFinal(){
    	return this->final;
    }

    void mostrarVotantesEnCola() {
	   NodoVotante* actual = frente;
	   while (actual != nullptr) {
		   std::cout << "Votante - Cedula: " << actual->datos.cedula << ", Nombre: " << actual->datos.nombre;
		   std::cout << " ESTATUS: " << actual->datos.votos->getFrente()->status << std::endl;

		   actual = actual->siguiente;
	   }
   }
};



#endif /* COLA_H_ */
