#include <iostream>
#include "mascota.h"
#include "voluntario.h"

using namespace std;

void mostrarMenuPrincipal();
void mostrarMenuReportes();
void mostrarMenuVoluntarios();
void gestionVoluntarios();
void reportes();

int main() {
    int opcion;

    do {
        mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarMascota();
                break;
            case 2: {
                int id;
                cout << "ID de mascota a actualizar: ";
                cin >> id;
                marcarComoAdoptada(id);
                break;
            }
            case 3:
                listarMascotasDisponibles();
                break;
            case 4:
                reportes();
                break;
            case 5:
                gestionVoluntarios();
                break;
            case 6:
                cout << "Terminar programa"<<endl;
                break;
            default:
                cout << "Opcion no valida"<<endl;
        }
        cout<<endl;
        system("PAUSE");
    } while (opcion != 6);

    return 0;
}

void mostrarMenuPrincipal() {
    system("CLS");
    cout <<endl << " |\\---/|"<<endl;
    cout << " | o_o | REFUGIO DE MASCOTAS"<< endl;
    cout << "  \\_^_/"<<endl;
    cout <<endl;
    cout << " 1. Registrar nueva mascota"<<endl;
    cout << " 2. Marcar mascota como adoptada"<<endl;
    cout << " 3. Listar mascotas disponibles"<<endl;
    cout << " 4. Reportes"<<endl;
    cout << " 5. Gestion de voluntarios"<<endl;
    cout << " 6. Salir"<<endl;
    cout << " Opcion: ";
}

void mostrarMenuReportes() {
    system("CLS");
    cout << endl << "--- MENU DE REPORTES ---"<<endl;
    cout << " 1. Listar mascotas disponibles"<<endl;
    cout << " 2. Listar mascotas adoptadas"<<endl;
    cout << " 3. Reporte por especie"<<endl;
    cout << " 4. Reporte de adopciones por fecha"<<endl;
    cout << " 5. Volver al menu principal"<<endl;
    cout << " Opcion: ";
}

void mostrarMenuVoluntarios(){
	system("CLS");
    cout << endl << "--- MENU DE VOLUNTARIOS ---"<<endl;
    cout << " 1. Registrar Voluntario"<<endl;
    cout << " 2. Actualizar Voluntario"<<endl;
    cout << " 3. Listar Voluntarios"<<endl;
    cout << " 4. Volver al menu principal"<<endl;
    cout << " Opcion: ";
}

void gestionVoluntarios(){
int opcion;
    do {
        mostrarMenuVoluntarios();
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                registrarVoluntario();
                system("PAUSE");
                break;
            case 2:
                actualizarVoluntario();
                system("PAUSE");
                break;
            case 3:
                listarVoluntarios();
                system("PAUSE");
                break;
            case 4:
                cout << "Volviendo al menu principal..."<<endl;
                break;
            default:
                cout << "Opcion no valida"<<endl;
        }
    } while (opcion != 4);	
}

void reportes() {
    int opcion;
    do {
        mostrarMenuReportes();
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                listarMascotasDisponibles();
                system("PAUSE");
                break;
            case 2:
                listarMascotasAdoptadas();
                system("PAUSE");
                break;
            case 3:
                reportePorEspecie();
                system("PAUSE");
                break;
            case 4:
                reporteAdopcionesPorRangoFechas();
                system("PAUSE");
                break;
            case 5:
                cout << "Volviendo al menu principal..."<<endl;
                break;
            default:
                cout << "Opcion no valida"<<endl;
        }
    } while (opcion != 5);
}
