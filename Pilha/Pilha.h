/*
 * Pilha.h
 *
 *  Created on: Sep 16, 2012
 *      Author: will
 */

#ifndef PILHA_H_
#define PILHA_H_

namespace Pilha {

int MAXPILHA = 30;
int PILHACHEIA = -2;
int PILHAVAZIA = -1;
class Pilha {
public:
	Pilha();
	virtual ~Pilha();
	virtual int empilhar(int);
	virtual int desempilhar();
	virtual int mostrarPilha();
	virtual int limpar();
private:
	int topo;
	int pilha[MAXPILHA];
	virtual bool pilhaVazia();
	virtual bool pilhaCheia();

};

} /* namespace Pilha */
#endif /* PILHA_H_ */
