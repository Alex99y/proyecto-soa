#include <Funciones_Servidor.h>
#include <iostream>
#include <string>
#include <json.hpp>
#include <pistache/endpoint.h>
#include <FuncionesMatematicas.h>

using json = nlohmann::json;
using namespace std;
using namespace Net;



int iniciar_Servidor(int puerto, string _IP, int threads){
	// Iniciar servidor
	// 10.0.2.15
	Net::Address addr(_IP, Net::Port(puerto) );
	auto opts = Net::Http::Endpoint::options()
		.threads(threads);
	Http::Endpoint SERVER(addr);
	SERVER.init(opts);
	SERVER.setHandler(Http::make_handler<Manejador>());
	SERVER.serve();
	return 0;
}

json ProcesarPorNombre( json input ) {
	json Array=json::array();
		if ( input[ "a" ].is_number() ) {Array.push_back(input["a"]);} 
		if ( input[ "b" ].is_number() ) {Array.push_back(input["b"]);}
		if ( input[ "c" ].is_number() ) {Array.push_back(input["c"]);}
		if ( input[ "d" ].is_number() ) {Array.push_back(input["d"]);}
		if ( input[ "e" ].is_number() ) {Array.push_back(input["e"]);}
		if ( input[ "f" ].is_number() ) {Array.push_back(input["f"]);}
		if ( input[ "g" ].is_number() ) {Array.push_back(input["g"]);}
		if ( input[ "h" ].is_number() ) {Array.push_back(input["h"]);}
		if ( input[ "i" ].is_number() ) {Array.push_back(input["i"]);}
		if ( input[ "j" ].is_number() ) {Array.push_back(input["j"]);}
		if ( input[ "k" ].is_number() ) {Array.push_back(input["k"]);}
		if ( input[ "l" ].is_number() ) {Array.push_back(input["l"]);}
		if ( input[ "m" ].is_number() ) {Array.push_back(input["m"]);}
		if ( input[ "n" ].is_number() ) {Array.push_back(input["n"]);}
		if ( input[ "o" ].is_number() ) {Array.push_back(input["o"]);}
		if ( input[ "p" ].is_number() ) {Array.push_back(input["p"]);}
		if ( input[ "q" ].is_number() ) {Array.push_back(input["q"]);}
		if ( input[ "r" ].is_number() ) {Array.push_back(input["r"]);}
		if ( input[ "s" ].is_number() ) {Array.push_back(input["s"]);}
		if ( input[ "t" ].is_number() ) {Array.push_back(input["t"]);}
		if ( input[ "u" ].is_number() ) {Array.push_back(input["u"]);}
		if ( input[ "v" ].is_number() ) {Array.push_back(input["v"]);}
		if ( input[ "w" ].is_number() ) {Array.push_back(input["w"]);}
		if ( input[ "x" ].is_number() ) {Array.push_back(input["x"]);}
		if ( input[ "y" ].is_number() ) {Array.push_back(input["y"]);}
		if ( input[ "z" ].is_number() ) {Array.push_back(input["z"]);}
	return Array;
}

json OperarPorValor( json input ) {
	json Respuesta, Error,AUX;
	string Params[100], Resp;
	vector <string> Resp_vec;
	FuncionesMatematicas *Op = new FuncionesMatematicas();
	/* Guardar parametros */
	int Total=input["params"].size();
	if ( Total == 0 || Total >= 100) { goto ERROR_001; }else{
		for ( int i=0; i < Total; i++ ) {
			Params[i]=to_string((float)input["params"].at(i));
		}
	}
	/* Preparar el JSON de salida*/

	Respuesta["id"] = input["id"];
	Respuesta["jsonrpc"] = "2.0";

	/* Operar: */
	if ( input["method"] == "add" ){
		Resp=Op->Suma(input["params"].size(),Params);
		if (Resp == "ERROR"){ goto ERROR_002; }
		Respuesta["result"]=stof(Resp);
		return Respuesta;

	}else if ( input["method"] == "sub" ){
		Resp=Op->Resta(input["params"].size(),Params);
		if (Resp == "ERROR"){ goto ERROR_002; }
		Respuesta["result"]=stof(Resp);
		return Respuesta;

	}else if ( input["method"] == "mul" ){
		Resp=Op->Multiplicacion(input["params"].size(),Params);
		if (Resp == "ERROR"){ goto ERROR_002; }
		Respuesta["result"]=stof(Resp);
		return Respuesta;

	}else if ( input["method"] == "truediv" ){

		Resp=Op->Division(input["params"].size(),Params);
		if (Resp == "ERROR"){ goto ERROR_002; }
		Respuesta["result"]=stof(Resp);
		return Respuesta;

	}else if ( input["method"] == "exp" ){

		Resp_vec=Op->Elevar(input["params"].size(),Params);
		if (Resp_vec[0] == "ERROR"){ goto ERROR_002; }
			AUX=json::array();
			if ( Resp_vec.size() > 1 ) {
			for (unsigned int i=0; i < input["params"].size()/2; i++){
				float a = stof(Resp_vec[i]);
				AUX.insert( AUX.begin() + AUX.size(), a );
			}
			Respuesta["result"]=AUX;
			return Respuesta;
		}else{
			Respuesta["result"]=stof(Resp_vec[0]);
			return Respuesta;
		}

	}else if ( input["method"] == "sqrt" ){
		Resp_vec=Op->RaizC(input["params"].size(),Params);
		if (Resp_vec[0] == "ERROR"){ goto ERROR_002; }
			AUX=json::array();
			if ( Resp_vec.size() > 1 ) {
			for (unsigned int i=0; i < input["params"].size(); i++){
				float a = stof(Resp_vec[i]);
				AUX.insert( AUX.begin() + AUX.size(), a );
			}
			Respuesta["result"]=AUX;
			return Respuesta;
		}else{
			Respuesta["result"]=stof(Resp_vec[0]);
			return Respuesta;
		}

	}else if ( input["method"] == "sin" ){

		Resp_vec=Op->Seno(input["params"].size(),Params);
		if (Resp_vec[0] == "ERROR"){ goto ERROR_002; }
			AUX=json::array();
			if ( Resp_vec.size() > 1 ) {
			for (unsigned int i=0; i < input["params"].size(); i++){
				float a = stof(Resp_vec[i]);
				AUX.insert( AUX.begin() + AUX.size(), a );
			}
			Respuesta["result"]=AUX;
			return Respuesta;
		}else{
			Respuesta["result"]=stof(Resp_vec[0]);
			return Respuesta;
		}

	}else if ( input["method"] == "cos" ){
		Resp_vec=Op->Coseno(input["params"].size(),Params);
		if (Resp_vec[0] == "ERROR"){ goto ERROR_002; }
			AUX=json::array();
			if ( Resp_vec.size() > 1 ) {
			for (unsigned int i=0; i < input["params"].size(); i++){
				float a = stof(Resp_vec[i]);
				AUX.insert( AUX.begin() + AUX.size(), a );
			}
			Respuesta["result"]=AUX;
			return Respuesta;
		}else{
			Respuesta["result"]=stof(Resp_vec[0]);
			return Respuesta;
		}

	}else if ( input["method"] == "tan" ){
		Resp_vec=Op->Tangente(input["params"].size(),Params);
		if (Resp_vec[0] == "ERROR"){ goto ERROR_002; }
			AUX=json::array();
			if ( Resp_vec.size() > 1 ) {
			for (unsigned int i=0; i < input["params"].size(); i++){
				float a = stof(Resp_vec[i]);
				AUX.insert( AUX.begin() + AUX.size(), a );
			}
			Respuesta["result"]=AUX;
			return Respuesta;
		}else{
			Respuesta["result"]=stof(Resp_vec[0]);
			return Respuesta;
		}

	}else if ( input["method"] == "asin" ){
		Resp_vec=Op->Arcoseno(input["params"].size(),Params);
		if (Resp_vec[0] == "ERROR"){ goto ERROR_002; }
			AUX=json::array();
			if ( Resp_vec.size() > 1 ) {
			for (unsigned int i=0; i < input["params"].size(); i++){
				float a = stof(Resp_vec[i]);
				AUX.insert( AUX.begin() + AUX.size(), a );
			}
			Respuesta["result"]=AUX;
			return Respuesta;
		}else{
			Respuesta["result"]=stof(Resp_vec[0]);
			return Respuesta;
		}
	}else if ( input["method"] == "acos" ){
		Resp_vec=Op->Arcocoseno(input["params"].size(),Params);
		if (Resp_vec[0] == "ERROR"){ goto ERROR_002; }
			AUX=json::array();
			if ( Resp_vec.size() > 1 ) {
			for (unsigned int i=0; i < input["params"].size(); i++){
				float a = stof(Resp_vec[i]);
				AUX.insert( AUX.begin() + AUX.size(), a );
			}
			Respuesta["result"]=AUX;
			return Respuesta;
		}else{
			Respuesta["result"]=stof(Resp_vec[0]);
			return Respuesta;
		}
	}else if ( input["method"] == "atan" ){
		Resp_vec=Op->Arcotangente(input["params"].size(),Params);
		if (Resp_vec[0] == "ERROR"){ goto ERROR_002; }
			AUX=json::array();
			if ( Resp_vec.size() > 1 ) {
			for (unsigned int i=0; i < input["params"].size(); i++){
				float a = stof(Resp_vec[i]);
				AUX.insert( AUX.begin() + AUX.size(), a );
			}
			Respuesta["result"]=AUX;
			return Respuesta;
		}else{
			Respuesta["result"]=stof(Resp_vec[0]);
			return Respuesta;
		}

	}else if ( input["method"] == "sinh" ){

		Resp_vec=Op->Senohiperbolico(input["params"].size(),Params);
		if (Resp_vec[0] == "ERROR"){ goto ERROR_002; }
			AUX=json::array();
			if ( Resp_vec.size() > 1 ) {
			for (unsigned int i=0; i < input["params"].size(); i++){
				float a = stof(Resp_vec[i]);
				AUX.insert( AUX.begin() + AUX.size(), a );
			}
			Respuesta["result"]=AUX;
			return Respuesta;
		}else{
			Respuesta["result"]=stof(Resp_vec[0]);
			return Respuesta;
		}

	}else if ( input["method"] == "cosh" ){

		Resp_vec=Op->Cosenohiberbolico(input["params"].size(),Params);
		if (Resp_vec[0] == "ERROR"){ goto ERROR_002; }
			AUX=json::array();
			if ( Resp_vec.size() > 1 ) {
			for (unsigned int i=0; i < input["params"].size(); i++){
				float a = stof(Resp_vec[i]);
				AUX.insert( AUX.begin() + AUX.size(), a );
			}
			Respuesta["result"]=AUX;
			return Respuesta;
		}else{
			Respuesta["result"]=stof(Resp_vec[0]);
			return Respuesta;
		}

	}else if ( input["method"] == "tanh" ){
		Resp_vec=Op->TangenteHiperbolica(input["params"].size(),Params);
		if (Resp_vec[0] == "ERROR"){ goto ERROR_002; }
			AUX=json::array();
			if ( Resp_vec.size() > 1 ) {
			for (unsigned int i=0; i < input["params"].size(); i++){
				float a = stof(Resp_vec[i]);
				AUX.insert( AUX.begin() + AUX.size(), a );
			}
			Respuesta["result"]=AUX;
			return Respuesta;
		}else{
			Respuesta["result"]=stof(Resp_vec[0]);
			return Respuesta;
		}

	}else if ( input["method"] == "atan2" ){
		Resp_vec=Op->Atan2(input["params"].size(),Params);
		if (Resp_vec[0] == "ERROR"){ goto ERROR_002; }
			AUX=json::array();
			if ( Resp_vec.size() > 1 ) {
			for (unsigned int i=0; i < input["params"].size()/2; i++){
				float a = stof(Resp_vec[i]);
				AUX.insert( AUX.begin() + AUX.size(), a );
			}
			Respuesta["result"]=AUX;
			return Respuesta;
		}else{
			Respuesta["result"]=stof(Resp_vec[0]);
			return Respuesta;
		}

	}
	return Respuesta;
	ERROR_001:
		Error["message"]="Invalid Request";
		Error["code"]=-32600;
		Respuesta["id"] = input["id"];
		Respuesta["jsonrpc"] = "2.0";
		Respuesta["error"]=Error;
	return Respuesta.dump(4);
	ERROR_002:
		Error["message"]="Invalid Params";
		Error["code"]=-32700;
		Respuesta["id"] = input["id"];
		Respuesta["jsonrpc"] = "2.0";
		Respuesta["error"]=Error;
	return Respuesta.dump(4);
}



