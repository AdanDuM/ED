/*
 * Nodo.h
 *
 *  Created on: Nov 8, 2012
 *      Author: will
 */

#ifndef NODO_H_
#define NODO_H_
#include "Info.h"

namespace AVL {

class Nodo {
public:
	Nodo();
	Nodo(Info *i);
	virtual ~Nodo();
	Info *info;
	int alt;
	Nodo *direita;
	Nodo *esquerda;
	int altura(Nodo *subArvore);
	Nodo* rotacaoEsquerdaSimples(Nodo* k2);
	Nodo* rotacaoDireitaSimples(Nodo* k2);
	Nodo* rotacaoDuplaEsquerda(Nodo* k2);
	Nodo* rotacaoDuplaDireita(Nodo* k2);
	Nodo* insere(Info *info,Nodo *arv, Nodo *pai);
	int max(int a, int b);

};

} /* namespace Fila */
#endif /* NODO_H_ */
