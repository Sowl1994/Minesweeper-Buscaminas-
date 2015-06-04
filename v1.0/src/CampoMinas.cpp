#include "../include/CampoMinas.h"
#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef CAMPOMINAS_H
#define CAMPOMINAS_H

class CampoMinas{
		Tablero t;
		int minasCercanas;

		int bombasAlrededor(int fila, int columna){
			minasCercanas = 0;

			if (t.getElemento(fila-1,columna).bomba && fila-1 >= 0)
				minasCercanas++;

			if (t.getElemento(fila-1,columna+1).bomba && fila-1 >= 0 && columna+1 <= getColumnas()-1)
				minasCercanas++;

			if (t.getElemento(fila,columna+1).bomba && columna+1 <= getColumnas()-1)
				minasCercanas++;

			if (t.getElemento(fila+1,columna+1).bomba && fila+1 <= getFilas()-1 && columna+1<= getColumnas()-1)
				minasCercanas++;

			if (t.getElemento(fila+1,columna).bomba && fila+1 <= getFilas()-1)
				minasCercanas++;

			if (t.getElemento(fila+1,columna-1).bomba && fila+1 <= getFilas()-1 && columna-1>=0)
				minasCercanas++;

			if (t.getElemento(fila,columna-1).bomba && columna-1>=0)
				minasCercanas++;
			
			if (t.getElemento(fila-1,columna-1).bomba && fila-1 >= 0 && columna-1>=0)
				minasCercanas++; 

			return minasCercanas;
	}


	public:
		CampoMinas(int f, int c,int nMinas):t(f,c){
			//Inicializamos el tablero con todo cerrado, sin bombas y sin marcar
			for (int i = 0; i < f; ++i){
				for (int j = 0; j < c; ++j){
					t.setElemento(i,j,false,false,false);
				}
			}



			//Genera minas en posiciones aleatorias
			for (int i = 0; i < nMinas; ++i){
				int filaAzar = Uniforme(0,getFilas()-1);
				int columnaAzar = Uniforme(0,getColumnas()-1);
				if (t.getElemento(filaAzar,columnaAzar).bomba)
					i--;
				else
					t.setElemento(filaAzar,columnaAzar,true,false,false);

			}


		}

		int Uniforme(int minimo, int maximo){
			double u01 = rand()/(RAND_MAX+1.0);
			return minimo+(maximo-minimo+1)*u01;
		}

		int getFilas() const{
			return t.getFilas();
		}

		int getColumnas() const{
			return t.getColumnas();
		}

		void checkExplosion(){
			for (int i = 0; i < getFilas(); ++i){
				for (int j = 0; j < getColumnas(); ++j){
					if (t.getElemento(i,j).bomba == true && t.getElemento(i,j).abierta == true)
						muestraTableroCompleto(true);
				}
			}
		}

		bool checkVictoria(){
			bool check = true;
			for (int i = 0; i < getFilas(); ++i){
				for (int j = 0; j < getColumnas(); ++j){
					//Bomba descubierta
					if (t.getElemento(i,j).bomba == true && t.getElemento(i,j).abierta == true)
						check = false;
					//Alguna casilla sin abrir sin bomba
					else if(t.getElemento(i,j).bomba == false && t.getElemento(i,j).abierta == false)
						check = false;
				}
			}
			return check;
		}

		void marcarCasilla(int fila, int columna){
			Casilla c = t.getElemento(fila,columna);

			if(!c.abierta){
				//Si la casilla esta marcada, le quita la marca y viceversa
				t.setElemento(fila, columna, c.bomba, c.abierta, !c.marcada);
			}
		}

		void abrirCasilla(int fila, int columna){
			//Comprobamos que el usuario no se salga del tablero con sus indicaciones
			if (fila < 0)
				fila = 0; 
			else if (fila > getFilas()-1)
				fila = getFilas()-1;
			else if (columna < 0)
				columna = 0;
			else if (columna > getColumnas()-1)
				columna = getColumnas()-1;

			Casilla c = t.getElemento(fila,columna);
			
			//Comprobamos que la casilla esta cerrada
			if(!c.abierta){

				//Si lo está, comprobamos que haya o no bombas alrededor
				if (bombasAlrededor(fila, columna) == 0){
					//Abrimos la casilla sin bombas alrededor
					t.setElemento(fila,columna, c.bomba, true, c.marcada);
					if(fila-1 >= 0)
						abrirCasilla(fila-1,columna);
					if(fila+1 <= getFilas()-1)
						abrirCasilla(fila+1,columna);
					if(columna-1 >= 0)
						abrirCasilla(fila,columna-1);
					if(columna+1 <= getFilas()-1)
						abrirCasilla(fila,columna+1);
				}else{
					//Tiene bombas cerca, asi que abrimos solamente la casilla en cuestion
					t.setElemento(fila,columna, c.bomba, true, c.marcada);
				}
			}
		}

		void PrettyPrint(){
			cout << "Mostrando tablero..." << endl;
			cout << "     ";
			for (int i = 0; i < getFilas(); ++i)
				cout << "| " << i << " |";
			cout << endl;

			for (int i = 0; i <= getFilas(); ++i)
				cout << "-----";
			cout << endl;

			for (int i = 0; i < getFilas(); ++i){
				cout << "| " << i << " |";
				for (int j = 0; j < getColumnas(); ++j){
					if(t.getElemento(i,j).abierta && !t.getElemento(i,j).marcada && !t.getElemento(i,j).bomba){
						if(bombasAlrededor(i,j) == 0)
							cout << "|   |";
						else
							cout << "| "<< bombasAlrededor(i,j) <<" |";
					}
					else if(!t.getElemento(i,j).abierta && t.getElemento(i,j).marcada)
						cout << "| ? |";
					else 
						cout << "| * |";
				}
				cout << endl;
			}

			for (int i = 0; i < getFilas()+1; ++i)
				cout << "-----";
			cout << endl;
		}

		void muestraTableroCompleto(bool partidaAcabada){

			if(!checkVictoria() && !partidaAcabada)
				cout << "No hagas trampa"<< endl;
			else{
				//Muestra el tablero completo
				cout << "Mostrando tablero completo..." << endl;
				cout << "     ";
				for (int i = 0; i < getColumnas(); ++i)
					cout << "| " << i << " |";
				cout << endl;

				for (int i = 0; i < getColumnas()+1; ++i)
					cout << "-----";
				cout << endl;

				for (int i = 0; i < getFilas(); ++i){
					cout << "| " << i << " |";
					for (int j = 0; j < getColumnas(); ++j){
						if (t.getElemento(i,j).bomba)
							cout << "| X |";
						else{
							if(bombasAlrededor(i,j) == 0)
								cout << "|   |";
							else
								cout << "| "<< bombasAlrededor(i,j) <<" |";
						}

					}
					cout << endl;

				}

				//Informa al user de su derrota y termina el programa
				cout << "Lo siento, has perdido" << endl;
				exit(0);
		}


	}
	
};
#endif