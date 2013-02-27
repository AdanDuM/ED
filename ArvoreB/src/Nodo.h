/*
 * Nodo.h
 *
 *  Created on: Jan 10, 2013
 *      Author: will
 */

#ifndef NODO_H_
#define NODO_H_

#define T 60
namespace Arvores {

class Nodo {
public:
	Nodo();
	Nodo(bool f);
	virtual ~Nodo();
	bool folha;
	int numeroChaves;
	Nodo** filhos;
	int* chaves;
	void mostrarNodo();

};

} /* namespace Ordenacao */
#endif /* NODO_H_ */
