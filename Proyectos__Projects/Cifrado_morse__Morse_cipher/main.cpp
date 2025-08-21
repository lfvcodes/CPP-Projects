/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

El objetivo de este proyecto es implementar un codificador y decodificador de código Morse en C++.
Deberás crear dos funciones principales: encode() para convertir texto a Morse y decode() para revertir el proceso.

The goal of this project is to implement a Morse code encoder and decoder in C++.
You'll need to create two main functions: encode() to convert text to Morse code, and decode() to reverse the process.
*/

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <cctype>
#include <vector>
#include <limits>
#include <cstdlib>

using namespace std;

// Prototipos de funciones
string encode(const string &text);
string decode(const string &morseText);
void initializeMorseMap(map<char, string> &morseMap);
void initializeTextMap(map<string, char> &textMap);

int main()
{
  int choice;
  string textInput;

  do
  {
    system("CLS"); // Usa "clear" en sistemas Unix/Linux/Mac

    cout << "--- APLICACION DE CODIGO MORSE ---" << endl;
    cout << "1. Codificar texto a Morse" << endl;
    cout << "2. Decodificar Morse a texto" << endl;
    cout << "3. Salir" << endl;
    cout << "----------------------------------" << endl;
    cout << "Seleccione una opcion: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el buffer

    switch (choice)
    {
    case 1:
      try
      {
        cout << "\nIngrese el texto a codificar: ";
        getline(cin, textInput);
        cout << "Texto codificado: " << encode(textInput) << endl;
      }
      catch (const runtime_error &e)
      {
        cerr << "Error: " << e.what() << endl;
      }
      break;
    case 2:
      try
      {
        cout << "\nIngrese el codigo Morse a decodificar: ";
        getline(cin, textInput);
        cout << "Texto decodificado: " << decode(textInput) << endl;
      }
      catch (const runtime_error &e)
      {
        cerr << "Error: " << e.what() << endl;
      }
      break;
    case 3:
      cout << "\nSaliendo del programa..." << endl;
      break;
    default:
      cout << "\nOpcion invalida. Por favor, intente de nuevo." << endl;
    }

    if (choice != 3)
    {
      system("pause");
    }

  } while (choice != 3);

  return 0;
}

void initializeMorseMap(map<char, string> &morseMap)
{
  morseMap['A'] = ".-";
  morseMap['B'] = "-...";
  morseMap['C'] = "-.-.";
  morseMap['D'] = "-..";
  morseMap['E'] = ".";
  morseMap['F'] = "..-.";
  morseMap['G'] = "--.";
  morseMap['H'] = "....";
  morseMap['I'] = "..";
  morseMap['J'] = ".---";
  morseMap['K'] = "-.-";
  morseMap['L'] = ".-..";
  morseMap['M'] = "--";
  morseMap['N'] = "-.";
  morseMap['O'] = "---";
  morseMap['P'] = ".--.";
  morseMap['Q'] = "--.-";
  morseMap['R'] = ".-.";
  morseMap['S'] = "...";
  morseMap['T'] = "-";
  morseMap['U'] = "..-";
  morseMap['V'] = "...-";
  morseMap['W'] = ".--";
  morseMap['X'] = "-..-";
  morseMap['Y'] = "-.--";
  morseMap['Z'] = "--..";
  morseMap['1'] = ".----";
  morseMap['2'] = "..---";
  morseMap['3'] = "...--";
  morseMap['4'] = "....-";
  morseMap['5'] = ".....";
  morseMap['6'] = "-....";
  morseMap['7'] = "--...";
  morseMap['8'] = "---..";
  morseMap['9'] = "----.";
  morseMap['0'] = "-----";
  morseMap[' '] = "/";
}

void initializeTextMap(map<string, char> &textMap)
{
  textMap[".-"] = 'A';
  textMap["-..."] = 'B';
  textMap["-.-."] = 'C';
  textMap["-.."] = 'D';
  textMap["."] = 'E';
  textMap["..-."] = 'F';
  textMap["--."] = 'G';
  textMap["...."] = 'H';
  textMap[".."] = 'I';
  textMap[".---"] = 'J';
  textMap["-.-"] = 'K';
  textMap[".-.."] = 'L';
  textMap["--"] = 'M';
  textMap["-."] = 'N';
  textMap["---"] = 'O';
  textMap[".--."] = 'P';
  textMap["--.-"] = 'Q';
  textMap[".-."] = 'R';
  textMap["..."] = 'S';
  textMap["-"] = 'T';
  textMap["..-"] = 'U';
  textMap["...-"] = 'V';
  textMap[".--"] = 'W';
  textMap["-..-"] = 'X';
  textMap["-.--"] = 'Y';
  textMap["--.."] = 'Z';
  textMap[".----"] = '1';
  textMap["..---"] = '2';
  textMap["...--"] = '3';
  textMap["....-"] = '4';
  textMap["....."] = '5';
  textMap["-...."] = '6';
  textMap["--..."] = '7';
  textMap["---.."] = '8';
  textMap["----."] = '9';
  textMap["-----"] = '0';
  textMap["/"] = ' ';
}

string encode(const string &text)
{
  map<char, string> morseMap;
  initializeMorseMap(morseMap);

  string encodedText = "";
  for (size_t i = 0; i < text.length(); ++i)
  {
    char c = toupper(text[i]);
    map<char, string>::iterator it = morseMap.find(c);
    if (it != morseMap.end())
    {
      encodedText += it->second;
      if (i < text.length() - 1)
      {
        encodedText += " ";
      }
    }
    else
    {
      throw runtime_error("Caracter invalido: " + string(1, c));
    }
  }
  return encodedText;
}

string decode(const string &morseText)
{
  map<string, char> textMap;
  initializeTextMap(textMap);

  string decodedText = "";
  string currentMorse;
  for (size_t i = 0; i < morseText.length(); ++i)
  {
    if (morseText[i] == ' ')
    {
      if (currentMorse.empty())
      {
        continue;
      }
      map<string, char>::iterator it = textMap.find(currentMorse);
      if (it != textMap.end())
      {
        decodedText += it->second;
      }
      else
      {
        throw runtime_error("Codigo Morse invalido: " + currentMorse);
      }
      currentMorse = "";
    }
    else
    {
      currentMorse += morseText[i];
    }
  }
  if (!currentMorse.empty())
  {
    map<string, char>::iterator it = textMap.find(currentMorse);
    if (it != textMap.end())
    {
      decodedText += it->second;
    }
    else
    {
      throw runtime_error("Codigo Morse invalido: " + currentMorse);
    }
  }

  return decodedText;
}
