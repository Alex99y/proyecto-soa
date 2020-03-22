#include <FuncionesCliente.h>
#include <json.hpp>
#include <curl/curl.h>
#include <string>
#include <stdarg.h>
#include <vector>
#include <iostream>

using namespace std;
using json = nlohmann::json;

struct String {
  char *Ptr;
  size_t len;
};
int _ID=0;


/* Obtener la respuesta http */
void init_string(struct String *s) {
  s->len = 0;
  s->Ptr = (char*)malloc(sizeof(char)*s->len+1);
  if (s->Ptr == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  s->Ptr[0] = '\0';
}
size_t writefunc(void *ptr, size_t size, size_t nmemb, struct String *s){
  size_t new_len = s->len + size*nmemb;
  s->Ptr = (char*)realloc(s->Ptr, sizeof(char)*new_len+1);
  if (s->Ptr == NULL) {
    fprintf(stderr, "realloc() failed\n");
    exit(EXIT_FAILURE);
  }
  memcpy(s->Ptr+s->len, ptr, size*nmemb);
  s->Ptr[new_len] = '\0';
  s->len = new_len;

  return size*nmemb;
}

/* Enviar peticion HTTP */
string Enviar_peticion(string Parametros, string SERVER){
	struct String s;
	CURL *curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if(curl) {
		init_string(&s);


		// Asignar Metodo y Datos a enviar
		char *Param = new char[Parametros.length() +1];
		strcpy(Param,Parametros.c_str());
		char *Param2 = new char[SERVER.length() +1];
		strcpy(Param2,SERVER.c_str());
		curl_easy_setopt(curl, CURLOPT_URL, Param2);			// Server: URL & Puerto
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, Param);		// Body
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);	// Callback
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);			// Write data

		// Enviar
		res = curl_easy_perform(curl);
	   	if(res != CURLE_OK) {
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
			curl_easy_strerror(res));
	 	}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	// Retornar la respuesta de CURL
	string Respuesta(s.Ptr);
	return Respuesta;
}


