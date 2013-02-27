/*
 * ArvoreB.h
 *
 *  Created on: Jan 21, 2013
 *      Author: will
 */

#ifndef ARVOREB_H_
#define ARVOREB_H_
#include "Nodo.h"

namespace Arvores {

class ArvoreB {

public:
	ArvoreB();
	virtual ~ArvoreB();
	void insereNaoCheio(int chave,Nodo* raiz);
	void insere(int chave);
	Nodo* raiz;
	void mostrarInOrdem(Nodo* nodo);
	int buscar(Nodo* raiz, int chave);
	void dividirNodo(Nodo* pai,int idx, Nodo* filho);

};

} /* namespace Ordenacao */
#endif /* ARVOREB_H_ */
