/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// getCurrentDate - Returns the current date.
// obtenerFechaActual - Devuelve la fecha actual.
string getCurrentDate() {
    time_t now = time(0);
    tm *timeStruct = localtime(&now);
    stringstream ss;
    ss << timeStruct->tm_mday << "/" << (timeStruct->tm_mon + 1) << "/" << (timeStruct->tm_year + 1900);
    return ss.str();
}

// convertMonthNumberToName - Converts a month number to its name in English.
// convertirMesNumeroANombre - Convierte un número de mes a su nombre en inglés.
string convertMonthNumberToName(int month) {
    string months[] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};
    return (month >= 1 && month <= 12) ? months[month - 1] : "Invalid month";
}

// isLeapYear - Determines if a year is a leap year.
// esBisiesto - Determina si un año es bisiesto.
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// toUpperCase - Converts a text to uppercase.
// convertirAMayusculas - Convierte un texto a mayúsculas.
string toUpperCase(string text) {
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    return text;
}

// toLowerCase - Converts a text to lowercase.
// convertirAMinusculas - Convierte un texto a minúsculas.
string toLowerCase(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

// trim - Removes leading and trailing whitespace from a text.
// eliminarEspacios - Elimina espacios en blanco al inicio y al final de un texto.
string trim(string text) {
    text.erase(0, text.find_first_not_of(" "));
    text.erase(text.find_last_not_of(" ") + 1);
    return text;
}

// generateRandomNumber - Generates a random number within a range.
// generarNumeroAleatorio - Genera un número aleatorio dentro de un rango.
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// splitString - Splits a string into parts based on a delimiter.
// dividirCadena - Divide una cadena en partes según un delimitador.
vector<string> splitString(string text, char delimiter) {
    vector<string> result;
    stringstream ss(text);
    string part;
    while (getline(ss, part, delimiter)) {
        result.push_back(part);
    }
    return result;
}

// replaceCharacter - Replaces a specific character in a string.
// reemplazarCaracter - Reemplaza un carácter específico en una cadena.
string replaceCharacter(string text, char searchChar, char replaceChar) {
    replace(text.begin(), text.end(), searchChar, replaceChar);
    return text;
}
