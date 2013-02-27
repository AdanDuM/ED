/*
 * Info.cpp
 *
 *  Created on: Nov 8, 2012
 *      Author: will
 */

#include "Info.h"

namespace AVL {

Info::Info() {
	// TODO Auto-generated constructor stub
	logradouro = 0;
	cep = 0;
}
Info::Info(long int c, char* l) {
	logradouro = l;
	cep = c;
}

Info::~Info() {
	// TODO Auto-generated destructor stub
}

} /* namespace Fila */
