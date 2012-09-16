/*
 * Pilha.h
 *
 *  Created on: Sep 16, 2012
 *      Author: will
 */

#ifndef PILHA_H_
#define PILHA_H_

namespace Pilha {

class Pilha {
public:
	Pilha();
	virtual ~Pilha();
	int incluir(int dado);
private:
	int topo;
	int MAXPILHA = -1;
	int PILHAVAZIA =-2;
};

} /* namespace Pilha */
#endif /* PILHA_H_ */
