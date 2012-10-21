/*
 * ElementoDePilha.cpp
 *
 *  Created on: Oct 13, 2012
 *      Author: will
 */

#include "Disco.h"

namespace PilhaEncadeada {

Disco::Disco() {
	// TODO Auto-generated constructor stub
	proximo =0;
	origem =0;
	tamanho =0;
}
Disco::Disco(int o, int t){
	proximo = 0;
	origem =o;
	tamanho =t;
}
Disco::~Disco() {
	// TODO Auto-generated destructor stub
}

} /* namespace Fila */
