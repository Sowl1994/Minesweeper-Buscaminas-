/**
  * @file BuscaMinas.cpp
  * @brief Main del buscaminas
  *
  */

#include <iostream>
#include <cstdlib>
#include "CampoMinas.cpp"
using namespace std;

/**
  * @brief Realiza el movimiento. LLeva la gestion de las acciones para jugar
  *
  * @param campo objeto de tipo CampoMinas 
  * @param f fila donde realizaremos la accion
  * @param c columna donde realizaremos la accion
  *
  */

void hacerMovimiento(CampoMinas &campo, int &f, int &c){
	char accion;
	cout << "Dime accion y posicion: \e[36m";	
	cin >> accion >> f >> c;
	cout << "\e[39m";
	if(cin.fail()){
		cout << "Accion no valida, repita sentencia..." << endl;
		cin.clear();
	}else{
		if (accion == 'a')
			campo.abrirCasilla(f,c);
		else if(accion == 'm')
			campo.marcarCasilla(f,c);
		else
			cout << "Accion no valida, repita sentencia (a o m)..." << endl;
	
		campo.checkExplosion();
	}
}

/**
  * @brief Main
  *
  */

int main(){
	srand (time(0));

	int f, c, nM;
	cout << "Dime el tamanio del tablero(filas y columnas): ";
	cin >> f >> c;
	if(cin.fail() || f <= 0 || c <= 0 || f > 20 || c > 20 ){
		cout << "numero de filas o columnas erroneo" << endl;
	}else{
	cout << "Dime el numero de minas: ";
	cin >> nM;

	//Controlar numero de minas
	if(nM < 5)
		nM = 5;
	else if(nM > (f*c)/2)
		nM = (f*c)/2;

	CampoMinas campo(f,c,nM);
	campo.PrettyPrint();
	while(!campo.checkVictoria()){
		hacerMovimiento(campo, f, c);
		campo.PrettyPrint();
	}
	cout << "HAS GANADO LA PARTIDA!" << endl;
	}
}
  /* Fin Fichero: BuscaMinas.cpp */