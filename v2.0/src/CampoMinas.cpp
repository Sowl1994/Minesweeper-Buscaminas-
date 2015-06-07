#include "../include/CampoMinas.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;

int CampoMinas::bombasAlrededor(int fila, int columna){
	minasCercanas = 0;

	if (fila-1 >= 0 && t.getElemento(fila-1,columna).bomba )
		minasCercanas++;

	if (fila-1 >= 0 && columna+1 <= getColumnas()-1 && t.getElemento(fila-1,columna+1).bomba )
		minasCercanas++;

	if (columna+1 <= getColumnas()-1 && t.getElemento(fila,columna+1).bomba )
		minasCercanas++;

	if (fila+1 <= getFilas()-1 && columna+1<= getColumnas()-1 && t.getElemento(fila+1,columna+1).bomba )
		minasCercanas++;

	if ( fila+1 <= getFilas()-1 && t.getElemento(fila+1,columna).bomba)
		minasCercanas++;

	if (fila+1 <= getFilas()-1 && columna-1>=0 && t.getElemento(fila+1,columna-1).bomba )
		minasCercanas++;

	if ( columna-1>=0 && t.getElemento(fila,columna-1).bomba)
		minasCercanas++;
			
	if (fila-1 >= 0 && columna-1>=0 && t.getElemento(fila-1,columna-1).bomba )
		minasCercanas++; 

	return minasCercanas;
}


	
CampoMinas::CampoMinas(int f, int c,int nMinas):t(f,c){
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

int CampoMinas::Uniforme(int minimo, int maximo){
	double u01 = rand()/(RAND_MAX+1.0);
	return minimo+(maximo-minimo+1)*u01;
}

int CampoMinas::getFilas() const{
	return t.getFilas();
}

int CampoMinas::getColumnas() const{
	return t.getColumnas();
}

bool CampoMinas::checkExplosion(int fila, int columna){
	bool explosion = false;
	if (t.getElemento(fila,columna).bomba == true && t.getElemento(fila,columna).abierta == true)
		explosion = true;	
	return explosion;
}

bool CampoMinas::checkVictoria(){
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

bool CampoMinas::marcarCasilla(int fila, int columna){
	bool success = false;
	if(fila < getFilas() && fila >= 0 && columna < getColumnas() && columna >= 0){
		Casilla c = t(fila,columna);
		//Si una casilla esta abierta no se abre
		if(!c.abierta){
			if(c.marcada) c.marcada = false; else c.marcada = true;
			//Si la casilla esta marcada, le quita la marca y viceversa
			t(fila, columna) = c; 
			success = true;
		}
	}
	return success;
}

void CampoMinas::Iniciar(CeldaPosicion *&puntero){
	puntero = new CeldaPosicion;
	puntero->fila = 0;
	puntero->columna = 0;
	puntero->next = 0;
}

void CampoMinas::sacar(CeldaPosicion *&puntero){
	//Borramos el puntero a sacar
	if(size(puntero) > 0){
		delete puntero->next;
		//Modificamos el puntero que apuntaba al objeto borrado para que apunte al siguiente del borrado
		//Si A apunta a B y B a C, hacemos que A apunte a C
		puntero->next = (puntero -> next)->next;
	}
}

void CampoMinas::insertar(CeldaPosicion *&puntero, int fila, int columna){
	//Si nuestra lista esta vacia, introducimos un nuevo objeto con el puntero al siguiente nulo, ya que sera el unico que haya
	if(size(puntero) == 0){
		CeldaPosicion *obj = new CeldaPosicion;
		obj->fila = fila;
		obj->columna = columna;
		obj->next = 0;
		puntero -> next = obj;
	}

	//Si la lista tiene algun componente, lo añadimos al principio de la lista
	else{
				
		CeldaPosicion *objNuevo = new CeldaPosicion;
		objNuevo->fila = fila;
		objNuevo->columna = columna;
		objNuevo->next = puntero->next;
		puntero->next = objNuevo;
	}
}

void CampoMinas::listar(CeldaPosicion *&puntero){
	CeldaPosicion *a = new CeldaPosicion;
	a->next = puntero->next;
	for(int i = 0; i < size(puntero); ++i){
		cout << (a->next)->fila << " " << (a->next)->columna << endl;
		a->next = (a->next)->next;
	}
	cout << endl;
}

int CampoMinas::size(CeldaPosicion *&puntero){
	int tam = 0;
	CeldaPosicion *a = new CeldaPosicion;
	a->next = puntero->next;
	while(a->next != 0){
		tam++;
		a->next = (a->next)->next;
	}
	return tam;
			
}

void CampoMinas::abrirCasilla(int fila, int columna){
	Casilla c = t.getElemento(fila,columna);

	if(!c.abierta && !c.marcada ){

		//Basicamente esto inicializa las celdas enlazadas y coge la primera casilla.
		CeldaPosicion *Pend;
		Iniciar(Pend);
		insertar(Pend,fila,columna);

				
		while(size(Pend) > 0){
			int cFila = (Pend->next)->fila;
			int cColumna = (Pend->next)->columna;
			Casilla c = t.getElemento(cFila,cColumna);				
			sacar(Pend);

			//si hay bombas al rededor simplemente se abre y se saca de la lista enlazada
			if(bombasAlrededor(cFila,cColumna) > 0 && bombasAlrededor(cFila,cColumna) < 9 ){			
				if(!c.abierta && !c.marcada)
					t.setElemento(cFila,cColumna, c.bomba, true, c.marcada);
			}else{
				if(!c.abierta && !c.marcada){
					t.setElemento(cFila,cColumna, c.bomba, true, c.marcada);
					for (int i = -1; i <= 1; ++i){
						for (int j = -1; j <= 1; ++j){
							if((i == 0 && j == 0) || cFila+i < 0 || cColumna+j < 0 || cFila+i >= getFilas() || cColumna+j >= getColumnas()){
								//Evitamos que introduzca en la lista elementos repetidos o que esten fuera del tablero
							}else{
								if(!c.abierta && !c.marcada)
									insertar(Pend,cFila+i,cColumna+j);
							}
						}
					}
				}
			}
		}
	}
}


void CampoMinas::PrettyPrint(ostream &a = cout){
	a << "Mostrando tablero..." << endl;
	a << "     ";
	for (int i = 0; i < getColumnas(); ++i)
		if( i < 10) {a << "| " << i << " |";}else{ a << " " << i << " |";};
	a << endl;

	for (int i = 0; i < getColumnas()+1; ++i)
		a << "-----";
	a << endl;

	for (int i = 0; i < getFilas(); ++i){
		if( i < 10) {a << "| " << i << " |";}else{ a << "|" << i << " |";};
			for (int j = 0; j < getColumnas(); ++j){
				if(t.getElemento(i,j).abierta && !t.getElemento(i,j).marcada && !t.getElemento(i,j).bomba){
							
					if(bombasAlrededor(i,j) == 0){
						cout << "|   |";
					}else{
						int nB = bombasAlrededor(i,j);
						if(nB == 1){ cout << "| \e[36m"<< bombasAlrededor(i,j) <<"\e[0m |"; };
						if(nB == 2){ cout << "| \e[92m"<< bombasAlrededor(i,j) <<"\e[0m |"; };
						if(nB > 2){ cout << "| \e[91m"<< bombasAlrededor(i,j) <<"\e[0m |"; };

					}

				}else if(!t.getElemento(i,j).abierta && t.getElemento(i,j).marcada)
					a << "| \e[91m?\e[0m |";
				else 
					a << "| * |";
			}
			a << endl;
		}
		for (int i = 0; i < getColumnas()+1; ++i)
			a << "-----";
		a << endl;
}



void CampoMinas::muestraTableroCompleto(bool partidaAcabada){

	if(!checkVictoria() && !partidaAcabada)
		cout << "No hagas trampa"<< endl;
	else{
		//Muestra el tablero completo
		cout << "Mostrando tablero completo..." << endl;
		cout << "     ";
		for (int i = 0; i < getColumnas(); ++i)
			if( i < 10) {cout << "| " << i << " |";}else{ cout << " " << i << " |";};
		cout << endl;
		for (int i = 0; i < getColumnas()+1; ++i)
			cout << "-----";
		cout << endl;

		for (int i = 0; i < getFilas(); ++i){
			if( i < 10) {cout << "| " << i << " |";}else{ cout << "|" << i << " |";};
			for (int j = 0; j < getColumnas(); ++j){
				if (t.getElemento(i,j).bomba)
					cout << "| \e[93mX\e[0m |";
				else{
					if(bombasAlrededor(i,j) == 0){
						cout << "|   |";
					}else{
						int nB = bombasAlrededor(i,j);
						if(nB == 1){ cout << "| \e[36m"<< bombasAlrededor(i,j) <<"\e[0m |"; };
						if(nB == 2){ cout << "| \e[92m"<< bombasAlrededor(i,j) <<"\e[0m |"; };
						if(nB > 2){ cout << "| \e[91m"<< bombasAlrededor(i,j) <<"\e[0m |"; };

					}
				}
			}
			cout << endl;

		}
		//Informa al user de su derrota y termina el programa
		cout << endl << "//-------------//" << endl;
		cout << "Lo siento, has perdido" << endl;
		cout << "//-------------//" << endl << endl;

		exit(0);
	}
}

bool CampoMinas::escribir(char nombre[]){ 
	bool success = false;
	ofstream fs(nombre);
	if (fs){
		fs << "#MP-BUSCAMINAS-V1" << endl;
		fs << t;
		success = true;
	}
	fs.close();
	return success;
}

bool CampoMinas::leer(char archivo[]){
	bool success = false;
	ifstream is(archivo);
	if (is){
		is >> t;
		success = true;
	}
	is.close();
	return success;
}
