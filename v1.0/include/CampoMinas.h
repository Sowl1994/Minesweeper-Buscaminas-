/**
  * @file CampoMinas.h
  * @brief Fichero cabecera para CampoMinas.cpp
  *
  * Gestiona el buscaminas y tiene los métodos necesarios para jugar
  *
  */
#include "../src/Tablero.cpp"

/**
  * @brief Consulta el numero de bombas que hay alrededor de una casilla
  *
  * @param fila int que es la fila de la casilla a analizar
  * @param columna int que es la columna de la casilla a analizar
  *
  * @return Devuelve el numero de bombas de la imagen en el archivo
  *
  */
int bombasAlrededor(int fila, int columna);

/**
  * @brief Genera numeros aleatorios en un intervalo
  *
  * @param minimo parte minima del intervalo
  * @param maximo parte maxima del intervalo
  * @return Devuelve int aleatorio
  */
int Uniforme(int minimo, int maximo);

/**
  * @brief Metodo que nos permite saber el numero de filas del tablero
  *
  * @return Devuelve int correspondiente al numero de filas
  *
  */
int getFilas() ;

/**
  * @brief Metodo que nos permite saber el numero de columnas del tablero
  *
  * @return Devuelve int correspondiente al numero de filas
  *
  */
int getColumnas();

/**
  * @brief Comprueba si una se ha producido una explosion y por tanto acaba la partida
  *
  */
void checkExplosion();

/**
  * @brief Comprueba si todas las casillas estan abiertas, lo que significa que el jugador ha ganado
  *
  */
bool checkVictoria();

/**
  * @brief Marca la casilla para hacer ver que la posibilidad de bomba es alta
  *
  * @param fila int que es la fila de la casilla a analizar
  * @param columna int que es la columna de la casilla a analizar
  *
  */
void marcarCasilla(int fila, int columna);

/**
  * @brief Abre la casilla. Si hay una bomba alrededor solo abre esa, en cambio, si no se produce una apertura recursiva
  *
  * @param fila int que es la fila de la casilla a analizar
  * @param columna int que es la columna de la casilla a analizar
  *
  */
void abrirCasilla(int fila, int columna);

/**
  * @brief Muestra el tablero por consola
  *
  */
void PrettyPrint();

/**
  * @brief Muestra el tablero resulto por pantalla, lo que significa que el jugador ha perdido
  *
  * @param partidaAcabada indica si la partida ha acabado
  *
  */
void muestraTableroCompleto(bool partidaAcabada);
  
  /* Fin Fichero: Tablero.h */