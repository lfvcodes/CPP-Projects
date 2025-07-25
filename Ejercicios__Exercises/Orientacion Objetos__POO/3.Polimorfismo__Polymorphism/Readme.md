# <a href="https://skillicons.dev"><img src="https://skillicons.dev/icons?i=cpp&perline=15" /></a> Polimorfismo / Polymorphism

---

## 🎯 ¿Qué es el Polimorfismo? / What is Polymorphism?

El **polimorfismo** (del griego "poli" - muchas, y "morfe" - formas) es uno de los pilares fundamentales de la Programación Orientada a Objetos (POO) en C++. Se refiere a la capacidad de un objeto de adoptar **múltiples formas**, permitiendo que diferentes clases respondan al mismo mensaje de maneras distintas.

En esencia, el polimorfismo nos permite tratar objetos de clases diferentes como si fueran del mismo tipo base, pero cada uno ejecutando su propio comportamiento específico. Esto promueve la flexibilidad, la extensibilidad y la mantenibilidad del código.

---

### Definición Formal / Formal Definition

El polimorfismo es la capacidad de un objeto de tomar múltiples formas, lo que permite que distintas clases respondan al mismo mensaje de diferentes maneras. Esta característica permite que objetos de diferentes clases sean tratados como si pertenecieran a una clase común y que cada uno exhiba su comportamiento específico.

_Polymorphism is the ability of an object to take on multiple forms, allowing different classes to respond to the same message in distinct ways. Objects from different classes can be treated as members of a common base class and display individualized behavior._

---

## 🚀 Tipos de Polimorfismo en C++ / Types of Polymorphism in C++

En C++, el polimorfismo se manifiesta principalmente de dos formas:

1.  **Polimorfismo en Tiempo de Compilación (Static Polymorphism):** Se resuelve durante la compilación del programa. Ejemplos incluyen la **sobrecarga de funciones** y la **sobrecarga de operadores**.
    - _Resolved during program compilation. Examples include **function overloading** and **operator overloading**._
2.  **Polimorfismo en Tiempo de Ejecución (Dynamic Polymorphism):** Se resuelve durante la ejecución del programa, utilizando punteros o referencias a la clase base. Las **funciones virtuales** y las **clases abstractas** son la clave aquí.
    - _Resolved during program execution, using base class pointers or references. **Virtual functions** and **abstract classes** are key here._

---

## ✨ Polimorfismo en Tiempo de Ejecución: Funciones Virtuales / Runtime Polymorphism: Virtual Functions

Las **funciones virtuales** son el corazón del polimorfismo en tiempo de ejecución en C++.

### ¿Cómo funcionan? / How do they work?

- La palabra clave `virtual` en una función dentro de una **clase base** le indica al compilador que esa función puede ser sobrescrita (reimplementada) por las clases derivadas.
  - _The `virtual` keyword in a function within a **base class** tells the compiler that this function can be overridden (reimplemented) by derived classes._
- Cuando se llama a una función virtual a través de un **puntero o una referencia de la clase base** que realmente apunta a un objeto de una clase derivada, C++ determina la implementación correcta de la función basándose en el **tipo real del objeto en tiempo de ejecución**, no en el tipo del puntero o referencia. Esto se conoce como **despacho dinámico** o **late binding**.
  - _When a virtual function is called through a **base class pointer or reference** that actually points to a derived class object, C++ determines the correct function implementation based on the **actual type of the object at runtime**, not the pointer or reference type. This is known as **dynamic dispatch** or **late binding**._

> 🔁 En tiempo de ejecución, C++ determina la implementación correcta de la función con base en el **tipo real del objeto al que apunta el puntero o referencia**, no en el tipo declarado del puntero o referencia. Esto es lo que permite el comportamiento polimórfico.
>
> _🔁 At runtime, C++ determines the correct function implementation based on the **actual type of the object pointed to by the pointer or reference**, not the declared type of the pointer or reference. This is what enables polymorphic behavior._

---

## 🔄 Polimorfismo en Tiempo de Compilación: Sobrecarga de Operadores / Compile-Time Polymorphism: Operator Overloading

La **sobrecarga de operadores** es una forma de polimorfismo que se resuelve en tiempo de compilación. Permite redefinir cómo los operadores (como `+`, `-`, `*`, `/`, etc.) actúan sobre objetos de tus propias clases.

- **Operator overloading** is a form of polymorphism resolved at compile-time. It allows you to redefine how operators (like `+`, `-`, `*`, `/`, etc.) behave when applied to objects of your own classes.\*

### ¿Cómo funciona? / How does it work?

El compilador decide qué versión del operador utilizar basándose en los **tipos de los operandos** en tiempo de compilación. No hay despacho dinámico involucrado.

_The compiler decides which version of the operator to use based on the **types of the operands** at compile-time. No dynamic dispatch is involved._

> 🧩 Este tipo de polimorfismo ocurre en **tiempo de compilación**. El compilador sabe exactamente qué función de operador debe llamar basándose en los tipos de los operandos.
>
> _🧩 This type of polymorphism occurs at **compile-time**. The compiler knows exactly which operator function to call based on the types of the operands._

---

## 🚫 Clases Abstractas y Funciones Virtuales Puras / Abstract Classes and Pure Virtual Functions

Las **clases abstractas** son la base para definir interfaces en el polimorfismo de tiempo de ejecución.

- **Abstract classes** are the foundation for defining interfaces in runtime polymorphism.\*

### Características / Characteristics

- Una clase se convierte en abstracta si contiene al menos una **función virtual pura**.
  - _A class becomes abstract if it contains at least one **pure virtual function**._
- Una función virtual pura se declara con `= 0;` al final de su firma en la clase base. Esto significa que la clase base **no proporciona una implementación** para esa función; en su lugar, **obliga a las clases derivadas a implementarla**.
  - _A pure virtual function is declared with `= 0;` at the end of its signature in the base class. This means the base class **does not provide an implementation** for that function; instead, it **forces derived classes to implement it**._
- **No se pueden crear instancias (objetos) de una clase abstracta directamente.** Solo pueden ser utilizadas como clases base para la herencia.
  - _You **cannot create instances (objects) of an abstract class directly**. They can only be used as base classes for inheritance._

> ❓ **¿Qué ocurre si intentas crear una instancia de una clase abstracta en C++?**
>
> \*❓ **What happens if you try to create an instance of an abstract class in C++?\***
>
> **Respuesta:** El compilador generará un **error de compilación**, impidiendo la creación del ejecutable. Las clases abstractas solo existen para servir como plantillas para otras clases, definiendo una interfaz común.
>
> - **Answer:** The compiler will generate a **compilation error**, preventing the executable from being created. Abstract classes only exist to serve as templates for other classes, defining a common interface.\*

---

## ✅ La Palabra Clave `override` en Funciones Virtuales / The `override` Keyword in Virtual Functions

La palabra clave `override` (introducida en C++11) es un especificador que se usa al sobrescribir una función virtual en una clase derivada.

_The `override` keyword (introduced in C++11) is a specifier used when overriding a virtual function in a derived class._

### Ventajas de usar `override` / Advantages of using `override`

- **Claridad:** Indica explícitamente que la función está sobrescribiendo una función virtual de la clase base.
  - - **Clarity:** It explicitly indicates that the function is overriding a virtual function from the base class.\*
- **Seguridad:** El compilador verifica que la función base realmente exista con la misma firma (nombre, tipo de retorno y parámetros). Si la firma no coincide, el compilador generará un error, ayudando a prevenir errores comunes como typos o cambios en la función base que no se reflejan en las derivadas.
  - - **Safety:** The compiler checks that the base function actually exists with the same signature (name, return type, and parameters). If the signature does not match, the compiler will generate an error, helping to prevent common mistakes like typos or changes in the base function not being reflected in derived ones.\*

> ✅ Sobrescribir (`override`) un método significa **implementar una versión específica** de una función virtual definida en la clase base. Esto permite que las clases derivadas personalicen su comportamiento, manteniendo el contrato definido por la clase base.
>
> _✅ Overriding (`override`) a method means **implementing a specific version** of a virtual function defined in the base class. This allows derived classes to customize their behavior while maintaining the contract defined by the base class._

---

## 💡 Ventajas del Polimorfismo / Benefits of Polymorphism

El polimorfismo es una herramienta muy poderosa en POO por varias razones:

_Polymorphism is a very powerful tool in OOP for several reasons:_

1.  **Flexibilidad y Extensibilidad:** Permite añadir nuevas clases derivadas sin tener que modificar el código existente que utiliza la clase base. Simplemente implementas la interfaz definida por la clase base.
    - - **Flexibility and Extensibility:** It allows you to add new derived classes without having to modify existing code that uses the base class. You simply implement the interface defined by the base class.\*
2.  **Mantenibilidad:** El código se vuelve más modular y fácil de mantener, ya que los cambios en la implementación de una clase derivada no afectan a las otras.
    - - **Maintainability:** The code becomes more modular and easier to maintain, as changes in one derived class's implementation do not affect others.\*
3.  **Abstracción:** Puedes interactuar con diferentes tipos de objetos a través de una **interfaz común** (la de la clase base), lo que simplifica el diseño y la comprensión del sistema.
    - - **Abstraction:** You can interact with different types of objects through a **common interface** (that of the base class), which simplifies system design and understanding.\*
4.  **Reutilización de Código:** Al definir comportamientos genéricos en la clase base, evitas duplicar código en las clases derivadas.
    - - **Code Reusability:** By defining generic behaviors in the base class, you avoid duplicating code in derived classes.\*

> La principal ventaja del polimorfismo es que mejora drásticamente la **flexibilidad, extensibilidad y mantenibilidad** del código. Puedes interactuar con distintos tipos de objetos a través de una **interfaz común**, lo que facilita agregar nuevas funcionalidades sin modificar el código existente.
>
> _The main advantage of polymorphism is that it drastically improves **code flexibility, extensibility, and maintainability**. You can interact with different types of objects through a **common interface**, making it easier to add new functionalities without modifying existing code._

---

## ⚠️ El Crucial Destructor Virtual / The Crucial Virtual Destructor

Cuando se trabaja con polimorfismo y memoria dinámica (usando `new` y `delete`), es **absolutamente fundamental** que las clases base tengan un **destructor virtual**.

_When working with polymorphism and dynamic memory (using `new` and `delete`), it is **absolutely fundamental** that base classes have a **virtual destructor**._

### ¿Por qué es importante? / Why is it important?

- Si eliminas un objeto de una clase derivada a través de un puntero a la clase base y el destructor de la clase base **no es virtual**, solo se llamará al destructor de la clase base. Los destructores de las clases derivadas no se ejecutarán.
  - _If you delete a derived class object through a base class pointer and the base class destructor is **not virtual**, only the base class destructor will be called. The destructors of the derived classes will not be executed._
- Esto puede llevar a **fugas de memoria** (memory leaks) si las clases derivadas asignan recursos que deben ser liberados en sus destructores, y a **comportamientos indefinidos**.
  - _This can lead to **memory leaks** if derived classes allocate resources that need to be released in their destructors, and to **undefined behavior**._

> 🎯 Siempre usa **destructores virtuales en clases base** si se espera que estas clases sean heredadas y que los objetos derivados sean eliminados a través de punteros de la clase base. ¡Esto te evitará muchos problemas de fugas de memoria y comportamientos inesperados\!
>
> _🎯 Always use **virtual destructors in base classes** if those classes are expected to be inherited and if derived objects will be deleted through base class pointers. This will save you from many memory leak issues and unexpected behaviors\!_

---
