/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects
*/

//#ifndef UTILITIES_H
//#define UTILITIES_H

#include <string>
#include <vector>

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

//#endif // UTILITIES_H
