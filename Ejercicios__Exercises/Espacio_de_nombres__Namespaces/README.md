## ¿Qué es un namespace? / What is a namespace?

Un **namespace** (espacio de nombres) en C++ es una forma de agrupar identificadores (funciones, variables, clases) bajo un nombre común para evitar conflictos y mejorar la organización del código.

A **namespace** in C++ is a way to group identifiers (functions, variables, classes) under a common name to avoid conflicts and improve code organization.

---

## ¿Por qué usar namespaces? / Why use namespaces?

- Evitan colisiones de nombres entre librerías o módulos.
- Permiten organizar el código por funcionalidad.
- Facilitan la reutilización y escalabilidad.

- They avoid name collisions between libraries or modules.
- They allow you to organize code by functionality.
- They facilitate reuse and scalability.

## Ejemplos / Examples

### Usando Variables / Using Vars

```cpp
#include <iostream>
namespace NS { int x = 5; }
int main() {
    using NS::x;
    std::cout << x;  // Output: 5
}
```

### Usando Funciones / Using Functions

```cpp
#include <iostream>

namespace A { void print() { std::cout << "A"; } }
namespace B { void print() { std::cout << "B"; } }

int main() {
    A::print();  // Output: A
    B::print();  // Output: B
}
```

### Directiva Using / Using Keyword

```cpp

#include <iostream>

namespace Greet {
    void hello() { std::cout << "Hello! "; }
    void bye() { std::cout << "Bye! "; }
}

int main() {
    using namespace Greet;  // Bring entire namespace
    hello();                // Output: Hello!
    bye();                  // Output: Bye!
}

```