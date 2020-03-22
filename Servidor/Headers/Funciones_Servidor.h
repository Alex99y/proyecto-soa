#include <string>
#include <json.hpp>
#include <iostream>
#include <pistache/endpoint.h>

using namespace Net;
using namespace std;
using json = nlohmann::json;

int iniciar_Servidor(int puerto, string _IP, int threads);

json OperarPorValor( json input );

json ProcesarPorNombre( json input );

class Manejador : public Http::Handler {
public:

	json Procesar_json( json input ) {
		json Respuesta,Error;
		// Validaciones ... 
		if ( input["id"] < 0 )
			goto ERROR_001;	// GOTO FAIL
		if ( input["jsonrpc"] != "2.0" )
			goto ERROR_001;	// GOTO FAIL
		if ( input.size() > 4 || input.size() < 4)
			goto ERROR_002;	// GOTO FAIL
		if ( input["params"].empty() )
			goto ERROR_001; // GOTO FAIL

		/* Parametros por nombre o por valor */
		if ( input["params"].is_object() ) {
			/* Ordenar los parametros, guardarlos en un array, y lamar OperarPorValor(input) */
			// "a":1 , "b":2 ... etc
			if ( input["params"].size() > 26 ) { goto ERROR_002; }
			input["params"] = ProcesarPorNombre(input["params"]);
			Respuesta = OperarPorValor(input);
			return Respuesta;			
		}else if ( input["params"].is_array() ) {
			Respuesta = OperarPorValor(input);
			return Respuesta;
		}else{
			/* Error en el json */
			goto ERROR_002;  // GOTO FAIL
		}
	/* Errores durante el parseo del json */
	ERROR_001:
		Respuesta["id"] = input["id"];
		Respuesta["jsonrpc"] = "2.0";
		Error["code"]=-32600;
		Error["message"]="Invalid Request";
		Respuesta["error"]=Error;
		return Respuesta;
	ERROR_002:
		Respuesta["id"] = input["id"];
		Respuesta["jsonrpc"] = "2.0";
		Error["code"]=-32700;
		Error["message"]="Parse error";
		Respuesta["error"]=Error;
		return Respuesta;
	}

    HTTP_PROTOTYPE(Manejador)
    void onRequest(const Http::Request& request, Http::ResponseWriter response) {
	
	if ( request.method() == Net::Http::Method::Post ) {
		json Respuesta;
		string Req(request.body()), Resp;
		json El_json = json::parse (Req);
		
		if ( !El_json.empty() ) {
			Respuesta = Procesar_json(El_json);
			Resp = Respuesta.dump(4);
			char *Param = new char[Resp.length() +1];
			strcpy(Param,Resp.c_str());
			response.send(Http::Code::Ok, Param);
		}else{
			/* Enviar error */
			
		}


        	response.send(Http::Code::Ok, "Json con la respuesta");
	}else{


		response.send(Http::Code::Not_Found, "Json con el error");
	}
    }
};

/* 

#include http_Defs.h para el status del response
 
*/
