/*
 * Chave.cpp
 *
 *  Created on: 30/11/2012
 *      Author: tiago
 */

#include "Chave.h"
namespace ArvoreB{
Chave::Chave() {
	// TODO Auto-generated constructor stub
	proximo = 0;
	anterior = 0;
	filhoEsquerda = 0;
	filhoDireita = 0;
	info = 0;
}

Chave::Chave(Info *inf){
	proximo = 0;
	anterior = 0;
	filhoEsquerda = 0;
	filhoDireita = 0;
	info = inf;
}

Chave::~Chave() {
	// TODO Auto-generated destructor stub
}

}
