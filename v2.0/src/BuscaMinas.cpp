/**
  * @file BuscaMinas.cpp
  * @brief Main del buscaminas (Segunda version)
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
  *
  */
void hacerMovimiento(CampoMinas &campo){
	char accion[100], ruta[100];
	int f,c;

	cout << "Dime accion y posicion: ";	
	cin >> accion;


	if ((accion[0] == 'a' && accion[1] == '\0')|| (accion[0] == 'A' && accion[1] == '\0') || strcmp(accion,"ABRIR") == 0 || strcmp(accion,"abrir") == 0){
		cin >> f >> c;
		if(cin.fail()){
			cout << "Accion no valida, repita sentencia..." << endl;
			cin.clear();
		}else{
			if(f < campo.getFilas() && f >= 0 && c < campo.getColumnas() && c >= 0){
				campo.abrirCasilla(f,c);
				if(campo.checkExplosion(f,c))
					campo.muestraTableroCompleto(true);
			
			}else
				cout << "No es posible abrir una casilla fuera de rango" << endl;		
		}
	}
	else if((accion[0] == 'm' && accion[1] == '\0') || (accion[0] == 'M' && accion[1] == '\0') || strcmp(accion,"MARCAR") == 0 ||strcmp(accion,"marcar") == 0){
		cin >> f >> c;
		if(cin.fail()){
			cout << "Accion no valida, repita sentencia..." << endl;
			cin.clear();
		}else{
			if(!campo.marcarCasilla(f,c))
				cout << "No es posible marcar la casilla, ¿Esta dentro del tablero o ya esta abierta?." << endl;
		}
	}
	else if((accion[0] == 's' && accion[1] == '\0') || (accion[0] == 'S' && accion[1] == '\0') || strcmp(accion,"SALVAR") == 0 ||strcmp(accion,"salvar") == 0){
		cin >> ruta;
		campo.escribir(ruta);

		cout << "Partida guardada, continuar juego? S/N: ";
		char c;
		cin >> c;
		if(c == 'N' || c == 'n') exit(0);
	}
	else
		cout << "Accion no valida, repita sentencia(solo a, m o s)..." << endl;
}


/**
  * @brief Main
  *
  */

int main(int argc, char *argv[]){
	srand (time(0));

	if(argc == 2){
		CampoMinas campo(0,0,0);
		if(campo.leer(argv[1])){;
			campo.PrettyPrint();
			while(!campo.checkVictoria()){
				hacerMovimiento(campo);
				campo.PrettyPrint();
			}
			cout << endl << "//-------------//" << endl;
			cout << "HAS GANADO LA PARTIDA!" << endl;
			cout << "//-------------//" << endl<< endl;
		}else{
			cout << "No ha sido posible cargar la partida, nombre de archivo incorrecto o currupto." << endl;
			exit(0);
		}

	}else if(argc == 4){

		if(atoi(argv[1])<4||atoi(argv[2])<4|| atoi(argv[3])> ((atoi(argv[1])*atoi(argv[2]))/2) ){
			cout << "Filas o columnas insuficientes o minas en cantidades desbordantes" << endl;
			exit(0);
		}else{
			CampoMinas campo(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
			campo.PrettyPrint();
			while(!campo.checkVictoria()){
				hacerMovimiento(campo);
				campo.PrettyPrint();
			}
			cout << endl << "//-------------//" << endl;
			cout << "HAS GANADO LA PARTIDA!" << endl;
			cout << "//-------------//" << endl << endl;
		}
	}else if( argc > 4) {
		cout << "//---------------------------------------------------------------------//" << endl;
		cout << "Demasiadas opciones. la sintaxis para inciar el juego es la siguiente:" << endl;
		cout << "Para cargar partida pasamos el nombre del archivo de la partida deseada. Ejemplo: ./buscaminas mipartidaguardada.txt" << endl;
		cout << "Para iniciar una nueva partida, debemos de especificar el tamaño del tablero(filas y columnas) y el numero de minas. Ejemplo: ./buscaminas 5 5 10" << endl;
		cout << "//--------------------------------------------------------------------//" << endl;
	}else if(argc == 1 || argc == 3){
		cout << "//--------------------------------------------------------------------//" << endl;
		cout << "Opciones insuficientes para iniciar, la sintaxis para inciar el juego es la siguiente:" << endl;
		cout << "Para cargar partida pasamos el nombre del archivo de la partida deseada. Ejemplo: ./buscaminas mipartidaguardada.txt" << endl;
		cout << "Para iniciar una nueva partida, debemos de especificar el tamaño del tablero(filas y columnas) y el numero de minas. Ejemplo: ./buscaminas 5 5 10" << endl;
		cout << "//-------------------------------------------------------------------//" << endl;
	}
}
  
/* Fin Fichero: BuscaMinas.cpp */