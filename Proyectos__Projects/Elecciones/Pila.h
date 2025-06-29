#include <iostream>
#include <string>
using namespace std;

class Pila {
private:
    struct Nodo {
        string status;
        Nodo* siguiente;
    };

    Nodo* cima; // Puntero que apunta al elemento en la cima de la pila

public:
    // Constructor: inicializa la pila
    Pila() {
        cima = nullptr;
    }

    // Método para insertar un elemento en la pila (meter pila)
    void push(string valor) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->status = valor;
        nuevoNodo->siguiente = cima;
        cima = nuevoNodo;
    }

    void mostrarPila() {
	   cout << "Contenido de la pila: ";
	   Nodo* aux = cima;
	   while (aux != nullptr) {
		   cout << aux->status << " ";
		   aux = aux->siguiente;
	   }
	   cout << endl;
    }

    Nodo* getFrente(){
    	return this->cima;
    }

    // Método para quitar un elemento de la pila (sacar pila)
    void pop() {
        if (cima != nullptr) {
            Nodo* nodoAEliminar = cima;
            cima = cima->siguiente;
            delete nodoAEliminar;
        } else {
            cout << "La pila está vacía, no se puede eliminar ningún elemento." << endl;
        }
    }
};


