/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects

Desarrolla un sistema de control de asistencia para una pequeña empresa.
El programa debe registrar los nombres de los empleados y marcar su asistencia diaria (presente/ausente),
luego generar un reporte con los días trabajados por cada empleado.

Develop an attendance tracking system for a small business.
The program should record employee names and mark their daily attendance (present/absent),
then generate a report showing the days worked by each employee.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> empleados;
    vector<int> asistencias;
    int dias = 0;
    char opcion;

    // Registro de empleados
    do {
        string nombre;
        cout << "\nDigite el nombre del empleado: ";
        cin >> nombre;
        empleados.push_back(nombre);
        asistencias.push_back(0);

        cout << "Desea agregar otro empleado? (s/n): ";
        cin >> opcion;
    } while(opcion == 's' || opcion == 'S');

    // Registro diario de asistencia
    do {
        cout << "\n--- Día " << dias+1 << " ---\n";
        for(int i = 0; i < empleados.size(); i++) {
            char estado;
            cout << empleados[i] << " esta presente? (s/n): ";
            cin >> estado;
            if(estado == 's' || estado == 'S') {
                asistencias[i]++;
            }
        }
        dias++;

        cout << "\nDesea registrar otro dia? (s/n): ";
        cin >> opcion;
    } while(opcion == 's' || opcion == 'S');

    // Reporte final
    cout << "\n=== REPORTE DE ASISTENCIA ===\n";
    for(int i = 0; i < empleados.size(); i++) {
        cout << empleados[i] << ": " << asistencias[i] << " dias de " << dias << " (" 
             << (asistencias[i]*100/dias) << "% de asistencia)\n";
    }

    return 0;
}