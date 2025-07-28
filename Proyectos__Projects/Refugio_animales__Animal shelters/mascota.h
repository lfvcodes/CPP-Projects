#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <string>

using namespace std;

const int MAX_MASCOTAS = 100;
const string ESTADOS_SALUD[] = {"Saludable", "En tratamiento", "Critico"};
const string ESTADOS_MASCOTA[] = {"Disponible", "Adoptada"};
const int NUM_ESTADOS_SALUD = 3;

struct Fecha {
    int dia;
    int mes;
    int anio;
    
    bool operator<(const Fecha& otra) const {
        if (anio != otra.anio) return anio < otra.anio;
        if (mes != otra.mes) return mes < otra.mes;
        return dia < otra.dia;
    }
    
    bool operator>(const Fecha& otra) const {
        if (anio != otra.anio) return anio > otra.anio;
        if (mes != otra.mes) return mes > otra.mes;
        return dia > otra.dia;
    }
};

struct Mascota {
    int id;
    string nombre;
    string especie;
    string raza;
    int edad;
    string estadoSalud;
    string estado;
    Fecha fechaIngreso;
    Fecha fechaAdopcion;
};

Mascota mascotas[MAX_MASCOTAS];
int totalMascotas = 0;

void registrarMascota() {
    if (totalMascotas >= MAX_MASCOTAS) {
        cout << "No hay espacio para mas mascotas."<<endl;
        return;
    }

    Mascota nueva;
    nueva.id = totalMascotas + 1;
    
    cout << endl <<"Registro de nueva mascota:"<<endl;
    cout << "Nombre: "; 
    cin.ignore();
    getline(cin, nueva.nombre);
    cout << "Especie: "; getline(cin, nueva.especie);
    cout << "Raza: "; getline(cin, nueva.raza);
    cout << "Edad: "; cin >> nueva.edad;
    
    cout << "Estado de salud (1-Saludable, 2-En tratamiento, 3-Critico): ";
    int opcionSalud;
    cin >> opcionSalud;
    nueva.estadoSalud = ESTADOS_SALUD[opcionSalud-1];
    
    nueva.estado = ESTADOS_MASCOTA[0];
    
    cout << "Fecha de ingreso (dd mm aaaa): ";
    cin >> nueva.fechaIngreso.dia >> nueva.fechaIngreso.mes >> nueva.fechaIngreso.anio;
    
    mascotas[totalMascotas] = nueva;
    totalMascotas++;
    cout <<endl << "Mascota registrada! ID: " << nueva.id << "\n";
}

void marcarComoAdoptada(int id) {
    for (int i = 0; i < totalMascotas; i++) {
        if (mascotas[i].id == id) {
            mascotas[i].estado = ESTADOS_MASCOTA[1];
            cout << "Fecha de adopcion (dd mm aaaa): ";
            cin >> mascotas[i].fechaAdopcion.dia >> mascotas[i].fechaAdopcion.mes >> mascotas[i].fechaAdopcion.anio;
            cout << mascotas[i].nombre << " ha sido marcado como adoptado.\n";
            return;
        }
    }
    cout << "No se encontro mascota con ID " << id << "\n";
}

void listarMascotasDisponibles() {
    cout << endl<<"--- MASCOTAS DISPONIBLES ---"<<endl;
    for (int i = 0; i < totalMascotas; i++) {
        if (mascotas[i].estado == ESTADOS_MASCOTA[0]) {
            cout << "ID: " << mascotas[i].id 
                 << " | Nombre: " << mascotas[i].nombre 
                 << " | Especie: " << mascotas[i].especie 
                 << " | Raza: " << mascotas[i].raza
                 << " | Edad: " << mascotas[i].edad
                 << " | Estado: " << mascotas[i].estadoSalud << "\n";
        }
    }
}

void listarMascotasAdoptadas() {
    cout << endl << "--- MASCOTAS ADOPTADAS ---"<<endl;
    for (int i = 0; i < totalMascotas; i++) {
        if (mascotas[i].estado == ESTADOS_MASCOTA[1]) {
            cout << "ID: " << mascotas[i].id 
                 << " | Nombre: " << mascotas[i].nombre 
                 << " | Especie: " << mascotas[i].especie 
                 << " | Fecha adopcion: " 
                 << mascotas[i].fechaAdopcion.dia << "/" 
                 << mascotas[i].fechaAdopcion.mes << "/" 
                 << mascotas[i].fechaAdopcion.anio << "\n";
        }
    }
}

void reportePorEspecie() {
    string especies[MAX_MASCOTAS];
    int conteo[MAX_MASCOTAS] = {0};
    int totalEspecies = 0;
    
    for (int i = 0; i < totalMascotas; i++) {
        bool encontrada = false;
        for (int j = 0; j < totalEspecies; j++) {
            if (especies[j] == mascotas[i].especie) {
                conteo[j]++;
                encontrada = true;
                break;
            }
        }
        if (!encontrada) {
            especies[totalEspecies] = mascotas[i].especie;
            conteo[totalEspecies] = 1;
            totalEspecies++;
        }
    }
    
    cout << endl<<"--- MASCOTAS POR ESPECIE ---"<<endl;
    for (int i = 0; i < totalEspecies; i++) {
        cout << especies[i] << ": " << conteo[i] << " mascotas"<<endl;
    }
}

void reporteAdopcionesPorRangoFechas() {
    Fecha inicio, fin;
    cout << endl << "--- REPORTE DE ADOPCIONES POR FECHA ---"<<endl;
    cout << "Fecha inicio (dd mm aaaa): ";
    cin >> inicio.dia >> inicio.mes >> inicio.anio;
    cout << "Fecha fin (dd mm aaaa): ";
    cin >> fin.dia >> fin.mes >> fin.anio;
    
    cout << endl << "Mascotas adoptadas entre " 
         << inicio.dia << "/" << inicio.mes << "/" << inicio.anio 
         << " y " << fin.dia << "/" << fin.mes << "/" << fin.anio << ":"<<endl;
    
    for (int i = 0; i < totalMascotas; i++) {
        if (mascotas[i].estado == ESTADOS_MASCOTA[1] && 
            mascotas[i].fechaAdopcion > inicio && 
            mascotas[i].fechaAdopcion < fin) {
            cout << "ID: " << mascotas[i].id 
                 << " | Nombre: " << mascotas[i].nombre 
                 << " | Fecha: " << mascotas[i].fechaAdopcion.dia << "/" 
                 << mascotas[i].fechaAdopcion.mes << "/" 
                 << mascotas[i].fechaAdopcion.anio << endl;
        }
    }
}

#endif
