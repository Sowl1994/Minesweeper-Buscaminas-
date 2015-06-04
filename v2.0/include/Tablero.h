/**
  * @file Tablero.h
  * @brief Fichero que crea el tablero y contiene sus operaciones basicas
  */

struct Casilla{
	bool bomba,abierta,marcada;
};

/**
  * @brief Metodo que nos permite saber el numero de filas del tablero
  *
  * @return Devuelve int correspondiente al numero de filas
  *
  */

int getFilas();

/**
  * @brief Metodo que nos permite saber el numero de columnas del tablero
  *
  * @return Devuelve int correspondiente al numero de columnas
  *
  */
int getColumnas();

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
  *	@alert DEPRECATED
  */
Casilla getElemento(int fila, int col);

/**
  * @brief Nos permite modificar el valor de una casilla. 
  *
  * @param fila fila donde se ubica la casilla
  * @param columna columna donde se ubica la casilla
  * @param bomb bool que muestra la existencia de bomba en esa casilla
  * @param open bool que muestra si una casilla esta abierta o no
  * @param mark bool que muestra si una casilla esta marcada o no
  *	@alert DEPRECATED
  *
  */
void setElemento(int &fila, int &col, bool bomb, bool open, bool mark);

/* Fin Fichero: Tablero.h */