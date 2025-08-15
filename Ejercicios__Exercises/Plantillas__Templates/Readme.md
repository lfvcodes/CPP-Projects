# 🧠 Introducción a PLantillas o Templates en C++ / Introduction to Templates in C++

Los templates en C++ permiten escribir funciones y clases genéricas que funcionan con cualquier tipo de dato. Son una herramienta poderosa para evitar la duplicación de código y mejorar la reutilización.

C++ templates allow you to write generic functions and classes that work with any data type. They are a powerful tool for avoiding code duplication and improving reusability.

---

## 📌 ¿Qué es un Template o Plantilla? / What is a Template?

Un *template* es una especie de molde que permite definir funciones o clases sin especificar el tipo de dato exacto. El tipo se determina cuando se usa el template.

A template is a type of template that allows you to define functions or classes without specifying the exact data type. The type is determined when the template is used.

---

## 🔧 Ejemplo de Template de Función / Function Template Example

```cpp
#include <iostream>
using namespace std;

// Declaración del template de función
template <typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int a = 5, b = 10;
    double c = 3.5, d = 7.2;
    
    cout << "Máximo entre " << a << " y " << b << ": " << maximo(a, b) << endl;
    cout << "Máximo entre " << c << " y " << d <<  ": " << maximo(c, d) << endl;
    
    return 0;
}

```
---

## 🔧 Ejemplo de Template de Clase / Class Template Example

``` cpp
#include <iostream>
using namespace std;

// Declaración del template de clase
template <typename T>
class Lista {
private:
    T* elementos;
    int tamano;
public:
    Lista(int n) {
        tamano = n;
        elementos = new T[tamano];
    }
    
    void agregar(T elemento) {
        if (tamano > 0) {
            elementos[--tamano] = elemento;
        }
        else {
            cout << "La lista está vacía." << endl;
        }
    }
    
    void mostrar() {
        if (tamano <= 0) {
            cout << "La lista está vacía." << endl;
        }
        else {
            cout << "Elementos de la lista: ";
            for (int i = 0; i < tamano; i++) {
                cout << elementos[i] << " ";
            }
            cout << endl;
        }
    }
};  


```


## 🧩 Ventajas de Usar Templates / Advantages of Using Templates
<ul>
<li>Evitan duplicar código para distintos tipos. / They avoid duplicating code for different types. </li>

<li>Mejoran la legibilidad y mantenimiento. / Improve readability and maintenance.</li>
</ul>

## ⚠️ Consideraciones / Considerations
<ul>
<li>Los templates se expanden en tiempo de compilación. / Templates are expanded at compile time</li>

<li>El código generado puede aumentar si se usan muchos tipos distintos. / The generated code can grow if many different types are used.</li>

<li>Los errores pueden ser más difíciles de entender si no se usan correctamente. / Errors can be more difficult to understand if not used correctly.</li>