#include <math.h>
#include <string>
#include <json.hpp>
#include <stdexcept>
#include <vector>

using namespace std;
using json = nlohmann::json;


class FuncionesMatematicas {
	string Resultado;
	vector<string> Resultados, ERROR_V;
	public: FuncionesMatematicas(){
	

	}
	/* Operaciones Aritmeticas */
	public: string Suma(int ARGV, string ARGC[100]) {
		float Resp=0,Aux=0;
		for ( int i=0; i< ARGV; i++ ) {
			try {
				Aux = stof(ARGC[i]);
				Resp = Resp + Aux;
			}catch (invalid_argument& ia){
				return "ERROR";
			}
		}
		Resultado = to_string(Resp);
		return Resultado;
	}

	public: string Resta(int ARGV, string ARGC[100]) {
		float Resp=0,Aux=0;
		try {
			Resp = stof(ARGC[0]);
			for ( int i=1; i< ARGV; i++ ) {
				Aux = stof(ARGC[i]);
				Resp = Resp - Aux;
			}
			Resultado = to_string(Resp);
			return Resultado;
		}catch (invalid_argument& ia){
			return "ERROR";
		}
	}

	public: string Multiplicacion(int ARGV, string ARGC[100]) {
		float Resp=1,Aux=0;
		for ( int i=0; i< ARGV; i++ ) {
			try {
				Aux = stof(ARGC[i]);
				Resp = Resp * Aux;
			}catch (invalid_argument& ia){
				return "ERROR";
			}
		}
		Resultado = to_string(Resp);
		return Resultado;
	}

	public: string Division(int ARGV, string ARGC[100]) {
		float Resp=0,Aux=0;
		try { Resp = stof(ARGC[0]); }catch( invalid_argument& ia ){ return "ERROR"; }
		for ( int i=1; i< ARGV; i++ ) {
			try {
				Aux = stof(ARGC[i]);
				if ( Aux == 0 ) { return "ERROR"; }
				Resp = Resp / Aux;
			}catch (invalid_argument& ia){
				return "ERROR";
			}
		}
		Resultado = to_string(Resp);
		return Resultado;

	return Resultado;
	}

	public: vector<string> Elevar(int ARGV, string ARGC[100]) {
		if ( ARGV % 2 == 0 ){
			for ( int i=0; i<ARGV; i=i+2 ) {
				try {
					float a = stof(ARGC[i]);
					float b = stof(ARGC[i+1]);
					float r = pow(a,b);
					Resultados.push_back(to_string(r));
				}catch(invalid_argument& ia){
					Resultado = "ERROR";
					ERROR_V.push_back(Resultado);
					return ERROR_V;
				}
			}
			return Resultados;
		}else{
			Resultado = "ERROR";
			ERROR_V.push_back(Resultado);
			return ERROR_V;
		}
	}

	public: vector<string> RaizC(int ARGV, string ARGC[100]) {
		for ( int i=0; i<ARGV; i++ ) {
			try {
				float a = stof(ARGC[i]);
				float r = sqrt(a);
				Resultados.push_back(to_string(r));
			}catch(invalid_argument& ia){
				Resultado = "ERROR";
				ERROR_V.push_back(Resultado);
				return ERROR_V;
			}
		}
		return Resultados;
	}
	/* Operaciones Trigonometricas */
	public: vector<string> Seno(int ARGV, string ARGC[100]){
		for ( int i=0; i<ARGV; i++ ) {
			try {
				float a = stof(ARGC[i]);
				float r = sin(a);
				Resultados.push_back(to_string(r));
			}catch(invalid_argument& ia){
				Resultado = "ERROR";
				ERROR_V.push_back(Resultado);
				return ERROR_V;
			}
		}
	return Resultados;
	}
	
	public: vector <string> Coseno(int ARGV, string ARGC[100]){
		for ( int i=0; i<ARGV; i++ ) {
			try {
				float a = stof(ARGC[i]);
				float r = cos(a);
				Resultados.push_back(to_string(r));
			}catch(invalid_argument& ia){
				Resultado = "ERROR";
				ERROR_V.push_back(Resultado);
				return ERROR_V;
			}
		}
	return Resultados;
	}

	public: vector <string> Tangente(int ARGV, string ARGC[100]){
		for ( int i=0; i<ARGV; i++ ) {
			try {
				float a = stof(ARGC[i]);
				float r = tan(a);
				Resultados.push_back(to_string(r));
			}catch(invalid_argument& ia){
				Resultado = "ERROR";
				ERROR_V.push_back(Resultado);
				return ERROR_V;
			}
		}
	return Resultados;	
	}

	public: vector <string> Arcoseno(int ARGV, string ARGC[100]){
		for ( int i=0; i<ARGV; i++ ) {
			try {
				float a = stof(ARGC[i]);
				float r = asin(a);
				Resultados.push_back(to_string(r));
			}catch(invalid_argument& ia){
				Resultado = "ERROR";
				ERROR_V.push_back(Resultado);
				return ERROR_V;
			}
		}
	return Resultados;
	}

	public: vector <string> Arcocoseno(int ARGV, string ARGC[100]){
		for ( int i=0; i<ARGV; i++ ) {
			try {
				float a = stof(ARGC[i]);
				float r = acos(a);
				Resultados.push_back(to_string(r));
			}catch(invalid_argument& ia){
				Resultado = "ERROR";
				ERROR_V.push_back(Resultado);
				return ERROR_V;
			}
		}
	return Resultados;
	}

	public: vector <string> Arcotangente(int ARGV, string ARGC[100]){
		for ( int i=0; i<ARGV; i++ ) {
			try {
				float a = stof(ARGC[i]);
				float r = atan(a);
				Resultados.push_back(to_string(r));
			}catch(invalid_argument& ia){
				Resultado = "ERROR";
				ERROR_V.push_back(Resultado);
				return ERROR_V;
			}
		}
	return Resultados;
	}
	/* Funciones transcendentes*/
	public: vector <string> Senohiperbolico(int ARGV, string ARGC[100]){
		for ( int i=0; i<ARGV; i++ ) {
			try {
				float a = stof(ARGC[i]);
				float r = sinh(a);
				Resultados.push_back(to_string(r));
			}catch(invalid_argument& ia){
				Resultado = "ERROR";
				ERROR_V.push_back(Resultado);
				return ERROR_V;
			}
		}
	return Resultados;
	}

	public: vector <string> Cosenohiberbolico(int ARGV, string ARGC[100]){
		for ( int i=0; i<ARGV; i++ ) {
			try {
				float a = stof(ARGC[i]);
				float r = cosh(a);
				Resultados.push_back(to_string(r));
			}catch(invalid_argument& ia){
				Resultado = "ERROR";
				ERROR_V.push_back(Resultado);
				return ERROR_V;
			}
		}
	return Resultados;
	}

	public: vector <string> TangenteHiperbolica(int ARGV, string ARGC[100]){
		for ( int i=0; i<ARGV; i++ ) {
			try {
				float a = stof(ARGC[i]);
				float r = tanh(a);
				Resultados.push_back(to_string(r));
			}catch(invalid_argument& ia){
				Resultado = "ERROR";
				ERROR_V.push_back(Resultado);
				return ERROR_V;
			}
		}
	return Resultados;
	}
	public: vector <string> Atan2(int ARGV, string ARGC[100]){
		if ( ARGV % 2 == 0 ){
			for ( int i=0; i<ARGV; i=i+2 ) {
				try {
					float a = stof(ARGC[i]);
					float b = stof(ARGC[i+1]);
					float r = atan2(a,b);
					Resultados.push_back(to_string(r));
				}catch(invalid_argument& ia){
					Resultado = "ERROR";
					ERROR_V.push_back(Resultado);
					return ERROR_V;
				}
			}
			return Resultados;
		}else{
			Resultado = "ERROR";
			ERROR_V.push_back(Resultado);
			return ERROR_V;
		}
	}

};








