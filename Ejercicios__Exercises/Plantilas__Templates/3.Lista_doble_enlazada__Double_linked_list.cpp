/*
 #author: @lfvcodes
 https://github.com/lfvcodes/CPP-Projects

Implementa una clase plantilla `ListaEnlazadaDoble` para crear una lista enlazada
doble que pueda almacenar elementos de cualquier tipo `T`. Cada nodo debe
tener punteros al nodo siguiente y al anterior.

La clase debe incluir las siguientes funcionalidades:
- Una estructura anidada `Nodo`.
- Constructor y destructor para manejar la memoria.
- Métodos para agregar elementos al inicio y al final de la lista.
- Un método para eliminar la primera ocurrencia de un valor dado.
- Un método para vaciar todos los nodos de la lista.
- Métodos para imprimir la lista hacia adelante y hacia atrás.
- Un método para verificar si la lista está vacía.

Implement a template class `ListaEnlazadaDoble` to create a doubly linked list
that can store elements of any type `T`. Each node should have pointers
to the next and previous nodes.

The class should include the following functionalities:
- A nested `Nodo` struct.
- Constructor and destructor to handle memory.
- Methods to add elements to the start and end of the list.
- A method to remove the first occurrence of a given value.
- A method to clear all nodes from the list.
- Methods to print the list forwards and backwards.
- A method to check if the list is empty.
*/

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class ListaEnlazadaDoble {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo* anterior;

        Nodo(const T& valor) : dato(valor), siguiente(NULL), anterior(NULL) {}
    };

    Nodo* primer;
    Nodo* ultimo;

public:
    ListaEnlazadaDoble() : primer(NULL), ultimo(NULL) {}

    ~ListaEnlazadaDoble() {
        vaciar();
    }

    bool estaVacia() const {
        return primer == NULL;
    }

    void agregarAlFinal(const T& valor) {
        Nodo* nuevo_nodo = new Nodo(valor);
        if (estaVacia()) {
            primer = ultimo = nuevo_nodo;
        } else {
            ultimo->siguiente = nuevo_nodo;
            nuevo_nodo->anterior = ultimo;
            ultimo = nuevo_nodo;
        }
    }

    void agregarAlInicio(const T& valor) {
        Nodo* nuevo_nodo = new Nodo(valor);
        if (estaVacia()) {
            primer = ultimo = nuevo_nodo;
        } else {
            primer->anterior = nuevo_nodo;
            nuevo_nodo->siguiente = primer;
            primer = nuevo_nodo;
        }
    }

    void eliminar(const T& valor) {
        Nodo* actual = primer;
        while (actual != NULL && actual->dato != valor) {
            actual = actual->siguiente;
        }

        if (actual == NULL) {
            return; // Valor no encontrado
        }

        if (actual->anterior != NULL) {
            actual->anterior->siguiente = actual->siguiente;
        } else {
            primer = actual->siguiente; // Era el primer nodo
        }

        if (actual->siguiente != NULL) {
            actual->siguiente->anterior = actual->anterior;
        } else {
            ultimo = actual->anterior; // Era el último nodo
        }

        delete actual;
    }

    void vaciar() {
        Nodo* actual = primer;
        while (actual != NULL) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
        primer = ultimo = NULL;
    }

    void imprimirHaciaAdelante() const {
        if (estaVacia()) {
            cout << "La lista esta vacia." << endl;
            return;
        }
        Nodo* actual = primer;
        cout << "Lista (adelante): ";
        while (actual != NULL) {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
    }

    void imprimirHaciaAtras() const {
        if (estaVacia()) {
            cout << "La lista esta vacia." << endl;
            return;
        }
        Nodo* actual = ultimo;
        cout << "Lista (atras): ";
        while (actual != NULL) {
            cout << actual->dato << " -> ";
            actual = actual->anterior;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    ListaEnlazadaDoble<int> lista_int;
    lista_int.agregarAlFinal(10);
    lista_int.agregarAlFinal(20);
    lista_int.agregarAlInicio(5);
    lista_int.agregarAlFinal(30);

    lista_int.imprimirHaciaAdelante(); // Salida: Lista (adelante): 5 -> 10 -> 20 -> 30 -> NULL
    lista_int.imprimirHaciaAtras();   // Salida: Lista (atras): 30 -> 20 -> 10 -> 5 -> NULL

    cout << "Eliminando el 20..." << endl;
    lista_int.eliminar(20);
    lista_int.imprimirHaciaAdelante(); // Salida: Lista (adelante): 5 -> 10 -> 30 -> NULL

    cout << "Eliminando el 5..." << endl;
    lista_int.eliminar(5);
    lista_int.imprimirHaciaAdelante(); // Salida: Lista (adelante): 10 -> 30 -> NULL

    ListaEnlazadaDoble<string> lista_string;
    lista_string.agregarAlFinal("Hola");
    lista_string.agregarAlFinal("Mundo");
    lista_string.imprimirHaciaAdelante(); // Salida: Lista (adelante): Hola -> Mundo -> NULL

    return 0;
}