//DEBUG

#include <iostream>
#include "carrera.h"

int main(){


	Carrera estaCarrera;

	int *tortuga= estaCarrera.getTortuga();
	int *liebre= estaCarrera.getLiebre();

	default_random_engine motor( static_cast<unsigned int>( time( 0 ) ) );
	uniform_int_distribution<unsigned int> intAleatorio( 1, 10 ); //entero aleatorio i rango del 1 al 11

	intAleatorio( motor );

	//cout <<  "META:" << META << endl;

	cout << endl << "SIMULACION DE LA CARRERA DE LA TORTUGA Y LA LIEBRE:" << endl;
	cout << endl;

	cout << "<T> Movimiento de la Tortuga: posicion 1" << endl;
	cout << "<H> Movimiento de la Liebre: posicion 1" << endl;

	estaCarrera.imprimirPosiciones(estaCarrera.getTortuga(), estaCarrera.getLiebre());

	estaCarrera.retardar();
	estaCarrera.retardar();
	estaCarrera.retardar();

	
	cout << endl;

	cout << "PUM !!!" << endl;
	cout << "Y ARRANCAN !!!" << endl;
	cout << endl;
	cout << endl;

	estaCarrera.retardar();
	estaCarrera.retardar();

	//carrera

	do{
		
		cout << endl << "SIMULACION DE LA CARRERA DE LA TORTUGA Y LA LIEBRE:" << endl;
		cout << endl;
	
		estaCarrera.moverTortuga(tortuga, intAleatorio( motor ));
		tortuga= estaCarrera.getTortuga();

		estaCarrera.moverLiebre(liebre, intAleatorio( motor ));
		liebre= estaCarrera.getLiebre();

		if(estaCarrera.getPosicionTortuga() ==  estaCarrera.getPosicionLiebre()){

			cout << endl << "OUCH!! la tortuga muerde a la liebre!!!" << endl;
			estaCarrera.retardar();
			estaCarrera.retardar();
			estaCarrera.retardar();

		}//end_if

		estaCarrera.imprimirPosiciones(estaCarrera.getTortuga(), estaCarrera.getLiebre());

		//retardo de tiempo en la consola

		estaCarrera.retardar();


	}while( estaCarrera.getPosicionTortuga() != META && estaCarrera.getPosicionLiebre() != META );

	if(estaCarrera.getPosicionTortuga() == META){

		cout << endl << "LA TORTUGA GANA!!! YAY!!!" << endl;
		cout << endl;

	}else if(estaCarrera.getPosicionLiebre() == META){

		cout << endl << "la liebre gana. Que mal." << endl;
		cout << endl;

	}
		

	

}//end_main
