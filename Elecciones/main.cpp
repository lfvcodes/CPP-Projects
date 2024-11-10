#include <iostream>
#include <string>
#include <windows.h>
#include "Cola.h"
#include "Lista.h"
using namespace std;

ListaMesas mesas;

void menu();
void verVotantesEnMesa();
void agregarVotanteEnColaDeMesa();

int main() {

	menu();
    return 0;
}

void menu(){
	int op;
	do{
		system("cls"); //limpiar pantalla
		cout << " 1- Agregar Mesa a la Lista" << endl;
		cout << " 2- Agregar votante a Mesa" << endl;
		cout << " 3- Ver votantes en Mesas" << endl;
		cout << " 4- Salir" << endl;
		cin >>op;
		system("cls");
		switch(op) {
			case 1: mesas.agregarMesa(); break;
			case 2: agregarVotanteEnColaDeMesa();break;
			case 3: mesas.mostrarMesasRegistradas(); break;
		}
		system("pause");
	}while(op != 4);
}

void agregarVotanteEnColaDeMesa(){
	int nMesa = 0; int cedula = 0; string nombre = "";
	cout<<" Digite el Numero de Mesa a Votar: "; cin>>nMesa; cout<<endl;
	NodoMesa* mesaConsultada = mesas.obtenerMesa(nMesa);
	cout<<" Digite el Numero de Cedula del Estudiante a Votar: "; cin>>cedula; cout<<endl;
	cout<<" Digite el Nombre del Estudiante a Votar: "; cin>>nombre; cout<<endl;
	mesaConsultada->votantes.agregarVotante(cedula,nombre);
	int opcionVoto;
	cout<<" Digite el tipo de Estatus: 1) Solo Voto \t 2)Aun NO Vota \t 3) Asistido"<<endl;
	cin>>opcionVoto;
	string voto;
	switch(opcionVoto) {
		case 1: voto = "Solo Voto"; break;
		case 2: voto = "Aun NO Vota"; break;
		case 3: voto = "Asistido"; break;
	}

	while(mesaConsultada->votantes.getFrente() != nullptr){
		NodoVotante* actual = mesaConsultada->votantes.getFrente();
		if(actual->datos.cedula == cedula){
			actual->datos.votos->push(voto);
		}
		actual = actual->siguiente;
	}
	cout<<" Votante Agregado Correctamente a Cola de Mesa: "<<nMesa<<endl;
}

void verVotantesEnMesa(){
	// Obtener una mesa específica y consultar su contenido
	int numeroDeMesa;
	cout<<" Digite el numero de mesa a consultar: ";
	cin>>numeroDeMesa;
	NodoMesa* mesaConsultada = mesas.obtenerMesa(numeroDeMesa);

	if (mesaConsultada != nullptr) {
		cout << "Contenido de la Mesa " << numeroDeMesa << ":" << std::endl;
		mesaConsultada->votantes.mostrarVotantesEnCola(); // Mostrar los votantes de la mesa consultada
	} else {
		cout << "La mesa especificada no existe." << std::endl;
	}
}
