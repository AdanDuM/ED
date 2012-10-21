/*
 * CabecaDePilha.h
 *
 *  Created on: Oct 13, 2012
 *      Author: will
 */

#ifndef PILHA_H_
#define PILHA_H_

#define ERRO_MOVIMENTO -1
#define PILHA_VAZIA 0

#include "Disco.h"

namespace PilhaEncadeada {

class Pilha {
public:
	Pilha();
	virtual ~Pilha();
	int id;
	int tamanho;
	int diametroTopo;
	Disco *topo;
	int empilha(Disco *novo);
	Disco* desempilha();
	bool vazia();
	bool contem(Disco *examinado);
};

} /* namespace Fila */
#endif /* CABECADEPILHA_H_ */
