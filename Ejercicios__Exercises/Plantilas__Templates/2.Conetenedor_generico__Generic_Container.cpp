/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Ejercicio intermedio: Contenedor genérico simple
Crear una clase plantilla que represente un contenedor simple para un único elemento de cualquier tipo.
La clase debe tener métodos para establecer, obtener y mostrar el valor.

Intermediate exercise: Simple generic container
Create a template class that represents a simple container for a single element of any type.
The class should have methods to set, get and display the value.
*/

#include <iostream>
#include <string>

template <typename T>
class Contenedor {
private:
    T elemento;
public:
    void setElemento(const T& nuevo) {
        elemento = nuevo;
    }
    
    T getElemento() const {
        return elemento;
    }
    
    void mostrar() const {
        std::cout << "Contenedor guarda: " << elemento << std::endl;
    }
};

int main() {
    // Ejemplos de uso
    Contenedor<int> contInt;
    contInt.setElemento(42);
    contInt.mostrar();
    
    Contenedor<std::string> contStr;
    contStr.setElemento("Hola Mundo");
    contStr.mostrar();
    
    Contenedor<double> contDouble;
    contDouble.setElemento(3.14159);
    std::cout << "Valor obtenido: " << contDouble.getElemento() << std::endl;
    
    return 0;
}