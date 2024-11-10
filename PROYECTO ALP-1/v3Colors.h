/*CODE BY V3LF*/
#ifndef V3COLORS_H_
#define V3COLORS_H_

#include <windows.h>
using namespace std;
#define $bkg_BB SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 17)
#define $bkg_Bb SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16)
#define $def SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)
#define $yellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14)
#define $red SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12)
#define $Lblue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11)
#define $green SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10)
#define $Dblue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9)
#define $Dgray SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8)
#define $gray SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7)
#define $gold SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6)
#define $Dfusc SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5)
#define $Dred SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4)
#define $DLblue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3)
#define $Dgreen SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2)
#define $black SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0)

#endif /* V3COLORS_H_ */
