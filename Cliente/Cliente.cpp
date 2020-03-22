#include <iostream>
#include <string>
#include <FuncionesCliente.h>


using namespace std;


int main () {
	// "http://10.0.2.15:9030"
	//Enviar la funcion y sus parametros, el final siempre tiene que ser NULL
	//cout<<Funcion("FuncionSumar","a=2","b=3",NULL)<<endl;
	//cout<<Funcion("asin","0.5",NULL)<<endl;
	//cout<<Funcion("acos","0.5","0.5",NULL)<<endl;
	//cout<<Funcion("atan2","10","5",NULL)<<endl;
	RPC func;
	func.set_server("http://10.0.2.15:9048");
	cout<<func.sub("b=10","a=60")<<endl;

	return 0;
}
