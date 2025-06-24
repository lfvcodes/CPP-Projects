/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects
*/

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>
#include <algorithm> // Necesario para std::max y std::min en la función clamp
#include <type_traits> // Necesario para las plantillas

// Usamos el namespace std para simplificar el código
using namespace std;

// Function declarations (Declaraciones de funciones)
string getCurrentDate(); 
string convertMonthNumberToName(int month);
bool isLeapYear(int year);
string toUpperCase(string text);
string toLowerCase(string text);
string trim(string text);
int generateRandomNumber(int min, int max);
vector<string> splitString(string text, char delimiter);
string replaceCharacter(string text, char searchChar, char replaceChar);
bool startsWith(const string& text, const string& prefix);
bool endsWith(const string& text, const string& suffix);
bool containsString(const string& text, const string& subString);
string reverseString(string text);
bool isNumber(const string& text);
template <typename T>
T clamp(T value, T low, T high);

#endif // UTILITIES_H