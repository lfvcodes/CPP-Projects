# Elections Project / Proyecto de Elecciones

## Overview / Descripción

The **Elections Project** was developed as part of the academic curriculum at the Universidad Centro Occidental Lisandro Alvarado (UCLA). This project implements a voting system for student councils, utilizing fundamental data structures in C++: stacks, queues, and linked lists.

El **Proyecto de Elecciones** fue desarrollado como parte del currículo académico en la Universidad Centro Occidental Lisandro Alvarado (UCLA). Este proyecto implementa un sistema de votación para consejos estudiantiles, utilizando estructuras de datos fundamentales en C++: pilas, colas y listas enlazadas.

## Features / Características

- **Mesa Management:** Allows adding and managing voting tables (mesas) where students can cast their votes.
- **Voter Queue:** Implements a queue data structure to manage voters waiting to vote at each table.
- **Voting Status:** Allows tracking of the voting status of students (e.g., voted, not yet voted, assisted).

- **Gestión de Mesas:** Permite agregar y gestionar mesas de votación donde los estudiantes pueden votar.
- **Cola de Votantes:** Implementa una estructura de datos en forma de cola para gestionar a los votantes que esperan para votar en cada mesa.
- **Estado de Voto:** Permite rastrear el estado de votación de los estudiantes (por ejemplo, votaron, aún no votaron, asistidos).

## Code Structure / Estructura del Código

### Main File / Archivo Principal

The main file showcases a menu-driven program where users can:

1. Add tables to the list.
2. Add voters to a specific table's queue.
3. View voters registered at a table.

El archivo principal muestra un programa basado en un menú donde los usuarios pueden:

1. Agregar mesas a la lista.
2. Agregar votantes a la cola de una mesa específica.
3. Ver los votantes registrados en una mesa.

### Example of Code Functionality / Ejemplo de Funcionalidad del Código

The following functions are central to this project:

- `menu()`: Displays the main menu and handles user interactions.
- `agregarVotanteEnColaDeMesa()`: Manages adding voters to the queue of a specified table.
- `verVotantesEnMesa()`: Allows viewing the voters registered at a specific table.

Las siguientes funciones son fundamentales en este proyecto:

- `menu()`: Muestra el menú principal y maneja las interacciones del usuario.
- `agregarVotanteEnColaDeMesa()`: Maneja la adición de votantes a la cola de una mesa específica.
- `verVotantesEnMesa()`: Permite ver los votantes registrados en una mesa específica.

## Getting Started / Cómo Comenzar

To run this project, ensure you have a C++ compiler installed. Clone the repository and compile the main file along with the necessary header files.

Para ejecutar este proyecto, asegúrate de tener un compilador de C++ instalado. Clona el repositorio y compila el archivo principal junto con los archivos de encabezado necesarios.

## Contact

For any questions or inquiries, feel free to reach out.

Para cualquier pregunta o consulta, ¡no dudes en ponerte en contacto!
