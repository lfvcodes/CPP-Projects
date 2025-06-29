/*CODE BY V3LF*/
#include "Ecuaciones.h"

Ecuaciones::Ecuaciones() {

	inicio = -1;
	fin = -1;
	datos w;
	w.primera_raiz = 0; w.segunda_raiz=0;
	w.primer_termino=0; w.segundo_termino=0; w.tercer_termino=0;
	for(int x = 0; x<20; x++){
		ecuacion[x] = w;
	};
}

bool Ecuaciones::cola_llena(){
	if(this->fin == 19)return true;
	return false;
}

bool Ecuaciones::cola_vacia(){
	if( (this->inicio > this->fin) || (this->inicio == -1))return true;
	return false;
}

void Ecuaciones::meterCola(datos x){
	if(!this->cola_llena()){
		if(inicio == -1)inicio=0;
		fin++;
		ecuacion[fin]=x;
	}
}

datos Ecuaciones::sacarCola(){
	datos x;
	if(!this->cola_vacia()){
		x = ecuacion[inicio];
		inicio++;
	}
	return x;
}

datos Ecuaciones::datoCola(int posicion){
	datos z;
	z = ecuacion[posicion];
	return z;
}

int Ecuaciones::getInicio(){return inicio;}
int Ecuaciones::getFin(){return fin;}
