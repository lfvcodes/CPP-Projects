/*
# Author: @lfvcodes
GitHub: https://github.com/lfvcodes/CPP-Projects

Sudoku Game - WinApi

*/

#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

// Constantes
const int BOARD_SIZE = 9;
const int CELL_SIZE = 40;
const int MARGIN = 50;
const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 600;

// Variables globales
int board[BOARD_SIZE][BOARD_SIZE];
int solution[BOARD_SIZE][BOARD_SIZE];
int userBoard[BOARD_SIZE][BOARD_SIZE];
bool fixedCells[BOARD_SIZE][BOARD_SIZE];
int selectedRow = -1;
int selectedCol = -1;
bool gameSolved = false;

// Prototipos de funciones
void InitializeGame();
void GenerateSudoku();
bool SolveSudoku(int grid[BOARD_SIZE][BOARD_SIZE]);
bool IsValid(int grid[BOARD_SIZE][BOARD_SIZE], int row, int col, int num);
void RemoveNumbers(int difficulty);
void DrawBoard(HDC hdc);
void DrawCell(HDC hdc, int row, int col, int number, bool isFixed, bool isSelected);
void HandleCellClick(int x, int y);
void HandleNumberInput(int number);
bool CheckSolution();
void ShowMessage(const string& message);

// Funci�n para verificar si un n�mero es v�lido en una posici�n
bool IsValid(int grid[BOARD_SIZE][BOARD_SIZE], int row, int col, int num) {
    // Verificar fila
    for (int x = 0; x < BOARD_SIZE; x++) {
        if (grid[row][x] == num) return false;
    }
    
    // Verificar columna
    for (int x = 0; x < BOARD_SIZE; x++) {
        if (grid[x][col] == num) return false;
    }
    
    // Verificar cuadrante 3x3
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }
    
    return true;
}

// Funci�n para resolver el Sudoku (backtracking)
bool SolveSudoku(int grid[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (IsValid(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (SolveSudoku(grid)) return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Funci�n para generar un Sudoku completo
void GenerateCompleteSudoku(int grid[BOARD_SIZE][BOARD_SIZE]) {
    // Inicializar con ceros
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            grid[i][j] = 0;
        }
    }
    
    // Llenar la diagonal de los 3 cuadrantes principales
    for (int i = 0; i < BOARD_SIZE; i += 3) {
        for (int j = 0; j < BOARD_SIZE; j += 3) {
            int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            // Mezclar n�meros
            for (int k = 0; k < 9; k++) {
                int r = k + rand() % (9 - k);
                int temp = numbers[r];
                numbers[r] = numbers[k];
                numbers[k] = temp;
            }
            
            int index = 0;
            for (int row = i; row < i + 3; row++) {
                for (int col = j; col < j + 3; col++) {
                    grid[row][col] = numbers[index++];
                }
            }
        }
    }
    
    // Resolver el resto del tablero
    SolveSudoku(grid);
}

// Funci�n para remover n�meros seg�n la dificultad
void RemoveNumbers(int difficulty) {
    int numbersToRemove;
    switch (difficulty) {
        case 1: numbersToRemove = 30; break; // F�cil
        case 2: numbersToRemove = 40; break; // Medio
        case 3: numbersToRemove = 50; break; // Dif�cil
        default: numbersToRemove = 40; break;
    }
    
    int removed = 0;
    while (removed < numbersToRemove) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        
        if (board[row][col] != 0) {
            int temp = board[row][col];
            board[row][col] = 0;
            
            // Verificar que tenga soluci�n �nica
            int tempGrid[BOARD_SIZE][BOARD_SIZE];
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    tempGrid[i][j] = board[i][j];
                }
            }
            
            if (SolveSudoku(tempGrid)) {
                removed++;
            } else {
                board[row][col] = temp;
            }
        }
    }
}

// Funci�n para generar el Sudoku
void GenerateSudoku() {
    srand(static_cast<unsigned int>(time(NULL)));
    
    // Generar soluci�n completa
    GenerateCompleteSudoku(solution);
    
    // Copiar a board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = solution[i][j];
            userBoard[i][j] = solution[i][j];
        }
    }
    
    // Remover n�meros (dificultad media por defecto)
    RemoveNumbers(2);
    
    // Marcar celdas fijas
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            fixedCells[i][j] = (board[i][j] != 0);
            userBoard[i][j] = board[i][j];
        }
    }
}

// Funci�n para inicializar el juego
void InitializeGame() {
    GenerateSudoku();
    selectedRow = -1;
    selectedCol = -1;
    gameSolved = false;
}

// Funci�n para dibujar una celda
void DrawCell(HDC hdc, int row, int col, int number, bool isFixed, bool isSelected) {
    int x = MARGIN + col * CELL_SIZE;
    int y = MARGIN + row * CELL_SIZE;
    
    // Dibujar fondo de celda
    if (isSelected) {
        HBRUSH hBrush = CreateSolidBrush(RGB(200, 200, 255));
        SelectObject(hdc, hBrush);
        Rectangle(hdc, x, y, x + CELL_SIZE, y + CELL_SIZE);
        DeleteObject(hBrush);
    } else {
        HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, hBrush);
        Rectangle(hdc, x, y, x + CELL_SIZE, y + CELL_SIZE);
        DeleteObject(hBrush);
    }
    
    // Dibujar borde
    HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    Rectangle(hdc, x, y, x + CELL_SIZE, y + CELL_SIZE);
    DeleteObject(hPen);
    
    // Dibujar n�mero si existe
    if (number != 0) {
        stringstream ss;
        ss << number;
        string numStr = ss.str();
        
        // Configurar color y fuente
        if (isFixed) {
            SetTextColor(hdc, RGB(0, 0, 0)); // Negro para n�meros fijos
        } else {
            SetTextColor(hdc, RGB(0, 0, 255)); // Azul para n�meros del usuario
        }
        
        SetBkMode(hdc, TRANSPARENT);
        HFONT hFont = CreateFont(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                               DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
                               CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
        HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
        
        RECT rect;
        rect.left = x;
        rect.top = y;
        rect.right = x + CELL_SIZE;
        rect.bottom = y + CELL_SIZE;
        DrawText(hdc, numStr.c_str(), -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
        
        SelectObject(hdc, hOldFont);
        DeleteObject(hFont);
    }
}

// Funci�n para dibujar el tablero completo
void DrawBoard(HDC hdc) {
    // Dibujar l�neas gruesas para los cuadrantes 3x3
    HPEN hThickPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    HPEN hOldPen = (HPEN)SelectObject(hdc, hThickPen);
    
    for (int i = 0; i <= 3; i++) {
        // L�neas verticales
        int x = MARGIN + i * 3 * CELL_SIZE;
        MoveToEx(hdc, x, MARGIN, NULL);
        LineTo(hdc, x, MARGIN + 9 * CELL_SIZE);
        
        // L�neas horizontales
        int y = MARGIN + i * 3 * CELL_SIZE;
        MoveToEx(hdc, MARGIN, y, NULL);
        LineTo(hdc, MARGIN + 9 * CELL_SIZE, y);
    }
    
    SelectObject(hdc, hOldPen);
    DeleteObject(hThickPen);
    
    // Dibujar celdas y n�meros
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            bool isSelected = (i == selectedRow && j == selectedCol);
            DrawCell(hdc, i, j, userBoard[i][j], fixedCells[i][j], isSelected);
        }
    }
}

// Funci�n para manejar clic en celda
void HandleCellClick(int x, int y) {
    if (x < MARGIN || y < MARGIN) return;
    
    int col = (x - MARGIN) / CELL_SIZE;
    int row = (y - MARGIN) / CELL_SIZE;
    
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
        selectedRow = row;
        selectedCol = col;
    }
}

// Funci�n para manejar entrada de n�meros
void HandleNumberInput(int number) {
    if (selectedRow != -1 && selectedCol != -1 && !fixedCells[selectedRow][selectedCol]) {
        userBoard[selectedRow][selectedCol] = number;
    }
}

// Funci�n para verificar la soluci�n
bool CheckSolution() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (userBoard[i][j] != solution[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Funci�n para mostrar mensajes
void ShowMessage(const string& message) {
    MessageBox(NULL, message.c_str(), "Sudoku", MB_OK | MB_ICONINFORMATION);
}

// Procedimiento de ventana
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            InitializeGame();
            break;
        }
        
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Dibujar fondo
            RECT rect;
            GetClientRect(hwnd, &rect);
            HBRUSH hBackground = CreateSolidBrush(RGB(240, 240, 240));
            FillRect(hdc, &rect, hBackground);
            DeleteObject(hBackground);
            
            // Dibujar tablero
            DrawBoard(hdc);
            
            // Dibujar t�tulo
            SetTextColor(hdc, RGB(0, 0, 0));
            SetBkMode(hdc, TRANSPARENT);
            HFONT hFont = CreateFont(24, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
                                   DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
                                   CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
            HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
            
            RECT titleRect;
            titleRect.left = 0;
            titleRect.top = 10;
            titleRect.right = WINDOW_WIDTH;
            titleRect.bottom = 40;
            DrawText(hdc, "SUDOKU", -1, &titleRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            
            SelectObject(hdc, hOldFont);
            DeleteObject(hFont);
            
            // Dibujar instrucciones
            HFONT hSmallFont = CreateFont(14, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                                        DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
                                        CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
            hOldFont = (HFONT)SelectObject(hdc, hSmallFont);
            
            RECT instRect;
            instRect.left = 10;
            instRect.top = WINDOW_HEIGHT - 60;
            instRect.right = WINDOW_WIDTH - 10;
            instRect.bottom = WINDOW_HEIGHT - 10;
            DrawText(hdc, "Clic en celda y presiona 1-9 para ingresar numeros. N: Nuevo juego. C: Verificar", 
                    -1, &instRect, DT_CENTER | DT_VCENTER | DT_WORDBREAK);
            
            SelectObject(hdc, hOldFont);
            DeleteObject(hSmallFont);
            
            EndPaint(hwnd, &ps);
            break;
        }
        
        case WM_LBUTTONDOWN: {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            HandleCellClick(x, y);
            InvalidateRect(hwnd, NULL, TRUE);
            break;
        }
        
        case WM_KEYDOWN: {
            if (gameSolved) break;
            
            switch (wParam) {
                case '1': case '2': case '3': case '4': case '5':
                case '6': case '7': case '8': case '9':
                    HandleNumberInput(wParam - '0');
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;
                    
                case VK_DELETE: case VK_BACK: case '0':
                    HandleNumberInput(0);
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;
                    
                case 'N': case 'n':
                    InitializeGame();
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;
                    
                case 'C': case 'c':
                    if (CheckSolution()) {
                        gameSolved = true;
                        ShowMessage("�Felicidades! Has resuelto el Sudoku correctamente.");
                    } else {
                        ShowMessage("La soluci�n no es correcta. Sigue intentando.");
                    }
                    break;
            }
            break;
        }
        
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
            
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// Funci�n principal
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Registrar clase de ventana
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "SudokuWindow";
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    
    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Error al registrar la clase de ventana!", "Error", MB_ICONERROR);
        return 0;
    }
    
    // Crear ventana
    HWND hwnd = CreateWindowEx(
        0,
        "SudokuWindow",
        "Sudoku Game",
        WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        NULL, NULL, hInstance, NULL
    );
    
    if (!hwnd) {
        MessageBox(NULL, "Error al crear la ventana!", "Error", MB_ICONERROR);
        return 0;
    }
    
    // Mostrar ventana
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    // Bucle de mensajes
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}
