/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects
*/

#ifndef V3COLORS_H_
#define V3COLORS_H_

#include <windows.h>
#include <iostream>
using namespace std;

// Funcion auxiliar para mostrar ejemplos
inline void showColorExample(const char* name, int colorCode) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
    cout << "[" << name << "] ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Vuelve a blanco
    cout << "Este texto muestra el color " << name << " (Codigo: " << colorCode << ")\n";
}

// Macros de colores con descripcion
#define $bkg_BB SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 17)  // Fondo azul, texto azul
#define $bkg_Bb SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16)  // Fondo azul, texto negro
#define $def SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)     // Blanco brillante (default)
#define $yellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14)  // Amarillo
#define $red SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12)     // Rojo
#define $Lblue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11)   // Azul claro
#define $green SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10)   // Verde
#define $Dblue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9)    // Azul oscuro
#define $Dgray SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8)    // Gris oscuro
#define $gray SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)     // Gris
#define $gold SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6)     // Dorado
#define $Dfusc SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5)    // Purpura
#define $Dred SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4)     // Rojo oscuro
#define $DLblue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3)   // Azul claro/cian
#define $Dgreen SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2)   // Verde oscuro
#define $black SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0)    // Negro

// Funcion para demostrar todos los colores
inline void demoColors() {
    system("cls"); // Limpiar pantalla (Windows)
    
    cout << "DEMOSTRACION DE COLORES DE TERMINAL:\n\n";
    
    $def; cout << "Colores basicos:\n";
    showColorExample("$black", 0);
    showColorExample("$Dred", 4);
    showColorExample("$Dgreen", 2);
    showColorExample("$gold", 6);
    showColorExample("$Dblue", 9);
    showColorExample("$Dfusc", 5);
    showColorExample("$Dgray", 8);
    showColorExample("$gray", 7);
    
    cout << "\nColores brillantes:\n";
    showColorExample("$red", 12);
    showColorExample("$green", 10);
    showColorExample("$yellow", 14);
    showColorExample("$Lblue", 11);
    showColorExample("$DLblue", 3);
    
    cout << "\nFondos:\n";
    $bkg_Bb; cout << " [$bkg_Bb] Texto negro sobre fondo azul\n";
    $bkg_BB; cout << " [$bkg_BB] Texto azul sobre fondo azul\n";
    
    $def; // Restaurar color por defecto
    cout << "\nDemo completa. Color restaurado a default ($def)\n";
}

#endif /* V3COLORS_H_ */
