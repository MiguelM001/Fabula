/*
Miguel Marquez
Caracas, 21-11-2019

Mi vision a la solucion al problema de la simulacion de la fabula de la tortuga y la liebre

*/
#include <iostream>
#include <random>
#include <ctime>
//#include <vector>
//#include <string>
#define META 70
#define PUERTA_DE_INICIO 1

using namespace std;

#ifndef PRUEBA_H
#define	PRUEBA_H

class Carrera{
	
	private:
		//vector< int > tortuga( 70 );

		//vector< int > liebre( 70 );

		int tortuga[META]={0};// inicializa todos los elementos en cero

		int liebre[META]={0};//  inicializa todos los elementos en cero

		int posicionTortuga;

		int posicionLiebre;

		int posicionActual;

		//int cimaResbalosa;

	public:

		Carrera();//constructor

		void retardar();
		
		int *moverIzquierda(int *, int, int);

		int *moverDerecha(int *, int, int);

		void moverTortuga(int *, unsigned int);

		void moverLiebre(int *, unsigned int);

		void imprimirPosiciones(int [], int []);

		int *getTortuga(){

			return this->tortuga;

		}//fin_funcion

		int *getLiebre(){
	
			return this->liebre;

		}//fin_funcion

		int getPosicionTortuga(){

			return this-> posicionTortuga;

		}//fin_funcion

		int getPosicionLiebre(){

			return this-> posicionLiebre;

		}//fin_funcion

		void setTortuga(int *tortuga){

			for(int i=0; i < META; i++)

				this->tortuga[i]= tortuga[i];

		}//fin_funcion

		void setLiebre(int *liebre){

			for(int i=0; i < META; i++)

				this->liebre[i]= liebre[i];

		}//fin_funcion

		//void ticReloj();
		
	
};//fin_clase

	Carrera::Carrera():posicionTortuga(0), posicionLiebre(0){
//los competidores empezaran la carrera en la posicion 1
		liebre[0]= PUERTA_DE_INICIO;

		tortuga[0]= PUERTA_DE_INICIO;

	}//Fin_constructor
//----------------------------------------------------------------------------------------------------------------------------------------
	int *Carrera::moverIzquierda(int *competidor, int decremento, int posicion){

		int i;

		for(i= (posicion ) ; i >= (posicion ) - decremento; i--){

			if(i == 0)
				competidor[0]= 1;

			if(i == -1){

				competidor[0]= 1;
				i= 0;
				break;

			}else
				competidor[i]= 0;
			
		}//fin_for

			Carrera::posicionActual= i;//retorna la posicion

			return competidor;

	}//fin_moverIzquierda
//----------------------------------------------------------------------------------------------------------------------------------------
	int *Carrera::moverDerecha(int *competidor, int incremento, int posicion){

		int i;

		for(i= (posicion ) ; i <= (posicion ) + incremento; i++){

				
			if(i == (META))

				break;
			else
				competidor[i]= i+1;
			
		}//fin_for

			Carrera::posicionActual= i;//retorna la posicion

			return competidor;

	}//fin_moverIzquierda
//----------------------------------------------------------------------------------------------------------------------------------------
	void Carrera::moverTortuga(int *tortuga, unsigned int i){
		
/*
		default_random_engine motor( static_cast<unsigned int>( time(0) ) );
		uniform_int_distribution<unsigned int> intAleatorio( 1, 11 ); //entero aleatorio i rango del 1 al 11

		intAleatorio( motor );

		unsigned int i= intAleatorio( motor );
*/

		//cout << "numero aleatorio: " << i << endl;

		cout << "<T> Movimiento de la Tortuga: ";

		if(       i >= 1 && i <= 5 ){//paso pesado rapido 3 posiciones a la derecha 50%

			cout << "Paso Pesado Rapido (+3)" << endl;

			Carrera::setTortuga(Carrera::moverDerecha(tortuga, 3, posicionTortuga));
			Carrera::posicionTortuga= Carrera::posicionActual;

		}else if( i >= 6 && i <= 7 ){//resbalon  6 posiciones a la izquierda 20%

			cout << "Resbalon (-6)" << endl;

			Carrera::setTortuga(Carrera::moverIzquierda(tortuga, 6, posicionTortuga));
			Carrera::posicionTortuga= Carrera::posicionActual;
		
		}else if ( i >= 8 && i <= 10 ){//paso pesado lento 1 posicion a la derecha 30%

			cout << "Paso Pesado Lento (+1)" << endl;

			Carrera::setTortuga(Carrera::moverDerecha(tortuga, 1, posicionTortuga));
			Carrera::posicionTortuga= Carrera::posicionActual;

		}//end_if

	}//fin_funcion
//----------------------------------------------------------------------------------------------------------------------------------------
	void Carrera::moverLiebre(int *liebre, unsigned int i){

		//cout << "numero aleatorio: " << i << endl;

		cout << "<H> Movimiento de la Liebre: " ;

		if(       i >= 1 && i <= 2 ){// sin movimiento

			cout << "Dormir (0)" << endl;

		}else if( i >= 3 && i <= 4 ){//

			cout << "Gran Salto (+9)" << endl;

			Carrera::setLiebre(Carrera::moverDerecha(liebre, 9, posicionLiebre));
			Carrera::posicionLiebre= Carrera::posicionActual;
		
		}else if( i == 5 ){//

			cout << "Gran Resbalon (-12)" << endl;

			Carrera::setLiebre(Carrera::moverIzquierda(liebre, 12, posicionLiebre));
			Carrera::posicionLiebre= Carrera::posicionActual;

		}else if( i >= 6 && i <= 8 ){//

			cout << "Pequenio Salto (+1)" << endl;

			Carrera::setLiebre(Carrera::moverDerecha(liebre, 1, posicionLiebre));
			Carrera::posicionLiebre= Carrera::posicionActual;

		}else if( i >= 9 && i <= 10  ){//

			cout << "Pequenio Resbalon (-2)" << endl;

			Carrera::setLiebre(Carrera::moverIzquierda(liebre, 2, posicionLiebre));
			Carrera::posicionLiebre= Carrera::posicionActual;

		}//end_if

	}//fin_funcion
//----------------------------------------------------------------------------------------------------------------------------------------
	void  Carrera::imprimirPosiciones(int tortuga[], int liebre[]){

		cout << endl;
		cout << "T: ";

		for(int i=0; i < META; i++ ){

			if( tortuga[i] != 0)

				cout << "*";

			else
				cout << "-";


		}//fin_for

		cout << " " << tortuga[ Carrera::getPosicionTortuga() == 0 ? Carrera::getPosicionTortuga() : Carrera::getPosicionTortuga() -1 ];

		cout << endl;
		cout << endl;

		cout << "H: ";

		for(int i=0; i < META; i++ ){

			if( liebre[i] != 0)

				cout << "*";

			else
				cout << "-";

		}//fin_for

		
		cout << " " << liebre[ Carrera::getPosicionLiebre() == 0 ? Carrera::getPosicionLiebre() : Carrera::getPosicionLiebre() -1 ];

		cout << endl;
		cout << endl;

	}//fin_funcion

//----------------------------------------------------------------------------------------------------------------------------------------

	void Carrera::retardar(){

		for(int i= 1; i <= 10000000; i++){

			cout  << '\0';//el caracter vacio
		
		}

	}//fin_funcion

#endif	/* PRUEBA_H */
