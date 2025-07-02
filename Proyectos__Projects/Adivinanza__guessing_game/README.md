# 🎮 Juego de Adivinanza en C++ / Number Guessing Game in C++

🔍 Un juego simple donde adivinas un número entre 1 y 100 / A simple game where you guess a number between 1 and 100

## 📚 Librerías utilizadas / Libraries used

- `<iostream>`: Para entrada/salida estándar / For standard input/output
- `<cstdlib>` y `<ctime>`: Para generación de números aleatorios / For random number generation
- `<limits>`: Para manejo seguro de los límites de tipos de datos y validación de entrada / For safe handling of data type limits and input validation

### 📖 Sobre `<limits>` / About `<limits>`

La librería `<limits>` proporciona información sobre las propiedades de los tipos fundamentales (como el valor máximo/mínimo que puede almacenar un tipo numérico). En este juego se usa junto con `cin.ignore()` para limpiar el buffer de entrada cuando el usuario ingresa datos no válidos.

The `<limits>` library provides information about the properties of fundamental types (like the maximum/minimum value a numeric type can store). In this game it's used with `cin.ignore()` to clear the input buffer when the user enters invalid data.

## 🚀 ¿Cómo funciona? / How does it work?

### Español

- El número secreto se genera aleatoriamente en cada ejecución
- El jugador introduce sus intentos desde la consola
- Se valida la entrada para asegurar que sea un número entero válido usando técnicas de `<limits>`
- El juego da retroalimentación ("más alto" o "más bajo") hasta acertar
- Finalmente, muestra cuántos intentos tomó adivinarlo

### English

- A secret number is randomly generated on each execution
- The player enters guesses through the console
- Input is validated to ensure it's a valid integer using `<limits>` techniques
- The game provides feedback ("higher" or "lower") until correct
- Finally, it shows how many attempts it took to guess

## 🛠️ Características / Features

- ✅ Validación de entrada robusta / Robust input validation
- ✅ Generación aleatoria segura / Secure random generation
- ✅ Interfaz sencilla / Simple interface
- ✅ Contador de intentos / Attempt counter

## 📋 Requisitos / Requirements

- Compilador C++ con soporte para C++11 / C++ compiler with C++11 support
- Sistema Windows/Linux/macOS / Windows/Linux/macOS system

## ▶️ Cómo ejecutar / How to run

```bash
g++ -std=c++11 adivinanza.cpp -o juego
./juego
```
