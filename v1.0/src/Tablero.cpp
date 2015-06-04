#include "../include/Tablero.h"
#include <iostream>
#include <cassert>

//Include guard para evitar errores por redefinicions
#ifndef TABLERO_H
#define TABLERO_H

class Tablero{
	private:
		int filas, columnas;
		Casilla objeto[20][20];
	public:
		Tablero(int f, int c){
			assert(f<20 && c<20);
			filas = f;
			columnas = c;
		}

		int getFilas() const{
			return filas;
		}

		int getColumnas() const{
			return columnas;
		}

		Casilla getElemento(int fila, int columna) const{
			return objeto[fila][columna];
		}

		void setElemento(int fila, int columna, bool bomb, bool open, bool mark){
			Casilla aCopiar = {bomb,open,mark};
			objeto[fila][columna] = aCopiar;
		}
};

#endif
