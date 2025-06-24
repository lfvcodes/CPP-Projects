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
#include <algorithm> // Required for std::transform, std::replace, std::reverse
#include <cctype>    // Required for std::isdigit
#include <limits>    // Required for std::numeric_limits

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
    // Seed the random number generator if not already seeded (only once per program execution)
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }
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

// startsWith - Checks if a string begins with a given prefix.
// comienzaCon - Verifica si una cadena comienza con un prefijo dado.
bool startsWith(const string& text, const string& prefix) {
    return text.size() >= prefix.size() && text.compare(0, prefix.size(), prefix) == 0;
}

// endsWith - Checks if a string ends with a given suffix.
// terminaCon - Verifica si una cadena termina con un sufijo dado.
bool endsWith(const string& text, const string& suffix) {
    return text.size() >= suffix.size() && text.compare(text.size() - suffix.size(), suffix.size(), suffix) == 0;
}

// containsString - Checks if a string contains another substring.
// contieneCadena - Comprueba si una cadena contiene otra subcadena.
bool containsString(const string& text, const string& subString) {
    return text.find(subString) != string::npos;
}

// reverseString - Reverses a string.
// invertirCadena - Invierte una cadena de texto.
string reverseString(string text) {
    reverse(text.begin(), text.end());
    return text;
}

// isNumber - Checks if a string represents a valid number.
// esNumero - Verifica si una cadena representa un número válido.
bool isNumber(const string& text) {
    if (text.empty()) {
        return false;
    }
    for (char c : text) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// clamp - Limits a value within a specified range.
// limitarValor - Limita un valor dentro de un rango específico.
template <typename T>
T clamp(T value, T low, T high) {
    return max(low, min(value, high));
}