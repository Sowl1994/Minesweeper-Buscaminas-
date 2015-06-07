/**
  * @file Tablero.h
  * @brief Fichero que crea el tablero y contiene sus operaciones basicas
  */
#include <iostream>
#include <cassert>
#include <string.h> 

using namespace std;

//Include guard para evitar errores por redefinicions
#ifndef TABLERO_H
#define TABLERO_H

struct Casilla{
	bool bomba,abierta,marcada;
};


class Tablero{
    int filas, columnas;
    Casilla *tabDinamico;

public:
/**
  * @brief Constructor de tableros
  *
  * @param f filas que tendra el tablero
  * @param c columna que tendra el tablero
  *
  */
    Tablero(int f, int c);

/**
  * @brief Constructor de copia
  *
  * @param t Tablero a copiar
  *
  */
    Tablero(const Tablero& t);
    
/**
  * @brief Destructor
  *
  */
    ~Tablero();

  /**
  * @brief Sobrecarga del operador de asignacion
  *
  * @param t tablero que analizaremos
  *
  */
    Tablero& operator=(const Tablero& t);

  /**
  * @brief Sobrecarga del operador parentesis
  *
  * @param fil fila donde se ubica la casilla
  * @param col columna donde se ubica la casilla
  *
  */
    const Casilla& operator()(int fil, int col) const;

  /**
  * @brief Sobrecarga del operador parentesis
  *
  * @param f fila donde se ubica la casilla
  * @param c columna donde se ubica la casilla
  *
  */
    Casilla& operator()(int &fila, int &col);

/**
  * @brief Metodo que nos permite saber el numero de filas del tablero
  *
  * @return Devuelve int correspondiente al numero de filas
  *
  */

int getFilas() const;

/**
  * @brief Metodo que nos permite saber el numero de columnas del tablero
  *
  * @return Devuelve int correspondiente al numero de columnas
  *
  */
int getColumnas() const;

/**
  * @brief Metodo que nos permite modificar el tablero
  *
  * @param f fila donde se ubica la casilla
  * @param c columna donde se ubica la casilla
  *
  */
void setTablero(int f, int c);

/**
  * @brief Modificamos el numero de filas del tablero
  *
  * @param fi fila donde se ubica la casilla
  *
  */
void setFilas(int fi);

/**
  * @brief Modificamos el numero de columnas del tablero
  *
  * @param co columna donde se ubica la casilla
  *
  */
void setColumnas(int co);

/**
  * @brief Metodo que nos permite saber el contenido de la casilla correspondiente a la fila y columna que pasamos por parametro
  *
  * @param fila fila donde se ubica la casilla
  * @param columna columna donde se ubica la casilla
  *
  * @return Devuelve Casilla correspondiente a la fila y columna
  *	@deprecated DEPRECATED
  */
Casilla getElemento(int fila, int col) const;

/**
  * @brief Nos permite modificar el valor de una casilla. 
  *
  * @param fila fila donde se ubica la casilla
  * @param columna columna donde se ubica la casilla
  * @param bomb bool que muestra la existencia de bomba en esa casilla
  * @param open bool que muestra si una casilla esta abierta o no
  * @param mark bool que muestra si una casilla esta marcada o no
  *	@deprecated DEPRECATED
  *
  */
void setElemento(int &fila, int &col, bool bomb, bool open, bool mark);



};

/**
  * @brief Sobrecarga del operador <<
  *
  * @param flujo flujo de datos que modificaremos
  * @param c casilla que analizaremos
  *
  */
ostream& operator << (ostream &flujo, const Casilla &c);

/**
  * @brief Sobrecarga del operador >>
  *
  * @param flujo flujo de datos que modificaremos
  * @param c casilla que analizaremos
  *
  */
istream& operator >> (istream &flujo, Casilla &c);

/**
  * @brief Sobrecarga del operador <<
  *
  * @param flujo flujo de datos que modificaremos
  * @param t tablero que analizaremos
  *
  */
ostream& operator << (ostream &flujo, const Tablero &tab);

/**
  * @brief Sobrecarga del operador >>
  *
  * @param flujo flujo de datos que modificaremos
  * @param t tablero que analizaremos
  *
  */
istream& operator >> (istream &flujo, Tablero &tab);

#endif
/* Fin Fichero: Tablero.h */