/*
 * Nodo.h
 *
 *  Created on: Jan 10, 2013
 *      Author: will
 */

#ifndef NODO_H_
#define NODO_H_

#define T 60
#include <iostream>
#include <string.h>
using namespace std;
namespace Arvores {

class Nodo {
public:
	Nodo();
	Nodo(bool f);
	virtual ~Nodo();
	bool folha;
	int numeroChaves;
	Nodo** filhos;
	string* chaves;
	void mostrarNodo();

};

} /* namespace Ordenacao */
#endif /* NODO_H_ */
