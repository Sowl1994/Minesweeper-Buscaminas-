#include "../include/Tablero.h"
#include <iostream>

using namespace std;

Tablero::Tablero(int f, int c){
	filas = f;
	columnas = c;
	tabDinamico = new Casilla [f*c];
}

Tablero::~Tablero(){
	delete[] tabDinamico;
}

int Tablero::getFilas() const{
	return filas;
}

void Tablero::setTablero(int f, int c){
	tabDinamico = new Casilla [f*c];
}

void Tablero::setFilas(int fi) {
	filas = fi;
}

void Tablero::setColumnas(int co){
	columnas = co;
}

int Tablero::getColumnas() const{
	return columnas;
}

//Deprecated
Casilla Tablero::getElemento(int fila, int col) const{
	return tabDinamico[(fila*columnas)+col];
}

//Deprecated
void Tablero::setElemento(int &fila, int &col, bool bomb, bool open, bool mark){
	Casilla aCopiar = {bomb,open,mark};
	tabDinamico[(fila*columnas)+col] = aCopiar;	
}

const Casilla& Tablero::operator()(int fila, int col)const{
	return tabDinamico[(fila*columnas)+col];
}

Casilla& Tablero::operator()(int &fila, int &col){
	return tabDinamico[(fila*columnas)+col];
}

ostream& operator << (ostream &fs,const Casilla &c){

	if(c.bomba){ fs << '1';}else{ fs << '0';};
	if(c.abierta){ fs << '1';}else{ fs << '0';};
	if(c.marcada){ fs << '1';}else{ fs << '0';};
	return fs;
}

ostream& operator << (ostream &fs, const Tablero &t){

	fs << t.getFilas() << " " << t.getColumnas() << endl;
			
	for (int i = 0; i < t.getFilas(); ++i){
		for (int j = 0; j < t.getColumnas(); ++j){
			fs << t(i,j) << " ";
		}
		fs << endl;
	}
	return fs;
}

//le he quitado el const antes de casilla
istream& operator >> (istream &is, Casilla &c){ 
	char bomba,abierta,marcada;
	is >> bomba >> abierta >> marcada;

	if(bomba == '1'){c.bomba = true;}else{ c.bomba = false;};
	if(abierta == '1'){c.abierta = true;}else{c.abierta = false;};
	if(marcada == '1'){c.marcada = true;}else{ c.marcada = false;};
	return is;
}

istream& operator >> (istream &is, Tablero &t){
			
	int filas, columnas;
	char cadenaMagica[128];
	is.getline(cadenaMagica,128);
	is >> filas;
	is >> columnas;
	t.setColumnas(columnas);
	t.setFilas(filas);
	t.setTablero(filas,columnas);
	char cadenaCorrecta[] = "#MP-BUSCAMINAS-V1";

	if(strcmp(cadenaCorrecta,cadenaMagica) == 0)
		for (int i = 0; i < t.getFilas(); ++i)
			for (int j = 0; j < t.getColumnas(); ++j)
				is >> t(i,j);
	return is;
}
