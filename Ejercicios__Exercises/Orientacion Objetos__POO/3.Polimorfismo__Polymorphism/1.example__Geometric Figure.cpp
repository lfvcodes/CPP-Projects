/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Enunciado del Ejercicio: Gestión de Figuras Geométricas con Polimorfismo
Este ejercicio demuestra el concepto de polimorfismo en C++ aplicando la herencia y funciones virtuales
para un sistema de cálculo de áreas y visualización de información de diferentes figuras geométricas.

Objetivo:
1.  Definir una clase base abstracta 'Figura' con una interfaz común para calcular el área y mostrar información.
2.  Implementar clases derivadas como 'Circulo' y 'Rectangulo', cada una con su propia lógica
    para calcular el área y mostrar su información específica.
3.  Utilizar punteros a la clase base para almacenar y procesar polimórficamente
    objetos de diferentes tipos de figuras en una única colección (un vector).
4.  Asegurar la correcta liberación de memoria mediante el uso de destructores virtuales.

----------------------------------------------------------------------------------------------------

Exercise Statement: Geometric Figure Management with Polymorphism
This exercise demonstrates the concept of polymorphism in C++ by applying inheritance and virtual functions
to a system for calculating areas and displaying information about different geometric figures.

Objective:
1.  Define an abstract base class 'Figura' with a common interface for calculating area and displaying information.
2.  Implement derived classes such as 'Circulo' (Circle) and 'Rectangulo' (Rectangle), each with its own logic
    to calculate the area and display its specific information.
3.  Use base class pointers to polymorphically store and process
    objects of different figure types in a single collection (a vector).
4.  Ensure proper memory deallocation through the use of virtual destructors.
*/

#include <iostream>
#include <vector> // Necesario para std::vector
#include <string> // Necesario para std::string, aunque no se usa explícitamente en este extracto, es buena práctica incluirlo si se usa string en general.
using namespace std;

// 1. Clase Base Abstracta: Figura
// Contiene un método virtual puro para calcular el área,
// lo que la convierte en una clase abstracta (no se pueden crear objetos de Figura directamente).
class Figura {
public:
    // Método virtual puro: obliga a las clases derivadas a implementarlo.
    virtual double calcularArea() const = 0;

    // Método virtual: puede ser sobrescrito por las clases derivadas.
    virtual void mostrarInformacion() const {
        cout << "Esta es una figura generica." << endl;
    }

    // Destructor virtual: ¡IMPORTANTE! Asegura que el destructor correcto de la clase derivada
    // sea llamado cuando se elimina un objeto a través de un puntero a la clase base.
    virtual ~Figura() {
        cout << "Destructor de Figura llamado." << endl;
    }
};

// 2. Clase Derivada: Circulo
class Circulo : public Figura {
private:
    double radio;

public:
    Circulo(double r) : radio(r) {
        cout << "Circulo creado con radio: " << radio << endl;
    }

    // Implementación obligatoria del método virtual puro
    double calcularArea() const override {
        return 3.14159 * radio * radio;
    }

    // Sobrescritura opcional del método virtual
    void mostrarInformacion() const override {
        cout << "Soy un Circulo con radio " << radio << endl;
    }

    ~Circulo() override {
        cout << "Destructor de Circulo llamado." << endl;
    }
};

// 3. Clase Derivada: Rectangulo
class Rectangulo : public Figura {
private:
    double ancho;
    double alto;

public:
    Rectangulo(double a, double al) : ancho(a), alto(al) {
        cout << "Rectangulo creado con ancho " << ancho << " y alto " << alto << endl;
    }

    double calcularArea() const override {
        return ancho * alto;
    }

    void mostrarInformacion() const override {
        cout << "Soy un Rectangulo con ancho " << ancho << " y alto " << alto << endl;
    }

    ~Rectangulo() override {
        cout << "Destructor de Rectangulo llamado." << endl;
    }
};

// 4. Función principal (main) para demostrar el polimorfismo
int main() {
    // Creamos un vector de punteros a la clase base Figura.
    // Esto es clave para el polimorfismo: podemos almacenar objetos de diferentes
    // clases derivadas bajo un tipo de puntero común (Figura*).
    vector<Figura*> misFiguras;

    // Agregamos objetos de las clases derivadas al vector
    misFiguras.push_back(new Circulo(5.0));
    misFiguras.push_back(new Rectangulo(4.0, 6.0));
    misFiguras.push_back(new Circulo(2.5));

    cout << "\n--- Procesando figuras polimorficamente ---" << endl;

    // Iteramos sobre el vector usando un for clásico y llamamos a los métodos.
    for (size_t i = 0; i < misFiguras.size(); ++i) {
        misFiguras[i]->mostrarInformacion();
        cout << "   Area: " << misFiguras[i]->calcularArea() << endl;
    }

    cout << "\n--- Liberando memoria ---" << endl;

    // Es crucial liberar la memoria asignada dinámicamente.
    // Gracias al destructor virtual, se llamará al destructor correcto de la clase derivada primero,
    // y luego al de la clase base, evitando fugas de memoria.
    for (size_t i = 0; i < misFiguras.size(); ++i) {
        delete misFiguras[i];
        misFiguras[i] = NULL; // Buena práctica: evita punteros colgantes
    }

    return 0;
}