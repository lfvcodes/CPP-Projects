#ifndef VOLUNTARIO_H
#define VOLUNTARIO_H

#include <iostream>
#include <string>

using namespace std;

const int MAX_VOLUNTARIOS = 50;
const int MAX_HABILIDADES = 10;

struct Voluntario {
    int id;
    string nombre;
    string contacto;
    string habilidades[MAX_HABILIDADES];
    int numHabilidades;
    string disponibilidad;
};

Voluntario voluntarios[MAX_VOLUNTARIOS];
int totalVoluntarios = 0;

void registrarVoluntario() {
    if (totalVoluntarios >= MAX_VOLUNTARIOS) {
        cout << "No hay espacio para mas voluntarios."<<endl;
        return;
    }

    Voluntario nuevo;
    nuevo.id = totalVoluntarios + 1;
    
    cout << endl << "Registro de nuevo voluntario:"<<endl;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nuevo.nombre);
    cout << "Contacto: "; getline(cin, nuevo.contacto);
    
    cout << "Numero de habilidades: ";
    cin >> nuevo.numHabilidades;
    cin.ignore();
    
    for (int i = 0; i < nuevo.numHabilidades; i++) {
        cout << "Habilidad " << i+1 << ": ";
        getline(cin, nuevo.habilidades[i]);
    }
    
    cout << "Disponibilidad: "; 
    getline(cin, nuevo.disponibilidad);
    
    voluntarios[totalVoluntarios] = nuevo;
    totalVoluntarios++;
    cout << "Voluntario registrado! ID: " << nuevo.id << "\n";
}

void actualizarVoluntario() {
    if (totalVoluntarios == 0) {
        cout << endl << "No hay voluntarios registrados para actualizar." << endl;
        return;
    }

    int id;
    cout << endl << "--- ACTUALIZAR VOLUNTARIO ---" << endl;
    cout << "Ingrese el ID del voluntario a actualizar: ";
    cin >> id;
    cin.ignore();

    bool encontrado = false;
    for (int i = 0; i < totalVoluntarios; i++) {
        if (voluntarios[i].id == id) {
            encontrado = true;
            
            cout << endl << "Actualizando datos del voluntario ID: " << id << endl;
            cout << "Nombre actual: " << voluntarios[i].nombre << endl;
            cout << "Nuevo nombre (dejar vacio para mantener): ";
            string nuevoNombre;
            getline(cin, nuevoNombre);
            if (!nuevoNombre.empty()) {
                voluntarios[i].nombre = nuevoNombre;
            }

            cout << "Contacto actual: " << voluntarios[i].contacto << endl;
            cout << "Nuevo numero de contacto (dejar vacio para mantener): ";
            string nuevoContacto;
            getline(cin, nuevoContacto);
            if (!nuevoContacto.empty()) {
                voluntarios[i].contacto = nuevoContacto;
            }

            cout << "Desea actualizar las habilidades? (s/n): ";
            char opcion;
            cin >> opcion;
            cin.ignore();
            
            if (tolower(opcion) == 's') {
                cout << "Numero de habilidades: ";
                cin >> voluntarios[i].numHabilidades;
                cin.ignore();
                
                for (int j = 0; j < voluntarios[i].numHabilidades; j++) {
                    cout << "Habilidad " << j+1 << ": ";
                    getline(cin, voluntarios[i].habilidades[j]);
                }
            }

            cout << "Disponibilidad actual: " << voluntarios[i].disponibilidad << endl;
            cout << "Nueva disponibilidad (dejar vacio para mantener): ";
            string nuevaDisp;
            getline(cin, nuevaDisp);
            if (!nuevaDisp.empty()) {
                voluntarios[i].disponibilidad = nuevaDisp;
            }

            cout << "Voluntario actualizado con exito!" << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << endl << "No se encontro voluntario con ID " << id << endl;
    }
}

void listarVoluntarios() {
    cout << endl <<"--- VOLUNTARIOS ---"<<endl;
    for (int i = 0; i < totalVoluntarios; i++) {
        cout << "ID: " << voluntarios[i].id 
             << " | Nombre: " << voluntarios[i].nombre 
             << " | Contacto: " << voluntarios[i].contacto 
             << " | Habilidades: ";
        
        for (int j = 0; j < voluntarios[i].numHabilidades; j++) {
            cout << voluntarios[i].habilidades[j];
            if (j < voluntarios[i].numHabilidades - 1) cout << ", ";
        }
        cout << "\n";
    }
}

#endif
