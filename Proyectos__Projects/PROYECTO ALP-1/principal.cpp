//#CODE BY V3LF
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "Ecuaciones.h"
#include "v3Colors.h"
using namespace std;

void titulo();
void menu();
void incluirEcuaciones();
void sacarEcuaciones();
void ecuacionesPresentes();
void raicesXposicion();
void raicesReales();
void raicesImaginarias();
void raicesLineales();
void menuPilas();
void calcularRaiz(datos n);

/*intancias*/
Ecuaciones cola,pilaReal,pilaImaginaria,pilaLineal;

int main(){
system("MODE 80,30");
system("TITLE PROYECTO ALP-1");
system("COLOR 0F");

char op[0];
op[0] = '\0';
do{
	menu();
	cin>>op[0];
	switch(op[0]){
		case '1': incluirEcuaciones(); break;
		case '2': sacarEcuaciones(); break;
		case '3': ecuacionesPresentes(); break;
		case '4': raicesXposicion(); break;
		case '5': menuPilas(); break;
		case '6':  exit(1); break;
		default: $red; cout<<"\n  Opcion no valida, digite una opcion valida...\n\n  ";$def;
		system("PAUSE");  break;
	}
}while(true);

system("PAUSE");
return 0;
}

void titulo(){
	cout<<"\n      _____  .____   __________          ____  "<<endl;
	cout<<"     /  _  \\ |    |  \\______   \\        /_   | "<<endl;
	cout<<"    /  /_\\  \\|    |   |     ___/  ______ |   | "<<endl;
	cout<<"   /    |    \\    |___|    |     /_____/ |   | "<<endl;
	cout<<"   \\____|__  /_______ \\____|             |___| "<<endl;
	cout<<"           \\/        \\/                        "<<endl;
	cout<<"  -----------------------------------------------"<<endl;
	$red; cout<<"    PROYECTO ALP-1 INFORMATICA 2DO SEMESTRE \n    AUTORES: LUIS VASQUEZ y DIXON FERNANDEZ  "<<endl;
	$def; cout<<"  -----------------------------------------------"<<endl;
}

void menu(){
	system("TITLE PROYECTO ALP-1 - MENU PRINCIPAL ");
	system("CLS");
	titulo();
	cout<<"\n  1. Incluir Ecuaciones\n";
	cout<<"\n  2. Sacar Ecuaciones\n";
	cout<<"\n  3. Consultar Ecuaciones Presentes\n";
	cout<<"\n  4. Raices de la Ecuacion segun posicion en cola\n";
	cout<<"\n  5. PILAS \32 \n";
	cout<<"\n  6. SALIR\n";
	cout<<"\n\n   Digite una opcion, y pulse enter: ";
}

void menuPilas(){
	char opc[0];
	opc[0] = '\0';
   do{
	system("TITLE PROYECTO ALP-1 - PILAS ");
	system("CLS");
	titulo();
	cout<<"\n  1. VER PILA DE RAICES REALES\n";
	cout<<"\n  2. VER PILA DE RAICES IMAGINARIAS\n";
	cout<<"\n  3. VER PILA DE ECUACIONES LINEALES\n";
	cout<<"\n  4. \33 Volver \n";
	cout<<"\n\n  Digite una Opcion y pulse enter: ";
	 cin>>opc;
	switch(opc[0]){
		case '1': raicesReales(); break;
		case '2': raicesImaginarias(); break;
		case '3': raicesLineales();break;
		case '4': main(); break;
		default:
			$red;cout<<"\n\a  Opcion no valida!, Digite una opcion valida...\n\n  ";$def;
			system("PAUSE"); break;
	}
  }while(true);
}

void incluirEcuaciones(){

	system("TITLE PROYECTO ALP-1 - INCLUIR ECUACIONES EN COLA ");
	system("CLS");
	cout<<"\n  [INCLUIR ECUACIONES] \n\n";
	if(cola.cola_llena() != true){
		datos n;
		$def; cout<<"\n  Digite el numero para el Primer Termino ax^2  : ";
		cin>>n.primer_termino;

		if(n.primer_termino == 0){
			$red; cout<<"\n\a el primer termino de la ecuacion no puede ser cero, no seria una ecuacion cuadratica... \n\n"; $def;
			system("PAUSE");
			incluirEcuaciones();
		}else{
			system("COLOR 08");
			$def;cout<<"\n  Digite el numero para el Segundo Termino bx  : ";
			cin>>n.segundo_termino;
			system("COLOR 08");
			$def;cout<<"\n  Digite el numero para el Tercer Termino c  : ";
			cin>>n.tercer_termino;
			system("COLOR 08");
			cola.meterCola(n);
			$green; cout<<"\n  Ecuacion ["<<n.primer_termino<<"x^2 + "<<n.segundo_termino<<"x + "<<n.tercer_termino<<"]  Agregada a cola Correctamente...\n\n"; $def;
		}
	}else cout<<"\n\a  la Cola de Ecuaciones está llena... \n No se puede Agregar mas por ahora\n";

	cout<<"\n\n  ";
	system("PAUSE");

}

void sacarEcuaciones(){

	system("TITLE PROYECTO ALP-1 - SACAR ECUACIONES DE COLA");
	system("CLS");
	datos x;
	if(cola.cola_vacia() != true ){
			x = cola.datoCola(cola.getInicio());
			calcularRaiz(x);
			cola.sacarCola();
			cout<<"\n\n  Ecuacion ["<< x.primer_termino<<"x^2 + "<<x.segundo_termino<<"x + "<<x.tercer_termino<<" ] ";
			cout<<" Sacada de cola, y puesta en pila Correctamente!.\n\n  ";
	}else cout<<"\n\a  LA COLA ESTA VACIA POR AHORA...\n\n  ";

	system("PAUSE");
}

void ecuacionesPresentes(){

	system("TITLE PROYECTO ALP-1 - ECUACIONES PRESENTES EN COLA ");
	system("CLS");
	datos presente;
	if( cola.cola_vacia() != true){
		$def; cout<<"\n  ECUACIONES PRESENTES EN COLA: \n\n";
		for(int j = cola.getInicio(); j<=cola.getFin(); j++){
			presente = cola.datoCola(j);
				$yellow; cout<<"  ["<<presente.primer_termino<<"x^2 + "<<presente.segundo_termino<<"x + "<<presente.tercer_termino<<" ] ";
				if(j < cola.getFin()){
					$def;
					cout<<",";
				}

				if(j==4 || j==7)cout<<"\n\n   ";

		};$def;
	}else cout<<"\n\a  No hay elementos Presentes en cola...\n";
	cout<<"\n\n  ";
	system("PAUSE");
}

void raicesXposicion(){

	system("TITLE PROYECTO ALP-1 - BUSCAR ECUACION X POSICION ");
	system("CLS");
	datos w;
	if(cola.cola_vacia() != true){
		$Dgreen;cout<<"\n  [BUSCAR ECUACION POR POSICION] \n";$def;
		cout<<"\n  Digite la posicion de cola a buscar: "; int pos=0; cin>>pos;
		if(pos==0)pos = cola.getInicio();

		if(cola.datoCola(pos).primer_termino == 0){
			$red;cout<<"\n  NO HAY ECUACIONES EN LA POSICION "<<pos<<" EN COLA\n\n";$def;
		}else{
			system("CLS");
			w = cola.datoCola(pos);
			cout<<"\n\n  ECUACION EN LA POSICION: "<<pos<<endl<<endl;$yellow;
			cout<<"  ["<<w.primer_termino<<"x^2 + "<<w.segundo_termino<<"x + "<<w.tercer_termino<<"]\n"<<endl;$def;
		}
	}else cout<<"\n\a  NO HAY ECUACIONES EN COLA POR AHORA...\n";

	cout<<"\n\n  "; system("PAUSE");
}

void calcularRaiz(datos n){

	system("CLS");
	double raizInterna = 0.0; //raiz interna = discriminante de la resolvente cuadratica
	double poli = (n.primer_termino + n.segundo_termino + n.tercer_termino);
	raizInterna = ( pow(n.segundo_termino,2) -(4* (n.primer_termino * n.tercer_termino)) );

	if(raizInterna < 0){
		n.primera_raiz = ((-n.segundo_termino + (sqrt(raizInterna))) /(2*n.primer_termino));
		n.segunda_raiz = ((-n.segundo_termino - (sqrt(raizInterna))) /(2*n.primer_termino));
		pilaImaginaria.meterCola(n);
		$red; cout<<"\n  [ECUACION IMAGINARIA]."<<endl; $def;
	}else{
		if(poli == 0){
			n.primera_raiz = ((-n.segundo_termino + (sqrt(raizInterna))) /(2*n.primer_termino));
			n.segunda_raiz = ((-n.segundo_termino - (sqrt(raizInterna))) /(2*n.primer_termino));
			pilaLineal.meterCola(n);
			$Lblue; cout<<"\n  [ECUACION LINEAL]."<<endl; $def;
		}else{
			n.primera_raiz = ((-n.segundo_termino + (sqrt(raizInterna))) /(2*n.primer_termino));
			n.segunda_raiz = ((-n.segundo_termino - (sqrt(raizInterna))) /(2*n.primer_termino));
			pilaReal.meterCola(n);
			$green; cout<<"\n  [ECUACION REAL]:"; $def;
		}
	}
}

/* PILAS DE TIPOS DE ECUACIONES */

void raicesReales(){

	system("TITLE PROYECTO ALP-1 - RAICES REALES ");
	system("CLS");
	if(pilaReal.cola_vacia() != true){
		$green; cout<<"\n  RAICES REALES: \n\n"; $def;
		datos w;
		for(int i = pilaReal.getFin(); i>-1; i--){
			w = pilaReal.datoCola(i);
			cout<<"  ["<<w.primer_termino<<"x^2 + "<<w.segundo_termino<<"x + "<<w.tercer_termino<<" ] \n\n";

			if(w.primera_raiz == w.segunda_raiz)
				cout<<"  RAIZ: x= "<<w.primera_raiz<<endl;
			else
				cout<<"  RAICES: x= "<<w.primera_raiz<<"  y  x= "<<w.segunda_raiz<<endl;

			cout<<endl;
		};

	}else cout<<"\n\a  NO HAY ECUACIONES REALES EN PILA...\n"<<endl;

	cout<<"\n\n  ";system("PAUSE");
}

void raicesImaginarias(){

	system("TITLE PROYECTO ALP-1 - RAICES IMAGINARIAS ");
	system("CLS");
		if(pilaImaginaria.cola_vacia() != true){
			$red; cout<<"\n  RAICES IMAGINARIAS EN PILA: \n";$gray;
			cout<<"\nEstas ecuaciones no poseen raices en los numeros reales...\n\n";$def;
			datos x;
			for(int j = pilaImaginaria.getFin(); j>-1; j--){
				x = pilaImaginaria.datoCola(j);
				cout<<"  ["<<x.primer_termino<<"x^2 + "<<x.segundo_termino<<"x + "<<x.tercer_termino<<" ] \n\n";
				float x1 = isnan(x.primera_raiz+0);
				float x2 = isnan(x.segunda_raiz+0);
				if(x1 == x2){
					$yellow; cout<<"  RAIZ IMAG APROXIMADA: x= "<<x1<<endl; $def;}
				else{
				$yellow;cout<<"  RAICES IMAG. APROXIMADAS: x= "<<x1<<"  y  x= "<<x2<<endl;}

				$def;cout<<endl;
			};
		}else cout<<"\n\a  NO HAY ECUACIONES IMAGINARIAS EN PILA...\n\n";
	cout<<"\n\n  "; system("PAUSE");
}

void raicesLineales(){

	system("TITLE PROYECTO ALP-1 - ECUACIONES LINEALES ");
	system("CLS");
		if(pilaLineal.cola_vacia() != true){
			$Lblue; cout<<"\n  [ECUACIONES LINEALES]: \n\n\n"; $def;
			datos y;
			for(int i = pilaLineal.getFin(); i>-1; i--){
				y = pilaLineal.datoCola(i);
				cout<<"  ["<<y.primer_termino<<"x^2 + "<<y.segundo_termino<<"x + "<<y.tercer_termino<<" ] \n\n";

				if(y.primera_raiz == y.segunda_raiz)
					cout<<"  RAIZ: x= "<<y.primera_raiz<<endl;
				else
					cout<<"  RAICES: x= "<<y.primera_raiz<<"  y  x= "<<y.segunda_raiz<<endl;

				cout<<endl;

			};

		}else cout<<"\n\a  NO HAY ECUACIONES LINEALES EN PILA...\n"<<endl;
	cout<<"\n\n  ";system("PAUSE");
}
