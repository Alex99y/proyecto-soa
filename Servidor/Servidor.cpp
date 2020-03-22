#include <iostream>
#include <string>
#include <Funciones_Servidor.h>

using namespace std;

int main(int argv, char* argc[]) {
	if ( argv == 3 ) {
		string Puerto(argc[1]);							// Guardo el puerto en un string para convertirlo a entero
		iniciar_Servidor(stoi(Puerto),argc[2],1);				// Inicio el servidor
	} else if ( argv == 4 ) {
		string Puerto(argc[1]);	
		string Threads(argc[3]);						// Hilos que tendrá el servidor
		iniciar_Servidor(stoi(Puerto),argc[2], stoi(Threads));
		
	}else {
		cout << " Error en los parametros para iniciar el servidor " <<endl;
		return -1;

	}
	return 0;
}
