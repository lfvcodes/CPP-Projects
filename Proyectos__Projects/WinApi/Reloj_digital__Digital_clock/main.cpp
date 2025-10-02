/*
# Author: @lfvcodes
GitHub: https://github.com/lfvcodes/CPP-

Desarrollar una aplicación gráfica de escritorio que muestre la hora actual en formato digital (HH:MM:SS),
actualizándose cada segundo. El proyecto debe estar implementado en C++98
utilizando la API de Windows (WinAPI) y ser compatible con Dev-C++.

Build a graphical desktop application that displays the current time in digital format (HH:MM:SS),
updating every second. The project must be implemented using C++98 and the Windows API (WinAPI),
and should be compatible with Dev-C++.
*/

#include <windows.h>
#include <ctime>
#include <sstream>

HWND hClockLabel;

void actualizarHora()
{
    time_t now = time(0);
    struct tm *local = localtime(&now);

    std::ostringstream oss;
    oss << "Hora actual: "
        << (local->tm_hour < 10 ? "0" : "") << local->tm_hour << ":"
        << (local->tm_min < 10 ? "0" : "") << local->tm_min << ":"
        << (local->tm_sec < 10 ? "0" : "") << local->tm_sec;

    SetWindowText(hClockLabel, oss.str().c_str());
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_CREATE:
        hClockLabel = CreateWindow("STATIC", "Hora actual: --:--:--",
                                   WS_CHILD | WS_VISIBLE | SS_CENTER,
                                   50, 50, 200, 30,
                                   hwnd, NULL, NULL, NULL);

        SetTimer(hwnd, 1, 1000, NULL); // Actualiza cada 1000 ms (1 segundo)
        break;

    case WM_TIMER:
        actualizarHora();
        break;

    case WM_DESTROY:
        KillTimer(hwnd, 1);
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow)
{
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInst;
    wc.lpszClassName = "ClockWinAPI";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClass(&wc);

    HWND hwnd = CreateWindow("ClockWinAPI", "Reloj Digital",
                             WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, CW_USEDEFAULT, 320, 180,
                             NULL, NULL, hInst, NULL);

    ShowWindow(hwnd, nCmdShow);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
        DispatchMessage(&msg);
    return 0;
}
