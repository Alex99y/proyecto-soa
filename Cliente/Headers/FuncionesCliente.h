#include <json.hpp>
#include <curl/curl.h>
#include <string>
#include <stdarg.h>
#include <vector>

using namespace std;
using json = nlohmann::json;

string Enviar_peticion(string Parametros, string server);

class RPC {
	string server;
	public: 
		string get_server() { return server; }
		void set_server(string S) { server = S; }
	
	private:
	int _ID=0;

	private:
	/* Crear el json  para enviarlo al servidor */
	string Crear_json(string Funcion, int cant, string params[100]) {
		// Creamos el JSON y llenamos los parametros estáticos
		json init_j = json::array();
		json init_o = json::object();
		json Solicitud;
		_ID = _ID + 1;
		Solicitud["jsonrpc"]="2.0";
		Solicitud["method"]=Funcion;
		Solicitud["id"]=_ID;
		// Verifico si es por parametro o por nombre y lleno Solicitud["params"]
		if ( params[0].find('=') != string::npos ) {
			for ( int i=0; i < cant; i++ ) {
				if ( params[i].find('=') != string::npos ) {
					try {
						vector<string> v{explode(params[i], '=')};
						string a=v[0];
						float b= stof(v[1]);
					init_o += { a , b };
					}catch(invalid_argument& ia){
						return "Error";
					}
				}else{
					return "Error";
				}
			}
		Solicitud["params"]=init_o;
		}else{
			for ( int i=0; i < cant; i++ ) {
				if ( params[i].find('=') != string::npos ) {
					return "Error";
				}else{
					try {
						init_j.insert( init_j.begin() + init_j.size(), stof( params[i]) );
					}catch(invalid_argument& ia){
						return "Error";
					}
				}
			}
		Solicitud["params"]=init_j;
		}
		return Solicitud.dump(4);
	}

	const vector<string> explode(const string& s, const char& c)
	{
		string buff{""};
		vector<string> v;
	
		for(auto n:s)
		{
			if(n != c) buff+=n; else
			if(n == c && buff != "") { v.push_back(buff); buff = ""; }
		}
		if(buff != "") v.push_back(buff);
	
		return v;
	}

	public:
	 json Funcion(string Funcion, string param1, ...) {
		// Leemos los argumentos
		string Arg[100];
		int cant=1;
		va_list ap;
		Arg[0] = param1;
		va_start(ap, param1);
		while ( true ){
			char *a = va_arg(ap, char*);
			if ( a == NULL ) { break; }
			string temp(a);
			Arg[cant] = temp;
			cant++;
		}
		va_end(ap);
		// Creamos el JSON
		string el_json;
		el_json = Crear_json(Funcion,cant, Arg);
		// Veo si hay algun error:
		if ( el_json == "Error" ) {
			throw std::invalid_argument( "Argumentos Invalidos" );
		}
		// Sino, Enviamos la peticion
		string Response = Enviar_peticion(el_json,server);
		json retorno=json::parse(Response);
		if ( retorno["result"].is_object() ) {
			throw std::invalid_argument( "Argumentos Invalidos" );
		}
		return retorno;
	}
		
	float add(char* a, char* b){
		json resp = Funcion("add",a,b,NULL);
		return resp["result"];
	}

	float sub(char* a, char* b){
		json resp = Funcion("sub",a,b,NULL);
		return resp["result"];
	}

	float mul(char* a, char* b){
		json resp = Funcion("mul",a,b,NULL);
		return resp["result"];
	}

	float div(char* a, char* b){
		json resp = Funcion("truediv",a,b,NULL);
		return resp["result"];
	}

	float exp(char* a, char* b){
		json resp = Funcion("exp",a,b,NULL);
		return resp["result"];
	}

	float sqrt(char* a){
		json resp = Funcion("sqrt",a,NULL);
		return resp["result"];
	}

	float sin(char* a){
		json resp = Funcion("sin",a,NULL);
		return resp["result"];
	}

	float cos(char* a){
		json resp = Funcion("cos",a,NULL);
		return resp["result"];
	}

	float tan(char* a){
		json resp = Funcion("tan",a,NULL);
		return resp["result"];
	}

	float asin(char* a){
		json resp = Funcion("asin",a,NULL);
		return resp["result"];
	}

	float acos(char* a){
		json resp = Funcion("acos",a,NULL);
		return resp["result"];
	}

	float atan(char* a){
		json resp = Funcion("atan",a,NULL);
		return resp["result"];
	}

	float sinh(char* a){
		json resp = Funcion("sinh",a,NULL);
		return resp["result"];
	}

	float cosh(char* a){
		json resp = Funcion("cosh",a,NULL);
		return resp["result"];
	}

	float tanh(char* a){
		json resp = Funcion("tanh",a,NULL);
		return resp["result"];
	}

	float atan2(char* a, char* b){
		json resp = Funcion("atan2",a,b,NULL);
		return resp["result"];
	}

};


