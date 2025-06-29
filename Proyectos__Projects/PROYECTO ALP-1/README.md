# ALP-1 Project

## Overview

The **ALP-1** project is designed to process mathematical equations of the form $ ax^2 \pm bx \pm c $. This application allows users to enqueue equations for processing, classify them based on their roots, and subsequently store the results in different stacks. The project demonstrates fundamental concepts of data structures in C++, including queues and stacks, while implementing mathematical logic to solve quadratic equations.

## Descripción

El proyecto **ALP-1** está diseñado para procesar ecuaciones matemáticas de la forma $ ax^2 \pm bx \pm c $. Esta aplicación permite a los usuarios encolar ecuaciones para su procesamiento, clasificarlas según sus raíces y almacenar los resultados en diferentes pilas. El proyecto demuestra conceptos fundamentales de estructuras de datos en C++, incluyendo colas y pilas, mientras implementa lógica matemática para resolver ecuaciones cuadráticas.

## Features / Características

- **Queue Management:** Users can enqueue mathematical equations for further processing.
- **Root Classification:** Equations are classified based on the nature of their roots:
  - **Real Roots:** Stored in a stack for real roots.
  - **Imaginary Roots:** Stored in a stack for imaginary roots.
  - **Linear Roots:** Stored in a stack for linear equations.
- **Root Calculation:** Allows users to view the roots of each equation after processing.

- **Gestión de Colas:** Los usuarios pueden encolar ecuaciones matemáticas para su posterior procesamiento.
- **Clasificación de Raíces:** Las ecuaciones se clasifican según la naturaleza de sus raíces:
  - **Raíces Reales:** Almacenadas en una pila de raíces reales.
  - **Raíces Imaginarias:** Almacenadas en una pila de raíces imaginarias.
  - **Raíces Lineales:** Almacenadas en una pila de ecuaciones lineales.
- **Cálculo de Raíces:** Permite a los usuarios ver las raíces de cada ecuación después del procesamiento.

## Code Structure / Estructura del Código

### Main File / Archivo Principal

The main file manages the user interface and invokes several key functions for processing equations. It allows users to:

1. Add equations to the queue.
2. Process equations and classify them by their roots.
3. Display the roots of equations.

El archivo principal gestiona la interfaz de usuario e invoca varias funciones clave para procesar ecuaciones. Permite a los usuarios:

1. Agregar ecuaciones a la cola.
2. Procesar ecuaciones y clasificarlas por sus raíces.
3. Mostrar las raíces de las ecuaciones.

### Example of Code Functionality / Ejemplo de Funcionalidad del Código

The following functions are central to this project:

- Adds a mathematical equation to the processing queue.
- Analyzes each equation, determines the type of roots, and pushes the equation onto the appropriate stack.
- Displays the calculated roots for each equation processed.

Las siguientes funciones son fundamentales en este proyecto:

- Agrega una ecuación matemática a la cola de procesamiento.
- Analiza cada ecuación, determina el tipo de raíces y empuja la ecuación a la pila correspondiente.
  -Muestra las raíces calculadas para cada ecuación procesada.

## Getting Started / Cómo Comenzar

To run this project, ensure you have a C++ compiler installed. Clone the repository and compile the main file along with the necessary header files.

Para ejecutar este proyecto, asegúrate de tener un compilador de C++ instalado. Clona el repositorio y compila el archivo principal junto con los archivos de encabezado necesarios.

## Contact

For any questions or inquiries, feel free to reach out.

Para cualquier pregunta o consulta, ¡no dudes en ponerte en contacto!
