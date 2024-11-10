/*CODE BY V3LF*/
#ifndef ECUACIONES_H_
#define ECUACIONES_H_

extern double raizInterna;

struct datos{
	double primer_termino;
	double segundo_termino;
	double tercer_termino;
	double primera_raiz;
	double segunda_raiz;
};

class Ecuaciones {

private:
	int inicio,fin;
	datos ecuacion[20];

public:
	Ecuaciones();
	bool cola_llena();
	bool cola_vacia();
	void meterCola(datos x);
	datos sacarCola();
	datos datoCola(int posicion);
	int getInicio(); int getFin();
};

#endif /* ECUACIONES_H_ */
