/*
 * ElementoDePilha.h
 *
 *  Created on: Oct 13, 2012
 *      Author: will
 */

#ifndef ELEMENTODEPILHA_H_
#define ELEMENTODEPILHA_H_


namespace PilhaEncadeada {

class Disco {
public:
	Disco();
	Disco(int origem, int tamanho);
	virtual ~Disco();
	int origem;
	int diametro;
	Disco *proximo;
};

} /* namespace Fila */
#endif /* ELEMENTODEPILHA_H_ */
