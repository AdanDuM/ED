#include <cstdlib>
#include "Elemento.h"

Elemento::Elemento(int con) {
	referencia[0] = NULL;
	referencia[1] = NULL;
	conteudo = con;
}

Elemento::~Elemento() {
}

Elemento* Elemento :: informarReferencia(bool extremo){
	return referencia[extremo];
}

int Elemento :: informarConteudo(){
	return conteudo;
}

Elemento* Elemento :: receberReferencia(Elemento *ref, bool extremo){
	referencia[extremo] = ref;
	return referencia[extremo];
}

void Elemento :: receberConteudo(int cont){
	conteudo = cont;
}
