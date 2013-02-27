/*
 * Chave.h
 *
 *  Created on: 30/11/2012
 *      Author: tiago
 */

#ifndef CHAVE_H_
#define CHAVE_H_
#include "Info.h"

#include "Nodo.h"
namespace ArvoreB{
class Nodo;
class Chave {
public:
	Chave();
	Chave(Info *info);
	virtual ~Chave();

	Chave *proximo, *anterior;
	Nodo *filhoEsquerda, *filhoDireita;
	Info *info;
};
}
#endif /* CHAVE_H_ */
