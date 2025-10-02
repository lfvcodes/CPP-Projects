/*
# Author: @lfvcodes
GitHub: https://github.com/lfvcodes/CPP-

Crear una aplicación gráfica de escritorio utilizando la API de Windows (WinAPI) y el estándar C++98.
La aplicación debe implementar una calculadora básica que permita al usuario:
ingresar dos números y realizar operaciones aritméticas (suma, resta, multiplicación, división)
mediante botones. El resultado debe mostrarse dinámicamente en la interfaz.

Create a graphical desktop application using the Windows API (WinAPI) and the C++98 standard.
The application must implement a basic calculator that allows users to input two numbers an
perform arithmetic operations (addition, subtraction, multiplication, division) using buttons.
 The result should be displayed dynamically on the interface.
*/

#include <windows.h>
#include <sstream>

HWND hInput1, hInput2, hResult;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void calcular(HWND hwnd, int operacion)
{
    char buffer1[256], buffer2[256];
    GetWindowText(hInput1, buffer1, 256);
    GetWindowText(hInput2, buffer2, 256);

    double num1 = atof(buffer1);
    double num2 = atof(buffer2);
    double resultado = 0;

    switch (operacion)
    {
    case 1:
        resultado = num1 + num2;
        break;
    case 2:
        resultado = num1 - num2;
        break;
    case 3:
        resultado = num1 * num2;
        break;
    case 4:
        resultado = (num2 != 0) ? num1 / num2 : 0;
        break;
    }

    std::ostringstream oss;
    oss << "Resultado: " << resultado;
    SetWindowText(hResult, oss.str().c_str());
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    const char CLASS_NAME[] = "CalculadoraWinAPI";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "Mini Calculadora", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
        NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        CreateWindow("STATIC", "Número 1:", WS_VISIBLE | WS_CHILD, 20, 20, 80, 20, hwnd, NULL, NULL, NULL);
        hInput1 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 20, 100, 20, hwnd, NULL, NULL, NULL);

        CreateWindow("STATIC", "Número 2:", WS_VISIBLE | WS_CHILD, 20, 60, 80, 20, hwnd, NULL, NULL, NULL);
        hInput2 = CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 100, 60, 100, 20, hwnd, NULL, NULL, NULL);

        CreateWindow("BUTTON", "+", WS_VISIBLE | WS_CHILD, 220, 20, 40, 30, hwnd, (HMENU)1, NULL, NULL);
        CreateWindow("BUTTON", "-", WS_VISIBLE | WS_CHILD, 270, 20, 40, 30, hwnd, (HMENU)2, NULL, NULL);
        CreateWindow("BUTTON", "*", WS_VISIBLE | WS_CHILD, 220, 60, 40, 30, hwnd, (HMENU)3, NULL, NULL);
        CreateWindow("BUTTON", "/", WS_VISIBLE | WS_CHILD, 270, 60, 40, 30, hwnd, (HMENU)4, NULL, NULL);

        hResult = CreateWindow("STATIC", "Resultado: ", WS_VISIBLE | WS_CHILD, 20, 110, 300, 20, hwnd, NULL, NULL, NULL);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) >= 1 && LOWORD(wParam) <= 4)
        {
            calcular(hwnd, LOWORD(wParam));
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
