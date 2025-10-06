SUDOKU GAME - C++ con WinAPI
=============================

DESCRIPCION
-----------
Juego de Sudoku completo desarrollado en C++98 con interfaz grafica WinAPI.
Compatible con Dev-C++ y compiladores antiguos.

CARACTERISTICAS
---------------
- Generacion aleatoria de tableros de Sudoku
- Interfaz grafica con WinAPI  
- Validacion de soluciones
- Compatible con C++98
- Controles con mouse y teclado

REQUISITOS
----------
- Sistema: Windows XP, 7, 8, 10, 11
- Compilador: Dev-C++ con MinGW
- RAM: Minimo 512 MB
- Espacio: 1 MB

INSTALACION EN DEV-C++
----------------------

Paso 1: Instalar Dev-C++
1. Descargar Dev-C++
2. Instalar version 5.11 recomendada

Paso 2: Crear Proyecto
1. Abrir Dev-C++
2. File -> New -> Project
3. Seleccionar "Windows Application"
4. Nombrar proyecto: SudokuGame
5. Guardar en carpeta deseada

Paso 3: Configurar Proyecto
1. Project -> Project Options
2. Pestaña "Parameters"
3. En campo "Linker" agregar: -lgdi32
4. Click OK

Paso 4: Agregar Codigo
1. Reemplazar todo el contenido del archivo principal con el codigo del juego
2. Guardar: File -> Save (Ctrl+S)

Paso 5: Compilar y Ejecutar
- Compilar: F11
- Compilar y Ejecutar: F9
- Ejecutar: F10

CONTROLES DEL JUEGO
-------------------

Mouse:
- Clic izquierdo: Seleccionar celda

Teclado:
- Teclas 1-9: Ingresar numero en celda seleccionada
- Delete/Backspace/0: Borrar numero
- N: Nuevo juego
- C: Verificar solucion

COMO JUGAR
----------
1. Seleccionar celda con clic
2. Ingresar numeros con teclas 1-9
3. Celdas fijas (negras) no se pueden modificar
4. Celdas usuario (azules) son tus respuestas
5. Presionar C para verificar solucion
6. Presionar N para nuevo juego

ESTRUCTURA DEL PROYECTO
-----------------------
SudokuGame/
  sudoku.cpp      - Codigo fuente principal
  sudoku.dev      - Archivo proyecto Dev-C++
  README.md       - Este archivo

SOLUCION DE PROBLEMAS
---------------------

Error: "undefined reference to CreateSolidBrush"
Solucion: Verificar que -lgdi32 este en parametros del linker

Error: "Windows.h not found"
Solucion: Reinstalar Dev-C++

Programa compila pero no ejecuta
Solucion:
1. Verificar antivirus
2. Ejecutar como administrador
3. Reinstalar Dev-C++

COMPILACION EN OTROS ENTORNOS
-----------------------------

Code::Blocks:
1. Crear proyecto "Windows GUI"
2. Agregar -lgdi32 en Project -> Build options -> Linker settings

Linea de comandos:
g++ -o sudoku.exe sudoku.cpp -lgdi32 -mwindows

NOTAS TECNICAS
--------------
- Lenguaje: C++98
- GUI: WinAPI (Windows.h)
- Compilador: MinGW GCC
- Compatibilidad: Windows 2000 o superior

REGLAS DEL SUDOKU
-----------------
- Cada fila debe contener 1-9 sin repetir
- Cada columna debe contener 1-9 sin repetir
- Cada cuadrante 3x3 debe contener 1-9 sin repetir

LICENCIA
--------
Proyecto de codigo abierto para fines educativos.

¡Disfruta jugando al Sudoku!