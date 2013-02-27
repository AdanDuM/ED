/*
 * Nodo.h
 *
 *  Created on: 01/11/2012
 *      Author: grad
 */

#ifndef NODO_H_
#define NODO_H_

class Nodo {
public:
	Nodo();
	Nodo(int v);
	virtual ~Nodo();
	Nodo *filhoEsquerda;
	Nodo *filhoDireita;
	int valor;
	Nodo* construir(int inferior, int superior, int vetor[]);
	void buscar(Nodo* raiz, int inicio, int fim);
};

#endif /* NODO_H_ */
